// Copyright (C) 2017 Jonathan Müller <jonathanmueller.dev@gmail.com>
// This file is subject to the license terms in the LICENSE file
// found in the top-level directory of this distribution.

#include <cppast/cpp_function.hpp>

#include <cppast/cpp_entity_kind.hpp>

using namespace cppast;

std::unique_ptr<cpp_function_parameter> cpp_function_parameter::build(
    const cpp_entity_index& idx, cpp_entity_id id, std::string name, std::unique_ptr<cpp_type> type,
    std::unique_ptr<cpp_expression> def)
{
    auto result = std::unique_ptr<cpp_function_parameter>(
        new cpp_function_parameter(std::move(name), std::move(type), std::move(def)));
    idx.register_entity(std::move(id), type_safe::cref(*result));
    return result;
}

cpp_entity_kind cpp_function_parameter::do_get_entity_kind() const noexcept
{
    return cpp_entity_kind::function_parameter_t;
}

cpp_entity_kind cpp_function::do_get_entity_kind() const noexcept
{
    return cpp_entity_kind::function_t;
}