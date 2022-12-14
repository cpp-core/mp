// Copyright (C) 2017, 2019, 2022 by Mark Melton
//

#ifndef CORE_MP_GENERATE_H
#define CORE_MP_GENERATE_H

#include "core/mp/list.h"

namespace core::mp
{

template<typename T, size_t N>
struct generate
{
    template<typename Tx, size_t Nx>
    struct impl_helper
    { using type = Tx; };
    
    template<typename Ix>
    struct impl;
    
    template<std::size_t... Is>
    struct impl<std::index_sequence<Is...>>
    { using type = mp::list<typename impl_helper<T,Is>::type...>; };
	
    using type = typename impl<std::make_index_sequence<N>>::type;
};

/// Generate a type list of type **T** repeated **N** times.
///
/// \tparam T The type to duplicate.
/// \tparam N The number of copies.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// generate_t<int,3> // list<int,int,int>
/// ```
/// \endverbatim
template<typename T, size_t N>
using generate_t = typename generate<T,N>::type;

}; // mp
    
#endif
