//
// Created by adrien on 28/05/19.
//

#include <getopt.h>
#include "MainApp.h"
#include "arguments.h"
#include "../View/Console/ConsoleView.h"
#include "exception/invalid_value.h"
#include "exception/bad_owner.h"
#include "exception/bad_board_coordinates.h"
#include "exception/invalid_input.h"
#include <sstream>

using std::invalid_argument;
using std::stringstream;
using std::exception;

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

    this->options = arguments(argc, argv, shortOpts, longOpts);
    process();
}

MainApp::~MainApp() {
    delete this->board;
}

void MainApp::process() {
    for(auto opt : this->options){
        if(opt.first == 'h'){
            printHelp();
            break;
        }
        else if(opt.first == 'm'){
            if(opt.second == "console"){
                consoleMode();
            }
            else if(opt.second == "graphic"){
                graphicMode();
            }
            else if(opt.second == "mixed"){
                mixedMode();
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
    board = new Board();
    shared_ptr<ConsoleView> view (new ConsoleView);
    board->addObserver(view);

    string currentPlayer, input;
    unsigned short row, column;

    while(!gameOver){
        try {
            currentPlayer = (turn) ? "Red Player" : "Blue Player";

            input = ConsoleView::selectPawn(currentPlayer, row, column);
            if(input == "exit"){
                gameOver = true;
                cout << "Thank you for playing Ataxx, we hope to see you back soon!" << endl;
                break;
            }
            stringstream verif(input);
            if(!(verif >> row) || !(verif >> column)){
                throw invalid_input("selectPawn", input);
            }
            board->setSelectedPawn(turn, row, column);


        }
        catch (invalid_input& ii){
            cout << ii.getSpecificMessage() << " Please try again." << endl;
        }
        catch (bad_board_coordinates& bbc){
            cout << bbc.getSpecificMessage() << " Please try again." << endl;
        }
        catch (bad_owner& bo){
            cout << bo.getSpecificMessage() << " Please try again." << endl;
        }
        catch (...){
        }
    }
}

void MainApp::graphicMode() {}

void MainApp::mixedMode() {}