#include<iostream>

using namespace std;
class connguoi{
    protected:
        string CMND;
        string Hoten;
        string gioitinh;
    public:
        void NhapCN();
        void XuatCN();
};
void connguoi::NhapCN(){
    cout<<"Nhap CMND: ";cin>>CMND;
    cout<<"Nhap ho ten: ";fflush(stdin);getline(cin,Hoten);
    cout<<"Nhap gioi tinh: ";cin>>gioitinh;
} 
void connguoi::XuatCN(){
    cout<<"CMND: "<< CMND<<endl;
    cout<<"Ho ten: "<<Hoten<<endl;
    cout<<"Gioi tinh: "<<gioitinh<<endl;
}
class Sinhvien:public connguoi{
    private:
        string Masv;
        float DTB;
    public:
        void NhapSV();
        void XuatSV();
};
void Sinhvien::NhapSV(){
    this->NhapCN();
    cout<<"Nhap Ma SV: ";cin>>Masv;
    cout<<"Nhap DTB: ";cin>>DTB;
}
void Sinhvien::XuatSV(){
    this->XuatCN();
    cout<<"Ma SV: "<<Masv;
    cout<<"DTB: "<<DTB;
}
int main(){
    Sinhvien sv;
    sv.NhapSV();
    sv.XuatSV();
}