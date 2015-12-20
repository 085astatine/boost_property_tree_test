#include <iostream>
#include "./io/xml.h"
#include "./card/card.h"
#include "./card/card_convert.h"

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
    return 0;
}
