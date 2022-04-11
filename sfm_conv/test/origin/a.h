#include <iostream>
#include <memory>
#include <boost/shared_ptr.hpp>
using namespace std;

namespace Test {

class A {
public:
    int x;
public:
	A() : x(0) { cout << "A()" << endl; }
    A(const A & a) : x(a.x) { cout << "A(A&)" << endl; }
	~A() { cout << "~A()" << endl; }
}; // class A

} // namespace Test

