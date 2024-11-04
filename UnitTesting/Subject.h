#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include <vector>
#include <algorithm>

class Subject {
public:
    virtual ~Subject() {}
    void attach(Observer* observer) {
        observers_.push_back(observer);
    }
    void detach(Observer* observer) {
        observers_.erase(std::remove(observers_.begin(), observers_.end(), observer), observers_.end());
    }
protected:
    void notify() {
        for(auto obs : observers_) {
            obs->update();
        }
    }
private:
    std::vector<Observer*> observers_;
};

#endif 
