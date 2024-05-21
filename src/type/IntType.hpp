#ifndef NAIL_CL_INTTYPE_HPP
#define NAIL_CL_INTTYPE_HPP
#include "VarType.hpp"
namespace NAIL_cl {

    class IntType : public VarType {
    public:
        explicit IntType(std::string name, int size);

    private:
        int size;
    };

} // NAIL_cl

#endif //NAIL_CL_INTTYPE_HPP
