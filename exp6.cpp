#include <iostream>
using namespace std;

class Box
{
public:
    Box() { cout << "Box created" << endl; }
    ~Box() { cout << "Box destroyed" << endl; }
    void show() { cout << "Box is being used" << endl; }
};

class Holder
{
    Box *p;
public:
    Holder(Box *b) : p(b) {}
    ~Holder()
    {
        delete p;
        cout << "Holder destroyed" << endl;
    }
    Box *operator->() { return p; }
};

int main()
{
    cout << "----- Holder -----" << endl;
    {
        Holder h(new Box());
        h->show();
    }
    cout << "\nProgram completed successfully." << endl;
    return 0;
}