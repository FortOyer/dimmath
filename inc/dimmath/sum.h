#ifndef DIMMATH_SUM_H
#define DIMMATH_SUM_H

#include <stddef.h>
#include <dimmath/get.h>

namespace dimmath
{
  template <typename Container, size_t INDEX>
  struct Sum
  {
    typedef typename Container::value_type value_type;

    constexpr static value_type apply(const Container& c)
    {
      return get<INDEX>(c) + Sum<Container, INDEX-1>::apply(c);
    }
  };

  template <typename Container>
  struct Sum<Container, 0>
  {
    typedef typename Container::value_type value_type;

    constexpr static value_type apply(const Container& c)
    {
      return get<0>(c);
    }
  };

  template <typename Container>
  constexpr static typename Container::value_type sum(const Container& c)
  {
    static_assert(c.size() > 0u, "Can't sum 0-size container.");
    return Sum<Container, c.size()-1>::apply(c);
  }
}

#endif

