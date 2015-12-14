#ifndef CARD_CARD_H
#define CARD_CARD_H

#include <string>

namespace card{
// Card Data
class CardData{
public:
    // constructor
    CardData(const std::string& name,
             const int& cost);
    // name
    const std::string& name() const;
    // cost
    const int& cost() const;
private:
    std::string name_;
    int cost_;
};
}// end namespace card
#endif// CARD_CARD_H
