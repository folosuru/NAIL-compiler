#include "Register.hpp"
namespace NAIL_cl::asm_obj {
    using enum register_operand::word_name;

    std::unordered_map<register_operand::word_name, std::array<std::string, 4>> register_operand::register_word_str = {
                        //   64bit  32bit   16bit   8bit
            {rax,   {"rax",  "eax",  "ax",   "al"  }},
            {rbx,   {"rbx",  "ebx",  "bx",   "bl"  }},
            {rcx,   {"rcx",  "ecx",  "cx",   "cl"  }},
            {rdx,   {"rdx",  "edx",  "dx",   "dl"  }},
            {rsi,   {"rsi",  "esi",  "si",   "sil" }},
            {rdi,   {"rdi",  "edi",  "di",   "dil" }},
            {rbp,   {"rbp",  "ebp",  "bp",   "bpl" }},
            {rsp,   {"rsp",  "esp",  "sp",   "spl" }},
            {r8,    {"r8 ",  "r8d",  "r8w" , "r8b" }},
            {r9,    {"r9 ",  "r9d",  "r9w" , "r9b" }},
            {r10,   {"r10",  "r10d", "r10w", "r10b"}},
            {r11,   {"r11",  "r11d", "r11w", "r11b"}},
            {r12,   {"r12",  "r12d", "r12w", "r12b"}},
            {r13,   {"r13",  "r13d", "r13w", "r13b"}},
            {r14,   {"r14",  "r14d", "r14w", "r14b"}},
            {r15,   {"r15",  "r15d", "r15w", "r15b"}},
            {xmm0,  {"xmm0", "",     "",     ""}},
            {xmm1,  {"xmm1", "",     "",     ""}},
            {xmm2,  {"xmm2", "",     "",     ""}},
            {xmm3,  {"xmm3", "",     "",     ""}},
            {xmm4,  {"xmm4", "",     "",     ""}},
            {xmm5,  {"xmm5", "",     "",     ""}},
            {xmm6,  {"xmm6", "",     "",     ""}},
            {xmm7,  {"xmm7", "",     "",     ""}},
            {xmm8,  {"xmm8", "",     "",     ""}},
            {xmm9,  {"xmm9", "",     "",     ""}},
            {xmm10, {"xmm10","",     "",     ""}},
            {xmm11, {"xmm11","",     "",     ""}},
            {xmm12, {"xmm12","",     "",     ""}},
            {xmm13, {"xmm13","",     "",     ""}},
            {xmm14, {"xmm14","",     "",     ""}},
            {xmm15, {"xmm15","",     "",     ""}}
};
}