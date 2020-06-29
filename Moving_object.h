//
// Created by dan on 29/06/2020.
//

#ifndef HW3_MOVING_OBJECT_H
#define HW3_MOVING_OBJECT_H


class Moving_object {
private:
//    Point _location;
//    Point _destination;
    int _speed;
public:
    Moving_object();
    ~Moving_object();

//    const Point &getLocation() const;

//    void setLocation(const Point &location);

//    const Point &getDestination() const;

//    void setDestination(const Point &destination);

    int getSpeed() const;

    void setSpeed(int speed);

    void start_moving(); //virtual?
};


#endif //HW3_MOVING_OBJECT_H
