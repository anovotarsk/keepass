#pragma once

#include <iterator>

namespace keepass {

template <typename C>
class bounds_checked_iterator :
    public std::iterator<std::output_iterator_tag, void, void, void, void>
{
 protected:
  typename C::iterator first_;
  typename C::iterator last_;

 public:
  explicit bounds_checked_iterator(C& container) :
      first_(container.begin()), last_(container.end()) {}

  bounds_checked_iterator& operator=(const typename C::value_type& value) {
    if (first_ == last_)
      throw std::out_of_range("assigning outside container limits.");

    *first_ = value;
    return *this;
  }

  bounds_checked_iterator& operator=(typename C::value_type&& value) {
    if (first_ == last_)
      throw std::out_of_range("assigning outside container limits.");

    *first_ = std::move(value);
    return *this;
  }

  bounds_checked_iterator& operator*() {
    return *this;
  }

  bounds_checked_iterator& operator++() {
    first_++;
    return *this;
  }

  bounds_checked_iterator operator++(int) {
    ++first_;
    return *this;
  }
};

template <typename C>
inline bounds_checked_iterator<C> bounds_checked(C& container) {
  return bounds_checked_iterator<C>(container);
}

} // namespace keepass
