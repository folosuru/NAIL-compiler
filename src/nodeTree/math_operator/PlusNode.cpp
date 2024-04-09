//
// Created by SurumeIka on 2024/04/09.
//

#include "PlusNode.hpp"

namespace NTSL_cl {

    std::shared_ptr<Node_parent> PlusNode::create(const NodeType& left, const NodeType& right) {
        return std::make_shared<PlusNode>(left, right);
    }
} // NTSL_cl