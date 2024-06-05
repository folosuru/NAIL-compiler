#ifndef NAIL_CL_TOKEN_HPP
#define NAIL_CL_TOKEN_HPP
#include <memory>
#include <cstdint>
#include <string_view>
#include <string>
#include <utility>
namespace NAIL_cl {
    class TokenList;
}
namespace NAIL_cl::Token {

    enum class TokenType {
        Preserved_word,
        Preserved_symbol,
        identify,
        number,
        text,
        eof
    };
    class Token {
    public:
        const std::size_t line;
        const std::int64_t pos;
        const TokenList& list;

        explicit Token(std::string_view view, std::size_t line, std::int64_t pos, const TokenList& list)
         : text(view), line(line), pos(pos), list(list) {}

        [[nodiscard]]
        virtual TokenType getType() const = 0;

        [[nodiscard]]
        std::string_view getString() const {
            return text;
        }

        static std::string_view getTypeName(TokenType);

        virtual ~Token() = default;
    private:
        std::string_view text;
    };

    using Token_ptr = std::shared_ptr<Token>;

}

#endif //NAIL_CL_TOKEN_HPP
