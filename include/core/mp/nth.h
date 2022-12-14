// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/mp/list.h"
#include "core/mp/at.h"
#include "core/mp/make_index_range.h"

namespace core::mp
{
namespace impl
{

template<typename L, size_t N, typename T, typename U>
struct nth_element;

template<typename L, size_t N, std::size_t... Ts, std::size_t... Us>
struct nth_element<L, N, std::index_sequence<Ts...>, std::index_sequence<Us...>>
{
    template<typename S>
    static auto apply(at_ct<Ts,L>..., S&& value, at_ct<Us,L>...)
    { return std::forward<S>(value); }
};

}; // impl

template<size_t N, typename... Ts>
auto nth(Ts... values)
{
    using List = list<Ts...>;
    using PreSeq = make_index_range_ct<0,N>;
    using PostSeq = make_index_range_ct<N+1,sizeof...(Ts)>;
    return impl::nth_element<List, N, PreSeq, PostSeq>::apply(values...);
}

}; // mp

