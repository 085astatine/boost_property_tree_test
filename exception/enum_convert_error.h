#ifndef EXCEPTION_ENUM_COMVERT_ERROR_H
#define EXCEPTION_ENUM_COMVERT_ERROR_H

#include <exception>
#include <string>

namespace exception{
class EnumConvertError: public std::exception{
public:
    // constructor
    EnumConvertError(
                const std::string& string_data,
                const std::string& enum_name);
    // show error
    const char* what() const noexcept override;
private:
    // parameter
    std::string string_data_;
    std::string enum_name_;
    // error message
    std::string message_;
};
}// end namespace exception
#endif// EXCEPTION_ENUM_COMVERT_ERROR_H
