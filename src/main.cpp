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

        auto node = NAIL_cl::Node::generate(token);
        node->PolishNotation();


    }
}