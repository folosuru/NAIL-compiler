#include <optional>
#include "PreservedSymbol.hpp"
#include "IdentifyToken.hpp"

namespace NAIL_cl::Token {
PreservedSymbol::PreservedSymbol(std::string_view name,
                                 std::size_t line,
                                 std::int64_t pos,
                                 const TokenList& list,
                                 Symbol_type type)
    : Token(name, line, pos, list), type(type) {}

TokenType PreservedSymbol::getType() const {
    return TokenType::Preserved_symbol;
}

Token_ptr PreservedSymbol::consume(const std::string& str,
                                   const std::size_t& line,
                                   std::int64_t& pos,
                                   const TokenList& list) {
    std::int64_t start = pos;
    std::optional<Symbol_type> result = std::nullopt;
    std::string_view text;
    // fall through
    switch (str.length() - pos) {
        default:

        case 3: {
            pos = start + 3;
            text = std::string_view(str.begin() + start, str.begin() + pos);

            // このn文字で終わりか、n+1文字目が変数名に使える名前でない -> このトークンは3文字である
            if (str.length() <= pos + 1 || !IdentifyToken::is_identify_char(str.at(pos))) {
                if (text == "for") {
                    result = Symbol_type::kw_for;
                    break;
                }
                if (text == "var") {
                    result = Symbol_type::kw_var;
                    break;
                }
            }
        }

        case 2: {
            pos = start + 2;
            text = std::string_view(str.begin() + start, str.begin() + pos);
            if (text == "->") {
                result = Symbol_type::right_arrow;
                break;
            }
        }

        case 1: {
            pos = start + 1;
            text = std::string_view(str.begin() + start, str.begin() + pos);
            if (text == ",") {
                result = PreservedSymbol::Symbol_type::comma;
                break;
            }
            if (text == "+") {
                result = PreservedSymbol::Symbol_type::plus;
                break;
            }
            if (text == "-") {
                result = PreservedSymbol::Symbol_type::minus;
                break;
            }
            if (text == "(") {
                result = PreservedSymbol::Symbol_type::small_bracket_open;
                break;
            }
            if (text == ")") {
                result = PreservedSymbol::Symbol_type::small_bracket_close;
                break;
            }
            if (text == "*") {
                result = PreservedSymbol::Symbol_type::mlu;
                break;
            }
            if (text == "/") {
                result = PreservedSymbol::Symbol_type::div;
                break;
            }
            if (text == ".") {
                result = PreservedSymbol::Symbol_type::period;
                break;
            }
            if (text == "=") {
                result = PreservedSymbol::Symbol_type::equal;
                break;
            }
            if (text == ";") {
                result = PreservedSymbol::Symbol_type::semi_coron;
                break;
            }
        }

        case 0:pos = start;
            return nullptr;
    }
    return std::make_shared<PreservedSymbol>(text, line, start, list, result.value());
}

} // NAIL_cl::Token