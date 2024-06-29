#ifndef NAIL_CL_INT32NODE_HPP
#define NAIL_CL_INT32NODE_HPP
#include "frontend/nodeTree/Node.hpp"
#include <cstdint>
#include <memory>
#include "frontend/tokenize/TokenList.hpp"
#include "frontend/tokenize/token/NumberToken.hpp"

namespace NAIL_cl {

class Int32Node : public Node_parent {
public:
    explicit Int32Node(std::shared_ptr<Scope>, std::int32_t value, Token::Token_ptr token);;

    ~Int32Node() override = default;

    static std::shared_ptr<Node_parent> consume(std::shared_ptr<Scope>, const std::shared_ptr<TokenList>& list);

    std::shared_ptr<VarTypeBase> getVarType() override;

    void PolishNotation() override;

private:
    std::int32_t value;
};

} // NAIL_cl

#endif //NAIL_CL_INT32NODE_HPP
