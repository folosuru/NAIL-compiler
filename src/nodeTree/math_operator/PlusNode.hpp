#ifndef NTSL_CL_PLUSNODE_HPP
#define NTSL_CL_PLUSNODE_HPP
#include <nodeTree/Node.hpp>
#include <memory>
#include <cstdint>
#include <utility>
#include "tokenize/TokenList.hpp"
namespace NTSL_cl {

    class PlusNode : public Node_parent{

    public:
        explicit PlusNode(NodeType left, NodeType right) : left(std::move(left)), right(std::move(right)) {};

        ~PlusNode() override = default;

        static std::shared_ptr<Node_parent> create(const NodeType& left, const NodeType& right);


    private:
        NodeType left, right;
    };

} // NTSL_cl

#endif //NTSL_CL_PLUSNODE_HPP
