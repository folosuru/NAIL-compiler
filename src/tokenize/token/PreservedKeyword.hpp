#ifndef NAIL_CL_PRESERVEDKEYWORD_HPP
#define NAIL_CL_PRESERVEDKEYWORD_HPP
#include <string>
#include <cstdint>
#include <tokenize/token/Token.hpp>

namespace NAIL_cl::Token {

    class PreservedKeyword : public Token{
    public:
        enum class word_type {
            for_t,
            var,
        };

        explicit PreservedKeyword(std::string_view name, std::size_t line, std::int64_t pos, word_type type);

        ~PreservedKeyword() override = default;

        [[nodiscard]]
        TokenType getType() const override;

        [[nodiscard]]
        word_type getWordType() const noexcept {
            return type;
        }

        static Token_ptr create(std::string_view, std::size_t line, std::int64_t pos);

    private:
        word_type type;

    };
} // NAIL_cl::Token

#endif //NAIL_CL_PRESERVEDKEYWORD_HPP
