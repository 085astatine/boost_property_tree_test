#ifndef CARD_CARD_CONVERT_H
#define CARD_CARD_CONVERT_H

#include <boost/property_tree/ptree.hpp>

namespace card{
// forward declaration
class CardData;
class CardDataList;
// CardData -> XML property_tree
boost::property_tree::ptree to_xml_ptree(
            const CardData& card);
// CardDataList -> XML property_tree
boost::property_tree::ptree to_xml_ptree(
            const CardDataList& card_list);
}// end namespace card
#endif// CARD_CARD_CONVERT_H
