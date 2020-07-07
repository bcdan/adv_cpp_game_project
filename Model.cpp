//
// Created by dan on 29/06/2020.
//

#include "Model.h"

Model Model::_IModel;


string Model::get_objName_by_point(Point p) {
    for (auto &obj : _sim_object_list) {
        if (obj->get_location() == p)
            return obj->getName();
    }
    string pos = "("+to_string(int(p._x))+", "+to_string(int(p._y))+")";
    return pos;
}

string Model::get_structName_by_point(Point p) {
    for (auto &obj : _structure_list) {
        if (obj->get_location() == p)
            return obj->getName();
    }
    string pos = "("+to_string(int(p._x))+", "+to_string(int(p._y))+")";
    return pos;
}

Point Model::get_point_by_name(const string& name) {
    for(auto& obj:_sim_object_list){
        if(obj->getName()==name)
            return obj->get_location();
    }
    return {999999,999999};
}
