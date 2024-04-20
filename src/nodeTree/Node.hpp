#ifndef NAIL_CL_NODE_HPP
#define NAIL_CL_NODE_HPP
#include <memory>
#include <list>
#include <backend/assembly/instruction/Instruction.hpp>
namespace NAIL_cl {


    class Node_parent {
    public:

         virtual ~Node_parent() = default;

         virtual void addAssembly(std::list<std::shared_ptr<asm_obj::instruction>>& result) {  };

    };
    using NodeType = std::shared_ptr<Node_parent>;

} // NAIL_cl

#endif //NAIL_CL_NODE_HPP
