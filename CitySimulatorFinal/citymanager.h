#ifndef CITYMANAGER_H
#define CITYMANAGER_H


class Department;

class citymanager  {
public:
    virtual void notify(Department* dept) = 0;
};

#endif
