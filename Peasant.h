//
// Created by dan on 29/06/2020.
//

#ifndef HW3_PEASANT_H
#define HW3_PEASANT_H
#include "Agent.h"
#define MAX_HP 20

class Peasant : public Agent{
private:
    int _inventory;
    string _type;
public:
    int getInventory() const {return _inventory;}
    string getType() const override{return _type;}


    Peasant(const string& name, Point &location,int state = stopped, int health = 10, int speed = 5) : _inventory(0),_type("Peasant"), Agent(name,health,state,location,speed){}
//    virtual void update() override;
//    void start_working(const string& farm, const string& castle);
};


#endif //HW3_PEASANT_H
