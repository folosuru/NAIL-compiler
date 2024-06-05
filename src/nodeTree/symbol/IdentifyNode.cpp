#include "IdentifyNode.hpp"
#include "tokenize/token/IdentifyToken.hpp"
#include <Symbol/scope/Scope.hpp>
#include <utility>

namespace NAIL_cl {
    std::shared_ptr<Node_parent> IdentifyNode::consume(const std::shared_ptr<Scope> &scope,
                                                       const std::shared_ptr<TokenList> &list) {
        if (auto current = list->consume_current(Token::TokenType::identify)) {
            return std::make_shared<IdentifyNode>(scope, std::string(current->getString()), current);
        }
        return nullptr;
    }


    IdentifyNode::IdentifyNode(const std::shared_ptr<Scope>& scope, std::string text, Token::Token_ptr token)
    : Node_parent(scope, std::move(token)), str(std::move(text)) {}

    std::shared_ptr<VarTypeBase> IdentifyNode::getVarType() {
        return std::shared_ptr<VarTypeBase>();
    }
}