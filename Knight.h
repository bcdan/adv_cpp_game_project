//
// Created by dan on 29/06/2020.
//

#ifndef HW3_KNIGHT_H
#define HW3_KNIGHT_H


#include "Agent.h"
#include "Structure.h"
#include <memory>
#include <vector>
#include "Model.h"

#define GOD_MODE 999

class Knight : public Agent{
private:
    string _type;
    //vector<shared_ptr<Structure>> visited_sites;
    vector<string> visited_sites;
public:
    virtual void update() override;
    Knight(const string& name, Point &startingLocation,int state = stopped, int health = GOD_MODE, int speed = 10) :_type("Knight"), Agent(name,health,state,startingLocation,speed){visited_sites.emplace_back(Model::Get().get_objName_by_point(startingLocation));}
    //Knight(const string& name, Point &location,int state = stopped, int health = GOD_MODE, int speed = 10) : Agent(name,health,state,location,speed){}


    Point find_nearest(); //find nearest structure to visit
    virtual void destination(const string& site); //set destination site
    bool hasVisited(const string& toVisit)const;
    bool allVisited()const;

    virtual string getType() const {return _type;}


};


#endif //HW3_KNIGHT_H
