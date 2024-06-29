#ifndef NAIL_CL_SRC_SYMBOL_SCOPE_CLASSSCOPE_HPP_
#define NAIL_CL_SRC_SYMBOL_SCOPE_CLASSSCOPE_HPP_

#include "Scope.hpp"

namespace NAIL_cl {

class ClassScope : public Scope {
public:
    void *as_type();
};

} // NAIL_cl

#endif //NAIL_CL_SRC_SYMBOL_SCOPE_CLASSSCOPE_HPP_
