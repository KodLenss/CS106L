#include <class.h>

long long obj::counter = 0;
obj& obj::operator=(const obj& other) {
    if (this != &other) {
        name = other.name;
    }
    return *this;
}