//
// Created by dan on 29/06/2020.
//

#ifndef HW3_PEASANT_H
#define HW3_PEASANT_H
#include "Agent.h"
#include "Model.h"

#define MAX_HP 20
#define MAX_INV 5
class Peasant : public Agent{
private:
    int _inventory;
    string _type;
    Point _farmSrc;
    bool _reachedFarm;//false -> on the way to farm , true -> on the way to castle (working mode)
public:
    int getInventory() const {return _inventory;}
    string getType() const override{return _type;}

    Peasant(const string& name, Point &startingLocation,int state = stopped, int health = 10, int speed = 5) : _inventory(0),_type("Peasant"),_reachedFarm(false), Agent(name,health,state,startingLocation,speed){}
    virtual void update() override;
    void start_working(const string& farm, const string& castle);
    void load(int crates,shared_ptr<Structure>farm);
    const Point &getFarmSrc() const;
};


#endif //HW3_PEASANT_H
