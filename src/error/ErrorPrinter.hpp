#ifndef NTSL_CL_ERRORPRINTER_HPP
#define NTSL_CL_ERRORPRINTER_HPP
#include <tokenize/TokenList.hpp>
#include <tokenize/token/Token.hpp>
namespace NTSL_cl {

    namespace ErrorPrinter {
        [[noreturn]]
        void print(const std::shared_ptr<TokenList>&, const std::shared_ptr<Token::Token>&, const std::string& message);

    };

} // NTSL_cl
#endif //NTSL_CL_ERRORPRINTER_HPP
