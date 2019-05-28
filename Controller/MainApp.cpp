//
// Created by adrien on 28/05/19.
//

#include <getopt.h>
#include "MainApp.h"
#include "Arguments.h"
#include "exception/too_many_arguments.h"
#include <iostream>

using std::cout;
using std::endl;

MainApp::MainApp(const int &argc, char *const *argv) {

    if(argc == 1){
        cout << "Option required!" << endl;
        printHelp(EXIT_FAILURE);
    }

    const char* const shortOpts = "hm:";
    const struct option longOpts[] = {
            {"help", no_argument, nullptr, 'h'},
            {"mode", required_argument, nullptr, 'm'},
            {nullptr, no_argument, nullptr, 0}
    };

    try{
        this->arg = new Arguments(argc, argv, shortOpts, longOpts);
    }
    catch(too_many_arguments& ia){
        cout << ia.what() << endl;
        exit(EXIT_FAILURE);
    }
    const map<char, string>& options = this->arg->getOptions();
    process(options);
}

MainApp::~MainApp() {
    delete this->arg;
}

void MainApp::printHelp(const char& exitCode) noexcept {
    cout <<
    "--mode <console, graphic, mixed>:      Set the display mode" << endl <<
    "--help:                                Show this help" << endl;
    exit(exitCode);
}

void MainApp::process(const map<char, string> &options) noexcept {
    for(auto opt : options){
        if(opt.first == 'h'){
            printHelp(EXIT_SUCCESS);
        }
        else if(opt.first == 'm'){
            if(opt.second == "console"){

            }
            else if(opt.second == "graphic"){

            }
            else if(opt.second == "mixed"){

            }
            else{
                cout << opt.second << " is not a valid argument. Please use --help to check the valid arguments." << endl;
                exit(EXIT_FAILURE);
            }
        }
        else{
            cout << opt.first << " is not a valid option. Please use --help to check the valid options." << endl;
            exit(EXIT_FAILURE);
        }
    }
}