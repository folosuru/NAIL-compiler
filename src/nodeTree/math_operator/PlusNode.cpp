#include "PlusNode.hpp"

namespace NAIL_cl {

    std::shared_ptr<Node_parent> PlusNode::create(const NodeType& left, const NodeType& right) {
        return std::make_shared<PlusNode>(left, right);
    }
} // NAIL_cl