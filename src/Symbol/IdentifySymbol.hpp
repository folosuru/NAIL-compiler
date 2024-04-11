#ifndef NAIL_CL_IDENTIFYSYMBOL_HPP
#define NAIL_CL_IDENTIFYSYMBOL_HPP
#include <string_view>
namespace NAIL_cl {

    class IdentifySymbol {
    public:
        const std::string& getName() const;

        explicit IdentifySymbol(std::string);
    private:
        std::string name;

    };

} // NAIL_cl

#endif //NAIL_CL_IDENTIFYSYMBOL_HPP
