#ifndef NAIL_CL_DUMP_HPP
#define NAIL_CL_DUMP_HPP
#include <iostream>

// For debug

namespace NAIL_cl::Printer {
    template<class T, class U, class V>
    void Dump_list(T title, U iteration_value, V dump_function) {
        std::cout << "== " << title << " ==\n";
        for (const auto& i : iteration_value) {
            std::cout << "<" << dump_function(i) << ">, ";
        }
        std::cout << "\n== " << title << " END ==\n";
    }

    template<class T>
    void print(T text) {
        std::cout << text;
    }

}

#endif //NAIL_CL_DUMP_HPP
