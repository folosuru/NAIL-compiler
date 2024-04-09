#include "ErrorPrinter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
namespace NAIL_cl {
    namespace ErrorPrinter {
        void print(const std::shared_ptr<TokenList>& list,
                   const std::shared_ptr<Token::Token>& token,
                   const std::string& message) {
            std::size_t line = token->line;
            std::string target_line = list->source_text.at(line);
            std::cout << message << "\n";

            std::cout << std::setw(4) << line+1 << ":" << token->pos+1
            << std::right  << " | " << target_line << "\n";
            std::cout << std::setw( token->pos+1 + 4 + 4 + std::log10(token->pos+1)+1) << "^";
            for (int i = 1; i < token->getString().size(); ++i) {
                std::cout << "~";
            }
            exit(0);
        }

    }

} // NAIL_cl