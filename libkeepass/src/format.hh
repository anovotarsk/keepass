#pragma once

#include <sstream>

class Format {
 private:
  std::stringstream str_;

  Format(const Format& rhs) = default;
  Format& operator=(const Format& rhs) = default;

 public:
  Format() = default;

  template <typename T>
  Format& operator<<(const T& val) {
    str_ << val;
    return *this;
  }

  operator std::string() const {
    return str_.str();
  }
};
