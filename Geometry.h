#ifndef HW3_GEOMETRY_H
#define HW3_GEOMETRY_H
#include <iostream>
#include <iomanip>
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
} Point;
//struct Polar_vector;
//typedef struct Cartesian_vector {
//	Cartesian_vector(const struct Polar_vector & pv);
//	Cartesian_vector();
//	void operator=(const struct Polar_vector & pv);
//	double _delta_x;
//	double _delta_y;
//} Cartesian_vector;
//typedef struct Polar_vector {
//	Polar_vector(const Cartesian_vector & cv);
//	Polar_vector();
//	void operator=(const Cartesian_vector & cv);
//	double _r;
//	double _theta;
//} Polar_vector;

#endif //HW3_GEOMETRY_H
