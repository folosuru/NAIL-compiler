#ifndef NAIL_CL_SUBNODE_HPP
#define NAIL_CL_SUBNODE_HPP
#include "nodeTree/BinaryTree.hpp"
namespace NAIL_cl {

    class SubNode : public BinaryTree{
    public:
        using BinaryTree::BinaryTree;
        ~SubNode() override = default;
    };

} // NAIL_cl

#endif //NAIL_CL_SUBNODE_HPP
