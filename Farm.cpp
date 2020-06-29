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

int Farm::getRate() const {
    return _rate;
}

void Farm::setRate(int rate) {
    Farm::_rate = rate;
}
