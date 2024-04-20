#ifndef NAIL_CL_CODEGENERATOR_HPP
#define NAIL_CL_CODEGENERATOR_HPP
#include <nodeTree/NodeIncludeList.hpp>
#include <list>
#include <backend/assembly/instruction/Instruction.hpp>
namespace NAIL_cl::asm_obj {
    std::list<std::shared_ptr<instruction>> getList(const std::shared_ptr<Node_parent>&);
    std::string getString(std::list<std::shared_ptr<instruction>>);
} // NAIL_cl::asm_obj

#endif //NAIL_CL_CODEGENERATOR_HPP
