// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/find_index.h"
#include "core/mp/constants.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, FindIndex)
{
    using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
    
    {
	using R = mp::find_index_t<L,mp_a>;
	EXPECT_EQ(R::value, 0u);
    }
    
    {
	using R = mp::find_index_t<L,mp_b>;
	EXPECT_EQ(R::value, 1u);
    }

    {
	using R = mp::find_index_t<L,mp_d>;
	EXPECT_EQ(R::value, 3u);
    }
    
    {
	using R = mp::find_index_t<L,mp_e>;
	EXPECT_EQ(R::value, 4u);
    }

    {
	using R = mp::find_index_t<L,mp_f>;
	EXPECT_EQ(R::value, 5u);
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
