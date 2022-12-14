// Copyright (C) 2017, 2019, 2022, 2023 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/type_name.h"

using namespace core;
using namespace std::string_literals;

TEST(MP, TypeName)
{
    EXPECT_EQ(mp::type_name<const int>(), "const int"s);
    EXPECT_EQ(mp::type_name<const __uint128_t>(), "const unsigned int128"s);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
