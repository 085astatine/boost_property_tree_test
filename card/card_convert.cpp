#include "./card.h"
#include "./card_convert.h"

namespace card{
// Type Translator
// translation function: std::string -> Type
Type TypeTranslator::to_enum(
            const std::string& data) const{
    return card::to_type(data);
}
// translation function: Type -> std::string
std::string TypeTranslator::to_string(
            const Type& data) const{
    return card::to_string(data);
}
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
// XML property_tree -> CardData
CardData load_card_xml_ptree(
            const boost::property_tree::ptree& xml_ptree){
    return CardData(
                xml_ptree.get<std::string>("<xmlattr>.name"),
                xml_ptree.get<int>("cost"),
                xml_ptree.get<Type>("type"));
}
// XML property_tree -> CardDataList
CardDataList load_card_list_xml_ptree(
            const boost::property_tree::ptree& xml_ptree){
    std::vector<CardData> card_list;
    if(const auto data_ptree = xml_ptree.get_child_optional("card_list")){
        for(const boost::property_tree::ptree::value_type& data: *data_ptree){
            if(data.first == "card"){
                card_list.push_back(load_card_xml_ptree(data.second));
            }
        }
    }
    return CardDataList(card_list);
}
}// end namespace card
