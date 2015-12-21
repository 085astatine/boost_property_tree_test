#include <iostream>
#include "./io/xml.h"
#include "./card/card.h"
#include "./card/card_convert.h"
#include "./exception/enum_convert_error.h"

int main(){
    std::cout << "XML Test" << std::endl;
    
    const boost::property_tree::ptree xml_ptree =
                io::load_xml("input.xml");
    const card::CardDataList card_list =
                card::load_card_list_xml_ptree(xml_ptree);
    for(const auto& data: card_list){
        show(data);
    }
    io::save_xml(
                "xml_test_output.xml",
                card::to_xml_ptree(card_list));
    return 0;
}
