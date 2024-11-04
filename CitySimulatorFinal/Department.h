#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class citymanager;

class Department {
public:

    Department(citymanager* mediator);


    void changed();


    double get() const;


    void set(double amount);

protected:
    citymanager* mediator;
    double assignedFunds;
};

#endif // DEPARTMENT_H
