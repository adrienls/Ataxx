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
#include "exception/no_more_move.h"
#include "exception/used_square.h"
#include "exception/not_available_move.h"
#include <sstream>

#define ENDGAME "Thank you for playing Ataxx, we hope to see you back soon!"

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
    bool selectOrMove = true;
    stringstream verif;
    string currentPlayer, input;
    unsigned short row, column, newRow, newColumn;

    while(true){
        try {
            if(selectOrMove){
                input = "Please select a pawn:";
                input = ConsoleView::selectPawn(input, turn, row, column);
                if(input == "exit"){
                    cout << ENDGAME << endl;
                    break;
                }
                verif.str("");
                verif.clear();
                verif << input;
                if(!(verif >> row) || !(verif >> column)){
                    selectOrMove = true;
                    throw invalid_input("selectPawn", input);
                }
                board->setSelectedPawn(turn, row, column);
            }


            input = "Select a destination from the available moves:";
            input = ConsoleView::selectPawn(input, turn, newRow, newColumn);
            if(input == "exit"){
                cout << ENDGAME << endl;
                break;
            }

            verif.str("");
            verif.clear();
            verif << input;
            if(!(verif >> newRow) || !(verif >> newColumn)){
                selectOrMove = false;
                throw invalid_input("selectPawn", input);
            }
            if(Board::isAdjacent(row, column, newRow, newColumn)) {
                board->addPawn((turn) ? Red : Blue, newRow, newColumn);
            }
            else{
                board->movePawn(row, column, newRow, newColumn);//TODO correct this condition by using the adjacent function
            }

            if(board->getNbRedPawn() == 0){
                cout << "Blue Player has won!" << endl << ENDGAME << endl;
                break;
            }
            else if(board->getNbBluePawn() == 0){
                cout << "Red Player has won!" << endl << ENDGAME << endl;
                break;
            }
            turn = !turn;
        }
        catch (invalid_input& ii){
            cout << ii.getSpecificMessage() << " Please try again." << endl;
        }
        catch (bad_board_coordinates& bbc){
            selectOrMove = true;
            cout << bbc.getSpecificMessage() << " Please try again." << endl;
        }
        catch (bad_owner& bo){
            selectOrMove = true;
            cout << bo.getSpecificMessage() << " Please try again." << endl;
        }
        catch (no_more_move& nmm){
            cout << nmm.getSpecificMessage() << " Please try again." << endl << ENDGAME << endl;
            break;
        }
        catch (used_square& us){
            selectOrMove = false;
            cout << us.getSpecificMessage() << " Please try again." << endl;
        }
        catch (not_available_move& nam){
            selectOrMove = false;
            cout << nam.getSpecificMessage() << " Please try again." << endl;
        }
    }
}

void MainApp::graphicMode() {}

void MainApp::mixedMode() {}