
#ifndef NAIL_CL_MLUNODE_HPP
#define NAIL_CL_MLUNODE_HPP
#include "nodeTree/BinaryTree.hpp"
namespace NAIL_cl {

    class MluNode : public BinaryTree {
    public:
        using BinaryTree::BinaryTree;
        void addAssembly(std::list<std::shared_ptr<asm_obj::instruction>> &result) override;
        ~MluNode() override = default;
    };

}  // NAIL_cl


#endif //NAIL_CL_MLUNODE_HPP
