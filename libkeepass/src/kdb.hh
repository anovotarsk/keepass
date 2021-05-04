#pragma once

#include <cstdint>
#include <memory>
#include <string>

#include "database.hh"

namespace keepass {

class Entry;
class Group;
class Key;

/**
 * @brief Keepass database file representation.
 */
class KdbFile final {
 private:
  std::shared_ptr<Group> ReadGroup(std::istream& src, uint32_t& id,
                                   uint16_t& level) const;
  void WriteGroup(std::ostream& dst, std::shared_ptr<Group> group,
                  uint32_t group_id, uint16_t level) const;

  std::shared_ptr<Entry> ReadEntry(std::istream& src,
                                   uint32_t& group_id) const;
  void WriteEntry(std::ostream& dst, std::shared_ptr<Entry> entry,
                  uint32_t group_id) const;

 public:
  std::unique_ptr<Database> Import(const std::string& path, const Key& key);
  void Export(const std::string& path, const Database& db, const Key& key);
};

}   // namespace keepass
