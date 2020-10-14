#ifndef BEVARAGE_H
#define BEVARAGE_H

#include <string>

class Bevarage {
 public:
  enum Size { TALL, GRANDE, VENTI };
  Bevarage() : _description("Unknown Beverage"), _size(TALL) {}
  virtual ~Bevarage() = default;
  virtual std::string description() const { return _description; }
  virtual double cost() const = 0;
  void setSize(Size size) const { _size = size; }
  Size size() const { return _size; }

 protected:
  std::string _description;
  mutable Size _size;
};

#endif  // BEVARAGE_H
