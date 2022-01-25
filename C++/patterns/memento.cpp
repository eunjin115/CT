#include <iostream>
#include <memory>
#include <string>
#include <stack>

class InputMemento {
public:
    InputMemento(std::string& input) {
        this->input = input;
    }
    std::string getState() {
        return this->input;
    }
private:
    std::string input;
};

class InputOriginator {
public:
    void setCurrentInput(std::string input) 
    {
        this->currentInput = input;
    }
    std::shared_ptr<InputMemento> saveCurrentInputToMemento() 
    {
        std::cout << "Save Current Input to Memento :" << currentInput << std::endl;
        std::shared_ptr<InputMemento> input_memento = std::make_shared<InputMemento>(currentInput);
        return input_memento;
    }
    void restoreFromInputMemento(std::shared_ptr<InputMemento> inputMemento) {
        this->currentInput = inputMemento->getState();
    }
    std::string getCurrentInput() {
        return currentInput;
    }

private:
    std::string currentInput;
};

class InputCareTaker {
public:
    void saveMemento(std::shared_ptr<InputMemento> inputMemento) {
        inputMementos.push(inputMemento->getState());
    }
    std::shared_ptr<InputMemento> popSavedMemento() {
        std::shared_ptr<InputMemento> ret = std::make_shared<InputMemento>(inputMementos.top());
        inputMementos.pop();
        return ret;
    }
private:
    std::stack<std::string> inputMementos;
};

int main() {
    std::shared_ptr<InputCareTaker> inputCareTaker = std::make_shared<InputCareTaker>();
    std::shared_ptr<InputOriginator> inputOriginator = std::make_shared<InputOriginator>();

    inputOriginator->setCurrentInput("abc");
    inputCareTaker->saveMemento(inputOriginator->saveCurrentInputToMemento()); //"abc" 저장 정보가 있는 객체를 caretaker에 저장 
    //input abc를 저장
    inputOriginator->setCurrentInput("def");
    inputCareTaker->saveMemento(inputOriginator->saveCurrentInputToMemento());
    //input def를 저장
    inputOriginator->setCurrentInput("ghi");

    inputOriginator->restoreFromInputMemento(inputCareTaker->popSavedMemento());
    std::cout << "Restore input : " << inputOriginator->getCurrentInput() << std::endl;

    inputOriginator->restoreFromInputMemento(inputCareTaker->popSavedMemento());
    std::cout << "Restore input : " << inputOriginator->getCurrentInput() << std::endl;


    return 0;
}