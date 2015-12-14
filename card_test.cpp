#include <iostream>
#include "./card/card.h"

int main(){
    std::cout << "Card Test" << std::endl;
    
    card::CardData card(
                "ベルガモット",
                6);
    std::cout << card.name() << std::endl
              << card.cost() << std::endl;
    return 0;
}
