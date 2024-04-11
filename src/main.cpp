#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include "tokenize/TokenList.hpp"
#include <nodeTree/NodeGenerator.hpp>

int main(int argc, char** argv) {
    if (argc == 2) {
        std::string file_name(argv[1]);
        std::ifstream file(file_name);

        std::vector<std::string> text;
        std::string buf;
        while(std::getline(file, buf)) {
            text.push_back(buf);
        }

        std::shared_ptr<NAIL_cl::TokenList> token = std::make_shared<NAIL_cl::TokenList>(text);
        token->print();
        NAIL_cl::Node::add(token);
    }

}