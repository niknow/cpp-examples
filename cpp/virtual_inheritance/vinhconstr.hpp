#pragma once

/*
There is an important consequence of virtual inheritance when it comes to initialization of objects:
In the below example, we have constructed a diamond shaped class hierarchy where the children 
D1 and D2 initialize their version of the base B in a different way. In non-virtual inheritance
the grandchild DD can defer the initialization of B to its parents D1 and D2 and as each have 
their own copy of B, there is no problem with the different initalizations. 
In virtual inheritance, the grandchild DD only has one copy of B and thus it has to initialize it
itself as otherwise it would not be clear, which parent D1 or D2 would be responsible for the
initialization.
*/

class B {
public:
    B(int i) : i_(i) {};
    int get_i() { return i_; };
private:
    int i_;
};

/* --------------------------------
   non-virtual inheritance
   ------------------------------- */
class D1 : public B {
public:
    D1(int i, int j) : B(i+1), j_(j) {};        // D1 initializes B different from D2 (!)
    int get_j() { return j_; };
private:
    int j_;
};

class D2 : public B {
public:
    D2(int i, int k) : B(i+2), k_(k) {};        // D2 initializes B different from D1 (!)
    int get_k() { return k_; };
private:
    int k_;
};

class DD : public D1, public D2 {
public:
    DD(int i, int j, int k, int l) : D1(i, j), D2(i, k), l_(l) {}; // the classes D1 and D2 initialize their versions of B themselves
    int get_l() { return l_; };
private:
    int l_;
};

/* --------------------------------
   virtual inheritance
   -------------------------------- */
class D1v : virtual public B {
public:
    D1v(int i, int j) : B(i+1), j_(j) {};
    int get_j() { return j_; };
private:
    int j_;
};

class D2v : virtual public B {
public:
    D2v(int i, int k) : B(i+2), k_(k) {};
    int get_k() { return k_; };
private:
    int k_;
};

class DDv : public D1v, public D2v {
public:
    DDv(int i, int j, int k, int l) : B(i), D1v(i, j), D2v(i, k), l_(l) {};  // because of virtual inheritance, DDv has to initialize B as well
    int get_l() { return l_; };
private:
    int l_;
};

