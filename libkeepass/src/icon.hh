#pragma once

#include <vector>

namespace keepass {

class Icon final {
 private:
  std::array<uint8_t, 16> uuid_;
  std::vector<uint8_t> data_;

 public:
  Icon(const std::array<uint8_t, 16>& uuid, const std::vector<uint8_t>& data) :
      uuid_(uuid), data_(data) {}

  const std::array<uint8_t, 16>& uuid() const { return uuid_; }

  const std::vector<uint8_t>& data() const { return data_; }
  void set_data(const std::vector<uint8_t>& data) { data_ = data; }

  bool operator==(const Icon& other) const {
    return data_ == other.data_;
  }
  bool operator!=(const Icon& other) const {
    return !(*this == other);
  }
};

}   // namespace keepass
