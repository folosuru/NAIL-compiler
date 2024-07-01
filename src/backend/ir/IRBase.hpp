#ifndef NAIL_CL_SRC_BACKEND_IR_IRBASE_HPP_
#define NAIL_CL_SRC_BACKEND_IR_IRBASE_HPP_


namespace NAIL_cl::backend {

class IRBase {
    enum class IRType {
        abstract,
        native
    };

};

} // NAIL_cl::backend

#endif //NAIL_CL_SRC_BACKEND_IR_IRBASE_HPP_
