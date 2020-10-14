#ifndef STEREO_H
#define STEREO_H

#include <iostream>

class Stereo {
 public:
  explicit Stereo() = default;
  void on() const { std::cout << "Stereo::on()" << std::endl; }
  void off() const { std::cout << "Stereo::off()" << std::endl; }
  void setCD() const { std::cout << "Stereo::setCD()" << std::endl; }
  void setVolume(int num) const {
    std::cout << "Stereo::volume =" << num << std::endl;
  }
};

#endif  // STEREO_H
