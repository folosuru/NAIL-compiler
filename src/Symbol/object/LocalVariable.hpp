#ifndef NAIL_CL_LOCALVARIABLE_HPP
#define NAIL_CL_LOCALVARIABLE_HPP
#include <Symbol/ObjectBase.hpp>
#include <cstdint>
namespace NAIL_cl {

    class LocalVariable : public ObjectBase {
    public:

    private:
        std::int32_t offset;
        void* type;
    };

} // NAIL_cl

#endif //NAIL_CL_LOCALVARIABLE_HPP
