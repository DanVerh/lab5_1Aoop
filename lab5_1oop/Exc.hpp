#pragma once
#include <iostream>
#include <string>

using namespace std;

class Exc {
    string msg;
public:
    Exc() throw()
        :msg()
    {}
    
    Exc(const string& msg1) throw()
        :msg(msg1)
    {}
    
    string what() const throw() { return "Exception: " + msg; }
    
    virtual ~Exc() {}
};
