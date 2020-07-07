//
// Created by dan on 29/06/2020.
//

#ifndef HW3_AGENT_H
#define HW3_AGENT_H


#include "Moving_object.h"
#include "Sim_object.h"
#include "View.h"
#include <memory>

enum states {stopped, dead, Moving_to_destination, Moving_on_course,working,attacking}; //current state of an agent

class Agent :  public Sim_object,public Moving_object{
private:
    int _health;
    int _state;
    double _angle;
public:
    double getAngle() const;
    void setAngle(double angle);

public:
    Agent(const string& name, int health, int state, Point &location, int speed): Sim_object(name),Moving_object(location,speed){
        _angle=0;
        _state=state;
        _health=health;

    }
    virtual void update() {}
    virtual int getInventory() const {return 0;}
    virtual string getType() const {return "Agent";}
    virtual void course(double angle); //set moving course at specified speed
    virtual void position(Point dest); //set destination as point (x,y) at specified speed
    virtual void destination(const string& ){} //set destination site - Knight only
    virtual void start_working(const string& , const string& ){}//Only for peasant
    virtual bool attack(const string& ){return false;} // only for THUG
    virtual void setTarget(const string &) {} // only for THUG
    virtual bool nearby_knights() {return false;} //returns true if a knight is in 2.5 k"m radius from thug
    virtual void resetInventory(){} // Only for PEASANT
    virtual void reduceHP() {--_health;}
    virtual Point &getLocation();


    int getHealth() const {
        return _health;
    }

    void setHealth(int health) {
        _health = health;
    }

    int getState() const {
        return _state;
    }

    void setState(int state) {
        _state = state;
    }
};


#endif //HW3_AGENT_H
