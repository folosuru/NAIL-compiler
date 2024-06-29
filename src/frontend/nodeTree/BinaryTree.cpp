#include "BinaryTree.hpp"
#include "frontend/Symbol/scope/Scope.hpp"
#include <utility>
#include "frontend/Printer/ErrorPrinter.hpp"
#include "frontend/Printer/Dump.hpp"

namespace NAIL_cl {
BinaryTree::BinaryTree(Type type, std::shared_ptr<Scope> scope, NodeType left, NodeType right, Token::Token_ptr list)
    : type(type), Node_parent(std::move(scope), std::move(list)), left(std::move(left)), right(std::move(right)) {}

std::shared_ptr<VarTypeBase> BinaryTree::getVarType() {
    auto result = VarTypeBase::getConflictType(left->getVarType(), right->getVarType());
    if (std::holds_alternative<VarType>(result)) {
        return get<VarType>(result);
    }
    ErrorPrinter::print(position->list, position, "Type Conflict");
}

void BinaryTree::PolishNotation() {
    Printer::print("(");
    Printer::print(position->getString());
    Printer::print(" ");
    left->PolishNotation();
    Printer::print(" ");
    right->PolishNotation();
    Printer::print(")");
}
} // NAIL_cl