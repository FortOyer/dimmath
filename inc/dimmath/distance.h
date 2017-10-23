#ifndef DIMMATH_DISTANCE_H
#define DIMMATH_DISTANCE_H

#include <dimmath/fold.h>
#include <cmath>

namespace dimmath
{

template <typename Container>
constexpr typename Container::value_type distance_squared(Container&& c)
{
  return foldr([](const typename Container::value_type& v1, const typename Container::value_type& v2)
               {
                 return v1*v1 + v2;
               },
               typename Container::value_type { },
               std::forward<Container>(c));
}

template <typename In> struct DistanceOut;
template < > struct DistanceOut<float> { typedef float type; };
template < > struct DistanceOut<double> { typedef double type; };
template < > struct DistanceOut<long double> { typedef long double type; };
template <typename In> struct DistanceOut { typedef typename std::enable_if<std::is_integral<In>::value, double>::type type; };

template <typename Container>
constexpr typename DistanceOut<typename Container::value_type>::type distance(Container&& c)
{
  return std::sqrt(distance_squared(std::forward<Container>(c)));
}


}

#endif

