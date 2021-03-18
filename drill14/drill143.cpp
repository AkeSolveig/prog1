#include "std_lib_facilities.h"
class A {
	virtual void pvf() =0;
};
class B1 : public A {
public:
    virtual void vf() { cout << "B1::vf()"; << endl }
    void f() { cout << "B1::f()"; << endl }
    virtual void pvf() {cout << "B1::pvf()" << endl;}
};

class D1 : public B1 {
public:
    void vf() { cout << "D1::vf()"; << endl }
    void f()  { cout << "D1::f()"; << endl }
};

class D2 : public D1 {
public:
    void pvf() { cout << "D2::pvf()"; << endl }
};

class B2 {
public:
    virtual void pvf() =0;
};

class D21 : public B2 {
public:
    void pvf() { cout << s << endl; }
    string s;
};

class D22 : public B2 {
public:
    void pvf() { cout << n << endl;}
    int n;
};

void f(B2& b2)
{
    b2.pvf();
}

int main() {
	cout << "---------------------------------" << endl;
    B1 b1;
    b1.vf();
    b1.f();

    cout << "---------------------------------" << endl;
    D1 d1;	
    d1.vf();
    d1.f();

    cout << "---------------------------------" << endl;
    B1& bref = d1;
    bref.vf();
    bref.f();

    cout << "---------------------------------" << endl;
    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();
    
    cout << "---------------------------------" << endl;
    D21 d21;
    d21.s = "d21.s";
    D22 d22;
    d22.n = 22;
    f(d21);
    f(d22);

    keep_window_open();
}