#include <nodeTree/NodeGenerator.hpp>
#include <nodeTree/NodeIncludeList.hpp>
#include <error/ErrorPrinter.hpp>
namespace NAIL_cl::Node {
    NodeType identify(const std::shared_ptr<TokenList>& list) {
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
        if (list->getCurrent()->getString() != "(") {
            return left;
        }
        list->getCurrentPos()++;

        if (list->getCurrent()->getString() != ")") {
            ErrorPrinter::print(list, list->getCurrent(), "unexpected token: except )", ")");
        }
        list->getCurrentPos()++;
        return left;
    }

    NodeType primary(const std::shared_ptr<TokenList>& list) {
        NodeType result;
        if (list->getCurrent()->getString() == "(") {
            list->getCurrentPos()++;
            result = add(list);
            if (list->getCurrent()->getString() != ")" ){
                ErrorPrinter::print(list, list->getCurrent(), "unexpected token: except )", ")");
            }
            list->getCurrentPos()++;
            return result;
        }

        result = function_call(list);
        if (result == nullptr) {
            ErrorPrinter::print(list, list->getCurrent(), "unexpected token: except primary");
        }

        while (true) {
            if (list->getCurrent()->getString() == ".") {
                list->getCurrentPos()++;
                result = BinaryTree::create<MemberAccessNode>(result, function_call(list));
                continue;
            }
            return result;
        }
    }

    NodeType unary(const std::shared_ptr<TokenList>& list) {
        if (list->getCurrent()->getString() == "+") {
            list->getCurrentPos()++;
            return primary(list);
        }

        if (list->getCurrent()->getString() == "-") {
            list->getCurrentPos()++;
            return primary(list);
        }
        return primary(list);

    }

    NodeType mlu(const std::shared_ptr<TokenList>& list) {
        NodeType left = unary(list);
        while (true) {
            if (list->getCurrent()->getString() == "*") {
                list->getCurrentPos()++;
                left = BinaryTree::create<MluNode>(left, unary(list));
                continue;
            }
            if (list->getCurrent()->getString() == "/") {
                list->getCurrentPos()++;
                left = BinaryTree::create<DivNode>(left, unary(list));
                continue;
            }
            return left;
        }
    }

    NodeType add(const std::shared_ptr<TokenList>& list) {
        NodeType left = mlu(list);
        while (true) {
            if (list->getCurrent()->getString() == "+") {
                list->getCurrentPos()++;
                left = BinaryTree::create<PlusNode>(left, mlu(list));
                continue;
            }
            if (list->getCurrent()->getString() == "-") {
                list->getCurrentPos()++;
                left = BinaryTree::create<SubNode>(left, mlu(list));
                continue;
            }
            return left;
        }
    }
}