//
// Created by dan on 29/06/2020.
//

#include "View.h"

View View::_IView;

void View::draw() const {
   // int y_limit = _size * _scale - _scale;
//    int y_limit = _size * _scale - _scale + _origin._y;
//    int x_limit = _size * _scale - _scale + _origin._x;
    int limit = _size * _scale - _scale;
    for (int i = limit+_origin._y, k = 0; i >= _origin._y ; i -= _scale, k++) {
        if (k % AXIS_SPACES == 0) {
            if (i > MAX_SINGLE_DIGIT)
                cout << i << " ";
            else
                cout << " " << i << " ";
        } else
            cout << "   ";

        for (int j = _origin._x; j <= limit+_origin._x; j += _scale) {
            string str = Get().elementInRange(j , i);
            if (str != "null")
                cout << str[0] << str[1];
            else
                cout << ". ";
//                cout << j << " ";

        }
        cout << endl;
    }
    cout << "   ";
    for (int i = 0, k = 0; i <= limit; i += _scale, k++) {
        if ((k + 1) % AXIS_SPACES == 0 && i + _scale > MAX_SINGLE_DIGIT) {
            cout << " " << i + _scale << " ";
            k += 1;
            i += _scale;
        } else if (k % AXIS_SPACES == 0 && i <= MAX_SINGLE_DIGIT)
            cout << i << " ";
        else
            cout << "  ";
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
    if(_scale < 0){
        //todo: throw excpt
        return;
    }
    _scale = scale;
}

void View::set_origin(Point origin) {
    _origin = origin;
}

void View::set_size(int size) {
    if(size < MIN_SIZE || size > MAX_SIZE){
        //todo: throw excpt
        return;
    }
    _size = size;
}

void View::set_defaults() {
    _origin = Point(0,0);
    _scale = DEFAULT_SCALE;
    _size = DEFAULT_SIZE;
}