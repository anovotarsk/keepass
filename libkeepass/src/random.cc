#include "random.hh"

namespace keepass {

RandomObfuscator::RandomObfuscator(const std::array<uint8_t, 32>& key,
                                   const std::array<uint8_t, 8>& init_vec) :
    cipher_(key, init_vec) {
}

void RandomObfuscator::FillBuffer() {
  static constexpr std::array<uint8_t, 64> kZeroBlock = { 0 };

  assert(buffer_pos_ == buffer_.size());
  cipher_.Process(kZeroBlock, buffer_);
  buffer_pos_ = 0;
}

std::vector<uint8_t> RandomObfuscator::Process(
    const std::vector<uint8_t>& data) {
  std::vector<uint8_t> obfuscated_data;
  obfuscated_data.resize(data.size());

  for (std::size_t i = 0; i < data.size(); ++i) {
    if (buffer_pos_ == buffer_.size())
      FillBuffer();

    obfuscated_data[i] = data[i] ^ buffer_[buffer_pos_++];
  }

  return obfuscated_data;
}

std::string RandomObfuscator::Process(const std::string& data) {
  std::string obfuscated_data;
  obfuscated_data.resize(data.size());

  for (std::size_t i = 0; i < data.size(); ++i) {
    if (buffer_pos_ == buffer_.size())
      FillBuffer();

    obfuscated_data[i] = data[i] ^ buffer_[buffer_pos_++];
  }

  return obfuscated_data;
}

}   // namespace keepass
