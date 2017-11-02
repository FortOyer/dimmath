#ifndef DIMMATH_FOLD_COMMON_H
#define DIMMATH_FOLD_COMMON_H

#include <stddef.h>
#include <type_traits>
#include <utility>

#include <dimmath/get.h>

namespace dimmath
{
  template <size_t Size, typename Fold>
  struct FoldDecide
  {
    using operation  = typename Fold::operation;
    using value_type = typename Fold::value_type;
    using container  = typename Fold::container;
    constexpr static value_type apply(operation&& op, const value_type& initial, const container& c)
    {
      return Fold::apply(std::forward<operation>(op), initial, c);
    }
  };

  template <typename Fold>
  struct FoldDecide<0, Fold>
  {
    using operation  = typename Fold::operation;
    using value_type = typename Fold::value_type;
    using container  = typename Fold::container;
    constexpr static value_type apply(operation&& /*op*/, const value_type& initial, const container& /*c*/)
    {
      return initial;
    }
  };
}

#endif
