#pragma once
#include<iostream>
#include<exception>

using namespace std;

class ExcInh : public exception
{
public:
    virtual const char* what() const throw() { return "Inherited exception: number = 0"; }
};
