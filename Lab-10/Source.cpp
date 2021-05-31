#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Program {
private:
    string n;

public:
    const string& getName() const { return n; }
    string& getName() { return n; }

    Program(const string& n) : n(n) {
        cout << " Object " << n << " created! " << endl;
    };

    Program() : n("Unknown") {
        cout << " Object " << n << " created! " << endl;
    };

    ~Program() {
        cout << " Object " << n << " deleted! " << endl;
    };
};

int main(int argc, char* argv[]) {
    int a = 321;
    int* a_ptr = &a;
    int* b = new int[8];
    int* b_init = b;

    void* p1 = nullptr;

    cout << " Zero pointer = " << p1 << endl;

    cout << "a = " << a << endl;

    cout << " Pointer a_ptr (" << a_ptr << ") with the meaning " << *a_ptr << endl;

    for (int i = 0; i < 8; i++)
        b[i] = i;
    cout << " Pointer on array (" << b << ") with the meaning " << *b << endl;

    cout << " Enlarged pointer on array (" << ++b << ") with the meaning " << *b << endl;
    cout << " Inequality = " << (b - b_init) * sizeof(int) << "byte" << endl;

    b = b_init;
    cout << " Proof that a [i] = i [a] = * (a + i) " << endl;
    cout << "b[2] = " << b[2] << endl;
    cout << "2[b] = " << 2[b] << endl;

    delete[] b;

    cout << " Raw pointer " << endl;
    Program* a1 = new Program(" a1");
    delete a1;

    cout << " A raw pointer to the object in the  scope area" << endl;
    Program* a2; {
        Program a3 = Program(" a3");
        a2 = &a3;
        cout << a2->getName() << endl;
    }
    cout << a2->getName() << endl;

    cout << " Raw pointer in scope area " << endl; {
        Program* a4 = new Program(" a4");
    }
    cout << " E3 still not deleted " << endl;

    cout << " Smart pointer unique_ptr " << endl; {
        unique_ptr<Program> a5 = make_unique<Program>(" a5");
    }

    cout << " Smart pointer shared_ptr, a7 ссылки a6 " << endl;
    shared_ptr<Program> a7; {
        auto a6 = make_shared<Program>(" a6");
        a7 = a6;
    }
    cout << " a6 is stiil alive with  a7 " << endl;
    a7.reset();

    cout << " Smart pointer weak_ptr " << endl;
    weak_ptr<Program> a8; {
        auto a9 = make_shared<Program>(" a9");
        a8 = a9;
    }
    cout << (a8.expired() ? " Е7 has done.. " : " Е7 is still alive ") << endl;
    getchar();
}