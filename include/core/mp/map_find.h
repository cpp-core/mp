// Copyright (C) 2017, 2019 by Mark Melton
//

#ifndef CORE_MP_MAP_FIND_H
#define CORE_MP_MAP_FIND_H

#include "core/mp/list.h"

namespace core::mp
{

// find
//
template<typename... T>
struct inherit: T...
{};

template<typename K, typename M>
struct map_find;

template<typename K, template<typename...> typename M, typename... T>
struct map_find<K,M<T...>>
{
    using U = inherit<identity<T>...>;

    template<template<typename...> typename L, typename... U>
        static identity<L<K, U...>>
        f( identity<L<K, U...>>* );

    static identity<void> f( ... );

    using V = decltype( f((U*)0) );

    using type = typename V::type;
};

template<typename K, typename M>
using map_find_t = typename map_find<K,M>::type;

}; // mp

#endif
