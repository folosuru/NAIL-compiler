#include "IdentifyNode.hpp"
#include "tokenize/token/IdentifyToken.hpp"
#include <Symbol/scope/Scope.hpp>

namespace NAIL_cl {
    std::shared_ptr<Node_parent> IdentifyNode::consume(std::shared_ptr<Scope> scope,
                                                       const std::shared_ptr<TokenList> &list) {
        if (list->current_is(Token::TokenType::identify)) {
            auto token = list->getCurrent();
            list->getCurrentPos()++;
            return std::make_shared<IdentifyNode>(scope, std::string(token->getString()));
        }
        return nullptr;
    }

    void IdentifyNode::addAssembly(std::list<std::shared_ptr<asm_obj::instruction>> &result) {
    }

    IdentifyNode::IdentifyNode(std::shared_ptr<Scope> scope, std::string text)
    : Node_parent(scope), str(std::move(text)) {}
}