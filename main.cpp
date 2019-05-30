#include <iostream>
#include "Controller/MainApp.h"

using std::exception;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
    try{
        MainApp app(argc, argv);
        return EXIT_SUCCESS;
    }
    catch(exception& e){
        cout << e.what() << endl;
        MainApp::printHelp();
        return EXIT_FAILURE;
    }
}