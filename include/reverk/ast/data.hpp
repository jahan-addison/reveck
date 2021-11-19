#pragma once

#include <reverk/ast/node.hpp>

namespace reverk
{
namespace scheme
{
namespace ast
{
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


/**
 * @brief number ast node
 */
struct number : public node
{
    explicit number(int16_t num) : num_(num) {}
    void print() const override
    {
        std::printf("%d", num_);
    }
private:
    int16_t num_;
};

} // namespace ast
} // namespace scheme
} // namespace reverk