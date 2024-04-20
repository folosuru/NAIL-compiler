#include "PlusNode.hpp"
#include "SubNode.hpp"
#include "MluNode.hpp"
#include "DivNode.hpp"
#include "backend/assembly/instruction/Push.hpp"
#include "backend/assembly/instruction/Pop.hpp"
#include "backend/assembly/instruction/math/Add.hpp"
#include "backend/assembly/instruction/math/Sub.hpp"
#include "backend/assembly/instruction/math/IMlu.hpp"
#include "backend/assembly/instruction/math/IDiv.hpp"
#include <backend/assembly/instruction/Cqo.hpp>
#include <backend/assembly/operand/Register.hpp>
namespace NAIL_cl {
    void PlusNode::addAssembly(std::list<std::shared_ptr<asm_obj::instruction>> &result) {
        left->addAssembly(result);
        right->addAssembly(result);
        auto rax = std::make_shared<asm_obj::register_operand>(asm_obj::register_operand::word_name::rax,asm_obj::data_size::qword);
        auto rdi = std::make_shared<asm_obj::register_operand>(asm_obj::register_operand::word_name::rdi,asm_obj::data_size::qword);
        result.push_back(std::make_shared<asm_obj::pop>(rax));
        result.push_back(std::make_shared<asm_obj::pop>(rdi));
        result.push_back(std::make_shared<asm_obj::add>(rax, rdi));
        result.push_back(std::make_shared<asm_obj::push>(rax));
    }

    void SubNode::addAssembly(std::list<std::shared_ptr<asm_obj::instruction>> &result) {
        left->addAssembly(result);
        right->addAssembly(result);
        auto rax = std::make_shared<asm_obj::register_operand>(asm_obj::register_operand::word_name::rax,asm_obj::data_size::qword);
        auto rdi = std::make_shared<asm_obj::register_operand>(asm_obj::register_operand::word_name::rdi,asm_obj::data_size::qword);
        result.push_back(std::make_shared<asm_obj::pop>(rdi));
        result.push_back(std::make_shared<asm_obj::pop>(rax));
        result.push_back(std::make_shared<asm_obj::Sub>(rax, rdi));
        result.push_back(std::make_shared<asm_obj::push>(rax));
    }

    void MluNode::addAssembly(std::list<std::shared_ptr<asm_obj::instruction>> &result) {
        left->addAssembly(result);
        right->addAssembly(result);
        auto rax = std::make_shared<asm_obj::register_operand>(asm_obj::register_operand::word_name::rax,asm_obj::data_size::qword);
        auto rdi = std::make_shared<asm_obj::register_operand>(asm_obj::register_operand::word_name::rdi,asm_obj::data_size::qword);
        result.push_back(std::make_shared<asm_obj::pop>(rax));
        result.push_back(std::make_shared<asm_obj::pop>(rdi));
        result.push_back(std::make_shared<asm_obj::iMlu>(rax, rdi));
        result.push_back(std::make_shared<asm_obj::push>(rax));
    }

    void DivNode::addAssembly(std::list<std::shared_ptr<asm_obj::instruction>> &result) {
        left->addAssembly(result);
        right->addAssembly(result);
        auto rax = std::make_shared<asm_obj::register_operand>(asm_obj::register_operand::word_name::rax,asm_obj::data_size::qword);
        auto rdi = std::make_shared<asm_obj::register_operand>(asm_obj::register_operand::word_name::rdi,asm_obj::data_size::qword);
        result.push_back(std::make_shared<asm_obj::pop>(rdi));
        result.push_back(std::make_shared<asm_obj::pop>(rax));
        result.push_back(std::make_shared<asm_obj::cqo>());
        result.push_back(std::make_shared<asm_obj::iDiv>(rdi));
        result.push_back(std::make_shared<asm_obj::push>(rax));
    }
}