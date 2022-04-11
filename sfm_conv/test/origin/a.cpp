#include <iostream>
#include <memory>
#include "a.h"
using namespace std;
using namespace Test;

void func1(A a) {
    cout << a.x + 1 << endl;
}
void func2(A & a) {
	cout << a.x + 2 << endl;
}
void func3(A * a) {
	cout << a->x + 3 << endl;
}
void func4(shared_ptr<A> a) {
    cout << a->x + 4 << endl;
}
int main() {
	cout << sizeof(A) << endl;

    A a1, a2, * a3 = new A();
    shared_ptr<A> a4(new A());

    func1(a1);
    cout << a1.x + 11 << endl;
	func2(a2);
    cout << a2.x + 12 << endl;
	func3(a3);
	cout << a3->x + 13 << endl;
    func4(a4);
    cout << a3->x + 14 << endl;

	delete a3;
	return 0;
}

