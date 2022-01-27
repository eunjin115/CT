//https://d-yong.tistory.com/44?category=685345 의 예제 수정 

#include <iostream>
#include <memory>

using namespace std;

class NetworkManager {
public:

    static shared_ptr<NetworkManager> Instance()
    {
        if (inst == nullptr)
        {
            inst = std::shared_ptr<NetworkManager>(new NetworkManager);
            cout << inst.use_count() << "\n";

        }
        return inst;
    }

    void connect()
    {
        cout << "connect..." << endl;
    }

    void disconnect() 
    {
        cout << "disconnect..." << endl;
    }

private:
    NetworkManager() {}
    static shared_ptr<NetworkManager> inst;
};

shared_ptr<NetworkManager> NetworkManager::inst = nullptr;

int main(int argc, const char* argv[])
{
    shared_ptr<NetworkManager> networkManager = NetworkManager::Instance();
    networkManager->connect();
    networkManager->disconnect();
    return 0;
}