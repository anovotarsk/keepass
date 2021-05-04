#include "io.hh"

namespace keepass {

template<>
std::string consume<std::string>(std::istream& src) {
  // Don't read the stream into a string directly. We want to make sure that we
  // get a clean string.
  std::vector<char> str_data;
  std::copy(std::istreambuf_iterator<char>(src), 
            std::istreambuf_iterator<char>(), 
            std::back_inserter(str_data));
  if (!src.good())
    throw IoError("Read error.");

  if (str_data.size() == 0)
    throw IoError("Couldn't read zero length string.");

  std::string str;
  str.reserve(str_data.size());
  for (char c : str_data) {
    if (c == '\0')
      break;
    str.push_back(c);
  }

  return str;
}

template <>
std::vector<char> consume<std::vector<char>>(std::istream& src) {
  std::vector<char> data;
  std::copy(std::istreambuf_iterator<char>(src),
            std::istreambuf_iterator<char>(),
            std::back_inserter(data));
  if (!src.good())
    throw IoError("Read error.");

  return data;
}

template <>
std::vector<uint8_t> consume<std::vector<uint8_t>>(std::istream& src) {
  // FIXME: This function needs to be made more efficient.
  std::vector<char> data;
  std::copy(std::istreambuf_iterator<char>(src),
            std::istreambuf_iterator<char>(),
            std::back_inserter(data));
  if (!src.good())
    throw IoError("Read error.");

  std::vector<uint8_t> unsigned_data;
  unsigned_data.resize(data.size());
  for (std::size_t i = 0; i < data.size(); ++i)
    unsigned_data[i] = data[i];

  return unsigned_data;
}

template <>
void conserve<std::string>(std::ostream& dst, const std::string& val) {
  dst.write(val.c_str(), val.size() + 1);   // FIXME: Is this safe?
  if (!dst.good())
    throw IoError("Write error.");
}

template <>
void conserve<std::vector<char>>(std::ostream& dst,
                                 const std::vector<char>& val) {
  dst.write(val.data(), val.size());
  if (!dst.good())
    throw IoError("Write error.");
}

template <>
void conserve<std::vector<uint8_t>>(std::ostream& dst,
                                    const std::vector<uint8_t>& val) {
  dst.write(reinterpret_cast<const char*>(val.data()), val.size());
  if (!dst.good())
    throw IoError("Write error.");
}

}   // namespace keepass
