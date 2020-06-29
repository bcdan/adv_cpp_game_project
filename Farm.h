//
// Created by dan on 29/06/2020.
//

#ifndef HW3_FARM_H
#define HW3_FARM_H


class Farm {
private:
    int _amount;
    int _rate;
public:
    int getAmount() const;

    void setAmount(int amount);

    int getRate() const;

    void setRate(int rate);

//    virtual void update();
//    virutal void deposit();
//    virtual void withdraw();
};


#endif //HW3_FARM_H
