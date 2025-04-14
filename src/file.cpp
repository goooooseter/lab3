#include "file.hpp"

File::File(const std::string& filename)
    : file(std::make_unique<std::ofstream>(filename)) {}

File::~File() {
    if (file && file->is_open()) {
        file->close();
    }
}

void File::write(const std::string& text) {
    if (file) {
        *file << text << std::endl;
    }
}