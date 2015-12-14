#include "./card.h"

namespace card{
// Card Data
// constructor
CardData::CardData(
            const std::string& name,
            const int& cost)
      : name_(name),
        cost_(cost){}
// name
const std::string& CardData::name() const{
    return name_;
}
// cost
const int& CardData::cost() const{
    return cost_;
}
}// end namespace card
