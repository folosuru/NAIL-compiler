#ifndef NAIL_CL_INT32NODE_HPP
#define NAIL_CL_INT32NODE_HPP
#include <nodeTree/Node.hpp>
#include <cstdint>
#include <memory>
#include "tokenize/TokenList.hpp"
#include <tokenize/token/NumberToken.hpp>

namespace NAIL_cl {

    class Int32Node : public Node_parent {
    public:
        explicit Int32Node(std::shared_ptr<Scope>, std::int32_t value, Token::Token_ptr token);;

        ~Int32Node() override = default;

        static std::shared_ptr<Node_parent> consume(std::shared_ptr<Scope>, const std::shared_ptr<TokenList>& list);

        std::shared_ptr<VarTypeBase> getVarType() override;
    private:
        std::int32_t value;
    };

} // NAIL_cl

#endif //NAIL_CL_INT32NODE_HPP
