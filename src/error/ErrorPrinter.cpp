#include "ErrorPrinter.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
namespace NAIL_cl {
    namespace ErrorPrinter {
        void print(const std::shared_ptr<TokenList>& list,
                   const std::shared_ptr<Token::Token>& token,
                   const std::string& message,
                   std::optional<std::string_view> suggest) {
            std::size_t line = token->line;
            std::string target_line = list->source_text.at(line-1);
            std::cout << message << "\n";

            std::cout << std::setw(4) << line << ":" << token->pos+1
            << std::right  << " | " << target_line << "\n";
            std::cout << std::setw( token->pos+1 + 4 + 4 + std::log10(token->pos+1)+1) << "^"
             <<  std::setfill('~') << std::setw(token->getString().size() - 1) << "" << std::setfill(' ') << "\n";
            if (suggest) {
                std::cout << std::setw( token->pos+1 + 4 + 4 + std::log10(token->pos+1)+1) << suggest.value() << "\n";
            }
            exit(0);
        }

    }

} // NAIL_cl