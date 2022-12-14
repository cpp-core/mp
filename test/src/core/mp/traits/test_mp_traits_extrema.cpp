// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/traits/extrema.h"

using namespace core;
using namespace std::string_literals;

TEST(MP, TraitsExtrema)
{
    EXPECT_EQ(mp::extrema<std::uint8_t>::min(), 0);
    EXPECT_EQ(mp::extrema<std::uint8_t>::max(), 255);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
