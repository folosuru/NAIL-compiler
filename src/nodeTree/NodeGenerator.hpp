#ifndef NTSL_CL_NODEGENERATOR_HPP
#define NTSL_CL_NODEGENERATOR_HPP
#include <nodeTree/Node.hpp>
#include <memory>
#include <tokenize/TokenList.hpp>
namespace NTSL_cl::Node {
    NodeType primary(const std::shared_ptr<TokenList>&);

    NodeType add(const std::shared_ptr<TokenList>&);
}  // NTSL_cl
#endif //NTSL_CL_NODEGENERATOR_HPP
