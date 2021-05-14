#pragma once
#include <initializer_list>

class MyClass {
public:
    int x_, y_;

    // old school constructor
    MyClass(int x, int y) : x_(x), y_(y) {};

    // initializer list constructor
    MyClass(std::initializer_list<int> l) {
        std::initializer_list<int>::iterator p = l.begin();
        x_ = *p;
        p++;
        y_ = *p;
    }
};

MyClass f() {
    return { 8, 9 };    // this calls the initializer list constructor of the return type
}
