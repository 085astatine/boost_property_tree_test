#ifndef IO_ENUM_TRANSLATOR_HPP
#define IO_ENUM_TRANSLATOR_HPP

#include <iostream>
#include <boost/property_tree/ptree.hpp>
#include "../exception/enum_convert_error.h"

namespace io{
template<typename T>
struct EnumTranslator{
    // type
    using internal_type = boost::property_tree::ptree::data_type;
    using external_type = T;
    // tlanslator
    virtual external_type to_enum(const internal_type& data) const = 0;
    virtual internal_type to_string(const external_type& data) const = 0;
    // property_tree -> T
    boost::optional<external_type> get_value(
                const internal_type& data) const{
        try{
            const external_type value = to_enum(data);
            return value;
        }catch(const exception::EnumConvertError& e){
            std::cerr << e.what() << std::endl;
            return boost::none;
        }
    }
    // T -> property_tree
    boost::optional<internal_type> put_value(
                const external_type& data) const{
        return to_string(data);
    }
};
}// end namespace io
#endif// IO_ENUM_TRANSLATOR_HPP
