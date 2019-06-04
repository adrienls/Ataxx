//
// Created by adrien on 03/06/19.
//

#ifndef ATAXX_SUBJECT_H
#define ATAXX_SUBJECT_H

#include <list>
#include <iostream>
#include <memory>
#include "../View/Observer.h"
using std::list;
using std::shared_ptr;

class Subject{
private:
    list<shared_ptr<Observer>> observers;
protected:
    void notifyObservers() noexcept;
public:
    void addObserver(const shared_ptr<Observer>& newObserver) noexcept{
        observers.push_back(newObserver);
    }
    void removeObserver(const shared_ptr<Observer>& newObserver) noexcept;

    Subject() = default;
    virtual ~Subject() = default;
};

#endif //ATAXX_SUBJECT_H
