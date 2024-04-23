#include<bits/stdc++.h>
using namespace std;
class Time{
    private:
    int gio,phut,giay;
    public:
    Time();
    Time(int gio, int phut, int giay);
    ~Time();
    friend istream&operator>>(istream &is,Time &tg);
    friend ostream&operator<<(ostream &os,Time tg);
    int doisanggiay() const;
    bool operator >(const time& tg);
};
Time::Time(){
    cout <<"Khoi tao co tham so\n";
    this->gio=this->phut=this->giay=0;
}
Time::Time(int gio, int phut, int giay){
    cout << "Khoi tao co tham so\n";
    this->gio=gio;
    this->phut=phut;
    this->giay=giay;
}
Time::~Time(){
cout <<"Huy tham so\n";
}
istream&operator>>(istream &is,Time &tg){
    cout <<"Nhap gio: "; is>>tg.gio;
    cout <<"Nhap phut: "; is>>tg.phut;
    cout <<"Nhap phut: "; is>>tg.giay;
    return is;
}
ostream&operator<<(ostream &os,Time tg){
    os << tg.gio << "gio"<< tg.phut << "phut" <<tg.giay <<"giay" <<endl;
    return os;
}
int Time::doisanggiay()const{
    return this->gio*3600 + this->phut*60 + this->giay;
}
bool Time::operator>(const Time& tg){
    return this->doisanggiay() < tg.doisanggiay();
}
int main(){
    // Time t1;
    // cout <<t1;
    // Time t2(1,0,0);
    // cout <<t2;
    int n;
    cout << "Nhap n";
    cin >> n;
    Time a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    } 
    for(int i=0;i<n;i++){
        cout<<a[i];
    } 
}