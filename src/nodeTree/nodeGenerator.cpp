#include <nodeTree/NodeGenerator.hpp>
#include <nodeTree/NodeIncludeList.hpp>
#include <Printer/ErrorPrinter.hpp>
#include <Symbol/scope/GlobalScope.hpp>
#include "nodeTree/syntax/BlockNode.hpp"
#include "tokenize/TokenUtility.hpp"
#include "tokenize/token/PreservedSymbol.hpp"
#include "tokenize/token/IdentifyToken.hpp"

namespace NAIL_cl::Node {
    NodeType identify(const std::shared_ptr<TokenList>& list, const std::shared_ptr<Scope>& scope) {
        if (auto number = Int32Node::consume(scope, list); number != nullptr) {
            return number;
        }
        if (auto identify = IdentifyNode::consume(scope, list); identify != nullptr) {
            return identify;
        }
        return nullptr;
    }

    NodeType function_call(const std::shared_ptr<TokenList>& list, const std::shared_ptr<Scope>& scope) {
        NodeType left = identify(list, scope);
        if (left == nullptr) {
            ErrorPrinter::print(list, list->getCurrent(), "unexpected token: need identifyer or number");
        }
        if (!list->consume_current("(")) {
            return left;
        }
        if (!list->consume_current(")")) {
            ErrorPrinter::print(list, list->getCurrent(), "unexpected token in function call: except )", ")");
        }
        return left;  //
    }

    NodeType primary(const std::shared_ptr<TokenList>& list, const std::shared_ptr<Scope>& scope) {
        NodeType result;

        // bracket
        if (list->consume_current("(")) {
            result = assign(list, scope);
            if (!list->consume_current(")")){
                ErrorPrinter::print(list, list->getCurrent(), "unexpected token: except )", ")");
            }
            return result;
        }
        if (auto token = TokenUtil::consume_current<Token::PreservedSymbol>(list)) {
            if (token->getSymbolType() == Token::PreservedSymbol::Symbol_type::kw_var) {
                auto name = TokenUtil::consume_current<Token::IdentifyToken>(list);
                if (name == nullptr) {
                    ErrorPrinter::print(list, list->getCurrent(),
                                        "unexpected token: need identifier at variable define", "<name>");
                }
                if (scope->exist_object(std::string(name->getString()))) {
                    ErrorPrinter::print(list, name,
                                        "This name is already used in this scope");
                }
                scope->createVariable(name);
                return 0; // これ多分、変数のnodeじゃなくてただの変数のNodeで十分だね。
            }
        }

        result = function_call(list, scope);
        if (result == nullptr) {
            ErrorPrinter::print(list, list->getCurrent(), "unexpected token: except primary");
        }

        while (true) {
            auto current = list->getCurrent();
            if (list->consume_current(".")) {
                result = BinaryTree::create(BinaryTree::Type::member_access, scope, result, function_call(list, scope), current);
                continue;
            }
            return result;
        }
    }

    NodeType unary(const std::shared_ptr<TokenList>& list, const std::shared_ptr<Scope>& scope) {
        if (list->consume_current("+")) {
            return primary(list, scope);
        }

        if (list->consume_current("-")) {
            return primary(list, scope);
        }
        return primary(list, scope);

    }

    NodeType mlu(const std::shared_ptr<TokenList>& list, const std::shared_ptr<Scope>& scope) {
        NodeType left = unary(list, scope);
        while (true) {
            if (auto current = list->consume_current("*")) {
                left = BinaryTree::create(BinaryTree::Type::mlu, scope, left, unary(list, scope), current);
                continue;
            }
            if (auto current =  list->consume_current("/")) {
                left = BinaryTree::create(BinaryTree::Type::div, scope, left, unary(list, scope), current);
                continue;
            }
            return left;
        }
    }

    NodeType add(const std::shared_ptr<TokenList>& list, const std::shared_ptr<Scope>& scope) {
        NodeType left = mlu(list, scope);
        while (true) {
            if (auto current = list->consume_current("+")) {
                left = BinaryTree::create(BinaryTree::Type::plus ,scope, left, mlu(list, scope), current);
                continue;
            }
            if (auto current = list->consume_current("-")) {
                left = BinaryTree::create(BinaryTree::Type::minus, scope, left, mlu(list, scope), current);
                continue;
            }
            return left;
        }
    }

    NodeType assign(const std::shared_ptr<TokenList>& token, const std::shared_ptr<Scope>& scope) {
        auto left = add(token, scope);
        while (auto current = token->consume_current("->")) {
            left = BinaryTree::create(BinaryTree::Type::assign, scope, left, assign(token, scope), current);
        }
        return left;
    }

    NodeType statement(const std::shared_ptr<TokenList>& token, const std::shared_ptr<Scope>& scope) {
        auto stm = assign(token, scope);
        if (!token->consume_current(";")) {
            ErrorPrinter::print(token, token->getCurrent(), "Need ; at end of statement", ";");
        }
        return stm;
    }

    NodeType generate(const std::shared_ptr<TokenList>& list ) {
        auto scope = std::make_shared<GlobalScope>();
        std::shared_ptr<BlockNode> node = std::make_shared<BlockNode>(scope, list->getCurrent());
        while (!list->current_is(Token::TokenType::eof)) {
            node->addChild(statement(list, scope));
        }
        return node;
    }

}