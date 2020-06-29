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
//	Point(double x, double y);
//	Point();
//	void print() const;
//	bool operator==(const Point& rhs);
} Point;
struct Polar_vector;
typedef struct Cartesian_vector {
//	Cartesian_vector(const struct Polar_vector & pv);
//	Cartesian_vector();
//	void operator=(const struct Polar_vector & pv);
	double _delta_x;
	double _delta_y;
} Cartesian_vector;
typedef struct Polar_vector {
//	Polar_vector(const Cartesian_vector & cv);
//	Polar_vector();
//	void operator=(const Cartesian_vector & cv);
	double _r;
	double _theta;
} Polar_vector;