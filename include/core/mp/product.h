// Copyright (C) 2022 by Mark Melton
//

#pragma once
#include "core/mp/append.h"

namespace core::mp
{

template<class T, class U> struct product;

template<class... Us>
struct product<mp::list<>, mp::list<Us...>> {
    using type = mp::list<>;
};

template<class T, class... Ts, class... Us>
struct product<mp::list<T, Ts...>, mp::list<Us...>> {
    using pairs = mp::list<std::pair<T, Us>...>;
    using prod = typename product<mp::list<Ts...>, mp::list<Us...>>::type;
    using type = mp::append_t<pairs, prod>;
};

template<class T, class U>
using product_t = typename product<T, U>::type;

}; // mp

