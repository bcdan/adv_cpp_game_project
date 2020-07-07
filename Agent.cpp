
#include "Agent.h"

void Agent::course(double angle) {
    setState(Moving_on_course);
    setAngle(angle);
    if (angle == 0) {
        setLocation(Point(getLocation()._x, getLocation()._y + getSpeed()));
        View::Get().update_location(getName(),getLocation());
    } else if (angle == 90) {
        setLocation(Point(getLocation()._x + getSpeed(), getLocation()._y));
        View::Get().update_location(getName(),getLocation());
    } else if (angle == 180) {
        setLocation(Point(getLocation()._x, getLocation()._y - getSpeed()));
        View::Get().update_location(getName(),getLocation());
    } else if (angle == 270) {
        setLocation(Point(getLocation()._x - getSpeed(), getLocation()._y));
        View::Get().update_location(getName(),getLocation());
    } else {
        throw Exceptions::InputException("Invalid angle\n");
    }

}

void Agent::position(Point dest) {
    if (dest._x == getLocation()._x && dest._y == getLocation()._y)
        return;
    double diffX = dest._x - getLocation()._x;
    double diffY = dest._y - getLocation()._y;
    double distX = abs(dest._x - getLocation()._x);
    double distY = abs(dest._y - getLocation()._y);
    if (diffX != 0) { // while both xs' are different
        if (diffX < 0) {// go left on X
            if (distX <= getSpeed()) {
                setLocation(Point(getLocation()._x - distX, getLocation()._y));
                View::Get().update_location(getName(),getLocation());
            } else {
                setLocation(Point(getLocation()._x - getSpeed(), getLocation()._y));
                View::Get().update_location(getName(),getLocation());
            }
        } else {//go right on X
            if (distX <= getSpeed()) {
                setLocation(Point(getLocation()._x + distX, getLocation()._y));
                View::Get().update_location(getName(),getLocation());
            } else {
                setLocation(Point(getLocation()._x + getSpeed(), getLocation()._y));
                View::Get().update_location(getName(),getLocation());
            }
        }
    } else {//both xs' are aligned , move on Y axis
        if (diffY < 0) {// go down on Y
            if (distY <= getSpeed()) {
                setLocation(Point(getLocation()._x, getLocation()._y - distY));
                View::Get().update_location(getName(),getLocation());
            } else {
                setLocation(Point(getLocation()._x, getLocation()._y - getSpeed()));
                View::Get().update_location(getName(),getLocation());
            }
        } else {//go down on Y
            if (distY <= getSpeed()) {
                setLocation(Point(getLocation()._x, getLocation()._y + distY));
                View::Get().update_location(getName(),getLocation());
            } else {
                setLocation(Point(getLocation()._x, getLocation()._y + getSpeed()));
                View::Get().update_location(getName(),getLocation());
            }
        }

    }
}

double Agent::getAngle() const {
    return _angle;
}

void Agent::setAngle(double angle) {
    _angle = angle;
}

Point &Agent::getLocation() {
    return Moving_object::getLocation();
}
