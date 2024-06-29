
#ifndef NAIL_CL_MEMBERACCESS_HPP
#define NAIL_CL_MEMBERACCESS_HPP
#include "frontend/nodeTree/BinaryTree.hpp"

namespace NAIL_cl {

class MemberAccessNode : public BinaryTree {
public:
    using BinaryTree::BinaryTree;

    ~MemberAccessNode() override = default;
};

}  // NAIL_cl


#endif // NAIL_CL_MEMBERACCESS_HPP
