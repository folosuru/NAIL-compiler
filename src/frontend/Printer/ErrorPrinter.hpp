#ifndef NAIL_CL_ERRORPRINTER_HPP
#define NAIL_CL_ERRORPRINTER_HPP
#include "frontend/tokenize/TokenList.hpp"
#include "frontend/tokenize/token/Token.hpp"
#include <optional>

namespace NAIL_cl::ErrorPrinter {
[[noreturn]]
void print(const TokenList&,
           const std::shared_ptr<Token::Token>&,
           const std::string& message,
           std::optional<std::string_view> suggest = std::nullopt);

[[noreturn]]
void print(const std::shared_ptr<TokenList>& tokenList,
           const std::shared_ptr<Token::Token>& tok,
           const std::string& message,
           std::optional<std::string_view> suggest = std::nullopt);

}

// NAIL_cl
#endif //NAIL_CL_ERRORPRINTER_HPP
