#ifndef NAIL_CL_BINARYTREE_HPP
#define NAIL_CL_BINARYTREE_HPP
#include <memory>
#include "Node.hpp"
namespace NAIL_cl {

    class BinaryTree : public Node_parent {
    public:
        enum class Type {
            plus,
            minus,
            mlu,
            div,

            member_access,
            assign
        };

        const Type type;

        explicit BinaryTree(Type type, std::shared_ptr<Scope> scope, NodeType left, NodeType right);;

        static NodeType create(Type type, const std::shared_ptr<Scope>& scope, const NodeType& left, const NodeType& right) {
            return std::make_shared<BinaryTree>(type, scope, left, right);
        }
    protected:
        NodeType left, right;
    };


} // NAIL_cl

#endif //NAIL_CL_BINARYTREE_HPP
