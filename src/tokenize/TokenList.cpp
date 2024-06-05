#include "TokenList.hpp"
#include <optional>
#include <memory>
#include <iostream>
#include <tokenize/token/Token.hpp>
#include <tokenize/token/IdentifyToken.hpp>
#include <tokenize/token/PreservedSymbol.hpp>
#include <tokenize/token/NumberToken.hpp>
#include <tokenize/token/EofToken.hpp>
namespace NAIL_cl {
    using Token_ptr = std::shared_ptr<Token::Token>;

    TokenList::TokenList(const std::vector<std::string>& text) : source_text(text) {
        std::size_t line_cnt = 0;
        for (const auto& line : source_text) {
            line_cnt++;
            std::int64_t current_pos_ = 0;
            while (current_pos_ < line.size()) {
                if (std::isspace(line[current_pos_])) {
                    current_pos_++;
                    continue;
                }
                if (push_token(Token::NumberToken::consume(line, line_cnt, current_pos_, *this))) {
                    continue;
                }
                if (push_token(Token::PreservedSymbol::consume(line, line_cnt, current_pos_, *this))) {
                    continue;
                }
                if (push_token(Token::IdentifyToken::consume(line, line_cnt, current_pos_, *this))) {
                    continue;
                }
                std::cout << "unknwon character:" << line[current_pos_]  << std::endl;
                exit(0);
            }
        }

        push_token(std::make_shared<Token::EofToken>(*this));
    }

    bool TokenList::push_token(const Token_ptr& ptr) {
        if (ptr != nullptr) {
            token_list.push_back(ptr);
            return true;
        }
        return false;
    }

    void TokenList::print() {
        for (const auto& i : token_list) {
            std::cout << "<" << Token::Token::getTypeName(i->getType()) << " \"" << i->getString() << "\">, ";
        }
        std::cout << "\n";
    }

    const std::size_t& TokenList::getCurrentPos() const {
        return current_pos;
    }

    Token_ptr TokenList::getToken(std::size_t pos) {
        if (token_list.size() <= pos) {
            return nullptr;
        }
        return token_list.at(pos);
    }

    Token_ptr TokenList::consume_current(const std::string& target) {
        auto current = getCurrent();
        if (current) {
            if (current->getString() == target) {
                current_pos++;
                return current;
            }
        }
        return nullptr;
    }

    bool TokenList::current_is(Token::TokenType type) {
        auto current = getCurrent();
        if (current) {
            if (current->getType() == type) {
                return true;
            }
        }
        return false;
    }

    void TokenList::seek_next() {
        current_pos++;
    }

    Token_ptr TokenList::consume_current(Token::TokenType target) {
        if (current_is(target)) {
            seek_next();
            return getToken(getCurrentPos() - 1);
        }
        return nullptr;
    }
} // NAIL_cl