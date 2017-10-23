#ifndef DIMMATH_SUM_H
#define DIMMATH_SUM_H

#include <functional>
#include <dimmath/fold.h>

namespace dimmath
{
  template <typename Container>
  constexpr typename Container::value_type sum(Container&& c)
  {
    return foldr(std::plus<typename Container::value_type> { },
                 typename Container::value_type { },
                 std::forward<Container>(c));
  }
}
  
#endif

