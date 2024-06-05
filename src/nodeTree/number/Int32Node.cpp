#include "Int32Node.hpp"
#include <backend/assembly/instruction/Push.hpp>
#include <backend/assembly/operand/Number.hpp>
#include <Symbol/scope/Scope.hpp>
#include <utility>
#include <type/IntType.hpp>
#include <Printer/Dump.hpp>

namespace NAIL_cl {
    std::shared_ptr<Node_parent> Int32Node::consume(std::shared_ptr<Scope> scope,
                                                    const std::shared_ptr<TokenList> &list) {
        if (auto current = list->consume_current(Token::TokenType::number)) {
            std::shared_ptr<Token::NumberToken> token = std::reinterpret_pointer_cast<Token::NumberToken>(current);
            return std::make_shared<Int32Node>(scope, static_cast<std::int32_t>(token->value), token);
        }
        return nullptr;
    }

    Int32Node::Int32Node(std::shared_ptr<Scope> scope, std::int32_t value, Token::Token_ptr token)
            : Node_parent(std::move(scope), std::move(token)), value(value) {}

    std::shared_ptr<VarTypeBase> Int32Node::getVarType() {
        return IntType::int32;
    }

    void Int32Node::PolishNotation() {
        Printer::print("( Number ");
        Printer::print(value);
        Printer::print(")")

    }
} // NAIL_cl