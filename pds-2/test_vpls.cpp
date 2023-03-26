#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "vpl03.hpp"
#include "vlp04.hpp"
#include <vector>

auto a = std::vector<std::vector<int>> {
    {11, 12, 13, 14, 15},
    {21, 22, 23, 24, 25},
    {31, 32, 33, 34, 35}
};

auto b = std::vector<std::vector<int>> {
    {11, 12, 13},
    {21, 22, 23},
    {31, 32, 33},
    {41, 42, 43},
    {51, 52, 53}
};


auto result = std::vector<std::vector<int>> {
    {2115, 2180, 2245},
    {3665, 3780, 3895},
    {5215, 5380, 5545}
};

string sentence = "O dia 13 de Fevereiro amanheceu com 13,45mm de chuva e 5+1,61 quartos de água.";

TEST_CASE("should return the correct columns number") {
    // CHECK(matrix_multiplication(a, b) == result);
    CHECK(number_of_columns(a) == 5);
    CHECK(number_of_columns(b) == 3);
    CHECK(number_of_columns(result) == 3);
}

TEST_CASE("should return the correct number of rows") {
    CHECK(number_of_rows(a) == 3);
    CHECK(number_of_rows(b) == 5);
    CHECK(number_of_rows(result) == 3);
}


TEST_CASE("should return the correct matrix after the multiplication") {
    auto product = matrix_multiplication(a, b);
    for (int i = 0; i < number_of_rows(a); i++) {
        for (int j = 0; j < number_of_columns(b); j++) {
            CHECK(product[i][j] == result[i][j]);
        }
    }
}


TEST_CASE("should return the correct string, which is the most repeated one") {
    CHECK(most_common_word(sentence) == "de");
}