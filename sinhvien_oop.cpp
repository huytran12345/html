#include<iostream>
#include<string.h>
#include <stdlib.h>
using namespace std;
class Sinhvien
{
private:
    char MaSV [20];
    char tenSV [20];
    int namsinh;
    float toan,ly,hoa;
public:
    //default constructor 

    //dạng không tham số
    Sinhvien();
    //có tham số
    // Sinhvien(char Masv[],char tensv[],int namsinh,);
    //sao cheps
    Sinhvien(const Sinhvien &sv);
    //Khởi tạo có tham số mang giá trị ngầm định (ko tham số + có tham số)
    //- không định nghĩa pt khởi tạo không tham số -trong khai báo phương thức khởi tạo có tham số gán default value cho các tham số(chỉ phần khai báo)
    Sinhvien(char Masv[] = "", char tensv[] = "", int namsinh = 1900, float toan =0, float ly =0, float hoa =0 );
    void nhap();
    void xuat();
    void tinhTB();
};
Sinhvien::Sinhvien(){
    cout<<"Hien thi khong tham so\n";
    strcpy (this -> MaSV,"");
    strcpy (this -> tenSV,"");
    this -> namsinh = 1990;
    
};

Sinhvien::Sinhvien(const Sinhvien &sv){
    cout << "Khoi tao sao chep\n";
    strcpy(this -> Masv,sv.Masv);
    strcpy(this -> tensv, sv.tensv)
}
void Sinhvien::nhap()
{
    cout << "Nhap tt sinh vien: \n";
    cout<< "MASV: ";
    cin >> this -> MaSV;
    cout << "TEN: ";
    cin >> this -> tenSV;
    cout << "NAMSINH: ";
    cin >> this -> namsinh;
    cout << "DT: ";
    cin >> this -> toan;
    cout << "DL: ";
    cin >> this -> ly;
    cout << "DH: ";
    cin >> this -> hoa;
    
}

void Sinhvien::xuat(){
    cout << "MASV: "<< this -> MaSV << "  ";
    cout << "TEN: "<< this -> tenSV << "  ";
    cout << "DT: "<< this -> toan << "  ";
    cout << "DL: "<< this -> ly << "  ";
    cout << "DH: " << this -> hoa << "  ";
}
void Sinhvien:: tinhTB(){
    float diemtb;
    diemtb = (this -> toan + this -> ly + this -> hoa)/3;
    cout << "DIEMTB: " << diemtb ;
}
typedef int i ;

int main(){
    Sinhvien sv1,sv2;
    // sv1.nhap();
    sv1.xuat();
    sv1.tinhTB();

}