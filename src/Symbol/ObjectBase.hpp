#ifndef NAIL_CL_OBJECTBASE_HPP
#define NAIL_CL_OBJECTBASE_HPP
#include <string_view>
#include <string>
namespace NAIL_cl {

    class ObjectBase {
    public:
        [[nodiscard]]
        const std::string& getName() const;

        explicit ObjectBase(std::string);
    private:
        std::string name;
    };

} // NAIL_cl

#endif //NAIL_CL_OBJECTBASE_HPP
