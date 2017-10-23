#ifndef DIMMATH_FOLD_H
#define DIMMATH_FOLD_H

#include <stddef.h>
#include <type_traits>
#include <dimmath/get.h>
#include <utility>

namespace dimmath
{
  template <size_t INDEX, typename Operation, typename T, typename Container>
  struct Foldr
  {
    constexpr static T apply(Operation op, const T& initial, const Container& c)
    {
      const T& out = Foldr<INDEX-1, Operation, T, Container>::apply(op, initial, c);
      return op(get<INDEX>(c), out);
    }
  };

  template <typename Operation, typename T, typename Container>
  struct Foldr<0, Operation, T, Container>
  {
    constexpr static T apply(Operation op, const T& initial, const Container& c)
    {
      return op(get<0>(c), initial);
    }
  };

  template <typename Operation, typename T, typename Container>
  constexpr T foldr(Operation&& op, const T& initial, const Container& c)
  {
    static_assert(c.size() > 0u, "Can't sum 0-size container.");
    return Foldr<c.size()-1, Operation, T, Container>::apply(std::forward<Operation>(op), initial, c);
  }


}

#endif

