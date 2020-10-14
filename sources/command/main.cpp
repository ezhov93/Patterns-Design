#include <functional>
#include <iostream>
#include "cellingfancommands.h"
#include "lightcommands.h"
#include "macrocommand.h"
#include "remotecontroll.h"
#include "stereocommands.h"

int main() {
  RemoteControll remote;

  Light light;
  LightOnCommand lighOn(&light);
  LightOffCommand lighOff(&light);

  Stereo stereo;
  StereoOnWithCDCommand stereoOn(&stereo);
  StereoOffWithCDCommand stereoOff(&stereo);

  CeilingFan ceilingFan("Living Room");
  CeilingFanHighCommand ceilingFanHigh(&ceilingFan);
  CeilingFanMediumCommand ceilingFanMedium(&ceilingFan);
  CeilingFanOffCommand ceilingFanOff(&ceilingFan);

  std::vector<Command*> partyOn;
  partyOn.push_back(&lighOn);
  partyOn.push_back(&stereoOn);
  std::vector<Command*> partyOff;
  partyOff.push_back(&lighOff);
  partyOff.push_back(&stereoOff);

  MacroCommand partyOnMacro(&partyOn);
  MacroCommand partyOffMacro(&partyOff);

  auto stereoCommand = new Command([&stereo]() {
    stereo.on();
    stereo.setCD();
    stereo.setVolume(15);
  });

  remote.setCommand(&lighOn, &lighOff);
  remote.setCommand(&stereoOn, &stereoOff);
  remote.setCommand(&ceilingFanMedium, &ceilingFanOff);
  remote.setCommand(&ceilingFanHigh, &ceilingFanOff);
  remote.setCommand(&partyOnMacro, &partyOffMacro);
  remote.setCommand(new Command([&light]() { light.on(); }),
                    new Command([&light]() { light.off(); }));
  remote.setCommand(stereoCommand, &stereoOff);

  for (size_t i = 0; i < remote.numberOfSlots(); ++i) {
    std::cout << "************************"
              << "Button " << i << "********************" << std::endl;
    std::cout << "Button " << i << " press ON" << std::endl;
    remote.onButtonWasPressed(i);
    std::cout << "Button " << i << " press OFF" << std::endl;
    remote.offButtonWasPressed(i);
    std::cout << remote.toString();
    std::cout << std::endl << "Button " << i << " UNDO" << std::endl;
    remote.undoButtonWasPressed();
    std::cout << std::endl;
  }

  system("pause");

  return 0;
}
