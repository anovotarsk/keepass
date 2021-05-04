#pragma once

#include "cipher.hh"

#include <memory>
#include <random>
#include <vector>

namespace keepass {

/**
 * Obfuscates binary data by xorring each byte with psuedo random data
 * generated by a Salsa20 stream cipher.
 */
class RandomObfuscator {
 private:
  Salsa20Cipher cipher_;

  std::array<uint8_t, 64> buffer_;
  std::size_t buffer_pos_ = 64;

  void FillBuffer();

 public:
  RandomObfuscator(const std::array<uint8_t, 32>& key,
                   const std::array<uint8_t, 8>& init_vec);

  std::vector<uint8_t> Process(const std::vector<uint8_t>& data);
  std::string Process(const std::string& data);
};

template <std::size_t N>
std::array<uint8_t, N> random_array() {
  std::random_device rd;
  std::mt19937 engine(rd());

  std::uniform_int_distribution<uint8_t> uniform_dist(0, 255);

  // Fill block with random values.
  std::array<uint8_t, N> array;
  for (std::size_t i = 0; i < N; ++i)
    array[i] = uniform_dist(engine);

  return array;
}

}   // namespace keepass
