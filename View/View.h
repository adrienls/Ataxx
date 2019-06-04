//
// Created by adrien on 04/06/19.
//

#ifndef ATAXX_VIEW_H
#define ATAXX_VIEW_H

#include <string>
#include "Observer.h"

using std::string;

class View : public Observer{
public:
    virtual void getUsernames(string& firstUsername, string& secondUsername) = 0;
    virtual void finalResult(Subject* subject) = 0;
    virtual ~View() = default;
};


#endif //ATAXX_VIEW_H
