#ifndef NAIL_CL_NODEGENERATOR_HPP
#define NAIL_CL_NODEGENERATOR_HPP
#include <nodeTree/Node.hpp>
#include <memory>
#include <tokenize/TokenList.hpp>
namespace NAIL_cl {
    class Scope;
}
namespace NAIL_cl::Node {
    // [value] + ( "(" + [assign] + ")" )?
    NodeType function_call(const std::shared_ptr<TokenList>&, const std::shared_ptr<Scope>&);

    // ( [value] ( + "." + [function_call] )*?  | "(" + [assign] + ")" )
    NodeType primary(const std::shared_ptr<TokenList>&, const std::shared_ptr<Scope>&);

    // ("+" | "-" )? + [primary]
    NodeType unary(const std::shared_ptr<TokenList>&, const std::shared_ptr<Scope>&);

    // [unary] ( ( "*" |  "/" ) + [unary] )*?
    NodeType mlu(const std::shared_ptr<TokenList>&, const std::shared_ptr<Scope>&);

    // [mlu] ( ( "+" | "-" ) [mlu] )*?
    NodeType add(const std::shared_ptr<TokenList>&, const std::shared_ptr<Scope>&);

    // [add] ( ( "==" | ">=" | "<=" | ">" | "<" ) + [add] )* ?

    // [] = [assign | add]
    NodeType assign(const std::shared_ptr<TokenList>&, const std::shared_ptr<Scope>&);

    // ([assign] | "var" + [identify] ) ;
    NodeType statement(const std::shared_ptr<TokenList>&, const std::shared_ptr<Scope>&);

    NodeType generate(const std::shared_ptr<TokenList>&);

}  // NAIL_cl::Node
#endif //NAIL_CL_NODEGENERATOR_HPP
