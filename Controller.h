

#ifndef HW3_CONTROLLER_H
#define HW3_CONTROLLER_H


#include "View.h"
#include "Model.h"
#include <sstream>
#include <algorithm>
#include <typeinfo>
#include "Exceptions.h"

/* Controller
This class is responsible for controlling the Model and View according to interactions
with the user.
*/

class Controller {
private:
    View* _view;
    Model* _model;
    Controller() {
        commands = {"default", "size", "zoom", "pan", "show", "status", "go","create","course","position","destination","stop","attack","start_working","exit"};
        _model=&Model::Get();
        _view=&View::Get();
    }
    static Controller _IController;

public:
    vector<string> commands;
    vector<string>types;



    Controller(const Controller&) = delete; //disable copy c-tor



    View *getView() const {
        return _view;
    }

    void setView(View *view) {
        _view = view;
    }

    void setModel(Model *model) {
        _model = model;
    }

    Model *getModel() const {
        return _model;
    }

    static Controller& Get(){
        return _IController;
    }

    int get_cmd_number(const string& phrase) const; //check if given string is a valid command
    bool agent_exist(const string& phrase); //check if given string is valid agent name
    static void remove_symbols(string *line); // removes ", ( " etc
    void printCastles()const;
    void printFarms()const;
    void printKnights()const;
    void printThugs()const;
    void printPeasants()const;
    void printStatus()const;
    static shared_ptr<Agent> findAgent(const string& name);
    // creates View object, runs the program by accepting user commands, then destroys View object
    void run();


};


#endif //HW3_CONTROLLER_H
