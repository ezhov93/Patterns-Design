#ifndef TURKEYADAPTER_H
#define TURKEYADAPTER_H

#include <cassert>
#include "duck.h"
#include "turkey.h"
#include <memory>

class TurkeyAdapter : public Duck {
 private:
  std::shared_ptr<Turkey> turkey;
  TurkeyAdapter(const TurkeyAdapter&) = delete;   // Disable copy constructor
  void operator=(const TurkeyAdapter&) = delete;  // Disable assignment operator

 public:
  explicit TurkeyAdapter(std::shared_ptr<Turkey> turkey) : turkey(turkey) {
    assert(turkey);
  }
  virtual ~TurkeyAdapter() = default;
  virtual void quack() const final {
    assert(turkey);
    turkey->gobble();
  }
  virtual void fly() const final {
    assert(turkey);
    for (int i = 0; i < 5; i++) turkey->fly();
  }
};

#endif  // TURKEYADAPTER_H
