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
    Player* redPlayer = nullptr;
    Player* bluePlayer = nullptr;
    bool gameOver = false;
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
             "-m  or  --mode  <console, graphic, mixed>:      Set the display mode" << endl <<
             "-h  or  --help:                                 Print Help (this message) and exit" << endl;
    }
    bool isGameOver() const noexcept{
        return gameOver;
    }
};


#endif //ATAXX_MAINAPP_H
