//
// Created by dan on 29/06/2020.
//

#ifndef HW3_FARM_H
#define HW3_FARM_H


#include "Structure.h"

class Farm : public Structure {
private:
    int _amount;
    int _rate;
public:

    Farm(int amount, int rate, Point &location, const string &name) : _amount(amount), _rate(rate),
                                                                      Structure(location, name) {}

    virtual int getAmount() const;

    void setAmount(int amount);

    int getRate() const { return _rate; }

    void setRate(int rate) { _rate = rate; }

//    virtual void update();
//    virutal void deposit();
//    virtual void withdraw();
};


#endif //HW3_FARM_H
