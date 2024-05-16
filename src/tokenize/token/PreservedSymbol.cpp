#include "PreservedSymbol.hpp"


namespace NAIL_cl::Token {
    PreservedSymbol::PreservedSymbol(std::string_view name, std::size_t line, std::int64_t pos, Symbol_type type)
      : Token(name, line, pos) , type(type) {}


    TokenType PreservedSymbol::getType() const {
        return TokenType::Preserved_symbol;
    }



    Token_ptr PreservedSymbol::consume(const std::string& str, const std::size_t &line, std::int64_t &pos) {
        std::int64_t start = pos;

        // fall through
        switch (str.length() - pos) {
            default:

            case 2: {
                pos = start + 2;
                std::string_view text = std::string_view(str.begin() + start, str.begin() + pos);
                if (text == "==") {
                    return std::make_shared<PreservedSymbol>(text, line, start, PreservedSymbol::Symbol_type::equal);
                }
            }

            case 1: {
                pos = start + 1;
                std::string_view text = std::string_view(str.begin() + start, str.begin() + pos);
                if (text == ",") {
                    return std::make_shared<PreservedSymbol>(text, line, start, PreservedSymbol::Symbol_type::comma);
                }
                if (text == "+") {
                    return std::make_shared<PreservedSymbol>(text, line, start, PreservedSymbol::Symbol_type::plus);
                }
                if (text == "-") {
                    return std::make_shared<PreservedSymbol>(text, line, start, PreservedSymbol::Symbol_type::minus);
                }
                if (text == "(") {
                    return std::make_shared<PreservedSymbol>(text, line, start, PreservedSymbol::Symbol_type::small_bracket_open);
                }
                if (text == ")") {
                    return std::make_shared<PreservedSymbol>(text, line, start, PreservedSymbol::Symbol_type::small_breacket_close);
                }
                if (text == "*") {
                    return std::make_shared<PreservedSymbol>(text, line, start, PreservedSymbol::Symbol_type::mlu);
                }
                if (text == "/") {
                    return std::make_shared<PreservedSymbol>(text, line, start, PreservedSymbol::Symbol_type::div);
                }
                if (text == ".") {
                    return std::make_shared<PreservedSymbol>(text, line, start, PreservedSymbol::Symbol_type::period);
                }
                if (text == "=") {
                    return std::make_shared<PreservedSymbol>(text, line, start, PreservedSymbol::Symbol_type::assign);
                }
                if (text == ";") {
                    return std::make_shared<PreservedSymbol>(text, line, start, PreservedSymbol::Symbol_type::semi_coron);
                }
            }

            case 0:
                pos = start;
                return nullptr;
        }
    }

} // NAIL_cl::Token