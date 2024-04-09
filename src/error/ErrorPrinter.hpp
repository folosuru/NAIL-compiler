#ifndef NAIL_CL_ERRORPRINTER_HPP
#define NAIL_CL_ERRORPRINTER_HPP
#include <tokenize/TokenList.hpp>
#include <tokenize/token/Token.hpp>
namespace NAIL_cl {

    namespace ErrorPrinter {
        [[noreturn]]
        void print(const std::shared_ptr<TokenList>&, const std::shared_ptr<Token::Token>&, const std::string& message);

    };

} // NAIL_cl
#endif //NAIL_CL_ERRORPRINTER_HPP
