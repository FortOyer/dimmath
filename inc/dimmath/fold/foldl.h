#ifndef DIMMATH_FOLDL_H
#define DIMMATH_FOLDL_H

#include <stddef.h>
#include <type_traits>
#include <utility>

#include <dimmath/get.h>
#include <dimmath/fold/fold_common.h>

namespace dimmath
{
  template <size_t INDEX, typename Operation, typename T, typename Container>
  struct Foldl
  {
    using operation = Operation;
    using value_type = T;
    using container = Container;
    constexpr static T apply(Operation op, const T& initial, const Container& c)
    {
      const T& out = Foldl<INDEX-1, Operation, T, Container>::apply(op, initial, c);
      return op(out, get<INDEX>(c));
    }
  };

  template <typename Operation, typename T, typename Container>
  struct Foldl<0, Operation, T, Container>
  {
    using operation = Operation;
    using value_type = T;
    using container = Container;
    constexpr static T apply(Operation op, const T& initial, const Container& c)
    {
      return op(initial, get<0>(c));
    }
  };

  template <typename Operation, typename T, typename Container>
  constexpr T foldl(Operation&& op, const T& initial, const Container& c)
  {
    return FoldDecide<c.size(), Foldl<c.size()-1, Operation, T, Container>>::apply(
        std::forward<Operation>(op), initial, c);
  }
}

#endif

