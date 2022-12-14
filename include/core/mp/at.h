// Copyright (C) 2017, 2019 by Mark Melton
//

#ifndef CORE_MP_AT_H
#define CORE_MP_AT_H

#include "core/mp/list.h"
#include "core/mp/map_find.h"

/** 
    @file 
**/

namespace core::mp
{

// at
//
template<typename L>
struct map_from_list
{
    template<typename Lx, typename Sx>
    struct impl;

    template<template<typename...> typename Lx, typename... Tx, std::size_t... Jx>
    struct impl<Lx<Tx...>, std::integer_sequence<std::size_t, Jx...>>
    { using type = list<list<std::integral_constant<std::size_t,Jx>, Tx>...>; };

    using type = typename impl<L,std::make_index_sequence<size<L>::value>>::type;
};

template<typename L>
using map_from_list_t = typename map_from_list<L>::type;

template<size_t I, typename L>
struct at_c
{
    template<size_t Ix, typename Lx>
    struct impl;

    template<size_t Ix, typename Lx>
    struct impl
    {
	using map = map_from_list_t<Lx>;
	using type = second_t<map_find_t<std::integral_constant<std::size_t,Ix>,map>>;
    };

    using type = typename impl<I,L>::type;
};

template<size_t I, typename L>
using at_ct = typename at_c<I,L>::type;

template<typename I, typename L>
using at = at_c<I::value,L>;

template<typename I, typename L>
using at_t = typename at<I,L>::type;

}; // mp

#endif
