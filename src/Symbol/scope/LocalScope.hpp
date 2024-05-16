#ifndef NAIL_CL_LOCALSCOPE_HPP
#define NAIL_CL_LOCALSCOPE_HPP
#include <Symbol/scope/Scope.hpp>
namespace NAIL_cl {

    class LocalScope : public Scope {
    public:
        explicit LocalScope(std::weak_ptr<Scope> parent = {});
//
//        void* createFunction() override;
//
//        void* createVariable() override;
    };

} // NAIL_cl

#endif //NAIL_CL_LOCALSCOPE_HPP
