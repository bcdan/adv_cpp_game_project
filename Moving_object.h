//
// Created by dan on 29/06/2020.
//

#ifndef HW3_MOVING_OBJECT_H
#define HW3_MOVING_OBJECT_H
#include "Geometry.h"

class Moving_object {
private:
    Point _location;
    Point _destination;
    int _speed;
public:
    Moving_object(Point &location, int speed): _location(location),_speed(speed){}
//    ~Moving_object();

    const Point &getLocation() const {
        return _location;
    }

    void setLocation(const Point &location) {
        _location = location;
    }

    const Point &getDestination() const {
        return _destination;
    }

    void setDestination(const Point &destination) {
        _destination = destination;
    }

    int getSpeed() const {
        return _speed;
    }

    void setSpeed(int speed) {
        _speed = speed;
    }


    void start_moving(); //virtual?
};


#endif //HW3_MOVING_OBJECT_H
