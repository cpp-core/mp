// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/mp/list.h"
#include "core/mp/at.h"

namespace core::mp
{

// swap
//
template<size_t I, size_t J, typename L>
struct swap
{
    template<typename IndexSequence>
    struct impl;
    
    template<std::size_t... Indices>
    struct impl<std::index_sequence<Indices...>>
    { using type = list<at_ct<Indices == I ? J : Indices == J ? I : Indices,L>...>; };

    constexpr static auto inner_size = size<L>::value;
    using type = typename impl<std::make_index_sequence<inner_size>>::type;
};

/// Swap entries at indices **I** and **J** in type list **L**.
///
/// \tparam I The first index.
/// \tparam J The second index.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// swap_t<1,3,list<mp_a,mp_b,mp_c,mp_d>> // list<mp_a,mp_d,mp_c,mp_b>
/// ```
/// \endverbatim
template<size_t I, size_t J, typename L>
using swap_t = typename swap<I,J,L>::type;

}; // core::mp

