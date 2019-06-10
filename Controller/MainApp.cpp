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
#include "exception/restart.h"
#include "../View/Qt/QtView.h"
#include <sstream>

#define ENDGAME "Thank you for playing Ataxx, we hope to see you back soon!"
#define TRYAGAIN " Please try again."

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
    unsigned short row = 0, column = 0, newRow = 0, newColumn = 0;

    while(true){
        try {
            if(selectOrMove){
                input = "Please select a pawn:";
                input = ConsoleView::selectPawn(input, turn, row, column);
                if(input == "exit"){
                    ConsoleView::printMessage(ENDGAME);
                    break;
                }
                if(input == "restart"){
                    throw restart("consoleMode", "restart");
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
                ConsoleView::printMessage(ENDGAME);
                break;
            }
            if(input == "restart"){
                throw restart("consoleMode", "restart");
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
                board->movePawn(row, column, newRow, newColumn);
            }

            if(board->getNbRedPawn() == 0){
                ConsoleView::printMessage("Blue Player has won!");
                ConsoleView::printMessage(ENDGAME);
                break;
            }
            else if(board->getNbBluePawn() == 0){
                ConsoleView::printMessage("Red Player has won!");
                ConsoleView::printMessage(ENDGAME);
                break;
            }
            selectOrMove = true;
            turn = !turn;
        }
        catch (invalid_input& ii){
            ConsoleView::printMessage(ii.getSpecificMessage() + TRYAGAIN);
        }
        catch (bad_board_coordinates& bbc){
            selectOrMove = true;
            ConsoleView::printMessage(bbc.getSpecificMessage() + TRYAGAIN);
        }
        catch (bad_owner& bo){
            selectOrMove = true;
            ConsoleView::printMessage(bo.getSpecificMessage() + TRYAGAIN);
        }
        catch (no_more_move& nmm){
            ConsoleView::printMessage(nmm.getSpecificMessage() + TRYAGAIN);
            ConsoleView::printMessage(ENDGAME);
            break;
        }
        catch (used_square& us){
            selectOrMove = false;
            ConsoleView::printMessage(us.getSpecificMessage() + TRYAGAIN);
        }
        catch (not_available_move& nam){
            selectOrMove = false;
            ConsoleView::printMessage(nam.getSpecificMessage() + TRYAGAIN);
        }
        catch (restart& r){
            ConsoleView::printMessage("-------------------------");
            ConsoleView::printMessage(r.getSpecificMessage());
            ConsoleView::printMessage("-------------------------");
            delete board;
            board = new Board();
            board->addObserver(view);
            turn = true;
            selectOrMove = true;
        }
    }
}

void MainApp::graphicMode() {
    board = new Board();
    shared_ptr<QtView> view (new QtView(board));
    board->addObserver(view);
}

void MainApp::mixedMode() {}