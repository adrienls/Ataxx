//
// Created by adrien on 03/06/19.
//

#include "Subject.h"

void Subject::notifyObservers() noexcept{
    for(const shared_ptr<Observer>& observer : this->observers){
        if (observer != nullptr){
            observer->update(this);//update the information of each observer
        }
    }
}

void Subject::addObserver(const shared_ptr<Observer>& newObserver) noexcept{
    observers.push_back(newObserver);
}
void Subject::removeObserver(const shared_ptr<Observer>& newObserver) noexcept{
    for(list<shared_ptr<Observer>>::iterator it = observers.begin(); it != observers.end(); it++){
        if(*it == newObserver){//finds the right observer to erase in the list
            observers.erase(it);
            return;
        }
    }
}