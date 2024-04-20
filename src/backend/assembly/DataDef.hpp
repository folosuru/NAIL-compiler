#ifndef NAIL_CL_DATADEF_HPP
#define NAIL_CL_DATADEF_HPP

namespace NAIL_cl::asm_obj {
    enum class data_size : int {
        qword = 0,
        dword = 1,
        word = 2,
        byte = 3,
    };

}
#endif //NAIL_CL_DATADEF_HPP
