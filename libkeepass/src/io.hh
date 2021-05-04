#pragma once

#include <istream>
#include <memory>
#include <ostream>
#include <string>
#include <vector>

#include "exception.hh"

namespace keepass {

template <typename T>
inline T consume(std::istream& src) {
  T val;
  src.read(reinterpret_cast<char *>(&val), sizeof(T));
  if (!src.good())
    throw IoError("Read error.");

  return val;
}

template <>
std::string consume<std::string>(std::istream& src);

template <>
std::vector<char> consume<std::vector<char>>(std::istream& src);

template <>
std::vector<uint8_t> consume<std::vector<uint8_t>>(std::istream& src);

template<typename T>
void conserve(std::ostream& dst, const T& val) {
  dst.write(reinterpret_cast<const char*>(&val), sizeof(T));
}

template <>
void conserve<std::string>(std::ostream& dst, const std::string& val);

template <>
void conserve<std::vector<char>>(std::ostream& dst,
                                 const std::vector<char>& val);
template <>
void conserve<std::vector<uint8_t>>(std::ostream& dst,
                                    const std::vector<uint8_t>& val);

}   // namespace keepass
