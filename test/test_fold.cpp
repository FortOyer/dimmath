#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <dimmath/sum.h>
#include <dimmath/distance.h>

#include <string>

TEST_CASE( "Sums are computed", "[fold]" )
{
  REQUIRE(dimmath::sum(std::array<double, 2> { 1.2, 3.3, }) == 4.5);
  REQUIRE(dimmath::sum(std::array<int, 1> { 1 }) == 1);
  REQUIRE(dimmath::sum(std::array<float, 3> { 1.0f/3.0f, 0.0f }) == 1.0f/3.0f);
}

TEST_CASE( "Distances are computed", "[fold]" )
{
  REQUIRE(dimmath::distance_squared(std::array<double, 2> { 4.0, 2.0, }) == 4.0*4.0 + 2.0*2.0);
  REQUIRE(dimmath::distance(std::array<int, 2> { 4, 2, }) == std::sqrt(4.0*4.0 + 2.0*2.0));
  REQUIRE(dimmath::distance(std::array<float, 3> { -5.0f, 1.0f, 100.0f }) == std::sqrt(-5.0f*-5.0f + 1.0f + 100.0f*100.0f));
}

TEST_CASE("Empty", "[fold]")
{
  REQUIRE(dimmath::foldr(std::plus<int>(), 5, std::array<int, 0> { }) == 5);
  REQUIRE(dimmath::foldl(std::plus<int>(), 5, std::array<int, 0> { }) == 5);
}

TEST_CASE("Associativity", "[fold]")
{
  REQUIRE(dimmath::foldl(std::minus<int>(), 0, std::array<int, 10> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }) == -55);
  REQUIRE(dimmath::foldr(std::minus<int>(), 0, std::array<int, 10> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }) == -5);
}

TEST_CASE("Different output form", "[fold]")
{
  REQUIRE(dimmath::foldr(
        [](double x, std::string y) -> std::string
        {
          return y + std::to_string(static_cast<int>(x));
        },
        std::string { "Hello" },
        std::array<double, 5> { 1.2, 2.22, 3.13431, 4.999999, 0.0 }) == "Hello04321");

  REQUIRE(dimmath::foldl(
        [](std::string y, double x) -> std::string
        {
          return y + std::to_string(static_cast<int>(x));
        },
        std::string { "Hello" },
        std::array<double, 5> { 1.2, 2.22, 3.13431, 4.999999, 0.0 }) == "Hello12340");
}
