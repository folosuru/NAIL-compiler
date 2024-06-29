#ifndef NTSL_CL_TOKENLIST_HPP
#define NTSL_CL_TOKENLIST_HPP
#include <string>
#include <vector>
#include <memory>
#include <frontend/tokenize/token/Token.hpp>

namespace NAIL_cl {

using Token_ptr = std::shared_ptr<Token::Token>;

class TokenList {
public:
    const std::vector<std::string> source_text;

    explicit TokenList(const std::vector<std::string>& text);

    void print();

    using Position_type = std::vector<Token_ptr>::iterator&;

    Token_ptr getToken(std::size_t);

    [[nodiscard]]
    const std::size_t& getCurrentPos() const;

    inline Token_ptr getCurrent() {
        return getToken(getCurrentPos());
    }

    Token_ptr consume_current(const std::string& target);

    Token_ptr consume_current(Token::TokenType target);

    bool current_is(Token::TokenType type);

    void seek_next();

private:
    std::vector<Token_ptr> token_list;

    bool push_token(const Token_ptr&);

    std::size_t current_pos = 0;
};

} // NAIL_cl

#endif //NTSL_CL_TOKENLIST_HPP
