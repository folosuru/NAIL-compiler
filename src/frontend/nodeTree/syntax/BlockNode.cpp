#include "BlockNode.hpp"

#include <utility>
#include "frontend/type/VoidType.hpp"
#include "frontend/Printer/Dump.hpp"

namespace NAIL_cl {
void BlockNode::addChild(const NodeType& node) {
    child.push_back(node);
}

BlockNode::BlockNode(std::shared_ptr<Scope> scope, Token::Token_ptr token) : Node_parent(std::move(scope),
                                                                                         std::move(token)) {}

std::shared_ptr<VarTypeBase> BlockNode::getVarType() {
    return VoidType::get();
}

void BlockNode::PolishNotation() {
    Printer::print("( Block \n");
    for (const auto& i : child) {
        if (!i) continue;
        Printer::print("  ");
        i->PolishNotation();
        Printer::print("\n");
    }
    Printer::print(")");
}

} // NAIL_cl