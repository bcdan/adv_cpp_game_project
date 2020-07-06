//
// Created by dan on 29/06/2020.
//

#ifndef HW3_VIEW_H
#define HW3_VIEW_H


#include <string>
#include <iostream>
#include <map>
#include "Geometry.h"
using namespace std;
#define MAX_SIZE 30
#define MIN_SIZE 6
#define DEFAULT_SIZE 25
#define DEFAULT_SCALE 2.0
#define MEASURE 10
#define AXIS_SPACES 3
#define MAX_SINGLE_DIGIT 9

/* View object
The View class encapsulates the data and functions needed to generate the map display, and control its properties. It has a "memory" for the names and locations of the to-be-plotted objects.

Usage:
1. Call the update_location function with the name and position of each object to be plotted. If the object is not already in the View's memory, it will be added along with its location. If it is already present, its location will be set to the supplied location. If a single object changes location, its location can be separately updated with a call to update_location.

2. Call the update_remove function with the name of any object that should no longer be plotted. This must be done *after* any call to update_location that has the same object name since update_location will add any object name supplied.

3. Call the draw function to print out the map.

4. As needed, change the origin, scale, or displayed size of the map with the appropriate functions. Since the view "remembers" the previously updated information, immediately calling the draw function will print out a map showing the previous objects using the new settings.
*/

class View {
private:
    View(int size=DEFAULT_SIZE, double scale = DEFAULT_SCALE) :_size(size),_scale(scale), _origin(Point(0,0)){}//default ctor: sets the default size, scale, and origin, outputs constructor message
    int _size;
    double _scale;
    Point _origin;
    map<string, Point> _db; //data base of 'view' - holds couples of string & point
    static View _IView;
public:
    View(const View &) = delete; //disable copy c-tor

    static View &Get() {
        return _IView;
    }


//     dtor
//    ~View();

//     Saves the supplied name and location for future use in a draw() call
//     If the name is already present,the new location replaces the previous one.
    void update_location(const std::string &name, Point location);

//     Removes the name and its location; no error if the name is not present.
    void update_remove(const std::string &name);

//     prints out the current map
    void draw() const;

//    Modifies the display parameters:
//    If the size is out of bounds will throw excpt

//     If scale is not positive, will throw excpt
    void set_size(int size);

    void set_zoom(double scale);

//     Any values are legal for the origin
    void set_origin(Point origin);

//     Sets the parameters to the default values
    void set_defaults();

    string elementInRange(int i,int j);
};

#endif //HW3_VIEW_H
