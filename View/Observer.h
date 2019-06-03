//
// Created by adrien on 03/06/19.
//

#ifndef ATAXX_OBSERVER_H
#define ATAXX_OBSERVER_H

class Subject;

class Observer{
public:
    virtual void update(Subject* subject) = 0;
    virtual ~Observer() = default;
};

#endif //ATAXX_OBSERVER_H
