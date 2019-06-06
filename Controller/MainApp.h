//
// Created by adrien on 28/05/19.
//

#ifndef ATAXX_MAINAPP_H
#define ATAXX_MAINAPP_H

#include <map>
#include <string>
#include <iostream>
#include "../Model/Board.h"

using std::cout;
using std::endl;
using std::map;
using std::string;

class MainApp {
private:
    Board* board = nullptr;
    bool turn = true;   //if set to true it is redPlayer's turn, otherwise it is bluePayer's turn
    map<char, string> options;

    void process();
    void consoleMode();
    void graphicMode();
    void mixedMode();
public:
    MainApp(const int& argc, char* const* argv);
    virtual ~MainApp();
    static void printHelp() noexcept{
        cout <<
             "-m  or  --mode  <console, graphic, mixed>:      Set the displayGrid mode" << endl <<
             "-h  or  --help:                                 Print Help (this message) and exit" << endl;
    }
};


#endif //ATAXX_MAINAPP_H
