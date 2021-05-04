#pragma once

namespace keepass {

class PasswordError final : public std::exception {
 public:
  explicit PasswordError() {}

  virtual const char* what() const throw() override {
    return "Invalid password.";
  }
};

class FormatError final : public std::exception {
 private:
  const std::string msg_;

 public:
  explicit FormatError(const std::string& msg) :
      msg_(msg) {}

  virtual const char* what() const throw() override {
    return msg_.c_str();
  }
};

/**
 * @brief Used for the same class of errors as asserts but for release builds.
 */
class InternalError : public std::exception {
 private:
  const std::string msg_;

 public:
  explicit InternalError(const std::string& msg) :
      msg_(msg) {}

  virtual const char* what() const throw() override {
    return msg_.c_str();
  }
};

class IoError : public std::exception {
 private:
  const std::string msg_;

 public:
  explicit IoError(const std::string& msg) :
      msg_(msg) {}

  virtual const char* what() const throw() override {
    return msg_.c_str();
  }
};

class FileNotFoundError final : public IoError {
 public:
  FileNotFoundError() :
      IoError("File not found.") {}
};

}   // namespace keepass
