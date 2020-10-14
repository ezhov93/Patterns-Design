#ifndef CELLINGFAN_H
#define CELLINGFAN_H

#include <iostream>
#include <string>

class CeilingFan {
 public:
  enum Speed { OFF, LOW, MEDIUM, HIGH };
  explicit CeilingFan(std::string location) : location(location), speed(OFF) {}
  void high() const {
    std::cout << location << " set speed HIGH" << std::endl;
    speed = HIGH;
  }
  void medium() const {
    std::cout << location << " set speed MEDIUM" << std::endl;
    speed = MEDIUM;
  }
  void low() const {
    std::cout << location << " set speed LOW" << std::endl;
    speed = LOW;
  }
  void off() const {
    std::cout << location << " set speed OFF" << std::endl;
    speed = OFF;
  }
  Speed getSpeed() const { return speed; }

 private:
  std::string location;
  mutable Speed speed;
};

#endif  // CELLINGFAN_H
