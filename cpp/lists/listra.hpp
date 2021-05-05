#pragma once

template <class X>
class ListRandomAccess : public std::list<X> {
public:
    X& operator[](int index) {
        typename std::list<X>::iterator p = this->begin();
        std::advance(p, index);
        X& e = *p;
        return e;
    }
};
