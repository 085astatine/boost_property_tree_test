#include <iostream>
#include "./io/xml.h"
#include "./card/card.h"
#include "./card/card_convert.h"
#include "./exception/enum_convert_error.h"

int main(){
    std::cout << "Card Test" << std::endl;
    
    const card::CardDataList card_list(
                std::vector<card::CardData>{
                    {"ベルガモット",
                     6,
                     card::Type::Princess},
                    {"見習い侍女",
                     2,
                     card::Type::Succession}});
    for(const auto& data: card_list){
        show(data);
    }
    io::save_xml(
                "test_output.xml",
                card::to_xml_ptree(card_list));
    try{
        const card::Type type = card::to_type("hoge");
        std::cout << to_string(type) << std::endl;
    }catch(const exception::EnumConvertError& e){
        std::cout << "catch" << std::endl;
        std::cerr << e.what();// << std::endl;
    }
    const boost::property_tree::ptree card_list_ptree =
                card::to_xml_ptree(card_list);
    for(const auto& card: card::load_card_list_xml_ptree(card_list_ptree)){
        show(card);
    }
    return 0;
}
