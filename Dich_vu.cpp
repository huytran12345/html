#include<iostream>
#include<string>

using namespace std;
class DichVu{
    private:
        int madv;
        string ten;
        float gia;
    public:
        DichVu();
        void nhap(){
            cout<<"nhap ma dich vu :";
            cin>>madv;
            cout<<"nhap ten dich vu";
            cin.ignore();getline(cin,ten);
            cout<<"nhap gia cuoc:";
            cin>>gia;
        }
        void xuat(){
            cout<<"MA DICH VU"<<madv<<"  TEN DICH VU :"<<ten<<"  GIA CUOC:"<<gia<<endl;
            
        }
        float laygiacuoc(){
            return gia;
        }
};
class

