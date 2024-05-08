#ifndef NAIL_CL_IDENTIFYNODE_HPP
#define NAIL_CL_IDENTIFYNODE_HPP
#include <nodeTree/Node.hpp>
#include <tokenize/TokenList.hpp>
#include <Symbol/ObjectBase.hpp>
#include <utility>

namespace NAIL_cl {

    class IdentifyNode : public Node_parent {
    public:
        explicit IdentifyNode(std::shared_ptr<Scope> scope, std::string text);

        static std::shared_ptr<Node_parent> consume(std::shared_ptr<Scope>, const std::shared_ptr<TokenList>& list);

        void addAssembly(std::list<std::shared_ptr<asm_obj::instruction>> &result) override;
    private:
        std::string str;
        std::shared_ptr<ObjectBase> symbol;
    };

} // NAIL_cl

#endif //NAIL_CL_IDENTIFYNODE_HPP
