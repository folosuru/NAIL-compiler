#include "BlockNode.hpp"

namespace NAIL_cl {
    void BlockNode::addChild(NodeType node) {
        child.push_back(node);
    }

    BlockNode::BlockNode(std::shared_ptr<Scope> scope) : Node_parent(scope) {


}

} // NAIL_cl