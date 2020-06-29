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
    string input, phrase, agent;
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
                    break;
                case 6: //go
                    break;
                case 7: {
                    //create
                    string name, type;
                    ss >> name >> type >> x >> y;
                    Point tempPoint(x, y);
                    if (type == "Peasant") {
                        shared_ptr<Agent> tempPeasant = make_shared<Peasant>(name, 100, stopped, tempPoint, 0);
                        Model::Get()._sim_object_list.emplace_back(tempPeasant);
                        Model::Get()._agent_list.emplace_back(tempPeasant);
                    } else if (type == "Thug") {
                        shared_ptr<Agent> tempThug = make_shared<Thug>(name, 100, stopped, tempPoint, 0);
                        Model::Get()._sim_object_list.emplace_back(tempThug);
                        Model::Get()._agent_list.emplace_back(tempThug);
                    } else if (type == "Knight") {
                        shared_ptr<Agent> tempKnight = make_shared<Knight>(name, 100, stopped, tempPoint, 0);
                        Model::Get()._sim_object_list.emplace_back(tempKnight);
                        Model::Get()._agent_list.emplace_back(tempKnight);
                    } else {
                        cerr << "Exception on types of agents" << endl;
                        //throw excepction
                    }
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
