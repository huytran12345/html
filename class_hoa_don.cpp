#include<iostream>
#include<string.h>
#include <stdlib.h>
using namespace std;
class hoa_don{
    private:
    char mvt[20];
    string tenvt;
    char loaiphieu[20];
    int ngay;
    float klg;
    float dongia;
    float tt;

    public:
    // Khoi tao khong tham so
    hoa_don();
    // khởi tạo có tham số 
    hoa_don(char mvt[20], string tenvt, char loaiphieu[20], int ngay, float klg, float dongia);
    // Khoi sao chep
    hoa_don(const hoa_don &hd);
    // cai dat phuong thuc huy
    ~hoa_don();
    void nhap();
    void in();
    void thanhtien();
};
void hoa_don::nhap(){
    cout<<"Nhap ma vat tu: ";
    cin>> this -> mvt;
    fflush(stdin);
    cout<<"Nhap ten vat tu: ";
    getline(cin, this -> tenvt);
    cout<<"Nhap loai phieu: ";
    cin>> this -> loaiphieu;
    cout<<"Nhap ngay ";
    cin>> this -> ngay;
    cout<<"Nhap khoi luong: ";
    cin>> this -> klg;
    cout<<"Nhap don gia: ";
    cin>> this -> dongia;
}

void hoa_don::in(){
    cout<<"Ma vat tu: " << this -> mvt << "\n";
    cout<<"Ten vat tu: " << this -> tenvt << "\n";
    cout<<"Loai phieu: " << this -> loaiphieu << "\n";
    cout<<"Ngay: " << this -> ngay << "\n";
    cout<<"Khoi luong: " << this -> klg << endl;
    cout<<"Don gia: " << this -> dongia << endl;
    thanhtien();
    cout<<"thanh tien: " << this -> tt << endl;
}
void hoa_don::thanhtien(){
    this -> tt = this -> dongia * this -> klg;
}
// khoi tao khong tham so
 hoa_don::hoa_don(){
    cout<< "Khoi tao khong tham so" << endl;
    strcpy(this -> mvt," ");
    this -> tenvt =" ";
    strcpy(this -> loaiphieu," ");
    this -> ngay = 0;
    this -> klg = 0.0f;
    this -> dongia = 0.0f;
 };
 hoa_don::hoa_don(char mvt[20], string tenvt, char loaiphieu[20], int ngay, float klg, float dongia)
 {
    cout<< "Khoi tao co tham so" << endl;
    strcpy(this -> mvt,mvt);
    this -> tenvt = tenvt;
    strcpy(this -> loaiphieu,loaiphieu);
    this -> ngay = ngay;
    this -> klg = klg;
    this -> dongia = dongia;
 };
 hoa_don::hoa_don(const hoa_don &hd){
    cout<< "Khoi tao sao chep" << endl;
    strcpy(this -> mvt,hd.mvt);
    this -> tenvt = hd.tenvt;
    strcpy(this -> loaiphieu,hd.loaiphieu);
    this -> ngay = hd.ngay;
    this -> klg = hd.klg;
    this -> dongia = hd.dongia;
 };
 hoa_don::~hoa_don(){
        cout<< "\n";
        cout<<"Huy hoa don"<<endl;
    }
int main(){
    hoa_don h1;
   // h1.nhap();
    h1.in();
    cout<< "\n";
    hoa_don h2("123","Hoa hong","phieu01",25,67.8,100);
    h2.in();
    cout<< "\n";
    hoa_don h3=h2;
    h3.in();
    return 0;
}