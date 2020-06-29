#include <iostream>
#include "Controller.h"
#include "Model.h"
using namespace std;

int main() {
    Controller::Get().setView(&View::Get());
    cout << Controller::Get().getView() << endl;
    cout << &View::Get() << endl;
    return 0;


}
