#include <bits/stdc++.h>
using namespace std;
#define PI 3.14

class circle{
    float radius;
    public:
        circle();
        void getradius();
        float area();
        void showradius();
};

circle :: circle(){
    radius = 10;
}

void circle :: getradius(){
    cout << "enter radius";
    cin >> radius ;
}

void circle :: showradius(){
    cout << radius << endl;
}

float circle :: area(){
    float area;
    area = PI*radius*radius;
    return area;
}

int main(){
    circle C1;
    C1.showradius();
    float a = C1.area();
    cout << "area of circle : " << a;
    return 0;
}

