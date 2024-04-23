#include <bits/stdc++.h>
#include<iostream>
#include<string>
using namespace std;

class Phuongtiengiaothong
{
private:
    string hangsx,ten;
    int nam;
    float vantoc;
public:
    void nhap();
    void xuat();
    bool operator>(const Phuongtiengiaothong &pt) const;

};
void Phuongtiengiaothong::nhap(){
    cout<<"Hangsx: "; cin >>hangsx;
    cout<<"Ten: "; cin>>ten;
    cout<<"nam: "; cin>>nam;
    cout<<"Vantoc: "; cin>>vantoc;
}
void Phuongtiengiaothong::xuat(){
    cout<<"Hangsx: " <<hangsx<<" Ten: " << ten << " Nam: " <<nam <<" Vantoc: " <<vantoc<<endl;
}
bool Phuongtiengiaothong::operator>(const Phuongtiengiaothong&pt) const{
    return this->vantoc > pt.vantoc;
}
int main(){
    int n;
    cout<<"Nhap n: "; cin>>n;
    Phuongtiengiaothong a[n];
    for (int i = 0; i < n; i++)
    {
        a[i].nhap();
    }
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i] > a[j]){
                swap(a[i],a[j]);
            }
        }
        
    }
    
    cout<<"-------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
}


/* 
class Sinhvien
{
private:
    int ma;
    string hoten;
public:
    friend istream &operator >>(istream &is, Sinhvien &sv){
        cout<<"Ma: "; is>>sv.ma;
        cout<<"hoten: ";is>>sv.hoten;
        return is;
    };
    friend ostream &operator <<(ostream &os, Sinhvien &sv){
        os<<"Ma: " << sv.ma <<" hoten: " << sv.hoten;
        return os;
    }
};
int main(){
    int n;
    cout<<"Nhap ma: "; cin>>n;
    Sinhvien *sv = new Sinhvien[n];
    for (int i = 0; i < n; i++)
    {
        cin>>sv[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<sv[i];
    }
} */



/* class Hanghoa
{
private:
    int mahang;
    string ten;
    string maloai;
public:
    friend istream& operator>>(istream&is, Hanghoa &hh){
        cout<<"Mahang: "; is>>hh.mahang;
        cout<<"Ten: "; is>>hh.ten;
        cin.ignore();
        cout<<"Maloai: "; getline(is,hh.maloai);
        return is;
    }
    friend ostream& operator<<(ostream &os, Hanghoa &hh){
        os<<"Mahang: " <<hh.mahang << " Ten: " << hh.ten << " Maloai: " << hh.maloai <<endl;
    }
    bool thuoc(string thuoc);
    // friend void hienthi(Hanghoa &hh,int n, string t);
};
bool Hanghoa::thuoc(string thuoc){
    return this->maloai == thuoc;
}


int main(){
    int n;
    cout<<"Nhap ds: "; cin>>n;
    Hanghoa *hh = new Hanghoa[n];
    for (int i = 0; i < n; i++)
    {
        cin>>hh[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<hh[i];
    }
    cout<<"\n------------------------------------------\n";
    // cin.ignore();
    cout<<"Nhap maloai can tim: ";
    string thuoc = "CONG NGHE";// getline(cin,thuoc);
    
    for (int i = 0; i < n; i++)
    {
        if(hh[i].thuoc(thuoc)){
            cout <<hh[i];
        }
    }   
}
*/