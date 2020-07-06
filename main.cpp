#include <iostream>
#include "Controller.h"
#include "Model.h"
#include "Castle.h"
#include "Farm.h"
#include "View.h"
#include <fstream>


using namespace std;


void init(char *castles, char *farms) {
    fstream cFile(castles, ios::in), fFile(farms, ios::in);
    string line, name, token;
    double x = 0, y = 0;
    int amount = 0, rate = 0;
    vector<string> parsed;
    if (!fFile || !cFile) {
        //exception
        return;
    }
    while (cFile.good()) {
        getline(cFile, line);
        Controller::remove_symbols(&line);
        stringstream ss(line);
        ss >> name >> x >> y >> amount;
        Point tempPoint(x, y);
        shared_ptr<Structure> tempCastle = make_shared<Castle>(amount, tempPoint, name);
        View::Get().update_location(name,tempPoint);
        Model::Get()._sim_object_list.emplace_back(tempCastle);
        Model::Get()._structure_list.emplace_back(tempCastle);
    }
    line = "";
    cFile.close();
    while (fFile.good()) {
        getline(fFile, line);
        Controller::remove_symbols(&line);
        stringstream ss(line);
        ss >> name >> x >> y >> amount >> rate;
        Point tempPoint(x, y);
        shared_ptr<Structure> tempFarm = make_shared<Farm>(amount, rate, tempPoint, name);
        View::Get().update_location(name,tempPoint);
        Model::Get()._sim_object_list.emplace_back(tempFarm);
        Model::Get()._structure_list.emplace_back(tempFarm);
    }
    fFile.close();

}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        //throw exception
    }
    init(argv[1], argv[2]);
    Controller::Get().run();




//    for (auto &name : Model::Get()._structure_list)
//        name->get_location().print();
//    cout << Model::Get()._agent_list[0]->getName() << endl;
//    Model::Get()._agent_list[0]->getLocation().print();
//    cout<<endl;
//    cout << Model::Get()._agent_list[0]->getState() << endl;
//    cout << Model::Get()._agent_list[0]->getHealth() << endl;
//    cout << Model::Get()._agent_list[0]->getSpeed() << endl;
//    cout << endl;
//    cout << Model::Get()._agent_list[1]->getName() << endl;
//    Model::Get()._agent_list[1]->getLocation().print();
//    cout << Model::Get()._agent_list[1]->getState() << endl;
//    cout << Model::Get()._agent_list[1]->getHealth() << endl;
//    cout << Model::Get()._agent_list[1]->getSpeed() << endl;
//    cout << endl;
//    cout << Model::Get()._agent_list[2]->getName() << endl;
//    Model::Get()._agent_list[2]->getLocation().print();
//    cout << Model::Get()._agent_list[2]->getState() << endl;
//    cout << Model::Get()._agent_list[2]->getHealth() << endl;
//    cout << Model::Get()._agent_list[2]->getSpeed() << endl;
//    cout << endl;
//    cout << Model::Get()._agent_list[0]->getSpeed() << endl;

//    Controller::Get().setView(&View::Get());
//    cout << Controller::Get().getView() << endl;
//    cout << &View::Get() << endl;
    return 0;


}


