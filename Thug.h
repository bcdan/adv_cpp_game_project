//
// Created by dan on 29/06/2020.
//

#ifndef HW3_THUG_H
#define HW3_THUG_H


#include "Agent.h"
#include "Peasant.h"

#define MAX_HP 20
#define MAX_SPEED 30

class Thug : public Agent{
private:
    string _type;
    bool _course;
    bool _position;
public:
    Thug(const string& name, Point &location,int state = stopped, int health = 5, int speed = 0) : _type("Thug"), Agent(name,health,state,location,speed){}
    void course(double angle, int speed); //set moving course at specified speed
    void position(Point dest, int speed); //set destination as point (x,y) at specified speed
//    virtual void update() override;
    Peasant& find_pray();//return peasant if a peasant is present in 1 k"m radius from thug, return null otherwise
    bool nearby_knights(); //returns true if a knight is in 2.5 k"m radius from thug
    void attack(Peasant& p); //preform attack on peasant
};


#endif //HW3_THUG_H
