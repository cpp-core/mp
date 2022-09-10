// Copyright (C) 2017, 2018, 2019 by Mark Melton
//

#pragma once
#include "core/mp/cat.h"
#include "core/mp/unique.h"

namespace core::mp
{

/**
   @brief Union of the given lists
   @tparam Ls... The lists to combine
   @returns The union of the given lists
*/
template<class... Ls>
using union_t = unique_t<cat_t<Ls...>>;

}; // core::mp