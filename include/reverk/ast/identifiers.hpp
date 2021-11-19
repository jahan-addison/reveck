#pragma once

#include <reverk/ast/node.hpp>

namespace reverk
{
namespace scheme
{
namespace ast
{
/**
 * @brief identifier ast node
 */
struct identifier : public node
{
    explicit identifier(std::string_view text) : text_(text) {}
    void print() const override
    {
        std::fputs(text_.data(), stdout);
    }
private:
    std::string_view text_;
};

} // namespace ast
} // namespace scheme
} // namespace reverk