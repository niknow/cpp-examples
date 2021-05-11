#pragma once
#include <initializer_list>

class MyClass {
public:
    int x_, y_;

    MyClass(int x, int y) : x_(x), y_(y) {};
    MyClass(std::initializer_list<int> l) {
        std::initializer_list<int>::iterator p = l.begin();
        x_ = *p;
        p++;
        y_ = *p;
    }

    

};