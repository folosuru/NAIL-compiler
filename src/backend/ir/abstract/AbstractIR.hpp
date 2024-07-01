#ifndef NAIL_CL_SRC_BACKEND_IR_IRBASE_CPP_ABSTRACTIR_HPP_
#define NAIL_CL_SRC_BACKEND_IR_IRBASE_CPP_ABSTRACTIR_HPP_

#include "backend/ir/IRBase.hpp"


namespace NAIL_cl::backend::abstract {

class AbstractIR : public IRBase {
public:
    enum class instruction_type {
        add,
        sub,
        push,
        pop,
        store,
        load
    };
    const instruction_type instruction;
};

}  // NAIL_cl::backend::abstract

#endif  //NAIL_CL_SRC_BACKEND_IR_IRBASE_CPP_ABSTRACTIR_HPP_
