#ifndef NAIL_CL_NODE_HPP
#define NAIL_CL_NODE_HPP
#include <memory>
#include <list>
#include <backend/assembly/instruction/Instruction.hpp>
namespace NAIL_cl {

    class Scope;

    class Node_parent {
    public:

        explicit Node_parent(std::shared_ptr<Scope>);
        Node_parent() = delete;

        virtual ~Node_parent() = default;

    protected:
        std::shared_ptr<Scope> scope;
    };
    using NodeType = std::shared_ptr<Node_parent>;

} // NAIL_cl

#endif //NAIL_CL_NODE_HPP
