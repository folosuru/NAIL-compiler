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
        arrow
    };

    const Type type;

    const NodeType left;

    const NodeType right;

    explicit BinaryTree(Type type, std::shared_ptr<Scope> scope, NodeType left, NodeType right, Token::Token_ptr);

    static NodeType create(Type type,
                           const std::shared_ptr<Scope>& scope,
                           const NodeType& left,
                           const NodeType& right,
                           const Token::Token_ptr& token) {
        return std::make_shared<BinaryTree>(type, scope, left, right, token);
    }

    std::shared_ptr<VarTypeBase> getVarType() override;

    void PolishNotation() override;

    bool isKindOf(NAIL_cl::Node_parent::NodeKind) const override;

};

} // NAIL_cl

#endif //NAIL_CL_BINARYTREE_HPP
