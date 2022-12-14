// Copyright (C) 2021, 2022 by Mark Melton
//

#include <gtest/gtest.h>
#include "core/mp/foreach.h"
#include "core/mp/list.h"
#include "core/mp/constants.h"
#include "core/mp/contains.h"

using namespace core;
using ::testing::StaticAssertTypeEq;

TEST(MP, Foreach)
{
    using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
    
    {
	size_t count{0};
	mp::foreach<L>([&]<class T>(int a, int b) {
		++count;
		EXPECT_EQ((mp::contains_v<T,L>), true);
		EXPECT_EQ(a, 4);
		EXPECT_EQ(b, 5);
	    },
	    4, 5);
	EXPECT_EQ(count, mp::size_v<L>);
    }
    
    {
	size_t count{0};
	auto r = mp::foreach_fold_or<L>([&]<class T>(int a, int b) {
		++count;
		EXPECT_EQ((mp::contains_v<T,L>), true);
		EXPECT_EQ(a, 4);
		EXPECT_EQ(b, 5);
		if (count == 3) return true;
		else return false;
	    },
	    4, 5);
	EXPECT_EQ(r, true);
	EXPECT_EQ(count, 3);
    }
    
    {
	size_t count{0};
	auto r = mp::foreach_fold_and<L>([&]<class T>(int a, int b) {
		++count;
		EXPECT_EQ((mp::contains_v<T,L>), true);
		EXPECT_EQ(a, 4);
		EXPECT_EQ(b, 5);
		if (count == 3) return false;
		else return true;
	    },
	    4, 5);
	EXPECT_EQ(r, false);
	EXPECT_EQ(count, 3);
    }
}

TEST(MP, Foreach1)
{
    using L = mp::list<mp_a,mp_b,mp_c,mp_d,mp_e>;
    
    {
	size_t count{0};
	mp::foreach<mp_a, mp_b, mp_c, mp_d, mp_e>([&]<class T>(int a, int b) {
		++count;
		EXPECT_EQ((mp::contains_v<T,L>), true);
		EXPECT_EQ(a, 4);
		EXPECT_EQ(b, 5);
	    },
	    4, 5);
	EXPECT_EQ(count, 5);
    }
    
    {
	size_t count{0};
	mp::foreach1<mp_a, mp_b, mp_c, mp_d, mp_e>([&]<class T>(int a, int b) {
		++count;
		EXPECT_EQ((mp::contains_v<T,L>), true);
		EXPECT_EQ(a, 4);
		EXPECT_EQ(b, 5);
	    },
	    4, 5);
	EXPECT_EQ(count, 5);
    }
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
