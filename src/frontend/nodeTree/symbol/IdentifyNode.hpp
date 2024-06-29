#ifndef NAIL_CL_IDENTIFYNODE_HPP
#define NAIL_CL_IDENTIFYNODE_HPP
#include "frontend/nodeTree/Node.hpp"
#include "frontend/tokenize/TokenList.hpp"
#include "frontend/Symbol/ObjectBase.hpp"
#include <utility>

namespace NAIL_cl {

class IdentifyNode : public Node_parent {
public:
    IdentifyNode(const std::shared_ptr<Scope>& scope, std::string text, Token::Token_ptr token);

    static std::shared_ptr<Node_parent> consume(const std::shared_ptr<Scope>& scope,
                                                const std::shared_ptr<TokenList>& list);

    std::shared_ptr<VarTypeBase> getVarType() override;

    void PolishNotation() override;

    void assign(NodeType);

private:
    std::string str;

    std::shared_ptr<Object::ObjectBase> symbol;
};

} // NAIL_cl

#endif //NAIL_CL_IDENTIFYNODE_HPP
