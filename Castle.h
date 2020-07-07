//
// Created by dan on 29/06/2020.
//

#ifndef HW3_CASTLE_H
#define HW3_CASTLE_H


#include "Structure.h"

class Castle : public Structure {
private:
    int _amount; //castle's current inventory
    string _type; // type of structure
public:
    Castle(int amount, Point &location, const string &name) : Structure(location, name) {
        _type = "Castle";
        _amount = amount;
    }

    virtual int getAmount() const;

    void setAmount(int amount);

    void update() override {}

    string getType() const override { return _type; }

    virtual void deposit(int crates);
};


#endif //HW3_CASTLE_H
