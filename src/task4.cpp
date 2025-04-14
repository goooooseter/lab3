#include <iostream>
#include <memory>
#include <vector>

class Subject {
public:
    void say_hello() const {
        std::cout << "Subject: Hello!\n";
    }

    ~Subject() {
        std::cout << "Subject destroyed.\n";
    }
};

class Observer {
private:
    std::weak_ptr<Subject> subject_ptr;

public:
    Observer(std::shared_ptr<Subject> subject) : subject_ptr(subject) {}

    void observe() {
        if (auto shared = subject_ptr.lock()) {
            shared->say_hello();
        }
        else {
            std::cout << "Observer: Subject no longer exists.\n";
        }
    }
};

int main() {
    std::shared_ptr<Subject> subject = std::make_shared<Subject>();
    Observer obs(subject);

    std::cout << "Observer tries to access Subject:\n";
    obs.observe();

    subject.reset();

    std::cout << "Observer tries to access Subject after deletion:\n";
    obs.observe();

    return 0;
}
