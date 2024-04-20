#include <nodeTree/NodeGenerator.hpp>
#include <nodeTree/NodeIncludeList.hpp>
#include <error/ErrorPrinter.hpp>
namespace NAIL_cl::Node {
    NodeType identify(const std::shared_ptr<TokenList>& list) {
        if (auto number = Int32Node::consume(list); number != nullptr) {
            return number;
        }
        if (auto number = Int32Node::consume(list); number != nullptr) {
            return number;
        }


        return nullptr;
    }

    NodeType function_call(const std::shared_ptr<TokenList>& list) {
        NodeType left = identify(list);
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

    NodeType primary(const std::shared_ptr<TokenList>& list) {
        NodeType result;
        if (list->current_is("(")) {
            result = add(list);
            if (!list->current_is(")")){
                ErrorPrinter::print(list, list->getCurrent(), "unexpected token: except )", ")");
            }
            return result;
        }

        result = function_call(list);
        if (result == nullptr) {
            ErrorPrinter::print(list, list->getCurrent(), "unexpected token: except primary");
        }

        while (true) {
            if (list->current_is(".")) {
                result = BinaryTree::create<MemberAccessNode>(result, function_call(list));
                continue;
            }
            return result;
        }
    }

    NodeType unary(const std::shared_ptr<TokenList>& list) {
        if (list->current_is("+")) {
            list->getCurrentPos()++;
            return primary(list);
        }

        if (list->current_is("-")) {
            list->getCurrentPos()++;
            return primary(list);
        }
        return primary(list);

    }

    NodeType mlu(const std::shared_ptr<TokenList>& list) {
        NodeType left = unary(list);
        while (true) {
            if (list->current_is("*")) {
                left = BinaryTree::create<MluNode>(left, unary(list));
                continue;
            }
            if (list->current_is("/")) {
                left = BinaryTree::create<DivNode>(left, unary(list));
                continue;
            }
            return left;
        }
    }

    NodeType add(const std::shared_ptr<TokenList>& list) {
        NodeType left = mlu(list);
        while (true) {
            if (list->current_is("+")) {
                left = BinaryTree::create<PlusNode>(left, mlu(list));
                continue;
            }
            if (list->current_is("-")) {
                left = BinaryTree::create<SubNode>(left, mlu(list));
                continue;
            }
            return left;
        }
    }
}