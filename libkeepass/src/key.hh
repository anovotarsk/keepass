#pragma once

#include <array>
#include <cstdint>
#include <vector>
#include <string>

namespace keepass {

class Key final {
 public:
  /**
   * Strategies for how to resolve sub keys before applying the
   * transformation.
   */
  enum class SubKeyResolution {
    /** All sub keys will be hashed together into a single hash. Single sub
     * keys will be hashed despite not being part of a composite key. */
    kHashSubKeys,

    /** All sub keys will be hashed together into a single hash. If there is
     * only a single sub key, that sub key will be processed as is without any
     * additional hashing. */
    kHashSubKeysOnlyIfCompositeKey
  };

 private:
  struct CompositeKey {
    std::array<uint8_t, 32> password_key_ = { { 0 } };
    std::array<uint8_t, 32> keyfile_key_ = { { 0 } };

    std::array<uint8_t, 32> Resolve(SubKeyResolution resolution) const;
  } key_;

 public:
  Key() = default;
  Key(const std::string& password);

  void SetPassword(const std::string& password);
  void SetKeyFile(const std::string& path);

  std::array<uint8_t, 32> Transform(const std::array<uint8_t, 32>& seed,
                                    const uint64_t rounds,
                                    SubKeyResolution resolution) const;
};

}
