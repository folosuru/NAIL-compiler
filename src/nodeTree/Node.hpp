#ifndef NAIL_CL_NODE_HPP
#define NAIL_CL_NODE_HPP
#include <memory>
namespace NAIL_cl {


    class Node_parent {
    public:

         virtual ~Node_parent() = default;

    };
    using NodeType = std::shared_ptr<Node_parent>;

} // NAIL_cl

#endif //NAIL_CL_NODE_HPP
