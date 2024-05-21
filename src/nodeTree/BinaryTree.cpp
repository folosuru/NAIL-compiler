#include "BinaryTree.hpp"
#include <Symbol/scope/Scope.hpp>
#include <utility>

namespace NAIL_cl {
    BinaryTree::BinaryTree(Type type, std::shared_ptr<Scope> scope, NodeType left, NodeType right)
            : type(type), Node_parent(std::move(scope)), left(std::move(left)), right(std::move(right)) {}
} // NAIL_cl