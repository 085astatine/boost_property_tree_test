#include <iostream>
#include "./card/card.h"

int main(){
    std::cout << "Card Test" << std::endl;
    
    card::CardData card(
                "ベルガモット",
                6,
                card::Type::Princess);
    show(card);
    return 0;
}
