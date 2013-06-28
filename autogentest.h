
// An abstract base class
class A
{
public:
    A();
    virtual void virtualMethod1() = 0;  // pure virtual
    virtual void virtualMethod2() {}    // normal virtual
};

// derived class
class B : public A
{
public: 
    B() : A() {}
    B(int a, int b) {} // overloaded ctor

    virtual void virtualMethod1() {}  // implement pure virtual

    void overloadedMethod() {}
    void overloadedMethod(int a, int b) {}
    void overloadedMethod(double d) {}

    void defaultArgs(int a = 0, int b = 123) {}

    bool operator==(const B& other) {}
    bool operator!=(const B& other) {}
    
};
