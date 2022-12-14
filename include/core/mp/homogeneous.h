// Copyright (C) 2017, 2019 by Mark Melton
//

#pragma once
#include "core/mp/list.h"
#include "core/mp/unique.h"

namespace core::mp
{

// homogenous
//
template<class L>
constexpr bool homogeneous_v = mp::size_v<mp::unique_t<L>> <= 1;

}; // mp

