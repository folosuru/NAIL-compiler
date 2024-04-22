#include "Int32Node.hpp"
#include <backend/assembly/instruction/Push.hpp>
#include <backend/assembly/operand/Number.hpp>
#include <Symbol/scope/Scope.hpp>

namespace NAIL_cl {
    std::shared_ptr<Node_parent> Int32Node::consume(std::shared_ptr<Scope> scope,
                                                    const std::shared_ptr<TokenList> &list) {
        if (auto current_tok = list->getCurrent(); current_tok->getType() == Token::TokenType::number) {
            std::shared_ptr<Token::NumberToken> token = std::reinterpret_pointer_cast<Token::NumberToken>(current_tok);
            list->getCurrentPos()++;
            return std::make_shared<Int32Node>(scope, static_cast<std::int32_t>(token->value));
        }
        return nullptr;
    }

    void Int32Node::addAssembly(std::list<std::shared_ptr<asm_obj::instruction>> &result) {
        result.push_back(std::make_shared<asm_obj::push>(std::make_shared<asm_obj::Number>(value)));
    }

    Int32Node::Int32Node(std::shared_ptr<Scope> scope, std::int32_t value) : Node_parent(scope), value(value) {}
} // NAIL_cl