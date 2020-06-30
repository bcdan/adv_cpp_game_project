//
// Created by dan on 29/06/2020.
//


#include "Controller.h"
#include "Peasant.h"
#include "Thug.h"
#include "Knight.h"

Controller Controller::_IController;

int Controller::get_cmd_number(const string &phrase) const {
    for (int i = 0; i < commands.size(); i++) {
        if (commands[i] == phrase)
            return i;
    }
}

bool Controller::agent_exist(const string &phrase) {
    for (auto &agent : Model::Get()._agent_list) {
        if (agent->getName() == phrase) {
            return true;
        }
    }
    return false;
}

void Controller::run() {
    string input, phrase, agent, location;
    double x = 0, y = 0;
    int command;
    while (getline(cin, input)) {
        remove_symbols(&input);
        stringstream ss(input);

        ss >> phrase;
        if (agent_exist(phrase)) {
            agent = phrase;
            ss >> phrase;
            command = get_cmd_number(phrase);
            if (command == -1) {
                //throw exception
                cout << "exception!" << endl;
                continue;
            }
        } else {
            command = get_cmd_number(phrase);
            if (command == -1) {
                //throw exception
                cout << "exception!" << endl;
                continue;
            }
            switch (command) {
                case 0: //default
                    break;
                case 1: //size
                    break;
                case 2: //zoom
                    break;
                case 3: //pan
                    break;
                case 4: //show
                    break;
                case 5: //status
                {
                    printCastles();
                    printFarms();
                    printPeasants();
                    break;
                }

                case 6: //go
                    break;
                case 7: {
                    //create
                    string name, type;
                    bool knightCreated = false;
                    ss >> name >> type;
                    if (type == "Knight") {
                        ss >> location; // knight has difference arguemnts -> gets string of site location instead point
                        for (auto &site :Model::Get()._structure_list) {//check if location is true and get it
                            if (site->getName() == location) {
                                Point tempPoint = site->get_location();
                                shared_ptr<Agent> tempKnight = make_shared<Knight>(name, tempPoint);
                                Model::Get()._sim_object_list.emplace_back(tempKnight);
                                Model::Get()._agent_list.emplace_back(tempKnight);
                                knightCreated = true; // found location -> returns true
                                break;
                            }
                        }
                        if (!knightCreated)
                            cout << "Couldn't create knight - not a valid location" << endl; //todo:Add exception
                        ss.clear();
                        break;
                    } else {
                        ss >> x >> y;
                        Point tempPoint(x, y);
                        if (type == "Peasant") {
                            shared_ptr<Agent> tempPeasant = make_shared<Peasant>(name, tempPoint);
                            Model::Get()._sim_object_list.emplace_back(tempPeasant);
                            Model::Get()._agent_list.emplace_back(tempPeasant);
                        } else if (type == "Thug") {
                            shared_ptr<Agent> tempThug = make_shared<Thug>(name, tempPoint);
                            Model::Get()._sim_object_list.emplace_back(tempThug);
                            Model::Get()._agent_list.emplace_back(tempThug);
                        } else {
                            cerr << "Exception on types of agents" << endl;
                            //throw exception
                        }
                    }
                    ss.clear();
                    break;
                }
                case 8://course
                    break;
                case 9: //position
                    break;
                case 10: //destination
                    break;
                case 11: //stop
                    break;
                case 12: //attack
                    break;
                case 13: //exit
                    return;
                    break;

            }

        }
    }

}

void Controller::remove_symbols(string *line) {
    line->erase(remove(line->begin(), line->end(), ')'), line->end()); //remove A from string
    line->erase(remove(line->begin(), line->end(), '('), line->end()); //remove A from string
    line->erase(remove(line->begin(), line->end(), ','), line->end()); //remove A from string
}

void Controller::printCastles() const {
    for (auto &structure: Model::Get()._structure_list) {
        if (structure->getType() == "Castle") {
            cout << "Castle " << structure->getName() << " at position ";
            structure->get_location().print();
            cout << ", Inventory: " << structure->getAmount() << endl;
        }
    }

}

void Controller::printFarms() const {
    for (auto &structure: Model::Get()._structure_list) {
        if (structure->getType() == "Farm") {
            cout << "Farm " << structure->getName() << " at position ";
            structure->get_location().print();
            cout << ", Inventory: " << structure->getAmount() << endl;
        }
    }
}

void Controller::printKnights() const {

}

void Controller::printThugs() const {
    for (auto &agent: Model::Get()._agent_list) {
        if (agent->getType() == "Thug") {
            cout << "Thug " << agent->getName() << " at position ";
            agent->getLocation().print();
            cout << ", Inventory: " << agent->getInventory() << endl;
        }
    }
}

void Controller::printPeasants() const {
    for (auto &agent: Model::Get()._agent_list) {
        if (agent->getType() == "Peasant") {
            cout << "Peasant " << agent->getName() << " at position ";
            agent->getLocation().print();
            if (agent->getState() == dead) cout << ", Dead" << endl;
            else if (agent->getState() == stopped) cout << ", Stopped" << endl;
            else {
                cout << ", Heading to " << Model::Get().get_structure_by_point(agent->getDestination()) << ", speed"
                     << agent->getSpeed() << "km/h" << endl;
            }
        }
    }
}


void Controller::printStatus() const {

}
