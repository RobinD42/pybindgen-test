
// An abstract base class
class A
{
public:
    A() {}
    virtual ~A() {}
    
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

    bool operator==(const B& other) { return false; }
    bool operator!=(const B& other) { return true; }

    B& operator+(const B& other) { return *this; }

    // anything special done for these?
    int __len__() { return 0; }  // yes, added to sequence methods structure
    int __int__() { return 0; }  // no but the method is still there
    
    operator bool() { return true; } // no
    
    static void staticMethod() {}
    
    int m_publicAttribute;
};


// derived class with protected members
class C : public B
{
public: 
    C() : B() {}
    C(int a, int b) : B(a, b)  {}

    //A* returnBaseClassPtr() { return this; }
    
    void baseClassParameterPtr(const A* ptr) {}
    void baseClassParameterRef(const A& ptr) {}
    
    
protected:
    int protectedMethod() { return 0; }
    virtual int protectedVirtualMethod() { return 0; }
    
    // int m_protectedAttribute;
};


