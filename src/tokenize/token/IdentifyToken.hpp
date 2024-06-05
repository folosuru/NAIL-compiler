#ifndef NAIL_CL_IDENTIFYTOKEN_HPP
#define NAIL_CL_IDENTIFYTOKEN_HPP
#include <string>
#include <tokenize/token/Token.hpp>



namespace NAIL_cl::Token {

    class IdentifyToken : public Token {
    public:
        constexpr static TokenType static_type = TokenType::identify;

        explicit IdentifyToken(std::string_view name, std::size_t line, std::int64_t pos, const TokenList&);

        ~IdentifyToken() override = default;

        [[nodiscard]]
        TokenType getType() const override;

        static Token_ptr consume(const std::string& str, const std::size_t& line, std::int64_t &pos, const TokenList&);

        static bool is_identify_char(char);
    private:
    };

} // NAIL_cl::Token

#endif //NAIL_CL_IDENTIFYTOKEN_HPP
