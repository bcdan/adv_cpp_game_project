//
// Created by dan on 29/06/2020.
//

#include "Knight.h"

void Knight::destination(const string &site) {
    setDestination(Model::Get().get_point_by_name(site));
    setState(Moving_to_destination);

}

bool Knight::hasVisited(const string &toVisit) const {
    for (auto &site:visited_sites) {
        if (site == toVisit)
            return true;
    }
    return false;
}

Point Knight::find_nearest() {
    double tempMin = 999999999;
    double currentDistance = 0;
    Point tempP(0, 0);
    for (auto &site:Model::Get()._structure_list) {
        if (!hasVisited(site->getName())) {
            currentDistance = getLocation().getDistance(site->get_location());
            if (currentDistance < tempMin) {
                tempMin = currentDistance;
                tempP = site->get_location();
            }
        }
    }
    return tempP;
}

bool Knight::allVisited() const {
    return visited_sites.size() == Model::Get()._structure_list.size();
}

void Knight::update() {
    if (getState() == stopped)
        return;
    if (getState() == Moving_to_destination) {
        if (!(getLocation() == getDestination())) {
            Point temp=getDestination();
            position(temp);
        } else {
            if (getDestination() == Model::Get().get_point_by_name(visited_sites[0])) {
                setState(stopped);
                return;
            } else {
                visited_sites.emplace_back(Model::Get().get_objName_by_point(getDestination()));
                if (!allVisited()) {
                    setDestination(find_nearest());
                } else {
                    setDestination(Model::Get().get_point_by_name(visited_sites[0]));
                }
            }
        }
    }else if (getState() == Moving_on_course){
        course(getAngle());
    }
}
