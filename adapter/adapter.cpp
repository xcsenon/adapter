#include <iostream>

// Target
class Target {
public:
    virtual void request() const = 0;
};

// Adaptee
class Adaptee {
public:
    void specificRequest() const {
        std::cout << "Adaptee's specific request" << std::endl;
    }
};

// Adapter
class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

    void request() const override {
        adaptee->specificRequest();
    }
};

int main() {
    Adaptee adaptee;
    Adapter adapter(&adaptee);

    // Using the Target interface to make a request
    Target* target = &adapter;
    target->request();

    return 0;
}
