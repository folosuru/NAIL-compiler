#ifndef NAIL_CL_SCOPE_HPP
#define NAIL_CL_SCOPE_HPP
#include <memory>
#include <utility>
#include <unordered_map>
#include <Symbol/ObjectBase.hpp>
#include <vector>
#include <nodeTree/Node.hpp>
#include <tokenize/token/Token.hpp>

namespace NAIL_cl {
    class Scope;
    class IdentifyNode;
    class Scope {
    public:
        explicit Scope(std::weak_ptr<Scope> parent = {}) : parent(std::move(parent)) {

        }
//
        virtual std::shared_ptr<Object::ObjectBase> createVariable(Token::Token_ptr word_ptr) = 0;
//
//        virtual void* createFunction() = 0;
//
        // あくまでスコープを解決する = only call in resolve "::"
        // std::shared_ptr<Scope> resolve_scope(std::string );

        std::shared_ptr<Object::ObjectBase> resolve_object(const std::string&);

        bool exist_object(const std::string&);

    protected:
        [[nodiscard]]
        std::weak_ptr<Scope> getParent() const noexcept;

        std::unordered_map<std::string, std::shared_ptr<Object::ObjectBase>> symbol;

        std::vector<std::shared_ptr<IdentifyNode>> child_node;
    private:
        std::weak_ptr<Scope> parent;

    };
}

#endif //NAIL_CL_SCOPE_HPP
