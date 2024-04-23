#include<iostream>
#include<string.h>
using namespace std;
class Sach{
    private:
        string ma, ten, loai;
    public:
        Sach();
        void nhap();
        void xuat();
        string getloai(){
            return loai;
        }

};
Sach::Sach(){
    cout << "Khoi tao mac dinh:\n";
    this->ma="";
    this->ten="";
    this->loai="";
}
void Sach::nhap(){
    cout << "Ma sach: ";  getline(cin, ma);
    cout << "Ten sach: ";  getline(cin, ten);
    cout << "Loai sach: ";  getline(cin, loai);
}
void Sach::xuat(){
    cout << "Ma sach: " << this->ma << ", Ten sach: " << this->ten <<", Loai sach: " << this->loai << endl;
}
void tim(Sach *s, int n){
    cout << "Danh sach sach thuoc loai CONG NGHE:\n";
    for(int i=0;i<n;i++){
        if(s[i].getloai()=="CONG NGHE")
            s[i].xuat();
    }
}
int main(){
    int n;
    cout << "Nhap n"; cin >> n;
    cin.ignore();l,
    Sach* s= new Sach[n];
    for(int i=0;i<n;i++){
        cout << "Nhap thong tin sach thu " << i+1 << endl;
        s[i].nhap();
    }
    for(int i=0;i<n;i++){
        cout << "Thong tin sach thu " << i+1 << endl;
        s[i].xuat();
    }
    tim(s,n);
    delete[] s;
    return 0;
}