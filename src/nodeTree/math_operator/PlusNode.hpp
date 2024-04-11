#ifndef NAIL_CL_PLUSNODE_HPP
#define NAIL_CL_PLUSNODE_HPP
#include <nodeTree/Node.hpp>
#include <memory>
#include <cstdint>
#include <utility>
#include "nodeTree/BinaryTree.hpp"

namespace NAIL_cl {

    class PlusNode : public BinaryTree{

    public:
        using BinaryTree::BinaryTree;
        ~PlusNode() override = default;
    };

} // NAIL_cl

#endif //NAIL_CL_PLUSNODE_HPP
