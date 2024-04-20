#ifndef NAIL_CL_DIVNODE_HPP
#define NAIL_CL_DIVNODE_HPP
#include "nodeTree/BinaryTree.hpp"
namespace NAIL_cl {

    class DivNode : public BinaryTree {
    public:
        using BinaryTree::BinaryTree;
        void addAssembly(std::list<std::shared_ptr<asm_obj::instruction>> &result) override;
        ~DivNode() override = default;
    };

} // NAIL_cl

#endif //NAIL_CL_DIVNODE_HPP
