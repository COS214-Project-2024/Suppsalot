#ifndef RESOURCEOBSERVER_H
#define RESOURCEOBSERVER_H

class ResourceObserver {
public:
    virtual ~ResourceObserver() = default;
    virtual void update(const std::string& resourceType, double currentLevel) = 0;
};


class LowResourceAlert : public ResourceObserver {
public:
    void update(const std::string& resourceType, double currentLevel) override {
        std::cout << "Alert: " << resourceType << " level is low! Current level: " << currentLevel << std::endl;
    }
};

#endif
