#include <iostream>
#include <memory>
#include "file.hpp"

void useUniquePtr() {
    while (true) {
        std::unique_ptr<int[]> data(new int[1000]);
    }
}

int main() {
    {
        File file("test.txt");
        file.write("������ RAII � ������.\n");
    }
    useUniquePtr();
    return 0;
}
