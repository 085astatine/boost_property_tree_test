#include "./card.h"
#include "./card_convert.h"

namespace card{
// CardData -> XML property_tree
boost::property_tree::ptree to_xml_ptree(
            const CardData& card){
    boost::property_tree::ptree ptree;
    ptree.put("card.<xmlattr>.name", card.name());
    ptree.put("card.cost", card.cost());
    ptree.put("card.type", to_string(card.type()));
    return ptree;
}
// CardDataList -> XML property_tree
boost::property_tree::ptree to_xml_ptree(
            const CardDataList& card_list){
    boost::property_tree::ptree card_list_ptree;
    for(const CardData& card: card_list){
        boost::property_tree::ptree card_ptree = to_xml_ptree(card);
        card_list_ptree.insert(
                card_list_ptree.end(),
                card_ptree.begin(),
                card_ptree.end());
    }
    boost::property_tree::ptree ptree;
    ptree.add_child("card_list", card_list_ptree);
    return ptree;
}
}// end namespace card
