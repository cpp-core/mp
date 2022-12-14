// Copyright (C) 2017, 2019 by Mark Melton
//

#pragma once
#include "core/mp/list.h"

namespace core::mp
{

// if
//
template<bool C, class T, class E>
struct if_c
{
    template<bool C2,typename T2,typename E2>
    struct impl;

    template<typename T2,typename E2>
    struct impl<true,T2,E2>
    { using type = T; };

    template<typename T2,typename E2>
    struct impl<false,T2,E2>
    { using type = E; };

    using type = typename impl<C,T,E>::type;
};

template<bool C, typename T, typename E>
using if_ct = typename if_c<C,T,E>::type;

template<typename C, typename T, typename E>
using _if = if_c<C::value,T,E>;

template<typename C, typename T, typename E>
using if_t = typename _if<C,T,E>::type;

}; // mp
