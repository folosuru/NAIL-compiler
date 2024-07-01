#include "IRList.hpp"

namespace NAIL_cl {
namespace backend {
void IRList::push(std::unique_ptr<IRBase>&& i) {
    list.push_back(std::move(i));
}

void IRList::push(std::vector<std::unique_ptr<IRBase>>&& li) {
    for (auto&& i : li) {
        push(std::move(i));
    }
}
} // backend
} // NAIL_cl