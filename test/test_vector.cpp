#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <dimmath/sum.h>
#include <dimmath/distance.h>

TEST_CASE( "Sums are computed", "[vector]" ) {
  REQUIRE(dimmath::sum(std::array<double, 2> { 1.2, 3.3, }) == 4.5);
  REQUIRE(dimmath::sum(std::array<int, 1> { 1 }) == 1);
  REQUIRE(dimmath::sum(std::array<float, 3> { 1.0f/3.0f, 0.0f }) == 1.0f/3.0f);
}

TEST_CASE( "Distances are computed", "[vector]" ) {
  REQUIRE(dimmath::distance_squared(std::array<double, 2> { 4.0, 2.0, }) == 4.0*4.0 + 2.0*2.0);
  REQUIRE(dimmath::distance(std::array<int, 2> { 4, 2, }) == std::sqrt(4.0*4.0 + 2.0*2.0));
  REQUIRE(dimmath::distance(std::array<float, 3> { -5.0f, 1.0f, 100.0f }) == std::sqrt(-5.0f*-5.0f + 1.0f + 100.0f*100.0f));
}
