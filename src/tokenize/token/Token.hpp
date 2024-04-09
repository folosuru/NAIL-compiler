#ifndef NTSL_CL_TOKEN_HPP
#define NTSL_CL_TOKEN_HPP
#include <memory>
#include <cstdint>
namespace NTSL_cl::Token {

    enum class TokenType {
        Preserved_word,
        Preserved_symbol,
        identify,
        number,
        text
    };

    class Token {
    public:
        const std::size_t line;
        const std::int64_t pos;

        explicit Token(std::string_view view, std::size_t line, std::int64_t pos)
         : text(view), line(line), pos(pos) {}

        [[nodiscard]]
        virtual TokenType getType() const = 0;

        [[nodiscard]]
        std::string_view getString() const {
            return text;
        }

        virtual ~Token() = default;
    private:
        std::string_view text;
    };

    using Token_ptr = std::shared_ptr<Token>;

}

#endif //NTSL_CL_TOKEN_HPP
