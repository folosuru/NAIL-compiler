#ifndef NAIL_CL_NODEGENERATOR_HPP
#define NAIL_CL_NODEGENERATOR_HPP
#include <nodeTree/Node.hpp>
#include <memory>
#include <tokenize/TokenList.hpp>
namespace NAIL_cl::Node {
    NodeType primary(const std::shared_ptr<TokenList>&);

    NodeType add(const std::shared_ptr<TokenList>&);
}  // NAIL_cl
#endif //NAIL_CL_NODEGENERATOR_HPP
