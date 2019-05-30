//
// Created by adrien on 28/05/19.
//

#ifndef ATAXX_MAINAPP_H
#define ATAXX_MAINAPP_H

#include <map>
#include <string>
#include "../Model/Board.h"

using std::map;
using std::string;

class MainApp {
private:
    Board* board = nullptr;
    map<char, string> options;
    void process();
public:
    MainApp(const int& argc, char* const* argv);
    virtual ~MainApp();
    inline static void printHelp() noexcept;
};


#endif //ATAXX_MAINAPP_H
