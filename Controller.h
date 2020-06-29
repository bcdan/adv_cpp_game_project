

#ifndef HW3_CONTROLLER_H
#define HW3_CONTROLLER_H


#include "View.h"
#include "Model.h"

/* Controller
This class is responsible for controlling the Model and View according to interactions
with the user.
*/

class Controller {
private:
    View* _view;
    Model* _model;
    Controller() {}
    static Controller _IController;
public:
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

    // creates View object, runs the program by accepting user commands, then destroys View object
    void run();
    void do_move();
    void do_go();
    void do_show();

};


#endif //HW3_CONTROLLER_H
