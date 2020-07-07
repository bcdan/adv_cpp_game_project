//
// Created by dan on 29/06/2020.
//

#ifndef HW3_FARM_H
#define HW3_FARM_H


#include "Structure.h"

class Farm : public Structure {
private:
    int _amount; //farm's inventory
    int _rate; //production rate
    string _type;
public:

    Farm(int amount, int rate, Point &location, const string &name) : Structure(location, name) {
        _amount = amount;
        _rate = rate;
        _type = "Farm";
    }

    virtual int getAmount() const;

    void setAmount(int amount);

    virtual string getType() const { return _type; }

    int getRate() const { return _rate; }

    void setRate(int rate) { _rate = rate; }

    virtual void update();

    virtual void withdraw(int crates); //peasant's withdraw from farm's inventory
};


#endif //HW3_FARM_H
