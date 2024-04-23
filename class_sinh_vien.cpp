#include<stdio.h>
#include<string.h>
#include <stdlib.h>
class Sinhvien
{
private:
    char MaSV [10];
    char tenSV[50] ;
    int namsinh;
    float toan,ly,hoa,diemTB;
public:
    //default constructor 

    //khong tham so
    Sinhvien();
    //co tham so
    Sinhvien(char Masv[],char tenSV[] ,int namsinh  ,float toan , float ly, float hoa);
    //sao chep
    Sinhvien(const Sinhvien &sv);
    
    ~Sinhvien();
    void nhap();
    void xuat();
    void tinhTB();
};
Sinhvien::Sinhvien(){
    printf("Hien thi khong tham so\n");
    strcpy (this -> MaSV," ");
    strcpy( this -> tenSV," ");
    this -> namsinh = 0;
    this -> toan = 0;
    this -> ly = 0;
    this -> hoa = 0;
};
Sinhvien::Sinhvien(char Masv[],char tenSV[],int namsinh  ,float toan, float ly, float hoa){
    printf("Khoi tao co tham so\n");
    strcpy(this -> MaSV, Masv);
    strcpy(this -> tenSV, tenSV);
    this -> namsinh = namsinh;
    this -> toan = toan;
    this -> ly = ly;
    this -> hoa = hoa;  
};
Sinhvien::Sinhvien(const Sinhvien &sv){
    printf("Khoi tao sao chep\n");
    strcpy(this -> MaSV, sv.MaSV);
    strcpy(this -> tenSV, sv.tenSV);
    this -> namsinh = sv.namsinh;
    this ->toan =sv.toan;
    this -> ly =sv.ly;
    this -> hoa =sv.hoa;
};
Sinhvien :: ~Sinhvien(){
    printf("Huy doi tuong\n");
}

void Sinhvien::nhap()
{
    printf("Nhap tt sinh vien: \n");
    printf( "MASV: ");
    gets(this -> MaSV);
    fflush (stdin);
    printf("TEN: ");
    gets(this ->tenSV);
    printf("NAM SINH: ");
    scanf("%d", &this -> namsinh);
    printf("DIEM TOAN: ");
    scanf("%f", &this -> toan);
    printf("DIEM LY: ");
    scanf("%f", &this -> ly);
    printf("DIEM HOA: ");
    scanf("%f" , &this -> hoa);
    
}

void Sinhvien::xuat(){
    printf("MASV: %s, ",this -> MaSV );
    printf("TEN: %s, ", this -> tenSV );
    printf(" NAM SINH: %d, " , this -> namsinh );
    printf("DIEM TOAN: %.2f, ", this -> toan );
    printf("DIEM LY: %.2f, ", this -> ly );
    printf("DIEM HOA: %.2f, ", this -> hoa );
    tinhTB();
    printf("DIEM TB: %.2f\n", this -> diemTB );
}
void Sinhvien::tinhTB(){
    this -> diemTB = (this -> toan + this -> ly + this -> hoa)/3;
}


int main(){
    Sinhvien s1;
 //s1.nhap();
    s1.xuat();
    Sinhvien s2("123","Huy",2001, 8, 10 ,9);
    s2.xuat();
    Sinhvien s3 = s2;
    s3.xuat();
}