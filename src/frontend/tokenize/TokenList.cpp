#include "TokenList.hpp"
#include <optional>
#include <memory>
#include <iostream>
#include <frontend/tokenize/token/Token.hpp>
#include <frontend/tokenize/token/IdentifyToken.hpp>
#include <frontend/tokenize/token/PreservedSymbol.hpp>
#include <frontend/tokenize/token/NumberToken.hpp>
#include <frontend/tokenize/token/EofToken.hpp>
#include <frontend/Printer/Dump.hpp>

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
            std::cout << "unknwon character:" << line[current_pos_] << std::endl;
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
    Printer::Dump_list("TOKEN DUMP", token_list, [](const Token_ptr& i) {
        return std::string(Token::Token::getTypeName(i->getType())) + " \"" + std::string(i->getString()) + "\"";
    });
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