#include "CodeGenerator.hpp"

namespace NAIL_cl::asm_obj {

    std::list<std::shared_ptr<instruction>> getList(std::shared_ptr<Node_parent> parent) {
        std::list<std::shared_ptr<instruction>> result;
        parent->addAssembly(result);
        return std::move(result);
    }
} // NAIL_cl::asm_obj
