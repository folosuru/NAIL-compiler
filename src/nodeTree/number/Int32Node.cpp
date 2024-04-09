#include "Int32Node.hpp"

namespace NTSL_cl {
    std::shared_ptr<Node_parent> Int32Node::consume(const std::shared_ptr<TokenList> &list) {
        if (auto current_tok = list->getCurrent(); current_tok->getType() == Token::TokenType::number) {
            std::shared_ptr<Token::NumberToken> token = std::reinterpret_pointer_cast<Token::NumberToken>(current_tok);
            list->getCurrentPos()++;
            return std::make_shared<Int32Node>(token->value);
        }
        return nullptr;
    }
} // NTSL_cl