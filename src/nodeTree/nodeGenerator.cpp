#include <nodeTree/NodeGenerator.hpp>
#include <nodeTree/NodeIncludeList.hpp>
#include <error/ErrorPrinter.hpp>
namespace NAIL_cl::Node {
    NodeType primary(const std::shared_ptr<TokenList>& list) {
        if (auto number = Int32Node::consume(list); number != nullptr) {
            return number;
        }
        ErrorPrinter::print(list, list->getCurrent(), "unexpected token");
    }
    NodeType add(const std::shared_ptr<TokenList>& list) {
        NodeType left = primary(list);

    }
}