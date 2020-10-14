#ifndef MENUEXCEPTION_H
#define MENUEXCEPTION_H

#include <exception>
#include <string>

class UnsupportedOperationException : public std::exception {
 private:
  const std::string _message;

 public:
  UnsupportedOperationException() : _message("") {}
  UnsupportedOperationException(const std::string message)
      : _message(message) {}
  std::string getMessage() const { return _message; }
  const char *what() const noexcept override { return _message.c_str(); }
};

#endif  // MENUEXCEPTION_H
