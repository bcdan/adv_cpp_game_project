
#include "Agent.h"

void Agent::course(double angle) {
    setState(Moving_on_course);
    setAngle(angle);
    if (angle == 0) {
        setLocation(Point(getLocation()._x, getLocation()._y + getSpeed()));
    } else if (angle == 90) {
        setLocation(Point(getLocation()._x + getSpeed(), getLocation()._y));

    } else if (angle == 180) {
        setLocation(Point(getLocation()._x, getLocation()._y - getSpeed()));

    } else if (angle == 270) {
        setLocation(Point(getLocation()._x - getSpeed(), getLocation()._y));

    } else {
        cout << "invalid angle" << endl; // todo: exception
    }

}

void Agent::position(Point dest) {
    if (dest._x == getLocation()._x && dest._y == getLocation()._y)
        return;
    double diffX = dest._x - get_location()._x, diffY = dest._y - get_location()._y, distX = abs(
            dest._x - getLocation()._x), distY = abs(dest._y - getLocation()._y);
    if (diffX != 0) { // while both xs' are different
        if (diffX < 0) {// go left on X
            if (distX <= getSpeed()) {
                setLocation(Point(getLocation()._x - distX, getLocation()._y));
            } else {
                setLocation(Point(getLocation()._x - getSpeed(), getLocation()._y));

            }
        } else {//go right on X
            if (distX <= getSpeed()) {
                setLocation(Point(getLocation()._x + distX, getLocation()._y));
            } else {
                setLocation(Point(getLocation()._x + getSpeed(), getLocation()._y));

            }
        }

    } else {//both xs' are aligned , move on Y axis
        if (diffY < 0) {// go down on Y
            if (distY <= getSpeed()) {
                setLocation(Point(getLocation()._x, getLocation()._y - distY));
            } else {
                setLocation(Point(getLocation()._x, getLocation()._y - getSpeed()));

            }
        } else {//go down on Y
            if (distY <= getSpeed()) {
                setLocation(Point(getLocation()._x, getLocation()._y + distX));
            } else {
                setLocation(Point(getLocation()._x, getLocation()._y + getSpeed()));

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
