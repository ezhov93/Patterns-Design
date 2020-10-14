#ifndef LIGHT_H
#define LIGHT_H

#include <iostream>

class Light {
 public:
  explicit Light() = default;
  void on() const { std::cout << "Light::on()" << std::endl; }
  void off() const { std::cout << "Light::off()" << std::endl; }
};

#endif  // LIGHT_H
