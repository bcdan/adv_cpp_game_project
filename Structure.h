//
// Created by dan on 29/06/2020.
//

#ifndef HW3_STRUCTURE_H
#define HW3_STRUCTURE_H


#include "Sim_object.h"

class Structure : public Sim_object{
private:
    Point _location;


public:
    Structure(Point& location,const string& name):_location(location),Sim_object(name){}
    virtual string getType()const{return "Structure";}
    Point get_location() const{return _location;}
    virtual void update(){}
    virtual int getAmount()const{return -1;} // virtual test
//    virutal void deposit();
    virtual void withdraw(int crates){};
};


#endif //HW3_STRUCTURE_H
