#include "util.hh"

#include <cassert>
#include <random>

namespace keepass {

std::string time_to_str(const std::time_t& time) {
  const std::tm* local_time = std::localtime(&time);
  assert(local_time != nullptr);

  char buffer[128];
  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", local_time);
  return buffer;
}

std::array<uint8_t, 16> generate_uuid() {
  std::random_device rd;
  std::mt19937 engine(rd());

  std::uniform_int_distribution<uint8_t> uniform_dist(0, 255);

  // Fill block with random values.
  std::array<uint8_t, 16> uuid;
  for (std::size_t i = 0; i < 16; ++i)
    uuid[i] = uniform_dist(engine);

  return uuid;
}

}   // namespace keepass
