#ifndef NAIL_CL_DUMP_HPP
#define NAIL_CL_DUMP_HPP
#include <iostream>
#include <utility>
#include <format>
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


inline void PolishNotationR() {}

template<class T> void PolishNotationR(T head) {
    head->PolishNotation();
}

template<class T, class... U> void PolishNotationR(T head, U... child) {
    head->PolishNotation();
    PolishNotationR(std::forward<U>(child)...);
    print(", ");
}

template<class T, class... U> void PolishNotation(T text, U... child) {
    print(std::format("( {} ", text));
    PolishNotationR(std::forward<U>(child)...);
    print(")");
}

}

#endif //NAIL_CL_DUMP_HPP
