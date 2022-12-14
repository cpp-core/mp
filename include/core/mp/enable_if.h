// Copyright (C) 2017, 2019, 2020, 2021, 2022 by Mark Melton
//

#pragma once
#include "core/mp/list.h"

namespace core::mp
{

/// Evaluates to true iff all types **Ts..** are the same as type **T**; otherwise, false.
///
/// \tparam T The type to compare against.
/// \tparam Ts Compare each of these types against T.
template<class T, class... Ts>
inline constexpr bool enable_if_all_v = std::conjunction_v<std::is_same<T, std::decay_t<Ts>>...>;

/** 
    Evaluate to void iff all types Ts... are the same as T; otherwise, fail.
*/
template<class T, class... Ts>
using enable_if_all_t = std::enable_if_t<enable_if_all_v<T, Ts...>>;

/// Evaluates to true iff any types **Ts..** are the same as type **T**; otherwise, false.
///
/// \tparam T The type to compare against.
/// \tparam Ts Compare each of these types against T.
template<class T, class... Ts>
inline constexpr bool enable_if_any_v = std::disjunction_v<std::is_same<T, std::decay_t<Ts>>...>;

/** 
    Evaluate to void type iff any types Ts... are the same as type T; otherwise, fail.
*/
template<class T, class... Ts>
using enable_if_any_t = std::enable_if_t<enable_if_any_v<T, Ts...>>;

/// Evaluates to true iff no types **Ts..** are the same as type **T**; otherwise, false.
///
/// \tparam T The type to compare against.
/// \tparam Ts Compare each of these types against T.
template<class T, class... Ts>
inline constexpr bool enable_if_none_v = !std::disjunction_v<std::is_same<T, std::decay_t<Ts>>...>;

/** 
    Evaluate to void type iff no types Ts... are the same as type T; otherwise, fail.
*/
template<class T, class... Ts>
using enable_if_none_t = std::enable_if_t<enable_if_none_v<T, Ts...>>;

}; // core::mp

