#include "ArrowNode.hpp"

#include <utility>
#include <nodeTree/symbol/IdentifyNode.hpp>

namespace NAIL_cl {
    ArrowNode::ArrowNode(std::shared_ptr<Scope> scope, NodeType left_, NodeType right_,
                         Token::Token_ptr token) : BinaryTree(BinaryTree::Type::arrow, std::move(scope),
                                                              std::move(left_), std::move(right_), std::move(token)) {
        if (right->isKindOf(NodeKind::identify)) {
            std::static_pointer_cast<IdentifyNode>(right)->assign(left);
        }
    }

    std::shared_ptr<VarTypeBase> ArrowNode::getVarType() {
        return right->getVarType();
    }

    void ArrowNode::printAsmPush(std::string & str) {
        left->printAsmPush(str);
        right->printAsmPtrPush(str);
        str += "pop rax\n"
               "pop rdi\n"
               "mov [rax], rdi\n"
               "push rdi\n";
        return;
    }

    void ArrowNode::printAsmPtrPush(std::string &) {
    }
} // NAIL_cl