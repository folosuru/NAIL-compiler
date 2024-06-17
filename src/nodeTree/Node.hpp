#ifndef NAIL_CL_NODE_HPP
#define NAIL_CL_NODE_HPP
#include <memory>
#include <list>
#include "type/VarTypeBase.hpp"
#include <tokenize/token/Token.hpp>
namespace NAIL_cl {
    class Scope;

    class Node_parent {
    public:
        enum class NodeKind {
            binary,
            arrow,
            identify
        };

        explicit Node_parent(std::shared_ptr<Scope>, Token::Token_ptr token);
        Node_parent() = delete;

        const Token::Token_ptr position;

        virtual ~Node_parent() = default;

        virtual std::shared_ptr<VarTypeBase> getVarType() = 0;

        virtual void PolishNotation() = 0;

        virtual void printAsmPush(std::string &) = 0;

        virtual void printAsmPtrPush(std::string &) = 0;

        [[nodiscard]]
        virtual bool isKindOf(NodeKind) const = 0;

    protected:
        std::shared_ptr<Scope> scope;

    };
    using NodeType = std::shared_ptr<Node_parent>;

} // NAIL_cl

#endif //NAIL_CL_NODE_HPP
