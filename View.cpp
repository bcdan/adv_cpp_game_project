//
// Created by dan on 29/06/2020.
//

#include "View.h"

View View::_IView;


void View::draw() const {
    int limit = _size * _scale - _scale;
    for (int i = limit + _origin._y, k = 0; i >= _origin._y; i -= _scale, k++) {
        if (k % AXIS_SPACES == 0) {
            if (abs(i) > MAX_DOUBLE_DIGIT) { //3 digits
                if (i < 0) { // if 3 digits with minus ex. -400
                    cout << "" << i << " ";
                } else { // ex. 400
                    cout << " " << i << " ";
                }
            } else if (abs(i) > MAX_SINGLE_DIGIT) { // 2 digits
                if (i < 0) { // if 2 digits with minus ex. -30
                    cout << " " << i << " ";
                } else { // ex. 30
                    cout << "  " << i << " ";
                }
            } else {
                if (i < 0) {
                    cout << "  " << i << " ";

                } else {
                    cout << "   " << i << " ";
                }
            }
        } else
            cout << "     ";

        for (int j = _origin._x; j <= limit + _origin._x; j += _scale) {
            string str = Get().elementInRange(j, i);
            if (str != "null")
                cout << str[0] << str[1];
            else
                cout << ". ";
        }
        cout << endl;
    }
    for (int i = _origin._x, k = 0; i <=limit+_origin._x; i += _scale, k++) {
        if (k % AXIS_SPACES == 0) { //print first number in x axis
            if(abs(i) <= MAX_SINGLE_DIGIT){ //single
                if(i < 0)
                    cout << "    " << i;
                else
                    cout << "     " << i;
            }
            else if(abs(i) > MAX_DOUBLE_DIGIT){ //triple
                if(i < 0)
                    cout << "  " << i;
                else
                    cout << "   " << i;
            }
            else if(abs(i) > MAX_SINGLE_DIGIT){ //double
                if(i < 0 )
                    cout << "   " << i;
                else
                    cout << "    " << i;
            }
        } else if ((k + 1) % AXIS_SPACES == 0) { //print all numbers in X axis
            if (abs(i + _scale) > MAX_DOUBLE_DIGIT) {
                if (i < 0) {
                    cout << "  " << i + _scale;
                } else {
                    cout << "   " << i + _scale;
                }
            } else if (abs(i + _scale) > MAX_SINGLE_DIGIT) {
                if (i < 0) {
                    cout << "   " << i + _scale;
                } else {
                    cout << "    " << i + _scale;
                }
            } else {
                if (i < 0) {
                    cout << "    " << i + _scale;
                } else {
                    cout << "     " << i + _scale;
                }
            }
            k += 1;
            i += _scale;
        }
    }
    cout << endl;

}


void View::update_location(const string &name, Point location) {
    for (auto &elem : _db) {
        if (elem.first == name) {
            elem.second = location;
            return;
        }
    }
    _db.insert(pair<string, Point>(name, location));
}

void View::update_remove(const string &name) {
    _db.erase(name);
}

string View::elementInRange(int i, int j) {
    for (auto &element : _db) {
        if (element.second._x >= i && element.second._x < (i + _scale) && element.second._y >= j &&
            element.second._y < (j + _scale))
            return element.first;
    }
    return "null";
}

void View::set_zoom(double scale) {
    if (scale < 0) {
        //todo: throw excpt
        return;
    }
    _scale = scale;
}

void View::set_origin(Point origin) {
    _origin = origin;
}

void View::set_size(int size) {
    if (size < MIN_SIZE || size > MAX_SIZE) {
        //todo: throw excpt
        return;
    }
    _size = size;
}

void View::set_defaults() {
    _origin = Point(0, 0);
    _scale = DEFAULT_SCALE;
    _size = DEFAULT_SIZE;
}