#ifndef NAIL_CL_BINARYTREE_HPP
#define NAIL_CL_BINARYTREE_HPP
#include <memory>
#include "Node.hpp"
namespace NAIL_cl {

    class BinaryTree : public Node_parent {
    public:
        explicit BinaryTree(NodeType left, NodeType right)
            : Node_parent(), left(std::move(left)), right(std::move(right)) {};

        template<class T>
        static NodeType create(NodeType left, NodeType right) {
            return std::shared_ptr<Node_parent>(new T(left, right));
        }
    private:
        NodeType left, right;
    };


} // NAIL_cl

#endif //NAIL_CL_BINARYTREE_HPP
