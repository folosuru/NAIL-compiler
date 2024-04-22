#include <fstream>
#include <iostream>
#include <string>
#include "tokenize/TokenList.hpp"
#include <nodeTree/NodeGenerator.hpp>

int main(int argc, char** argv) {
    if (argc == 2) {
        {
            std::ofstream result_file("test/out.s");
            result_file << "";
        }
        std::string file_name(argv[1]);
        std::ifstream file(file_name);

        std::vector<std::string> text;
        std::string buf;
        while(std::getline(file, buf)) {
            text.push_back(buf);
        }

        std::shared_ptr<NAIL_cl::TokenList> token = std::make_shared<NAIL_cl::TokenList>(text);
        token->print();
        std::list<std::shared_ptr<NAIL_cl::asm_obj::instruction>> result;
        NAIL_cl::Node::generate(token)->addAssembly(result);

        std::ofstream result_file("test/out.s");
        result_file << ".intel_syntax noprefix\n"
                     ".globl main\n"
                     "main:\n"
                     "  push rbp\n"
                     "  mov rbp, rsp\n";
        for (const auto& i : result) {
            result_file << "  " << i->getString() << "\n";
        }
        result_file <<
                "  pop rax\n"
                "  mov rsp, rbp\n"
                "  pop rbp\n"
                "  ret\n";
    }

}