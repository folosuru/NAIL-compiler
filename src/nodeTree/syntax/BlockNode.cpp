#include "BlockNode.hpp"

#include <utility>

namespace NAIL_cl {
    void BlockNode::addChild(const NodeType& node) {
        child.push_back(node);
    }

    BlockNode::BlockNode(std::shared_ptr<Scope> scope) : Node_parent(std::move(scope)) {


}

} // NAIL_cl