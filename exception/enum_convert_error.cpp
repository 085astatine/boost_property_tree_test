#include <boost/format.hpp>
#include "./enum_convert_error.h"

namespace exception{
// constructor
EnumConvertError::EnumConvertError(
            const std::string& string_data,
            const std::string& enum_name)
      : string_data_(string_data),
        enum_name_(enum_name){
    message_ = (boost::format(
                    "exception::EnumConvertError\n"
                    "    could not convert string<%1%> to %2%\n")
            % string_data_
            % enum_name_).str();
}
// show error
const char* EnumConvertError::what() const noexcept{
    return message_.data();
}
}// end namespace exception
