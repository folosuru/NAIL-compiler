#ifndef NAIL_CL_ERRORPRINTER_HPP
#define NAIL_CL_ERRORPRINTER_HPP
#include <tokenize/TokenList.hpp>
#include <tokenize/token/Token.hpp>
#include <optional>
namespace NAIL_cl {

    namespace ErrorPrinter {
        [[noreturn]]
        void print(const std::shared_ptr<TokenList>&,
                   const std::shared_ptr<Token::Token>&,
                   const std::string& message,
                   std::optional<std::string_view> suggest = std::nullopt);

    };

} // NAIL_cl
#endif //NAIL_CL_ERRORPRINTER_HPP
