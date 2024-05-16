#include "ErrorPrinter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

namespace NAIL_cl::ErrorPrinter {
    void print(const std::shared_ptr<TokenList>& list,
               const std::shared_ptr<Token::Token>& token,
               const std::string& message,
               std::optional<std::string_view> suggest) {


        std::size_t line;
        std::string target_line;
        std::size_t pos;
        if (token->getType() == Token::TokenType::eof) {
            target_line = *list->source_text.rbegin();
            line = 0;
            pos = target_line.size();
        } else {
            line = token->line;
            target_line = list->source_text.at(line - 1);
            pos = token->pos;
        }

        std::cout << "Error: " <<  message << "\n";
        std::cout << std::setw(4) << line << ":" << pos+1
        << std::right  << " | " << target_line << "\n";
        std::cout << std::setw( pos+1 + 4 + 4 + static_cast<int>(std::log10(pos+1))+1) << "^"
         <<  std::setfill('~') << std::setw(token->getString().size() - 1) << "" << std::setfill(' ') << "\n";
        if (suggest) {
            std::cout << std::setw( pos+1 + 4 + 4 + static_cast<int>(std::log10(pos+1)) +1) << suggest.value() << "\n";
        }
        exit(0);
    }

}

// NAIL_cl