//
// Created by dan on 29/06/2020.
//

#ifndef HW3_MODEL_H
#define HW3_MODEL_H

#include <vector>
#include <memory>
#include <iostream>
#include "Sim_object.h"
#include "Structure.h"
#include "Agent.h"
#include "View.h"
#include "Castle.h"
#include <sstream>


using namespace std;

class Model {
private:
    View* _view;
    Model() {time=0;}
    static Model _IModel;
public:
    Model(const Model&) =delete; //disable copy c-tor

    static Model& Get(){
        return _IModel;
    }

    int time;
    vector<shared_ptr<Sim_object>> _sim_object_list;
    vector<shared_ptr<Structure>> _structure_list;
    vector<shared_ptr<Agent>> _agent_list;
    vector<shared_ptr<View>> _view_list;

    string get_objName_by_point(Point p); // find structure obj by point obj
    string get_structName_by_point(Point p);
    Point get_point_by_name(const string& name); //get Point obj by object name
    void add_agent();
    void attach(View* v) { _view = v;}
    void detach() {_view = nullptr;}
};


#endif //HW3_MODEL_H
