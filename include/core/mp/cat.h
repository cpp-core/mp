// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#pragma once
#include "core/mp/list.h"

namespace core::mp
{

// concatenation
//
template<typename... L>
struct cat
{
    template<bool B,typename... Lx>
    struct impl;

    template<bool B>
    struct impl<B>
    { using type = mp::list<>; };

    template<bool B,template<typename...> typename Lx, typename... Tx>
    struct impl<B,Lx<Tx...>>
    { using type = Lx<Tx...>; };

    template<bool B,template<typename...> typename L1, typename... T1,
	     template<typename...> typename L2, typename... T2, typename... Lr>
    struct impl<B,L1<T1...>, L2<T2...>, Lr...>
    { using type = typename cat<L1<T1..., T2...>, Lr...>::type; };

    using type = typename impl<true,L...>::type;
};

/// Concatenate the given type lists **L**.
///
/// \tparam L The type lists.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// cat_t<list<int>,list<char>> // list<int,char>
/// ```
/// \endverbatim
template<class... L>
using cat_t = typename cat<L...>::type;

}; // core::mp

