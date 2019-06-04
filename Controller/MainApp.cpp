//
// Created by adrien on 28/05/19.
//

#include <getopt.h>
#include "MainApp.h"
#include "arguments.h"
#include "../View/Console/ConsoleView.h"
#include <sstream>

using std::invalid_argument;
using std::stringstream;

MainApp::MainApp(const int &argc, char *const *argv) {

    if(argc == 1){
        throw invalid_argument("Option required!");
    }
    else if(argc > 3){
        throw invalid_argument("Too many arguments!");
    }

    const char* const shortOpts = "hm:";
    const struct option longOpts[] = {
            {"help", no_argument, nullptr, 'h'},
            {"mode", required_argument, nullptr, 'm'},
            {nullptr, no_argument, nullptr, 0}
    };

    options = arguments(argc, argv, shortOpts, longOpts);
    process();
}

MainApp::~MainApp() {
    delete board;
    delete redPlayer;
    delete bluePlayer;
}

void MainApp::process() {
    for(auto opt : options){
        if(opt.first == 'h'){
            printHelp();
            break;
        }
        else if(opt.first == 'm'){
            if(opt.second == "console"){
                consoleMode();
            }
            else if(opt.second == "graphic"){

            }
            else if(opt.second == "mixed"){

            }
            else{
                stringstream invalidArgument;
                invalidArgument << opt.second << " is not a valid argument. Please check the valid arguments.";
                throw invalid_argument(invalidArgument.str());
            }
        }
        else{
            stringstream invalidArgument;
            invalidArgument << opt.first << " is not a valid option. Please check the valid options.";
            throw invalid_argument(invalidArgument.str());
        }
    }
}

void MainApp::consoleMode() {
    string firstUsername, secondUsername;
    shared_ptr<ConsoleView> view (new ConsoleView);
    view->getUsernames(firstUsername, secondUsername);

    redPlayer = new Player(firstUsername, true, Red);
    bluePlayer = new Player(secondUsername, false, Blue);
    board = new Board(redPlayer, bluePlayer);
    board->addObserver(view);

    board->addPawn(Red, 0, 1);
    view->finalResult(board);
}