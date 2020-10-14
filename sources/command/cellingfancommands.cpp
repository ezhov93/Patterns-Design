#include "cellingfancommands.h"

void CeilingFanCommand::undo() const {
  if (prevSpeed == CeilingFan::HIGH) {
    ceilingFan->high();
  } else if (prevSpeed == CeilingFan::MEDIUM) {
    ceilingFan->medium();
  } else if (prevSpeed == CeilingFan::LOW) {
    ceilingFan->low();
  } else if (prevSpeed == CeilingFan::OFF) {
    ceilingFan->off();
  }
}