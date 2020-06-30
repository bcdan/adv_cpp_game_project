//
// Created by dan on 29/06/2020.
//

#ifndef HW3_CASTLE_H
#define HW3_CASTLE_H


#include "Structure.h"

class Castle : public Structure{
private:
    int _amount;
    string _type;
public:
    Castle(int amount,Point& location,const string& name):_amount(amount),_type("Castle"),Structure(location,name){}
    virtual int getAmount() const;

    void setAmount(int amount);

    void update() override {}

    string getType()const override{return _type;}
    virtual void deposit(int crates);
//    virtual void withdraw();
};


#endif //HW3_CASTLE_H
