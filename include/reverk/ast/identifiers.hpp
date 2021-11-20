#pragma once

#include <vector>
#include <variant>

#include <reverk/ast/node.hpp>

namespace reverk
{
namespace scheme
{
namespace ast
{

template<class... Ts> struct overload : Ts... { using Ts::operator()...; };

using identifier_t = std::vector<std::variant<letter, digit>>;

/**
 * @brief identifier ast node
 */

struct identifier : public node
{
    explicit identifier(identifier_t id) : id_(std::move(id)) {}
    void print() const override
    {
        for (std::variant<letter, digit> const& j : id_)
        {
            std::visit(overload{
                [](auto&& arg) { arg.print(); },
                }, j);
        }
    }
private:
    identifier_t id_;
};

/**
 * @brief letter ast node
 */
struct letter : public node
{
    explicit letter(unsigned char c) : char_(c) {}
    void print() const override
    {
        std::putc(char_, stdout);
    }
private:
    unsigned char char_;
};

/**
 * @brief digit ast node
 */
struct digit : public node
{
    explicit digit(uint8_t d) : digit_(d) {}

    void print() const override
    {
        std::printf("%d", digit_);
    }

private:
    uint8_t digit_;
};

} // namespace ast
} // namespace scheme
} // namespace reverk