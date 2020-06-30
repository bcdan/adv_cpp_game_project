//
// Created by dan on 29/06/2020.
//

#include "Farm.h"

int Farm::getAmount() const {
        return _amount;
}

void Farm::setAmount(int amount) {
    Farm::_amount = amount;
}

void Farm::update() {
    setAmount(_amount+_rate);
}

void Farm::withdraw(int crates) {
    if(crates>_amount)
        _amount=0;
    _amount-=crates;
}





