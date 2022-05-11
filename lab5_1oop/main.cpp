#include <iostream>
#include "FloatPower.hpp"
#include "Exc.hpp"
#include "ExcInh.hpp"

using namespace std;

FloatPower makeFloatPower(float x, float y);
void _unexpected_to_bad();


int main() {
    set_unexpected(_unexpected_to_bad);
    set_terminate(_unexpected_to_bad);

    FloatPower a;
    try {
        cin >> a;
        cout << a;
    }
    catch (Exc a){
        cerr << a.what() << endl;
    }

    

    try {
        --a;
        cout << "first = " << a.GetFirst() << endl;
    }
    catch (ExcInh &a){
        cerr << a.what() << endl;
    }

    try {
        --a;
        cout << "first = " << a.GetFirst() << endl;
    }
    catch (ExcInh* a) {
        cerr << a->what() << endl;
    }

    try {
        FloatPower b(0, 2);
    }
    catch (invalid_argument b) {
        cerr << b.what() << endl;
    }

    return 0;
}


FloatPower makeFloatPower(float x, float y)
{
    FloatPower nn;
    if (!nn.Init(x, y))
        cout << "wrong argument to Init (first)" << endl;
    return nn;
}

void _unexpected_to_bad() {
    cerr << "bad_exception" << endl;
    throw;
}
