#ifndef NAIL_CL_NODEGENERATOR_HPP
#define NAIL_CL_NODEGENERATOR_HPP
#include <nodeTree/Node.hpp>
#include <memory>
#include <tokenize/TokenList.hpp>
namespace NAIL_cl::Node {
    // [value] + ( "(" + [assign] + ")" )?
    NodeType function_call(const std::shared_ptr<TokenList>&);

    // ( [value] ( + "." + [function_call] )*?  | "(" + [assign] + ")" )
    NodeType primary(const std::shared_ptr<TokenList>&);

    // ("+" | "-" )? + [primary]
    NodeType unary(const std::shared_ptr<TokenList>&);

    // [unary] ( ( "*" |  "/" ) + [unary] )*?
    NodeType mlu(const std::shared_ptr<TokenList>&);

    // [mlu] ( ( "+" | "-" ) [mlu] )*?
    NodeType add(const std::shared_ptr<TokenList>&);

    // [add] ( ( "==" | ">=" | "<=" | ">" | "<" ) + [add] )* ?

    // [] = [assign | add]
    NodeType assign(const std::shared_ptr<TokenList>&);

    // [assign] ;
    NodeType statement(const std::shared_ptr<TokenList>&);

}  // NAIL_cl
#endif //NAIL_CL_NODEGENERATOR_HPP
