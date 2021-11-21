#pragma once

#include <optional>
#include <complex>
#include <reverk/ast/node.hpp>

namespace reverk
{
namespace ast
{

/**
 * @brief number ast node
 */
struct number : public node
{
    std::int64_t                              integer;
    std::optional<std::int64_t>               exponent;
    std::optional<std::complex<std::int64_t>> complex;
};

} // namespace ast
} // namespace reverk