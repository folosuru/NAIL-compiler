#ifndef NAIL_CL_ARROWNODE_HPP
#define NAIL_CL_ARROWNODE_HPP
#include "BinaryTree.hpp"

namespace NAIL_cl {

class ArrowNode : public BinaryTree {
public:
    ArrowNode(std::shared_ptr<Scope> scope, NodeType left, NodeType right, Token::Token_ptr);

    static NodeType create(const std::shared_ptr<Scope>& scope,
                           const NodeType& left,
                           const NodeType& right,
                           const Token::Token_ptr& token) {
        return std::make_shared<ArrowNode>(scope, left, right, token);
    }

    std::shared_ptr<VarTypeBase> getVarType() override;

    void printAsmPush(std::string&) override;

    void printAsmPtrPush(std::string&) override;
};

} // NAIL_cl

#endif //NAIL_CL_ARROWNODE_HPP
