#ifndef NAIL_CL_SCOPE_HPP
#define NAIL_CL_SCOPE_HPP
#include <memory>
#include <utility>
#include <unordered_map>
#include <Symbol/IdentifySymbol.hpp>
#include <vector>
namespace NAIL_cl {
    class Scope;
    class IdentifyNode;
    class Scope {
    public:
        explicit Scope(std::weak_ptr<Scope> parent = {}) : parent(std::move(parent)) {

        }

        //void resolve_scope();

    protected:
        [[nodiscard]]
        std::weak_ptr<Scope> getParent() const noexcept;

    private:
        std::weak_ptr<Scope> parent;

        std::unordered_map<std::string, std::shared_ptr<IdentifySymbol>> symbol;

        std::vector<std::shared_ptr<IdentifyNode>> child_node;
    };
}

#endif //NAIL_CL_SCOPE_HPP
