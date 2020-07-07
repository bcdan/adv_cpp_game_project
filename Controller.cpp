//
// Created by dan on 29/06/2020.
//

#include "Controller.h"
#include "Peasant.h"
#include "Thug.h"
#include "Knight.h"

Controller Controller::_IController;

int Controller::get_cmd_number(const string &phrase) const {
    for (int i = 0; i < (int)commands.size(); i++) {
        if (commands[i] == phrase)
            return i;
    }
    return -1;
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
    int command=-1;
    while (true) {
        cout<<"Time "<<_model->time<<": "<<"Enter command: ";
        getline(cin, input);
        remove_symbols(&input);
        stringstream ss(input);
        ss >> phrase;
        if (agent_exist(phrase)) { //check if first phrase in command is a valid agent
            shared_ptr<Agent> temp = findAgent(phrase);
            if (temp->getState() == dead) {
                cout << temp->getName() << " is dead , can't perform actions" << endl;
                continue;
            }
            agent = phrase;
            ss >> phrase;
            command = get_cmd_number(phrase);
            if (command == -1) {
                cout << "Invalid command!" << endl;
                continue;
            }
        } else { //else, check if first phrase in command is a valid command
            command = get_cmd_number(phrase);
            if (command == -1) {
                cout << "Invalid command!" << endl;
                continue;
            }
        }
        switch (command) {
            case 0: //default
            {
                _view->set_defaults();
                break;
            }
            case 1: //size
            {
                try {
                    int tempSize = 0;
                    ss >> tempSize;
                    _view->set_size(tempSize);
                    ss.clear();
                    break;
                }catch(Exceptions::runtime_error &err){
                    cout<<err.what()<<endl;
                    ss.clear();
                    break;
                }
            }
            case 2: //zoom
            {
                try{
                    double tempZoom = 0;
                    ss >> tempZoom;

                    _view->set_zoom(tempZoom);
                    ss.clear();
                    break;
                }catch(Exceptions::runtime_error &err){
                    cout<<err.what()<<endl;
                    ss.clear();
                    break;
                }

            }
            case 3: { //pan
                ss >> x >> y;
                _view->set_origin(Point(x, y));
                ss.clear();
                break;
            }
            case 4: //show
                cout<<"Display size: "<<_view->get_size()<<", scale: "<<_view->getScale()<<" origin: ("<<setprecision(2)<<_view->getOrigin()._x<<", "<<_view->getOrigin()._y<<")"<<endl;
                View::Get().draw();
                break;
            case 5: //status
            {
                printStatus();
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
                try {
                    if(_model->get_point_by_name(name)._x != INVALID_POINT)
                        throw Exceptions::InputException("Agent already exists");
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
                            throw Exceptions::InputException("Couldn't create knight - not a valid location" );

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
                            throw Exceptions::Wrong_Type_Exception("Invalid type of an agent" );
                        }
                    }
                    ss.clear();
                    break;
                }catch(Exceptions::runtime_error & error){
                    cout<<error.what()<<endl;
                    ss.clear();
                    break;
                }
            }
            case 8://course
            {
                try {
                    shared_ptr<Agent> temp = findAgent(agent); //find agent
                    if (temp == nullptr) {
                        throw Exceptions::Agent_Not_Found_Exception(agent + " was not found");
                    }
                    double angle=0;
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
                } catch (Exceptions::runtime_error &error) {
                    cout << error.what() << endl;
                    ss.clear();
                    break;
                }
            }
            case 9: //position
            {
                try {
                    shared_ptr<Agent> temp = findAgent(agent);  //find agent
                    if (temp == nullptr) {
                        throw Exceptions::Agent_Not_Found_Exception(agent + " was not found");
                    }
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

                } catch (Exceptions::runtime_error &error) {
                    cout << error.what() << endl;
                    ss.clear();
                    break;
                }
            }
            case 10: { //destination
                try {
                    shared_ptr<Agent> temp = findAgent(agent); //find agent
                    if (temp == nullptr) {
                        throw Exceptions::Agent_Not_Found_Exception(agent + " was not found");
                    }
                    if (temp->getType() != "Knight") { //The only agent that's allowed to use this command is 'Knight'
                        throw Exceptions::Wrong_Type_Exception(temp->getName() + " is not a Knight - can't perform the requested command");
                    } else {
                        string dest;
                        ss >> dest; //get destination name from command
                        temp->destination(dest);
                        ss.clear();
                        break;
                    }
                } catch (Exceptions::runtime_error &error) {
                    cout << error.what() << endl;
                    ss.clear();
                    break;
                }
            }
            case 11: { //stop
                try {
                    shared_ptr<Agent> temp_agent = findAgent(agent);
                    if (temp_agent == nullptr) {
                        throw Exceptions::Agent_Not_Found_Exception(agent + " was not found");
                    }
                    temp_agent->setState(stopped);
                    break;


                } catch (Exceptions::runtime_error &error) {
                    cout << error.what() << endl;
                    ss.clear();
                    break;
                }
            }
            case 12: //attack
            {
                try {
                    shared_ptr<Agent> temp = findAgent(agent); //find thug
                    if (temp == nullptr)
                        throw Exceptions::Agent_Not_Found_Exception(agent + " was not found");
                    if (temp->getType() != "Thug") { //Only "thug" agent is allowed to use this
                        throw Exceptions::Wrong_Type_Exception(
                                temp->getName() + " is not a Thug - can't perform the requested command");
                    } else {
                        string target;
                        ss >> target;
                        temp->setTarget(target);
                        if (findAgent(target) == nullptr)
                            throw Exceptions::Agent_Not_Found_Exception(target + " was not found");
                        if (findAgent(target)->getType() != "Peasant")
                            throw Exceptions::Wrong_Type_Exception(
                                    target + " is not a Peasant - can't attack non-peasants");
                        temp->setState(attacking);
                        ss.clear();
                        break;
                    }
                } catch (Exceptions::runtime_error &error) {
                    cout << error.what() << endl;
                    ss.clear();
                    break;
                }
                break;
            }
            case 13: //start_working
            {
                try {
                    shared_ptr<Agent> temp = findAgent(agent); //find agent
                    if (temp == nullptr) {
                        throw Exceptions::Agent_Not_Found_Exception(agent + " was not found");
                    }
                    if (temp->getType() != "Peasant") { //The only agent that's allowed to use this command is 'Peasant'
                        throw Exceptions::Wrong_Type_Exception(temp->getName() + " is not a Peasant - can't attack non-peasants");
                    } else {
                        string farm, castle;
                        ss >> farm >> castle;
                        temp->start_working(farm, castle);
                        ss.clear();
                        break;

                    }
                } catch (Exceptions::runtime_error &error) {
                    cout << error.what() << endl;
                    ss.clear();
                    break;
                }
            }
            case 14://exit
                return;

        }
        ss.clear();
    }

}

void Controller::remove_symbols(string *line) {
    for(auto& c:*line){
        if(c=='('||c==')'||c==',')
            c=' ';
    }

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
            else if (agent->getState() == working){
                cout << ", Heading to " << Model::Get().get_objName_by_point(agent->getDestination()) << ", speed "
                     << agent->getSpeed() << "km/h";
            }else if (agent->getState() == Moving_on_course){
                cout << ", Heading on course " << agent->getAngle()  << " deg, speed "
                     << agent->getSpeed() << "km/h";
            }else if( agent->getState() == Moving_to_destination ){
                cout << ", Heading to " << Model::Get().get_structName_by_point(agent->getDestination()) << ", speed "
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
