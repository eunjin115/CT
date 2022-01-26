#include <iostream>
#include <memory>
#include <string>
#include <stack>

class Memento {
private:
    std::string state;

public:
    Memento(std::string input) {
        state = input;
    }
    std::string GetState() 
    {
        return state;
    }

};

class Originator {
private:
    std::string current;
    std::string input;

public:
    void SetCurrent(std::string str)
    {
        current = str;
        input += current;
        std::cout << "Written at Notepad : " << input << std::endl;
    }

    std::shared_ptr<Memento> SaveCurrentToMemento()
    {
        std::shared_ptr<Memento> current_memento = std::make_shared<Memento>(current);
        return current_memento;
    }

    void RestoreFromMemento(std::shared_ptr<Memento> Memento) 
    {
        current = Memento->GetState();
        int tmp = input.find(current);
        input.erase(tmp, current.size());
    }

    void GetCurrent() 
    {
        std::cout << "Restore Notepad : " << input << "\n";
    }
};

class CareTaker {
public:
    void SaveMemento(std::shared_ptr<Memento> Memento) {
        Mementos.push(Memento);
    }
    std::shared_ptr<Memento> PopSavedMemento() {
        std::shared_ptr<Memento> ret = Mementos.top();
        Mementos.pop();
        return ret;
    }
private:
    std::stack<std::shared_ptr<Memento>> Mementos;
};

int main() {
    std::shared_ptr<CareTaker> caretaker = std::make_shared<CareTaker>();
    std::shared_ptr<Originator> originator = std::make_shared<Originator>();

    originator->SetCurrent("abc");
    caretaker->SaveMemento(originator->SaveCurrentToMemento()); //"abc" 저장 정보가 있는 메멘토를 caretaker에 저장 

    originator->SetCurrent("def");
    caretaker->SaveMemento(originator->SaveCurrentToMemento()); //"def" 저장 

    originator->SetCurrent("ghi");
    caretaker->SaveMemento(originator->SaveCurrentToMemento()); //"ghi" 저장 


    originator->RestoreFromMemento(caretaker->PopSavedMemento());  //ctrl + z를 누른 것 처럼 이전으로 되돌림 
    originator->GetCurrent();

    originator->RestoreFromMemento(caretaker->PopSavedMemento());
    originator->GetCurrent();

    originator->RestoreFromMemento(caretaker->PopSavedMemento());
    originator->GetCurrent();
   
    return 0;
}
