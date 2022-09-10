// Copyright (C) 2017, 2019 by Mark Melton
//

#pragma once
#include "core/mp/list.h"
#include "core/mp/at.h"
#include "core/mp/swap.h"

namespace core::mp
{

template<typename L, template <typename, typename> typename C>
struct sort
{
    template <typename Lx, size_t Ix, size_t Jx, size_t Nx>
    struct impl
    {
        // Compare and conditionally swap
        using Px = std::conditional_t
	    <C<at_ct<Ix,Lx>, at_ct<Jx,Lx>>::value, Lx, swap_t<Ix, Jx, Lx>>;
	
	// Recurse until J == N
        using type = typename impl<Px, Ix, Jx + 1, Nx>::type;
    };

    // Increment I and set J = I + 1
    template <typename Lx, size_t Ix, size_t Nx>
    struct impl<Lx, Ix, Nx, Nx>
    { using type = typename impl<Lx, Ix + 1, Ix + 2, Nx>::type; };

    // End of loop
    template <typename Lx, size_t J, size_t N>
    struct impl<Lx, N, J, N>
    { using type = Lx; };

    using type = typename impl<L, 0, 1, size<L>::value>::type;
};

template<typename L, template <typename, typename> typename C>
using sort_t = typename sort<L,C>::type;

}; // mp

