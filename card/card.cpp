#include <iostream>
#include <sstream>
#include "./card.h"

namespace card{
// Type
// Type List
std::vector<Type> AllTypeList(){
    return {Type::Princess,
            Type::Territory,
            Type::Succession,
            Type::Action,
           };
}
// Type -> std::string
std::string to_string(
            const Type& type){
    return (type == Type::Princess)
           ? "プリンセス"
           : (type == Type::Territory)
           ? "領地"
           : (type == Type::Succession)
           ? "継承権"
           : "行動";
}
// std::string -> Type
Type to_type(
            const std::string& string_data){
    for(const Type& type: AllTypeList()){
        if(to_string(type) == string_data){
            return type;
        }
    }
}
// Card Data
// constructor
CardData::CardData(
            const std::string& name,
            const int& cost,
            const Type& type)
      : name_(name),
        cost_(cost),
        type_(type){}
// Name
const std::string& CardData::name() const{
    return name_;
}
// Cost
const int& CardData::cost() const{
    return cost_;
}
// Type
const Type& CardData::type() const{
    return type_;
}
// show
void show(const CardData& card){
    std::ostringstream ss;
    ss << "CardData" << std::endl
       << "    Name: " << card.name() << std::endl
       << "    Cost: " << card.cost() << std::endl
       << "    Type: " << to_string(card.type()) << std::endl;
    std::cout << ss.str();
}
}// end namespace card
