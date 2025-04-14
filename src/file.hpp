#pragma once

#include <fstream>
#include <string>

class File {
public:
    File() = default;
    File(const std::string& filename);
    ~File();
    void write(const std::string& text);

private:
    std::unique_ptr<std::ofstream> file;
};
