#ifndef NAIL_CL_BLOCKNODE_HPP
#define NAIL_CL_BLOCKNODE_HPP
#include <nodeTree/Node.hpp>
#include <vector>
namespace NAIL_cl {

    class BlockNode : public Node_parent {
    public:
        BlockNode(std::shared_ptr<Scope>);
        ~BlockNode() override = default;
        void addChild(const NodeType&);
    private:
        std::vector<NodeType> child;
    };

} // NAIL_cl

#endif //NAIL_CL_BLOCKNODE_HPP
