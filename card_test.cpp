#include <iostream>
#include "./card/card.h"

int main(){
    std::cout << "Card Test" << std::endl;
    
    card::CardData card(
                "ベルガモット",
                6,
                card::Type::Princess);
    std::cout << card.name() << std::endl
              << card.cost() << std::endl
              << to_string(card.type()) << std::endl;
    return 0;
}
