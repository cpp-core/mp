// Copyright (C) 2017, 2019 by Mark Melton
//

#ifndef CORE_MP_PUSH_FRONT_H
#define CORE_MP_PUSH_FRONT_H

#include "core/mp/list.h"

namespace core::mp
{

// push_front
//
template<typename T, typename L>
struct push_front
{
    template<typename Tx, typename Lx>
    struct impl;

    template<typename Tx, template<typename...> typename Lx, typename... Us>
    struct impl<Tx, Lx<Us...>>
    { using type = Lx<Tx, Us...>; };

    using type = typename impl<T,L>::type;
};

template<typename T, typename L>
using push_front_t = typename push_front<T,L>::type;

}; // mp

#endif