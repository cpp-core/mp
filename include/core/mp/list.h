// Copyright (C) 2017, 2018, 2019, 2022 by Mark Melton
//

#pragma once
#include <functional>

namespace core::mp
{

template<typename... Ts>
struct list { };

/// Create a type list of the types **Ts**.
///
/// \tparam Ts The types to put in the type list.
template<typename... Ts>
using list_t = list<Ts...>;

// rename
//
template<typename A, template<typename...> typename B>
struct rename
{
    template<typename A2, template<typename...> typename B2>
    struct impl;
    
    template<template<typename...> typename A2, typename... T, template<typename...> typename B2>
    struct impl<A2<T...>, B2>
    { using type = B2<T...>; };

    using type = typename impl<A,B>::type;
};

/// Rename the type list **L** with the variadic template name **N**.
///
/// \tparam L The type list to rename.
/// \tparam N The new variadic template name.
///
/// \verbatim embed:rst:leading-slashes
/// ```{code-block} cpp
/// rename_t<list<int,char>,std::tuple> // std::tuple<int,char>
/// ```
/// \endverbatim
template<class L, template<class...> class N>
using rename_t = typename rename<L, N>::type;

// rename to void function
//
template<typename... Ts>
struct rename_to_void_function;

template<template<typename...> typename T, typename... Ts>
struct rename_to_void_function<T<Ts...>> { using type = std::function<void(Ts...)>; };

template<typename T>
using rename_to_void_function_t = typename rename_to_void_function<T>::type;

// head
//
template<typename T, typename... Ts>
struct head_x { using type = T; };

template<typename L>
using head = mp::rename_t<L, head_x>;

/// The first type in type list **L**.
///
/// \tparam L The type list.
template<typename L>
using head_t = typename head<L>::type;

template<typename T1, typename T2, typename... Ts>
struct second_x { using type = T2; };

template<typename L>
using second = rename_t<L, second_x>;

/// The second type in type list **L**.
///
/// \tparam L The type list.
template<typename L>
using second_t = typename second<L>::type;

// tail
//
template<typename T, typename... Ts>
struct tail_x { using type = list<Ts...>; };

template<typename L>
using tail = rename_t<L, tail_x>;

/// A type list containing all but the first type of type list **L**.
///
/// \tparam L The type list.
template<typename L>
using tail_t = typename tail<L>::type;

// size
//
/**
   @brief The length of the list
   @tparam L The list
   @returns The length of the list (as an integral constant type)
 */
template<typename... Ts>
using size_x = std::integral_constant<std::size_t,sizeof...(Ts)>;

template<typename L>
using size = rename_t<L, size_x>;

template<typename... Ts>
inline constexpr size_t size_x_v = size_x<Ts...>::value;

/**
   @brief The length of the list
   @tparam L The list
   @returns The length of the list (as an integer)
 */
template<typename L>
inline constexpr size_t size_v = size<L>::value;

/**
   @brief Is the list empty?
   @tparam L The list
   @returns True if the list is empty, false otherwise (as an integral constant).
 */
template<typename... Ts>
using empty_x = std::integral_constant<bool,sizeof...(Ts) == 0>;

template<typename... Ts>
inline constexpr bool empty_x_v = empty_x<Ts...>::value;

template<typename L>
using empty = rename_t<L, empty_x>;

/**
   @brief Is the list empty?
   @tparam L The list
   @returns True if the list is empty, false otherwise.
 */
template<typename L>
inline constexpr bool empty_v = empty<L>::value;

/**
   @brief Identity function
   @tparam L The list
   @returns The list
 */
template<typename T>
struct identity { using type = T; };

}; // mp

