#include <iostream>

using namespace std;

class BaseFile {
public:
    virtual void Use() = 0;
    virtual ~BaseFile(){}
};

class HwpFile : public BaseFile  {
public:
    virtual void Use() {
        cout<<"Use HwpFile"<<endl;
    }
};

class DocFile : public BaseFile  {
public:
    virtual void Use() {
        cout<<"Use DocFile"<<endl;
    }
};


class BaseFileFactory {
public:
    BaseFile* CreateFile() {//factory method
        GetDataFromDB();
        BaseFile* baseFile = CreateNewFile();
        SaveLog();
        
        return baseFile;
    }
    virtual ~BaseFileFactory() {
        
    }
private:
    virtual void GetDataFromDB() = 0;
    virtual BaseFile* CreateNewFile() = 0;
    virtual void SaveLog() = 0;
};


class HwpFileFactory : public BaseFileFactory {
    
private:
    virtual void GetDataFromDB() {
        cout<<"Hwp file GetDataFromDB"<<endl;
    }
    virtual BaseFile* CreateNewFile() {
        cout<<"Hwp file CreateNewFile"<<endl;
        return new HwpFile();
    }
    virtual void SaveLog() {
        cout<<"Hwp file SaveLog"<<endl;
    }
};

class DocFileFactory : public BaseFileFactory {
    
private:
    virtual void GetDataFromDB() {
        cout<<"Doc file GetDataFromDB"<<endl;
    }
    virtual BaseFile* CreateNewFile() {
        cout<<"Doc file CreateNewFile"<<endl;
        return new DocFile();
    }
    virtual void SaveLog() {
        cout<<"Doc file SaveLog"<<endl;
    }
};

int main(int argc, const char * argv[]) {
    
    BaseFileFactory* factory = new DocFileFactory();
    BaseFile* file = factory->CreateFile();
    file->Use();
    
    delete factory;
    delete file;
    
    factory = new HwpFileFactory();
    file = factory->CreateFile();
    file->Use();
    
    return 0;
}