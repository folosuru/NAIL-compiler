#ifndef NAIL_CL_BINARYTREE_HPP
#define NAIL_CL_BINARYTREE_HPP
#include <memory>
#include "Node.hpp"
namespace NAIL_cl {

    class BinaryTree : public Node_parent {
    public:
        explicit BinaryTree(std::shared_ptr<Scope> scope, NodeType left, NodeType right);;

        template<class T>
        static NodeType create(std::shared_ptr<Scope> scope, NodeType left, NodeType right) {
            return std::shared_ptr<Node_parent>(new T(scope, left, right));
        }
    protected:
        NodeType left, right;
    };


} // NAIL_cl

#endif //NAIL_CL_BINARYTREE_HPP
