#include <iostream>
#include "Controller/Arguments.h"

int main(int argc, char** argv) {
    Arguments* arg = new Arguments(argc, argv);
    arg->display();
    delete arg;
    return 0;
}