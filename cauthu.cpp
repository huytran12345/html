#include<iostream>
using namespace std;
class cauthu{
private:
    string hoten;
    int namsinh;
    string vitri;
    float cannang;
    float chieucao;
    
public:
    cauthu();
    cauthu(string hoten, int namsinh, string vitri, float cannang, float chieucao);
    cauthu(const cauthu & ct);
    ~cauthu();
    void nhap();
    void xuat();
    int tinhtuoi();
    void thuoc(string vt);
    bool kiemtravt();
    bool lonhon30();
};
cauthu::cauthu() {
    cout << "Khoi tao ko tham so\n";
    this->hoten="";
    this->namsinh=0;
    this->vitri="";
    this->cannang=0;
    this->chieucao=0;
}
cauthu::cauthu(string hoten, int namsinh, string vitri, float cannang, float chieucao){
    cout <<"Khoi tao co tham so\n";
    this->hoten=hoten;
    this->namsinh=namsinh;
    this->vitri=vitri;
    this->cannang=cannang;
    this->chieucao=chieucao;
}
cauthu::cauthu(const cauthu & ct){
    this->hoten= ct.hoten;
    this->namsinh= ct.namsinh;
    this->vitri= ct.vitri;
    this->cannang= ct.cannang;
    this->chieucao= ct.chieucao;
}
cauthu::~cauthu(){
    cout << "Huy doi tuong\n";
    this->hoten="";
    this->namsinh=0;
    this->vitri="";
    this->cannang=0;
    this->chieucao=0;
}
void cauthu::nhap(){
    cout << "Nhap ten: "; getline(cin >> ws , this->hoten); // ws loai bo khoang trang va ki tu dac viet
    cout << "Nam sinh: "; cin >> this->namsinh;
    cout << "Vi tri: "; getline(cin >> ws, this->vitri);
    cout << "Can nang "; cin >> this->cannang;
    cout << "Chieu cao "; cin >> this->chieucao;
}
void cauthu::xuat(){
    printf("Thong tin cau thu: Ho ten: %s, Nam sinh: %d, Vi tri: %s, Can nang: %.2f, Chieu cao: %.2f\n",
        this->hoten.c_str(),
        this->namsinh,
        this->vitri.c_str(),
        this->cannang,
        this->chieucao);

}
int cauthu::tinhtuoi(){
    return  2024 - this->namsinh;
}
void cauthu::thuoc(string vt){
    if(this->vitri==vt){
        cout << "Cau thu " <<this->hoten<<" thuoc vi tri " <<vt<<endl;
    }
    else{
        cout << "Cau thu " <<this->hoten<<" ko thuoc vi tri " <<vt<<endl;
    }
}
bool cauthu::kiemtravt(){
    return this->vitri == "Tien Dao";
}
bool cauthu::lonhon30(){
    return this->tinhtuoi() >30;
}
int main(){
    
    int n=0;
    do{
        cout <<"Nhap n:";
        cin >> n;
    }while(n<=0);
    cauthu a[n];
    for(int i=0;i<n;i++){
        cout<<"Nhap thong tin cho cau thu "<<i+1<<":"<<endl;
       a[i].nhap();
    }
    for(int i=0;i<n;i++){
        cout<<"Thong tin cua cau thu "<<i+1<<":"<<endl;
        a[i].xuat();
    }
    for(int i=0;i<n;i++){
        cout <<"tuoi cau thu "<<i+1<<": "<< a[i].tinhtuoi() << endl;
    }
    string vtnhap;
    cout <<"Nhap vi tri muon tim kiem: ";
    getline(cin >> ws,vtnhap);
    cout<<"Cac cau thu thuoc vi tri "<< vtnhap << " la:" << endl;
        for(int i=0;i<n;i++){
            a[i].thuoc(vtnhap);
        }
    cout << "Danh sach cau thu la tien dao va lon hon 30 tuoi:" << endl;
    for(int i=0;i<n;i++){
        if(a[i].kiemtravt() && a[i].lonhon30()){
            a[i].xuat();
        }
    }
    return 0;
}