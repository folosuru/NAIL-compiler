#include <nodeTree/NodeGenerator.hpp>
#include <nodeTree/NodeIncludeList.hpp>
#include <error/ErrorPrinter.hpp>
#include <Symbol/scope/GlobalScope.hpp>
namespace NAIL_cl::Node {
    NodeType identify(const std::shared_ptr<TokenList>& list, std::shared_ptr<Scope> scope) {
        if (auto number = Int32Node::consume(scope, list); number != nullptr) {
            return number;
        }
        if (auto number = Int32Node::consume(scope, list); number != nullptr) {
            return number;
        }
        return nullptr;
    }

    NodeType function_call(const std::shared_ptr<TokenList>& list, std::shared_ptr<Scope> scope) {
        NodeType left = identify(list, scope);
        if (left == nullptr) {
            ErrorPrinter::print(list, list->getCurrent(), "unexpected token: need identifyer or number");
        }
        if (!list->current_is("(")) {
            return left;
        }
        if (!list->current_is(")")) {
            ErrorPrinter::print(list, list->getCurrent(), "unexpected token: except )", ")");
        }
        return left;
    }

    NodeType primary(const std::shared_ptr<TokenList>& list, std::shared_ptr<Scope> scope) {
        NodeType result;
        if (list->current_is("(")) {
            result = add(list, scope);
            if (!list->current_is(")")){
                ErrorPrinter::print(list, list->getCurrent(), "unexpected token: except )", ")");
            }
            return result;
        }

        result = function_call(list, scope);
        if (result == nullptr) {
            ErrorPrinter::print(list, list->getCurrent(), "unexpected token: except primary");
        }

        while (true) {
            if (list->current_is(".")) {
                result = BinaryTree::create<MemberAccessNode>(scope, result, function_call(list, scope));
                continue;
            }
            return result;
        }
    }

    NodeType unary(const std::shared_ptr<TokenList>& list, std::shared_ptr<Scope> scope) {
        if (list->current_is("+")) {
            list->getCurrentPos()++;
            return primary(list, scope);
        }

        if (list->current_is("-")) {
            list->getCurrentPos()++;
            return primary(list, scope);
        }
        return primary(list, scope);

    }

    NodeType mlu(const std::shared_ptr<TokenList>& list, std::shared_ptr<Scope> scope) {
        NodeType left = unary(list, scope);
        while (true) {
            if (list->current_is("*")) {
                left = BinaryTree::create<MluNode>(scope, left, unary(list, scope));
                continue;
            }
            if (list->current_is("/")) {
                left = BinaryTree::create<DivNode>(scope, left, unary(list, scope));
                continue;
            }
            return left;
        }
    }

    NodeType add(const std::shared_ptr<TokenList>& list, std::shared_ptr<Scope> scope) {
        NodeType left = mlu(list, scope);
        while (true) {
            if (list->current_is("+")) {
                left = BinaryTree::create<PlusNode>(scope, left, mlu(list, scope));
                continue;
            }
            if (list->current_is("-")) {
                left = BinaryTree::create<SubNode>(scope, left, mlu(list, scope));
                continue;
            }
            return left;
        }
    }

    NodeType generate(const std::shared_ptr<TokenList>& list ) {
        return add(list, std::make_shared<GlobalScope>());
    }
}