#include "BlockNode.hpp"

#include <utility>
#include <type/VoidType.hpp>

namespace NAIL_cl {
    void BlockNode::addChild(const NodeType& node) {
        child.push_back(node);
    }

    BlockNode::BlockNode(std::shared_ptr<Scope> scope,Token::Token_ptr token) : Node_parent(std::move(scope), std::move(token)) {


}

    std::shared_ptr<VarTypeBase> BlockNode::getVarType() {
        return VoidType::get();
    }

} // NAIL_cl