#ifndef NAIL_CL_INTTYPE_HPP
#define NAIL_CL_INTTYPE_HPP
#include "VarTypeBase.hpp"
namespace NAIL_cl {

    class IntType : public VarTypeBase {
    public:
        const int size;
        const bool is_unsigned;

        static const std::shared_ptr<IntType> int8;
        static const std::shared_ptr<IntType> int16;
        static const std::shared_ptr<IntType> int32;
        static const std::shared_ptr<IntType> int64;

        static const std::shared_ptr<IntType> uint8;
        static const std::shared_ptr<IntType> uint16;
        static const std::shared_ptr<IntType> uint32;
        static const std::shared_ptr<IntType> uint64;



    private:
        explicit IntType(std::string name, int size, bool is_unsigned);
    };

} // NAIL_cl

#endif //NAIL_CL_INTTYPE_HPP
