#ifndef NAIL_CL_EOFTOKEN_HPP
#define NAIL_CL_EOFTOKEN_HPP
#include <string>
#include <tokenize/token/Token.hpp>


namespace NAIL_cl::Token {
        class EofToken : public Token {
        public:
            EofToken();

            ~EofToken() override = default;

            [[nodiscard]]
            TokenType getType() const override;
        };
} // Nail_cl::Token

#endif //NAIL_CL_EOFTOKEN_HPP
