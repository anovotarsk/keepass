#include "metadata.hh"

namespace keepass {

void Metadata::AddBinary(std::shared_ptr<Binary> binary) {
  binaries_.push_back(binary);
}

void Metadata::AddIcon(std::shared_ptr<Icon> icon) {
  icons_.push_back(icon);
}

void Metadata::AddField(const std::string& key, const std::string& value) {
  fields_.push_back(Field(key, value));
}

}   // namespace keepass
