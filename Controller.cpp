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
        if (agent_exist(phrase)) { //check if first phrase in command is a valid agent
            shared_ptr<Agent> temp = findAgent(phrase);
            if (temp->getState() == dead) {//todo:exception
                cout << temp->getName() << " is dead , can't perform actions" << endl;
                continue;
            }
            agent = phrase;
            ss >> phrase;
            command = get_cmd_number(phrase);
            if (command == -1) {
                //throw exception
                cout << "exception!" << endl;
                continue;
            }
        } else { //else, check if first phrase in command is a valid command
            command = get_cmd_number(phrase);
            if (command == -1) {
                //throw exception
                cout << "exception!" << endl;
                continue;
            }
        }
        switch (command) {
            case 0: //default
                break;
            case 1: //size
                break;
            case 2: //zoom
                break;
            case 3: { //pan
                ss >> x >> y;
                _view->set_origin(Point(x, y));
                ss.clear();
                break;
            }
            case 4: //show

                View::Get().draw();
                break;
            case 5: //status
            {
                printStatus();
                //todo: add thug and knight print functions
                break;
            }

            case 6: //go
            {
                for (auto &obj : Model::Get()._sim_object_list)
                    obj->update();
                Model::Get().time++;
                break;
            }
            case 7: {   //create
                string name, type;
                bool knightCreated = false;
                ss >> name >> type;
                if (type == "Knight") {
                    ss >> location; // knight has difference arguments -> gets string of site location instead point
                    for (auto &site :Model::Get()._structure_list) {//check if location is true and get it
                        if (site->getName() == location) {
                            Point tempPoint = site->get_location();
                            shared_ptr<Agent> tempKnight = make_shared<Knight>(name, tempPoint);
                            View::Get().update_location(name, tempPoint);
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
                        View::Get().update_location(name, tempPoint);
                        Model::Get()._sim_object_list.emplace_back(tempPeasant);
                        Model::Get()._agent_list.emplace_back(tempPeasant);
                    } else if (type == "Thug") {
                        shared_ptr<Agent> tempThug = make_shared<Thug>(name, tempPoint);
                        View::Get().update_location(name, tempPoint);
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
            {
                shared_ptr<Agent> temp = findAgent(agent); //find agent
                double angle;
                ss >> angle; //get angle from command
                temp->setAngle(angle);
                if (temp->getType() == "Thug") {
                    int speed = 0;
                    ss >> speed;
                    temp->setSpeed(speed);
                }
                temp->setState(Moving_on_course);
                ss.clear();
                break;
            }
            case 9: //position
            {
                shared_ptr<Agent> temp = findAgent(agent);  //find agent
                ss >> x >> y;   //get Point coordinate from command
                if (temp->getType() == "Thug") {
                    int speed = 0;
                    ss >> speed;
                    temp->setSpeed(speed);
                }
                temp->setDestination(Point(x, y));   //set new destination for agent
                temp->setState(Moving_to_destination);  //set new state for agent
                ss.clear();
                break;
            }
            case 10: { //destination todo:TEST THIS
                shared_ptr<Agent> temp = findAgent(agent); //find agent
                if (temp->getType() != "Knight") { //The only agent that's allowed to use this command is 'Knight'
                    //todo:throw exception -> cmd only for Knight type agent
                } else {
                    string dest;
                    ss >> dest; //get destination name from command
                    temp->destination(dest);
                    ss.clear();
                }
                break;
            }
            case 11: { //stop
                shared_ptr<Agent> temp_agent = findAgent(agent);
                temp_agent->setState(stopped);
                break;
            }
            case 12: //attack
            {
                shared_ptr<Agent> temp = findAgent(agent); //find thug
                if (temp->getType() != "Thug") { //Only "thug" agent is allowed to use this
                    //todo:throw exception -> cmd only for Thug type agent
                } else {
                    string target;
                    ss >> target;
                    temp->setTarget(target);
                    //todo:check if target exists AND is a peasant
                    temp->setState(attacking);
                }
                ss.clear();
                break;

            }
            case 13: //start_working
            {
                shared_ptr<Agent> temp = findAgent(agent); //find agent
                if (temp->getType() != "Peasant") { //The only agent that's allowed to use this command is 'Peasant'
                    //todo:throw exception -> cmd only for Peasant type agent
                } else {
                    string farm, castle;
                    ss >> farm >> castle;
                    temp->start_working(farm, castle);
                    ss.clear();
                }

                break;
            }
            case 14://exit
                return;

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
    for (auto &agent: Model::Get()._agent_list) {
        if (agent->getType() == "Knight") {
            cout << "Knight " << agent->getName() << " at position ";
            agent->getLocation().print();
            if (agent->getState() == Moving_on_course)
                cout << ", Heading on course " << agent->getAngle() << " deg," << " speed " << agent->getSpeed()
                     << " km/h" << endl;
            else if (agent->getState() == Moving_to_destination) {
                cout << ", Heading to " << Model::Get().get_objName_by_point(agent->getDestination());
                cout << ", speed " << agent->getSpeed() << " km/h" << endl;
            } else if (agent->getState() == stopped)
                cout << ", Stopped" << endl;
            else if (agent->getState() == dead)
                cout << ", Dead - R.I.P" << endl;
        }
    }
}

void Controller::printThugs() const {
    for (auto &agent: Model::Get()._agent_list) {
        if (agent->getType() == "Thug") {
            cout << "Thug " << agent->getName() << " at position ";
            agent->getLocation().print();
            if (agent->getState() == Moving_on_course)
                cout << ", Heading on course " << agent->getAngle() << " deg," << " speed " << agent->getSpeed()
                     << " km/h";
            else if (agent->getState() == Moving_to_destination) {
                cout << ", Heading to position ";
                agent->getDestination().print();
                cout << ", speed " << agent->getSpeed() << " km/h";
                // cout << ", speed " << agent->getSpeed() << " km/h" <<" HP : "<<agent->getHealth()<<endl;

            } else if (agent->getState() == stopped)
                cout << ", Stopped";
            else if (agent->getState() == dead) {
                cout << ", Dead - R.I.P" << endl;
                continue;
            }
            cout << ", HP: " << agent->getHealth() << endl;

        }
    }
}

void Controller::printPeasants() const {
    for (auto &agent: Model::Get()._agent_list) {
        if (agent->getType() == "Peasant") {
            cout << "Peasant " << agent->getName() << " at position ";
            agent->getLocation().print();
            if (agent->getState() == dead) {
                cout << ", Dead" << endl;
                continue;
            } else if (agent->getState() == stopped) cout << ", Stopped";
            else {
                cout << ", Heading to " << Model::Get().get_objName_by_point(agent->getDestination()) << ", speed "
                     << agent->getSpeed() << "km/h";
            }
            cout << " ,Inventory: " << agent->getInventory() << ", HP: " << agent->getHealth() << endl;

        }
    }
}


void Controller::printStatus() const {
    printCastles();
    printFarms();
    printPeasants();
    printThugs();
    printKnights();
}

shared_ptr<Agent> Controller::findAgent(const string &name) {
    for (auto agent : Model::Get()._agent_list) {
        if (agent->getName() == name) {
            return agent;
        }
    }
    return nullptr;
}
