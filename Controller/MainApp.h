//
// Created by adrien on 28/05/19.
//

#ifndef ATAXX_MAINAPP_H
#define ATAXX_MAINAPP_H


#include "../Model/Board.h"
#include "Arguments.h"

class MainApp {
private:
    Board board;
    Arguments* arg;
    void process(const map<char, string>& options) noexcept;
public:
    MainApp(const int& argc, char* const* argv);
    virtual ~MainApp();
    inline void printHelp(const char& exitCode) noexcept;
};


#endif //ATAXX_MAINAPP_H
