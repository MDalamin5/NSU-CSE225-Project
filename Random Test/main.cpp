#include <iostream>

class MyClass {
public:
    void callMain() {
        int (*mainPtr)() = reinterpret_cast<int(*)()>(main);
        mainPtr();
    }
};

int main() {
    std::cout << "Inside main function." << std::endl;
    return 0;
}

int main() {
    MyClass obj;
    obj.callMain();
    return 0;
}