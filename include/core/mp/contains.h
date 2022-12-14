// Copyright (C) 2017, 2019 by Mark Melton
//

#pragma once
#include "core/mp/list.h"

/** 
    @file 
**/

namespace core::mp
{

// contains
//

template<typename V, typename L>
struct contains
{
    template<std::size_t Ix, typename Tx>
    struct inherit_second: Tx
    { };

    template<typename Lx, typename Sx>
    struct inherit_indirect_impl;

    template<template<typename...> typename Lx, typename... Ts, std::size_t... Js>
    struct inherit_indirect_impl<Lx<Ts...>,std::integer_sequence<std::size_t,Js...>>
	: inherit_second<Js,identity<Ts>>...
    { };

    template<typename Lx>
    using inherit_indirect = inherit_indirect_impl<Lx, std::make_index_sequence<size<Lx>::value>>;
    
    template<typename Vx, typename Lx>
    struct impl;

    template<typename Vx, template<typename...> typename Lx, typename... Tx>
    struct impl<Vx,Lx<Tx...>>
    {
	using U = inherit_indirect<Lx<Tx...>>;
	using type = std::is_base_of<identity<Vx>, U>;
    };

    using type = typename impl<V,L>::type::type;
};
    
template<typename V, typename L>
using contains_t = typename contains<V, L>::type;

template<typename V, typename L>
inline constexpr bool contains_v = contains_t<V,L>::value;

template<class V, class... Ls>
using is_member_t = contains_t<V,list<Ls...>>;

template<class V, class... Ls>
inline constexpr bool is_member_v = is_member_t<V,Ls...>::value;

}; // mp

