#ifndef CARD_CARD_CONVERT_H
#define CARD_CARD_CONVERT_H

#include <boost/property_tree/ptree.hpp>
#include "../io/enum_translator.hpp"

namespace card{
// forward declaration
class CardData;
class CardDataList;
enum class Type;
// Type Translator
struct TypeTranslator: public io::EnumTranslator<Type>{
    // translation function
    Type to_enum(const std::string& data) const override;
    std::string to_string(const Type& data) const override;
};
// CardData -> XML property_tree
boost::property_tree::ptree to_xml_ptree(
            const CardData& card);
// CardDataList -> XML property_tree
boost::property_tree::ptree to_xml_ptree(
            const CardDataList& card_list);
// XML property_tree -> CardData
CardData load_card_xml_ptree(
            const boost::property_tree::ptree& xml_ptree);
// XML property_tree -> CardData
CardDataList load_card_list_xml_ptree(
            const boost::property_tree::ptree& xml_ptree);
}// end namespace card

namespace boost{
namespace property_tree{
// card Type Translator
template<typename Ch, typename Traits, typename Alloc>
struct translator_between<
            std::basic_string<Ch, Traits, Alloc>,
            card::Type>{
    using type = card::TypeTranslator;
};
}// end namespace property_tree
}// end namespace boost
#endif// CARD_CARD_CONVERT_H
