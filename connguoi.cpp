#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class connguoi
{
protected:
    string cmnd;
    string hoten;
    string gioitinh;
public:
    virtual void nhap();
    virtual void xuat();
    connguoi();
    connguoi(string cmnd, string hoten,string gioitinh);
    ~connguoi();
};

connguoi::connguoi(string cmnd, string hoten,string gioitinh){
    cout <<"Khoi tao co tham so lop con nguoi\n";
    this->cmnd =cmnd;
    this->hoten = hoten;
    this->gioitinh =gioitinh;
}
connguoi::connguoi(){
    cout <<"Khoi tao khong tham so lop con nguoi\n";
    this->cmnd = this->hoten = this->gioitinh=" ";

}
connguoi::~connguoi(){
    cout <<"Huy khoi tao lop con nguoi\n";
}

void connguoi::nhap(){
    cout  <<"CMND: "; cin >> cmnd;
    cout << "HOTEN: "; cin >>hoten;
    cout <<"Gioitinh: ";cin>>gioitinh;
}
void connguoi::xuat(){
    cout <<"CMND: " << cmnd <<" " << "Hoten: " << hoten <<" " << "Gioitinh: " << gioitinh;
}
class sinhvien:public connguoi{
private: 
    string Masv;
    float diemtb;
public:
    void nhap();
    void xuat();
    sinhvien();
    sinhvien(string cmnd,string hoten,string gioitinh,string Masv,float diemtb);
    ~sinhvien();
};
sinhvien::sinhvien(string cmnd,string hoten,string gioitinh,string Masv,float diemtb){
    cout <<"Khoi tao co tham so lop sinh vien\n";
    this->Masv=Masv;
    this->diemtb =diemtb;
}
sinhvien::sinhvien(){
    cout << "Khoi tao khong tham so lop sinh vien\n";
    this->Masv =" ";
    this->diemtb = 0;
}
sinhvien::~sinhvien(){
    cout <<"Huy khoi tao lop sinh vien\n";
}
void sinhvien::nhap(){
    this ->connguoi::nhap();//câu lệnh gọi đệ quy chính pt nhập của lớp sv khi trùng tên
    cout <<"Masv: "; cin >> Masv;
    cout <<"DTB: "; cin >> diemtb;
}
void sinhvien::xuat(){
    this->connguoi::xuat();
    cout <<" Masv: " << Masv << " " << "DTB: " << diemtb << endl;
}

class giangvien:public connguoi{
private: 
    string Magv;
    float sobb;
public:
    void nhap();
    void xuat();
    giangvien();
    giangvien(string cmnd,string hoten,string gioitinh,string Magv,float sobb);
    ~giangvien();
};
giangvien::giangvien(string cmnd,string hoten,string gioitinh,string Magv,float sobb){
    cout <<"Khoi tao co tham so lop giang vien\n";
    this->Magv=Magv;
    this->sobb =sobb;
}
giangvien::giangvien(){
    cout << "Khoi tao khong tham so lop giang vien\n";
    this->Magv =" ";
    this->sobb = 0;
}
giangvien::~giangvien(){
    cout <<"Huy khoi tao lop giang vien\n";
}
void giangvien::nhap(){
    this ->connguoi::nhap();//câu lệnh gọi đệ quy chính pt nhập của lớp sv khi trùng tên
    cout <<"Magv: "; cin >> Magv;
    cout <<"SOBB: "; cin >> sobb;
}
void giangvien::xuat(){
    this->connguoi::xuat();
    cout <<" Magv: " << Magv << " " << "DTB: " << sobb << endl;
}
// tu khoa viẻtual va con tro
int main(){
    
    // connguoi *cn = new sinhvien;
    // cn->nhap();
    // cn->xuat();
   
    //connguoi *cn = new giangvien;
    //cn->nhap();
    //cn->xuat();
    int n;
    cout << "Nhap so luong doi tuong cn: ";
    cin >> n;
    connguoi *arr[n];
    cout << "nhap thong tin danh sach: " << endl;
    for (int i = 0; i<n;i++){
        cout << "1. sinh vien\n";
        cout << "2. Giang vien\n";
        cout << "3. thoat\n";
        int c;
        cin >> c;
        switch (c){
            case 1:
                arr[i] = new sinhvien;
                break;
            case 2:
                arr[i] = new giangvien;
                break;
            case 3:
                cout << "Tam biet";
                return 0;
            default:
                arr[i] = new connguoi;
        }
        arr[i] -> nhap();
    }
        cout << "Danh sach doi tuong\n";
        for(int i=0;i<n;i++){
            arr[i]->xuat();
        }
        for(int i=0;i<n;i++){
            delete arr[i];
        }

        
    
}