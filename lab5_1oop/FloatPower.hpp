//FloatPower.h
#pragma once
using namespace std;

class FloatPower {
  private:
    float first;
    float second;
  public:
    float GetFirst() const { return first; };
    float GetSecond() const { return second; };
    void SetFirst(float value);
    void SetSecond(float value);

    bool Init(float x, float y);
    void Display() const;
    void DisplayResult();
    void Read();

    float power();
    
    //2.1
    FloatPower();
    FloatPower(float, float);
    FloatPower(const FloatPower&);
    
    FloatPower& operator =(const FloatPower&);
    friend istream& operator >>(istream&, FloatPower&);
    friend ostream& operator <<(ostream&, FloatPower a);
    operator string() const;
    
    FloatPower& operator ++();
    FloatPower& operator --();
    FloatPower operator ++(int);
    FloatPower operator --(int);
    
};
