#include <iostream>
using namespace std ;

float circlearea(float radius){
    float area = 3.14*radius*radius;
    return area;
}

int main(){
    float x;
    cout<<"Enter the radius of the circle : ";
    cin >> x;
    float ans = circlearea(x);

    cout << "area of the circle is : "<<ans<<endl;

}