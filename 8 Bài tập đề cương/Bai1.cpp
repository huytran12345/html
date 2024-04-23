#include<iostream>
using namespace std;
class PTGT{
    private:
        string hsx;
        string ten;
        int nam;
        float vantoc;
    public:
        PTGT();
        PTGT(string hsx, string ten, int nam, float vantoc);
        ~PTGT();
        void nhap();
        void xuat();
        bool operator>(const PTGT &pt) const;
}; 
PTGT::PTGT(){
    cout << "Khoi tao mac dinh\n";
    this->hsx="";
    this->ten="";
    this->nam=0;
    this->vantoc=0;
}
PTGT::PTGT(string hsx, string ten, int nam, float vantoc){
    cout<<"Khoi tao co tham so:\n";
    this->hsx=hsx;
    this->ten=ten;
    this->nam=nam;
    this->vantoc=vantoc;
}
PTGT::~PTGT(){
    cout << "Huy doi tuong\n";
    this->hsx="";
    this->ten="";
    this->nam=0;
    this->vantoc=0;
}
void PTGT::nhap(){
    cout << "Hang san xuat: ";
    cin.ignore();
    getline(cin, hsx);
    cout << "Ten: ";cin.ignore();
    getline(cin, ten);
    cout << "Nam san xuat: ";
    cin >> nam;
    cout << "Van toc toi da: ";
    cin >> vantoc;
}
void PTGT::xuat(){
    cout<<"Hangsx: " <<hsx<<" Ten: " << ten << " Nam: " <<nam <<" Vantoc: " <<vantoc<<endl;
}
bool PTGT::operator>(const PTGT &pt)const{
    return this->vantoc > pt.vantoc;
}
void swap (PTGT &a, PTGT &b){
    PTGT temp = a;
    a=b;
    b=temp;
}
int main(){
    int n;
    cout << "Nhap n :"; cin >> n;
    cin.ignore();
    PTGT * p = new PTGT[n];
    for(int i=0;i<n;i++){
        cout << "Nhap thong tin PTGT thu " << i+1 << endl;
        p[i].nhap();
        cout << endl;
    }
    cout << "Danh sach thong tin PTGT:\n";
    for(int i=0;i<n;i++){
        cout << "Phuong tien thu " << i+1 <<": ";
        p[i].xuat();
        cout << endl;
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(p[i] > p[j])
            swap(p[i],p[j]);
        }
    }
    cout << "Danh sach sau khi sap xep:\n";
    for(int i=0;i<n;i++){
        p[i].xuat();
        cout << endl;
    }
    delete[] p;
    return 0;
}

