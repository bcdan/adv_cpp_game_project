//
// Created by dan on 29/06/2020.
//

#include "Peasant.h"



void Peasant::update() {
    if (getState() == stopped || getState() == dead)
        return;
    else if (getState() == Moving_to_destination) {
        position(getDestination());
    } else if (getState() == Moving_on_course) {
        course(getAngle());
    } else if (getState() == working) {
        if (!_reachedFarm) {
            if (!(getLocation() == getFarmSrc())) {
                position(_farmSrc);
                return;
            }
            _reachedFarm = true;
            string farmName = Model::Get().get_objName_by_point(_farmSrc);
            for (auto &farm:Model::Get()._structure_list) {
                if (farmName == farm->getName())
                    load(MAX_INV - _inventory, farm);
            }
            return;
        }else{
            if (!(getLocation() == getDestination())) {
                position(getDestination());
                return;
            }else{

            }

        }
    }
}

void Peasant::start_working(const string &farm, const string &castle) {
    setState(working);
     Point farmP = Model::Get().get_point_by_name(farm), castleP = Model::Get().get_point_by_name(castle);
    //todo: check if valid names/objects
    _farmSrc = farmP;
    setDestination(castleP);
}

const Point &Peasant::getFarmSrc() const {
    return _farmSrc;
}

void Peasant::load(int crates, shared_ptr<Structure> farm) {
    farm->withdraw(crates);
    _inventory += crates;
}
