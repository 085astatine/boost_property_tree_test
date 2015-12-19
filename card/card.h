#ifndef CARD_CARD_H
#define CARD_CARD_H

#include <string>
#include <vector>

namespace card{
// Type
enum class Type{
    Princess,
    Territory,
    Succession,
    Action,
};
// Type List
std::vector<Type> AllTypeList();
// Type -> std::string
std::string to_string(
            const Type& type);
// std::string -> Type
Type to_type(
            const std::string& string_data);
// Card Data
class CardData{
public:
    // constructor
    CardData(const std::string& name,
             const int& cost,
             const Type& type);
    // Name
    const std::string& name() const;
    // Cost
    const int& cost() const;
    // Type
    const Type& type() const;
private:
    std::string name_;
    int cost_;
    Type type_;
};
// show
void show(const CardData& card);
}// end namespace card
#endif// CARD_CARD_H
