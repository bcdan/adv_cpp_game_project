//
// Created by dan on 29/06/2020.
//

#ifndef HW3_KNIGHT_H
#define HW3_KNIGHT_H


#include "Agent.h"
#include "Structure.h"
#include <memory>
#include <vector>
#define GOD_MODE 999

class Knight : public Agent{
private:
    string _type;
    vector<shared_ptr<Structure>> visited_sites;
public:
//    virtual void update() override;
    Knight(const string& name, Point &location,int state = stopped, int health = GOD_MODE, int speed = 10) :_type("Knight"), Agent(name,health,state,location,speed){}
    //Knight(const string& name, Point &location,int state = stopped, int health = GOD_MODE, int speed = 10) : Agent(name,health,state,location,speed){}


    Point& find_nearest(); //find nearest structure to visit
    void destination(const string& site); //set destination site
    void course(double angle); //set moving course
    void position(Point dest); //set destination as point (x,y)
};


#endif //HW3_KNIGHT_H
