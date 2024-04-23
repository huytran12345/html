#include<iostream>
#include<string.h>
#include<math.h>
#include <stdlib.h>
using namespace std;
class sinhvien
{
private:
    char MaSV [20];
    string tenSV ;
    int namsinh;
    float toan,ly,hoa,diemTB;
    static int count;
public:
    static int COUNT;
    //default constructor 

    //dạng không tham số
    sinhvien();
    //có tham số
    sinhvien(char Masv[20],string tensv ,int namsinh  ,float toan , float ly, float hoa);
    //sao cheps
    // sinhvien(const sinhvien &sv);
    //Khởi tạo có tham số mang giá trị ngầm định (ko tham số + có tham số)
    //- không định nghĩa pt khởi tạo không tham số -trong khai báo phương thức khởi tạo có tham số gán default value cho các tham số(chỉ phần khai báo)
    // sinhvien(char Masv[] = "", char tensv[] = "", int namsinh = 1900, float toan =0, float ly =0, float hoa =0 );
    ~sinhvien();
    void nhap();
    void xuat();
    void tinhTB();
    bool operator>(const sinhvien &sv);
    friend void nhapp();
    friend istream& operator >> (istream &is, sinhvien &sv);
    friend ostream& operator << (ostream &is, sinhvien &sv);
};

int sinhvien::COUNT = 0;

sinhvien::sinhvien(){
    cout<<"Hien thi khong tham so\n";
    strcpy (this -> MaSV,"");
    this -> tenSV = " ";
    this -> namsinh = 0;
    this -> toan = 0;
    this -> ly = 0;
    this -> hoa = 0;
};
sinhvien::sinhvien(char Masv[20],string tensv,int namsinh  ,float toan, float ly, float hoa){
    cout << "Khoi tao co tham so\n";
    strcpy(this -> MaSV,Masv);
    this -> tenSV = tenSV;
    this -> namsinh = namsinh;
    this -> toan = toan;
    this -> ly = ly;
    this -> hoa = hoa;  
};
/*sinhvien::sinhvien(const sinhvien &sv){
    cout << "Khoi tao sao chep\n";
    strcpy(this -> MaSV, sv.MaSV);
    this -> tenSV = sv.tenSV;
    this -> namsinh = sv.namsinh;
    this ->toan =sv.toan;
    this -> ly =sv.ly;
    this -> hoa =sv.hoa;
};*/
sinhvien :: ~sinhvien(){
    cout << "Huy doi tuong\n";
}
void sinhvien::nhap()
{
    //cout << "Nhap tt sinh vien: \n";
    //cout<< "MASV: ";
    //cin >> this -> MaSV;
    fflush (stdin);
    cout << "TEN: ";
    getline(cin,this ->tenSV);
    cout << "NAMSINH: ";
    cin >> this -> namsinh;
    cout << "DT: ";
    cin >> this -> toan;
    cout << "DL: ";
    cin >> this -> ly;
    cout << "DH: ";
    cin >> this -> hoa;
    (COUNT)++;
}
void sinhvien::xuat(){
    cout << "MASV: "<< this -> MaSV << "  ";
    cout << "TEN: "<< this -> tenSV << "  ";
    cout << "NAMSINH: " << this -> namsinh << " ";
    cout << "DT: "<< this -> toan << "  ";
    cout << "DL: "<< this -> ly << "  ";
    cout << "DH: " << this -> hoa << "  ";
    tinhTB();
    cout << "DIEMTB: " << this -> diemTB << endl;
}
void sinhvien::tinhTB(){
    // this -> diemTB = (this -> toan + this -> ly + this -> hoa)/3;
}
// nap chong toan tu nhap
istream& operator >> (istream &is, sinhvien &sv){
    cout << "Nhap thong tin sv: ";
    cout <<"MSV: ";
    fflush (stdin);
    is >> sv.MaSV;
    cout << "TEN: ";
    getline(is, sv.tenSV);
    cout << "NAMSINH: ";
    is >> sv.namsinh;
    cout << "DT: ";
    is >> sv.toan;
    cout << "DL: ";
    is >> sv.ly;
    cout << "DH: ";
    is >> sv.hoa;
    return is;
}
ostream& operator << (ostream &os, sinhvien &sv){
    os << "MASV: "<< sv.MaSV << "  ";
    os << "TEN: "<< sv.tenSV << "  ";
    os << "NAMSINH: " << sv.namsinh << " ";
    os << "DT: "<< sv.toan << "  ";
    os << "DL: "<< sv.ly << "  ";
    os << "DH: " << sv.hoa << "  ";
    return os;
}
//nap chong toan tu
bool sinhvien::operator>(const sinhvien &sv){
    if (this -> toan + this -> ly + this -> hoa > sv.toan + sv.ly + sv.hoa)
    {
        return true;
    }else{
        return false;
    }
    
}
int main(){
    // nhap vao tu ban phim 1 mang vao n sinh vien
    // hien thi danh sach sv da nhap ra man hinh
    // sap xep ds sinh vien  theo chieu tang dan cua dtb
    // hienthi
 /*   sinhvien s2("1", "Bich Khanh",1997, 10, 10 ,9),s1("2", "chien",1997, 10, 10 ,9);
    if (s1>s2)
    {
        cout << "sv1 > sv2\n";
    }else{
cout << "sv1 <= sv2\n";
    }*/
int n;
cout<<"Nhap n: "; cin >> n;
sinhvien sv[n];
cout <<"Nhap ds sinh vien \n";
for(int i = 0; i<n;i++){
    //sv[i].nhap();
    cin >> sv[i];
}
cout <<"DS sinh vien vua nhap\n";
for(int i=0;i<n;i++){
    //sv[i].xuat();
    cout << sv[i];
}
for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
        if(sv[i]>sv[j]){
            sinhvien tg = sv[i];
            sv[i]=sv[j];
            sv[j]=tg;
        }
    }
}
cout <<"DS sinh vien vua nhap\n";
for(int i=0;i<n;i++){
    sv[i].xuat();
}
}
