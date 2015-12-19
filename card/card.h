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
// Card Data List
class CardDataList{
public:
    // constructor
    explicit CardDataList(
                const std::vector<CardData>& card_list);
    // vector
    const std::vector<CardData>& vector() const;
private:
    std::vector<CardData> card_list_;
};
// iterator
std::vector<CardData>::const_iterator begin(
            const CardDataList& card_list);
std::vector<CardData>::const_iterator end(
            const CardDataList& card_list);
}// end namespace card
#endif// CARD_CARD_H
