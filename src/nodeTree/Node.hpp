#ifndef NTSL_CL_NODE_HPP
#define NTSL_CL_NODE_HPP
#include <memory>
namespace NTSL_cl {


    class Node_parent {
    public:

         virtual ~Node_parent() = default;

    };
    using NodeType = std::shared_ptr<Node_parent>;

} // NTSL_cl

#endif //NTSL_CL_NODE_HPP
