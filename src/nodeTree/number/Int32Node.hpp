#ifndef NTSL_CL_INT32NODE_HPP
#define NTSL_CL_INT32NODE_HPP
#include <nodeTree/Node.hpp>
#include <cstdint>
#include <memory>
#include "tokenize/TokenList.hpp"
#include <tokenize/token/NumberToken.hpp>

namespace NTSL_cl {

    class Int32Node : public Node_parent {
    public:
        explicit Int32Node(std::int32_t value) : value(value) {};

        ~Int32Node() override = default;

        static std::shared_ptr<Node_parent> consume(const std::shared_ptr<TokenList>& list);

    private:
        std::int32_t value;
    };

} // NTSL_cl

#endif //NTSL_CL_INT32NODE_HPP
