// Copyright (C) 2017, 2019 by Mark Melton
//

#ifndef CORE_MP_FIND_INDEX_H
#define CORE_MP_FIND_INDEX_H

#include "core/mp/list.h"

namespace core::mp
{

// find_index
//
template<typename L, typename V>
struct find_index
{
    template<typename Lx, typename Vx>
    struct impl;

    template<template<typename...> typename Lx, typename Vx>
    struct impl<Lx<>, Vx>
    { using type = std::integral_constant<std::size_t,0>; };

    constexpr static std::size_t cx_find_index(bool const * first, bool const * last)
    { return first == last || *first? 0: 1 + cx_find_index(first + 1, last); }

    template<template<typename...> typename Lx, typename... Tx, typename Vx>
    struct impl<Lx<Tx...>, Vx>
    {
	static constexpr bool _v[] = { std::is_same<Tx, Vx>::value... };
	using type = std::integral_constant<std::size_t,cx_find_index(_v, _v + sizeof...(Tx))>;
    };

    using type = typename impl<L,V>::type;
};


template<typename V, typename L>
using find_index_t = typename find_index<V,L>::type;

template<typename V, typename L>
inline constexpr std::size_t find_index_v = find_index_t<V,L>::value;

}; // mp

#endif
