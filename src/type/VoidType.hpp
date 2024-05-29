#ifndef NAIL_CL_VOIDTYPE_HPP
#define NAIL_CL_VOIDTYPE_HPP
#include <type/VarTypeBase.hpp>
namespace NAIL_cl {

    class VoidType : public VarTypeBase {

    public:
        static VarType get();
    private:
        VoidType();
        static inline VarType instance;
    };

} // NAIL_cl

#endif //NAIL_CL_VOIDTYPE_HPP
