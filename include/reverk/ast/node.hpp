#pragma once

#include <string_view>
#include <cstdint>

namespace reverk
{
namespace ast
{

/**
 * @brief ast node interface
 */
struct node
{
    node(node const&) = delete;
    node& operator=(node const&) = delete;
    virtual ~node() = default;
    virtual void print() const = 0;
protected:
    node() = default;
};

} // namespace ast
} // namespace reverk