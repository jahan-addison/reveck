#pragma once

#include <list>
#include <variant>
#include <vector>
#include <string>

#include <reverk/ast/node.hpp>
#include <reverk/ast/number.hpp>
#include <reverk/ast/identifier.hpp>

namespace reverk
{
namespace ast
{

template<class... Ts> struct overload : Ts... { using Ts::operator()...; };

/**
 * @brief symbol ast node
 */
struct symbol : public ast::identifier {};

/**
 * @brief boolean ast node
 */
struct boolean : public node
{
    enum class bool_t : int8_t
    {
        TRUE = 1,
        FALSE = 0
    };
    explicit boolean(bool_t bool_) : bool_(bool_) {}
    void print() const override
    {
        switch (bool_)
        {
        case bool_t::TRUE: std::fputs("true", stdout);
            break;
        case bool_t::FALSE: std::fputs("false", stdout);
            break;
        }
    }
private:
    bool_t bool_;
};

/**
 * @brief character ast node
 */
struct character : public node
{
    explicit character(unsigned char c) : char_(c) {}
    void print() const override
    {
        std::putc(char_, stdout);
    }
private:
    unsigned char char_;
};

/**
 * @brief string ast node
 */
struct string : public node
{
    explicit string(std::string_view text) : text_(text) {}
    void print() const override
    {
        std::fputs(text_.data(), stdout);
    }
private:
    std::string_view text_;
};

struct vector : public node
{
    explicit vector(std::vector<datum> v) : vector_(std::move(v)) {};
    void print() const override
    {
        for (auto const& j : vector_)
            j.print();
    }
private:
    std::vector<datum> vector_;
};

struct list : public node
{
    explicit list(std::list<datum> v) : list_(std::move(v)) {};
    void print() const override
    {
        for (auto const& j : list_)
            j.print();
    }
private:
    std::list<datum> list_;
};

/**
 * @brief the sumtype of all node::data types
 *
 */
struct datum : public node
{
    using datum_t = std::variant<boolean, number, character, string, symbol, list, vector>;
    datum_t data;
    void print() const override
    {
        std::visit(overload{
            [](auto&& arg) { arg.print(); },
            }, data);
    }
};

} // namespace ast
} // namespace reverk