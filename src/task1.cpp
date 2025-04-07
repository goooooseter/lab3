#include <iostream>
#include <thread>

void createMemoryLeak() {
    while (true) {
        int* leak = new int[1000];
    }
}

int main() {
    std::cout << "Task1\n";
    createMemoryLeak();
    return 0;
}
