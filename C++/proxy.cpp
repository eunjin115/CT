#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Image {
public:
    virtual void renderImage() = 0;
};

class RealImage : public Image {
public:
    RealImage(const string filePath) {
        cout << "Load Image:" << filePath << endl;
    }
    virtual void renderImage(){
        cout << "Render real image" << endl;
    }
};

class ProxyImage : public Image {
private:
    std::shared_ptr<Image> real_image; 
    string filePath;
public:
    ProxyImage(string filePath) : real_image(nullptr) {
        this->filePath = filePath;
    }

    virtual void renderImage(){
        if (real_image == nullptr) {
            real_image = std::make_shared<RealImage>(filePath);
        }
        real_image->renderImage();
    }
};

//client
int main() {
    std::shared_ptr<Image> p1 = std::make_shared<ProxyImage>("/web/image/test.png");

    p1->renderImage();

    return 0;
}