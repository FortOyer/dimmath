#ifndef DIMMATH_FOLDR_H
#define DIMMATH_FOLDR_H

#include <stddef.h>
#include <type_traits>
#include <utility>

#include <dimmath/get.h>
#include <dimmath/fold/fold_common.h>

namespace dimmath
{
  template <size_t MAX_INDEX, size_t INDEX, typename Operation, typename T, typename Container>
  struct Foldr
  {
    using operation = Operation;
    using value_type = T;
    using container = Container;
    constexpr static T apply(operation op, const value_type& initial, const container& c)
    {
      const T& out = Foldr<MAX_INDEX, INDEX+1, operation, value_type, container>::apply(op, initial, c);
      return op(get<INDEX>(c), out);
    }
  };

  template <size_t MAX_INDEX, typename Operation, typename T, typename Container>
  struct Foldr<MAX_INDEX, MAX_INDEX, Operation, T, Container>
  {
    using operation = Operation;
    using value_type = T;
    using container = Container;
    constexpr static T apply(Operation op, const T& initial, const Container& c)
    {
      return op(get<MAX_INDEX>(c), initial);
    }
  };

  template <typename Operation, typename T, typename Container>
  constexpr T foldr(Operation&& op, const T& initial, const Container& c)
  {
    return FoldDecide<c.size(), Foldr<c.size()-1, 0, Operation, T, Container>>::apply(
        std::forward<Operation>(op), initial, c);
  }
}

#endif
