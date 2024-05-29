#ifndef NAIL_CL_IDENTIFYNODE_HPP
#define NAIL_CL_IDENTIFYNODE_HPP
#include <nodeTree/Node.hpp>
#include <tokenize/TokenList.hpp>
#include <Symbol/ObjectBase.hpp>
#include <utility>

namespace NAIL_cl {

    class IdentifyNode : public Node_parent {
    public:
        IdentifyNode(const std::shared_ptr<Scope>& scope, std::string text, Token::Token_ptr token);

        static std::shared_ptr<Node_parent> consume(const std::shared_ptr<Scope> &scope, const std::shared_ptr<TokenList>& list);

        std::shared_ptr<VarTypeBase> getVarType() override;
    private:
        std::string str;
        std::shared_ptr<ObjectBase> symbol;
    };

} // NAIL_cl

#endif //NAIL_CL_IDENTIFYNODE_HPP
