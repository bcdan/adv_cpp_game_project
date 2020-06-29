//
// Created by dan on 29/06/2020.
//

#ifndef HW3_CASTLE_H
#define HW3_CASTLE_H


#include "Structure.h"

class Castle : public Structure{
private:
    int _amount;
public:
    Castle(int amount,Point& location,const string& name):_amount(amount),Structure(location,name){}
    virtual int getAmount() const;

    void setAmount(int amount);

    virtual void update(){
        cout << "ani be castle" << endl;
    };
//    virutal void deposit();
//    virtual void withdraw();
};


#endif //HW3_CASTLE_H
