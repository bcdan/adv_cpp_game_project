//
// Created by dan on 29/06/2020.
//

#include "Model.h"

Model Model::_IModel;

void Model::add_agent() {


}

string Model::get_structure_by_point(Point p) {
    for (auto &site : _structure_list) {
        if (site->get_location() == p)
            return site->getName();
    }
    return "null";
}
