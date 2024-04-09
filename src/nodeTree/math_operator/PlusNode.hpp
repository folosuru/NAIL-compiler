#ifndef NAIL_CL_PLUSNODE_HPP
#define NAIL_CL_PLUSNODE_HPP
#include <nodeTree/Node.hpp>
#include <memory>
#include <cstdint>
#include <utility>
#include "tokenize/TokenList.hpp"
namespace NAIL_cl {

    class PlusNode : public Node_parent{

    public:
        explicit PlusNode(NodeType left, NodeType right) : left(std::move(left)), right(std::move(right)) {};

        ~PlusNode() override = default;

        static std::shared_ptr<Node_parent> create(const NodeType& left, const NodeType& right);


    private:
        NodeType left, right;
    };

} // NAIL_cl

#endif //NAIL_CL_PLUSNODE_HPP
