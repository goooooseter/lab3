#include <iostream>
#include <memory>

class SharedData {
public:
    SharedData(int v) : value(v) {
        std::cout << "SharedData created.\n";
    }
    ~SharedData() {
        std::cout << "SharedData destroyed.\n";
    }

    int value;
};

int main() {
    std::shared_ptr<SharedData> data = std::make_shared<SharedData>(42);

    {
        std::shared_ptr<SharedData> data2 = data;
        std::cout << "Value: " << data2->value << "\n";
        std::cout << "Reference count: " << data.use_count() << "\n";
    }

    std::cout << "After data2, counter: " << data.use_count() << "\n";
    return 0;
}