#include<iostream>
using namespace std;

class giangvien{
private:
    int magv,sobb;
    string ten,khoa;
public:
    giangvien();
    giangvien(int magv, string ten, string khoa, int sobb);
    giangvien(const giangvien &gv);
    ~giangvien();
    void nhap();
    void xuat();
    bool thuoc(const char k[]);
    string getten();
    string getkhoa();
    bool khenthuong();
};

giangvien::giangvien(){
    cout <<"-----Khoi tao khong tham so" << endl;
    this->magv=this->sobb=0;
    this->ten=" ";
    this->khoa=" ";
}

giangvien::giangvien(int magv, string ten, string khoa, int sobb){
    cout << "-----Khoi tao co tham so" << endl;
    this->magv=magv;
    this->ten=ten;
    this->khoa=khoa;
    this->sobb=sobb;
}

giangvien::giangvien(const giangvien &gv){
    cout << "-----Khoi tao sao chep" << endl;
    this->magv=gv.magv;
    this->ten=gv.ten;
    this->khoa=gv.khoa;
    this->sobb=gv.sobb;
}

giangvien::~giangvien(){
    cout << "-----Huy doi tuong\n";
    this->magv=this->sobb=0;
    this->ten=" ";
    this->khoa=" ";
}

void giangvien::nhap(){
    cout << "Nhap magv: "; cin >> this->magv;
    cout << "Nhap Ho Ten: "; cin.ignore(); getline(cin, this->ten);
    cout << "Nhap Khoa: "; getline(cin, this->khoa);
    cout << "Nhap SoBB: "; cin >> this->sobb;
}

void giangvien::xuat(){
    cout << "Magv: " << this->magv << ", Ho ten: " << this->ten << ", Khoa: " << this->khoa << ", SoBB: " << this->sobb << endl; 
}
bool giangvien::thuoc(const char k[]){
    return this->khoa == k;
}
string giangvien::getten(){
    return this->ten;
}
string giangvien::getkhoa(){
    return this->khoa;
}
bool giangvien::khenthuong(){
    return this->sobb >=2;
}
int main(){
    /*giangvien s1,s3;
    s1.xuat();
    giangvien s2(98,"Bui Huy Hieu","CNTT",124);
    s2.xuat();
    s3=s2;
    s3.xuat();*/
    int n=0;
    do{
        cout << "Nhap n: "; cin >> n;
    }while(n<=0);
    giangvien a[n];
    for(int i=0;i<n;i++){
        cout << "Nhap thong tin giang vien " << i+1 << ":" << endl;
        a[i].nhap();
    }
    for(int i=0;i<n;i++){
        cout << "Thong tin giang vien " << i+1 << ":" << endl;
        a[i].xuat();
    }
    char nhapkhoakt[60];
    cout << "Nhap khoa can kiem tra: ";cin.ignore();
    cin.getline(nhapkhoakt,60);
    for(int i=0;i<n;i++){
        if(a[i].thuoc(nhapkhoakt)){
            cout << "Giang vien " << a[i].getten() <<" thuoc khoa " << nhapkhoakt << endl;
        }
        else{
            cout << "Giang vien " << a[i].getten() <<" khong thuoc khoa " << nhapkhoakt << endl;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i].khenthuong()){
            cout << "Giang vien " << a[i].getten() << " duoc khen thuong" << endl;
            }
        }
    // giang vien khoa cntt va duoc khen thuong
    cout << "Danh sach giang vien thuoc khoa CNTT va duoc khen thuong:" << endl;
    for(int i=0;i<n;i++){
        if(a[i].thuoc("CNTT") && a[i].khenthuong()){
            a[i].xuat();
        }
    }
    return 0;
}

