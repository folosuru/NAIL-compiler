#ifndef NAIL_CL_TOKENUTILITY_HPP
#define NAIL_CL_TOKENUTILITY_HPP
#include "TokenList.hpp"

namespace NAIL_cl::TokenUtil {
template<class T>
std::shared_ptr<T> consume_current(const std::shared_ptr<TokenList>& list) {
    if (T::static_type == list->getCurrent()->getType()) {
        auto v = std::reinterpret_pointer_cast<T>(list->getCurrent());
        list->seek_next();
        return v;
    }
    return nullptr;
}
}
#endif //NAIL_CL_TOKENUTILITY_HPP
