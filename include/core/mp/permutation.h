// Copyright (C) 2017, 2018, 2019 by Mark Melton
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

template<typename S, typename T>
using permutation_t = typename permutation<S,T>::type;

}; // mp
    
#endif