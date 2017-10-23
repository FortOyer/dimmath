#ifndef DIMATH_VECTOR_H
#define DIMATH_VECTOR_H

#include <stddef.h>
#include <array>


namespace dimmath
{
template<typename T, size_t Dimensions>
struct Vector
{
  std::array<T, Dimensions> vals;
};
}

#endif

