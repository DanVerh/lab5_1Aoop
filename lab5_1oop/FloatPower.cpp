//FloatPower.cpp
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include "FloatPower.hpp"
#include "Exc.hpp"
#include "ExcInh.hpp"

using namespace std;

void FloatPower::SetFirst(float value) {
    if (value == 0) throw invalid_argument("number can't be 0");
    first = value;
}

void FloatPower::SetSecond(float value) {
    second = value;
}


bool FloatPower::Init(float x, float y) {
    if (x != 0) {
        first = x;
        second = y;
        return true;
    }
    else
        return false;
}

void FloatPower::Display() const {
    cout << "number " << first << " to power " << second << endl;
}

void FloatPower::Read()
{
    int x, y;
    do {
        cout << "number =  ";
        cin >> x;
        cout << "power = ";
        cin >> y;
    } while (!Init(x, y));
}

float FloatPower::power() {
    return pow(first, second);
}

void FloatPower::DisplayResult() {
    cout << "Result = " << pow(first, second) << endl;
}




//2.1
FloatPower::FloatPower() {
    first = 1;
    second = 1;
}

FloatPower::FloatPower(float a, float b) {
    if (a == 0) throw invalid_argument("number can't be 0");
    first = a;
    second = b;
}

FloatPower::FloatPower(const FloatPower& a) {
    *this = a;
}


FloatPower& FloatPower::operator =(const FloatPower& a)  {
    if (a.first == 0) throw invalid_argument("number can't be 0");
    first = a.first;
    second = a.second;
    return *this;
}


istream& operator >>(istream& in, FloatPower& a) {
    cout << "number: "; in >> a.first;
    if (a.first == 0) throw Exc("number can't be 0");
    cout << "power: "; in >> a.second;
    return in;
}

ostream& operator <<(ostream& out, FloatPower a) {
    out << "Power function: " << a.power() << endl;
    return out;
}

FloatPower::operator string() const {
    FloatPower a = *this;
    stringstream ss;
    ss << a.power();
    return ss.str();
}

FloatPower& FloatPower::operator ++() {
    ++first;
    if (first == 0) throw ExcInh();
    return *this;
}
FloatPower& FloatPower::operator --()  {
    --first;
    if (first == 0) throw new ExcInh();
    return *this;
}
FloatPower FloatPower::operator ++(int)  {
    FloatPower tmp = *this;
    this->second++;
    return tmp;
}
FloatPower FloatPower::operator --(int) {
    FloatPower tmp = *this;
    this->second--;
    return tmp;
}
