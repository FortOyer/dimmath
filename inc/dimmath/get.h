#ifndef DIMMATH_GET_H
#define DIMMATH_GET_H

#include <stddef.h>

namespace dimmath
{
  template <typename Container, typename DIM>
  typename Container::value_type get(const Container& c);

  template <size_t INDEX, typename Container>
  typename Container::value_type get(const Container& c)
  {
    return get<INDEX>(c);
  }
}

#endif

