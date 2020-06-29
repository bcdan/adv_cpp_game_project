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

using namespace std;

class Model {
private:
    Model() {time=0;}
    static Model _IModel;
public:
    Model(const Model&) = delete; //disable copy c-tor

    static Model& Get(){
        return _IModel;
    }

    int time;
    vector<shared_ptr<Sim_object>> _sim_object_list;
    vector<shared_ptr<Structure>> _structure_list;
    vector<shared_ptr<Agent>> _agent_list;
    vector<shared_ptr<View>> _view_list;

    void update();
    void add_agent();
    void attach();
    void detach();
    void notify_location();
};


#endif //HW3_MODEL_H
