#include "BinaryTree.hpp"
#include <Symbol/scope/Scope.hpp>

namespace NAIL_cl {
    BinaryTree::BinaryTree(std::shared_ptr<Scope> scope, NodeType left, NodeType right)
            : Node_parent(scope), left(std::move(left)), right(std::move(right)) {}
} // NAIL_cl