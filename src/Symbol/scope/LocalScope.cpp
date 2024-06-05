#include "LocalScope.hpp"
#include <error/ErrorPrinter.hpp>
#include <utility>
#include <Symbol/object/LocalVariable.hpp>
namespace NAIL_cl {
//    void* LocalScope::createFunction() {
//
//    }
//
//    void *LocalScope::createVariable() {
//
//    }
    void *LocalScope::createVariable(Token::Token_ptr word_ptr) {
        VarType type = nullptr;
        symbol.insert({
            std::string(word_ptr->getString()),
            std::make_shared<LocalVariable>(word_ptr, type)
        });
        return 0;
    }

    LocalScope::LocalScope(std::weak_ptr<Scope> parent) : Scope(std::move(parent)) {

    }
} // NAIL_cl