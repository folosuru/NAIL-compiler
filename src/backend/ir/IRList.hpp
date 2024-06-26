#ifndef NAIL_CL_SRC_BACKEND_IR_IRLIST_HPP_
#define NAIL_CL_SRC_BACKEND_IR_IRLIST_HPP_
#include <list>
#include <memory>
#include <backend/ir/IRBase.hpp>
namespace NAIL_cl {
namespace backend {

class IRList {
public:
    void push(std::unique_ptr<IRBase>);



private:
    std::list<std::unique_ptr<IRBase>> list;

};

} // backend
} // NAIL_cl

#endif //NAIL_CL_SRC_BACKEND_IR_IRLIST_HPP_
