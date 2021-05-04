#pragma once

#include <string>

#include "security.hh"

namespace keepass {

class Binary final {
 private:
  protect<std::string> data_;
  bool compress_ = false;

 public:
  Binary(const protect<std::string>& data) :
      data_(data) {}

  bool Empty() const { return data_->empty(); }
  std::size_t Size() const { return data_->size(); }

  const protect<std::string>& data() const { return data_; }
  void set_data(const protect<std::string>& data) { data_ = data; }

  bool compress() const { return compress_; }
  void set_compress(bool compress) { compress_ = compress; }

  bool operator==(const Binary& other) const {
    return data_ == other.data_;
  }
  bool operator!=(const Binary& other) const {
    return !(*this == other);
  }
};

}   // namespace keepass
