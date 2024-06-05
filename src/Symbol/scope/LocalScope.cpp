#include "LocalScope.hpp"
#include <Symbol/object/LocalVariable.hpp>
#include <Printer/ErrorPrinter.hpp>
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
    std::shared_ptr<Object::ObjectBase> LocalScope::createVariable(Token::Token_ptr word_ptr) {
        VarType type = nullptr;
        auto obj = std::make_shared<NAIL_cl::Object::LocalVariable>(word_ptr, type);
        symbol.insert({
            std::string(word_ptr->getString()),
            obj
        });
        return obj;
    }

    LocalScope::LocalScope(std::weak_ptr<Scope> parent) : Scope(std::move(parent)) {

    }
} // NAIL_cl