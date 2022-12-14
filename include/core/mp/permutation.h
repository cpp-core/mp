// Copyright (C) 2017, 2018, 2019, 2022 by Mark Melton
//

#ifndef CORE_MP_PERMUTATION_H
#define CORE_MP_PERMUTATION_H

#include "core/mp/list.h"
#include "core/mp/append.h"
#include "core/mp/at.h"
#include "core/mp/find_index.h"

namespace core::mp
{

template<typename S, typename T>
struct permutation
{
    template<size_t Ix, size_t Nx>
    struct impl;

    template<size_t Ix, size_t Nx>
    struct impl
    {
	using rest = typename impl<Ix+1,Nx>::type;
	using head = find_index_t<S,at_ct<Ix,T>>;
	static_assert(head::value < mp::size_v<S>, "permutation: value not found in index");
	using type = append_t<list<head>,rest>;
    };

    template<size_t Nx>
    struct impl<Nx,Nx>
    { using type = list<>; };

    using type = typename impl<0,size_v<T>>::type;
};

/// Compute the permutation vector that maps type list **S** to type
/// list **T**.
///
/// \tparam S The initial type list.
/// \tparam T The permuted type list.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// permutation_t<list<int,char>,list<char,int>> // list<mp_1s, mp_0s>
/// ```
/// \endverbatim
template<typename S, typename T>
using permutation_t = typename permutation<S,T>::type;

}; // mp

#endif
