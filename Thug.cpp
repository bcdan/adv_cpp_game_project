//
// Created by dan on 29/06/2020.
//

#include "Thug.h"

void Thug::course(double angle, int speed) {
    setSpeed(speed);
    setAngle(angle);
    Agent::course(angle);
}

void Thug::position(Point dest, int speed) {
    setSpeed(speed);
    setDestination(dest);
    Agent::position(dest);
}

bool Thug::attack(const shared_ptr<Agent> &peasant) {

    double dist = getLocation().getDistance(peasant->getLocation());
    if (!inRange(peasant->getLocation())) {
        cout << "failed to attack peasant - not in range" << endl;
        return false;
    }
    if (dist > getSpeed()) {
        cout << "failed to attack peasant - not in reach" << endl;
        return false;
    }
    if (peasant->nearby_knights()) {
        cout << "failed to attack peasant - nearby nights" << endl;
        return false;
    }
    if (getHealth() < peasant->getHealth()) {
        cout << "failed to attack peasant - thug is weaker than peasant" << endl;
        return false;
    }
    setToAttackPos(peasant->getLocation());
    return true;
}

void Thug::update() {
    if (getHealth() == 0)
        setState(dead);
    if (getState() == stopped || getState() == dead)
        return;
    else if (getState() == Moving_to_destination) {
        if (getDestination() == getLocation())
            setState(stopped);
        else position(getDestination(), getSpeed());
    } else if (getState() == Moving_on_course) {
        course(getAngle(), getSpeed());
    } else if (getState() == attacking) {
        shared_ptr<Agent> peasant_target;
        bool foundPeasant = false;
        for (auto &peasant:Model::Get()._agent_list) {
            if (peasant->getName() == _target) {
                peasant_target = peasant;
                foundPeasant = true;
                break;
            }
        }
        if (!foundPeasant) {
            //todo: throw exception - > peasant not found
            cout << "Target peasant was not found" << endl;
            setState(stopped);
            return;
        }
        if (attack(peasant_target)) {
            peasant_target->resetInventory();
            peasant_target->reduceHP();
            if (peasant_target->getHealth() == 0) {
                peasant_target->setState(dead);
            } else {
                peasant_target->setState(stopped);
            }
            setState(stopped);
        } else {
            reduceHP();
            peasant_target->reduceHP();
            if (getHealth() == 0)
                setState(dead);
            else
                setState(stopped);
        }
    }
}


bool Thug::inRange(Point p) {
    double x = getLocation()._x, y = getLocation()._y;
    return x == p._x - 1 || x == p._x || x == p._x + 1 || y == p._y - 1 || y == p._y || y == p._y + 1;
}

void Thug::setToAttackPos(Point p) {
    double x = getLocation()._x, y = getLocation()._y;
    if (p._x - 1 || x == p._x || x == p._x + 1) {
        if (y > p._y)
            setLocation(Point(x, y - p._y));
        else
            setLocation(Point(x, y + p._y));
    } else if (y == p._y - 1 || y == p._y || y == p._y + 1) {
        if (x > p._x)
            setLocation(Point(x - p._x, y));
        else
            setLocation(Point(x + p._x, y));
    }
}
