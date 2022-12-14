// Copyright (C) 2017, 2019 by Mark Melton
//

#ifndef CORE_MP_MAKE_INDEX_RANGE_H
#define CORE_MP_MAKE_INDEX_RANGE_H

#include "core/mp/list.h"
#include "core/mp/append.h"

namespace core::mp
{

// make_index_range
//
template<std::size_t From, std::size_t To>
struct make_index_range_c
{
    template<std::size_t N, std::size_t... S>
    constexpr static std::index_sequence<N + S...> add(std::index_sequence<S...>) { return {}; }
    
    using type = decltype(add<From>(std::make_index_sequence<To-From>()));
};

template<std::size_t From, std::size_t To>
using make_index_range_ct = typename make_index_range_c<From,To>::type;

template<typename From, typename To>
using make_index_range = make_index_range_c<From::value,To::value>;

template<typename From, typename To>
using make_index_range_t = typename make_index_range<From,To>::type;

}; // mp

#endif
