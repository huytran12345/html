#include<iostream>
using namespace std;
template <class T>
T Max(T a, T b){
    if(a>b) return a;
    return b;
}
int main(){
    int a=5, b=7;
    float x=3.5, y=3.4;
    string str1 = "HANOI", str2 = "hanoi";
    cout << "MAX(a,b) = " << Max<string>(str1,str2);
}