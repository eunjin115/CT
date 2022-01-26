#include <iostream>
#include <memory>
#include <string>
#include <stack>

class Memento 
{

private:
    std::string state;

public:
    Memento(std::string input) 
    {
        state = input;
    }
    std::string GetState() //���� ���� ���� 
    {
        return state;
    }

};

class Originator 
{

private:
    std::string current; //���� ���� �� ���ڿ� 
    std::string input; //�޸��忡 ���� ���ڿ� 

public:
    void SetCurrent(std::string str)
    {
        current = str;
        input += current;
        std::cout << "Written at Notepad : " << input << std::endl;
    }

    std::shared_ptr<Memento> SaveCurrentToMemento()
    {
        std::shared_ptr<Memento> current_memento = std::make_shared<Memento>(current); //���� ���ڿ� �����Ͽ� �޸��� ��ü ���� 
        return current_memento;
    }

    void RestoreFromMemento(std::shared_ptr<Memento> Memento) 
    {
        current = Memento->GetState(); //�޸��� ��ü�� ���� �� ���� ������ 
        int tmp = input.find(current);
        input.erase(tmp, current.size()); //Restore�� �ϸ鼭 state�� ���� �� ���� ����� 
    }

    void GetCurrent() 
    {
        std::cout << "Restore Notepad : " << input << "\n";
    }
};

class CareTaker 
{
public:

    void SaveMemento(std::shared_ptr<Memento> Memento) 
    {
        Mementos.push(Memento);
    }
    std::shared_ptr<Memento> PopSavedMemento() 
    {
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
    caretaker->SaveMemento(originator->SaveCurrentToMemento()); //"abc" ���� ������ �ִ� �޸��並 caretaker�� ���� 

    originator->SetCurrent("def");
    caretaker->SaveMemento(originator->SaveCurrentToMemento()); //"def" ���� 

    originator->SetCurrent("ghi");
    caretaker->SaveMemento(originator->SaveCurrentToMemento()); //"ghi" ���� 


    originator->RestoreFromMemento(caretaker->PopSavedMemento());  //ctrl + z�� ���� �� ó�� �������� �ǵ��� 
    originator->GetCurrent();

    originator->RestoreFromMemento(caretaker->PopSavedMemento());
    originator->GetCurrent(); //������ ����� ���ڿ� ����� ��� 

    originator->RestoreFromMemento(caretaker->PopSavedMemento());
    originator->GetCurrent();
   
    return 0;
}
