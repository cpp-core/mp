// Copyright (C) 2019, 2021 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/iterator.h"

using namespace core;

struct Foo {
};

TEST(MP, IsIterator)
{
    EXPECT_FALSE(mp::is_iterator_v<int>);
    EXPECT_FALSE(mp::is_iterator_v<std::string>);
    EXPECT_FALSE(mp::is_iterator_v<Foo>);

    EXPECT_TRUE(mp::is_iterator_v<int*>);
    EXPECT_TRUE(mp::is_iterator_v<std::string*>);
    EXPECT_TRUE(mp::is_iterator_v<Foo*>);
    EXPECT_TRUE(mp::is_iterator_v<std::vector<int>::iterator>);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
