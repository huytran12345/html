#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
using namespace std;
// Nhan vien 
// ngay sinh, gioi tinh, dia chi, ma so thue, ho ten ,ma nhan vien
// xay dung ham nhap su dung nap chong toan tu. Danh sach ma nhan vien tang tu dong(khong nhap ma nhap ma)
// xay dung ham khoi tao ko tham so: xau ki tu rong thi bang 0
// xay dung ham khoi tao co tham so
// xay dung ham huy
// ngay sinh nhap vao input 2/2/2002 output 02/02/2002 sau do sap xep thu tu ngay sinh tu gia den tre
// xuat ra cac doi tuong da sap xep
class nhanvien{
    private:
        static int count; // khong thuoc ve doi tuong noa day ma la thuoc ve doi tuong chung
        int ngay, thang, nam;
        char gt[10];
        string dc;
        char mst[20];
        string ten;
        char mnv[20];
    public:
        nhanvien(); //(ham khoi tao ko tham so)
        nhanvien(int ngay,int thang,int nam,char gt[],string dc,char mst[],string ten,char mnv[]); //khoi tao co tham so
        ~nhanvien();
        nhanvien operator++(int);
        bool operator>(const nhanvien &nv);
        void nhap();
        void xuat();
};
int nhanvien::count = 0;
nhanvien::nhanvien(){
    cout<< "Doi tuong mac dinh duoc tao o day !\n";
    this -> ngay = this -> thang = this -> nam = 0;
    strcpy(this -> gt, " ");
    this -> dc = "";
    strcpy(this -> mst, " ");
    this -> ten = "";
    strcpy (this -> mnv ," ");

}
nhanvien::nhanvien(int ngay,int thang,int nam,char gt[],string dc,char mst[],string ten,char mnv[]){
    cout<<"Doi tuong co tham so duoc tao o day !\n";
    this -> ngay = ngay;
    this -> thang = thang;
    this -> nam = nam;
    strcpy(this -> gt, gt);
    this -> dc = dc;
    strcpy(this -> mst, mst);
    this -> ten = ten;
    strcpy (this -> mnv, mnv);
}
nhanvien::~nhanvien(){
    cout<<"Huy doi tuong !\n";
}
void nhanvien::nhap(){
    cout<<"Nhap ngay sinh :"; cin >> this-> ngay;
    cout<<"Nhap thang sinh :"; cin >> this-> thang;
    cout<<"Nhap nam sinh :"; cin >> this -> nam;
    cout<<"Nhap gioi tinh :"; cin >> this -> gt;
    cin.ignore();
    cout<<"Nhap dia chi :"; getline(cin, this -> dc);
    cout<<"Nhap ma so thue :"; cin >> this -> mst;
    cin.ignore();
    cout<<"Nhap ten :"; getline(cin, this -> ten);
    (*this)++;
}
void nhanvien::xuat(){
    cout<< setfill('0');

    cout<<"Ngay sinh: " << setw(2) << this ->ngay<<"/"  << setw(2)<< this -> thang <<"/" << setw(4)<< this -> nam << "; "<<
    // setw cho phep gioi han do rong cua 1 gia tri
    "Dia chi: "<< this -> dc << " ;" << "Ma so thue: "<< this -> mst <<" ;" << "Ten: " << this -> ten << " ;" << "Ma NV: " << this -> mnv << endl;
}
nhanvien nhanvien::operator++(int){
    nhanvien temp  = *this;
    count++;
    sprintf(this -> mnv, "NV%03d", count);
    return temp;
}
bool nhanvien::operator>(const nhanvien &nv){
    if(this -> nam > nv.nam){
        return true;
    }
    else return false;
}
void sapxep(nhanvien *dsnv, int n){
    nhanvien temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(dsnv[i] > dsnv[j]){
                swap(dsnv[i], dsnv[j]);
                // temp = dsnv[i];
                // dsnv[i] = dsnv[j];
                // dsnv[j] = temp;
            }
        }
    }
}
int main(){
    int n;
    do{
        cout<<"Nhap so luong nhan vien: ";
        cin >> n;
    }while(n<=0);
    nhanvien *dsnv = new nhanvien[n];
    for(int i=0;i<n;i++){
        dsnv[i].nhap();
    }
    sapxep(dsnv,n);
    for(int i=0;i<n;i++){
        dsnv[i].xuat();
    }
    delete[] dsnv;
}