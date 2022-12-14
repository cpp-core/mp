// Copyright (C) 2017, 2018, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/mp/append.h"
#include "core/mp/contains.h"
#include "core/mp/if.h"

namespace core::mp
{

// subtract
//
template<class L1, class L2, size_t N>
struct subtract;

template<class L1, class L2>
struct subtract<L1, L2, 0>
{ using type = mp::list<>; };

template<class L1, class L2, size_t N>
struct subtract
{
    using pred = std::negation<mp::contains_t<mp::head_t<L1>, L2>>;
    using tail = mp::tail_t<L1>;
    using rtail = typename subtract<tail,L2,size_v<tail>>::type;
    using concat = mp::append_t<mp::list<mp::head_t<L1>>, rtail>;
    using type = mp::if_t<pred,concat,rtail>;
};

/// Removes all occurrences of the types in type list **L2** from type
/// list **L1**.
///
/// \tparam L1 The type list to subtract from.
/// \tparam L2 A type list of the types to remove from **L1**.
template<typename L1, typename L2>
using subtract_t = typename subtract<L1,L2,size_v<L1>>::type;

}; // mp

