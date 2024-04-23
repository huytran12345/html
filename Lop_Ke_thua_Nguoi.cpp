#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
class Nguoi{
    private:
        string madd,ten;
    public:
        Nguoi(){
            cout << "Khoi tao mac dinh\n";
            this->madd=this->ten="";
        };
        ~Nguoi(){
            cout << "Huy doi tuong\n";
            this->madd=this->ten="";
        };
        void nhap(){
            cout << "Nhap ma dinh danh: "; 
            getline(cin,madd);
            cout << "Nhap Ho Ten: "; getline(cin,ten);
        };
        void xuat(){
            cout << "Ma dinh danh: " << madd << ", Ho ten: " << ten << endl;
        };
};
class Nhanvien:public Nguoi{
    private:
        int nam;
        float hsl;
        static float tienpc;
    public:
        
        Nhanvien(){
            cout << "khoi tao mac dinh\n";
            this->nam=2000;
            this->hsl=0;
        };
        void nhap(){
            this->Nguoi::nhap();
            cout << "Nhap nam sinh: "; cin >> this->nam;
            cout << "Nhap he so luong: "; cin >>  this->hsl;
        };
        void xuat(){
            this->Nguoi::xuat();
            cout << ", nam sinh: " << this->nam << ", he so luong: " << this->hsl << ", luong: " << tinhluong() << endl; 
        };
        float tinhluong(){
            return hsl*1550 + tienpc;
        };
        bool operator>(const Nhanvien &nv){
            return this->hsl < nv.hsl;
        };

};
float Nhanvien :: tienpc = 500;
int main(){
    Nguoi s1;
    s1.xuat();
    Nhanvien nv1;
    nv1.xuat();
    Nguoi ng;
    ng.nhap();
    ng.xuat();
   int n;
   do{
    cout << "Nhap n: "; cin >> n;
   }while(n<=0);
   cin.ignore();
   cout << "-----Nhap thong tin nhan vien------\n";
   Nhanvien *a=new Nhanvien[n];
   for(int i=0;i<n;i++){
     a[i].nhap();
   }
   for(int i=0;i<n;i++){
     a[i].xuat();
   }
   for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
        if(a[i]>a[j])
        swap (a[i],a[j]);
    }
   }
   for(int i=0;i<n;i++){
     a[i].xuat();
   }
   delete[] a;
}
