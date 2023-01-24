#include <iostream>
#include <cmath>

class Vector
{
private:
//members
    float X;
    float Y;
    float Z;
    
public:
//methods
    float get_X () {std::cout<<"X = "<< X<<"\n"; return X;}
    float get_Y () {std::cout<<"Y = "<< Y<<"\n"; return Y;}
    float get_Z () {std::cout<<"Z = "<< Z<<"\n"; return Z;}
    
    void set_X (float value) { X = value ;}
    void set_Y (float value) { Y = value ;}
    void set_Z (float value) { Z = value ;}
    
    double magnitude () { return sqrt(X*X + Y*Y + Z*Z); }

//overloaded constructors

    Vector() : X {3} , Y {4},  Z{5}  { }// No arg constructor
    Vector(float X_val) : X {X_val}, Y {10}, Z{10} { } // One arg constructor
    Vector(float X_val, float Y_val) : X {X_val} , Y {Y_val}, Z{13}  { } // Two args constructor
    
};

int main(int argc, char **argv)
{
    
	Vector myVec;
    Vector myVec1(10);
    Vector myVec2(5, 12);
    
    myVec.set_X(50);
    myVec.get_X();
    std::cout<<"magnitude of myVec2: "<< myVec2.magnitude()<<std::endl;
    
	return 0;
}

