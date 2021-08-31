// SimpleSpriteGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
// More on refactoring code:  https://refactoring.guru/
// More on state machine:  https://levelup.gitconnected.com/finite-state-machine-and-its-implementation-with-state-pattern-from-scratch-9732787a1277
// More on super state design pattern:  https://medium.com/nerd-for-tech/the-super-state-design-pattern-166127ce7c9a

#include <iostream>

class State {
public:
    virtual void UpdateState() = 0;
    //in Cpp you can not have a virtual constructor, but you can have a virtual destructor, which will
    //be overwritten in the inheriting classes' own destructor; (you can not instantiate an abstract class)
    virtual ~State() {
    }
};

class StateA :public State {
public:
    void UpdateState() override {
        std::cout << "Update state A" << std::endl;
    }

    StateA() {
        std::cout << "StateA is created!" << std::endl;
    }

    ~StateA() {
        std::cout << "StateA is destructed!" << std::endl;
    }
};

class StateB :public State {
public:
    void UpdateState() override {
        std::cout << "Update state B" << std::endl;
    }

    StateB() {
        std::cout << "StateB is created!" << std::endl;
    }

    ~StateB() {
        std::cout << "StateB is destructed!" << std::endl;
    }
};

class StateC :public State {
public:
    void UpdateState() override {
        std::cout << "Update state C" << std::endl;
    }

    StateC() {
        std::cout << "StateC is created!" << std::endl;
    }

    ~StateC() {
        std::cout << "StateC is destructed!" << std::endl;
    }
};

class StateController {
private:
    State* currentState = nullptr;

public:
    void Initialize() {
        currentState = new StateA();
    }

    void Update() {
        currentState->UpdateState();
    }

    void Transition(char c) {
        delete currentState;
        if (c == 'a') {
            currentState == new StateA();
        }
        else if (c == 'b') {
            currentState == new StateB();
        }
        else {
            currentState = new StateC();
        }
    }

    ~StateController() {
        delete currentState;
    }
};

int main()
{
    StateController stateController;
    stateController.Initialize();
    std::string str = "n";

    while (str[0] != 'q') {
        stateController.Update();
        std::cin >> str;
        std::cout << std::endl;

        if (str[0] == 'a' || str[0] == 'b' || str[0] == 'c') {
            stateController.Transition(str[0]);
        }
    }
}