#ifndef HW3_GEOMETRY_H
#define HW3_GEOMETRY_H
#include <iostream>
#include <iomanip>
#include <cmath>
#define INVALID_POINT 999999
using namespace std;
// angle units conversion functions
double to_radians(double theta_d);
double to_degrees(double theta_r);
// class declarations
typedef struct Point {
	double _x;
	double _y;
	Point(double x, double y):_x(x),_y(y){}
	Point():_x(0),_y(0){}
	void print() const{
	    cout<<"("<<_x<<","<<_y<<")";
	}
	bool operator==(const Point& rhs) const{return _x==rhs._x && _y==rhs._y;
	};
	double getDistance(const Point& b) const{
        return abs(sqrt(pow(this->_x-b._x,2)+pow(this->_y-b._y,2)));
    }
} Point;


#endif //HW3_GEOMETRY_H
