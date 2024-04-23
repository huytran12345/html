#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string.h>
using namespace std;
// class 
// thuoc tinh: atribute
// phuong thuc: method, behavior
// object: doi tuong (la thuc the cua class)
//Constructor: Ham khoi tao khong co kieu tra ve
//Destructor: Ham huy (Khong the ghip de duoc, kho co kieu tra ve, co ten trung voi class va co dau ~)
//This pointer
// setter getter
    // ham getter la de gan gia tri cho cac thuoc tinh
//-Encapsulation : dong goi
//-Acces modifier: 
    //-Private (thuoc tinh)
    //-Public (phuong thuc thi dung)
    //-Protected (lien quan den tinh ke thua trong oop)
//static
//Friend function, friend class


//SV001 => SV002 => SV003
// Gan tu dong ma sinh vien

// chuan hoa ten vd: nguyen vaN A => Nguyen Van A
// forward declaration

// Operator overloading (toan tu nhap xuat)
// << >> 
// cout :  ostream
// cin : istream

/*class sinhvien{
    // thuoc tinh va phuong thuc
    private:
        string id,ten,ns;
        double gpa;
    public:
        
        friend istream& operator >> (istream &in, sinhvien &a);
        friend ostream& operator << (ostream &out, sinhvien a);
        // cach1 nap chong toan tu nho hon
        //bool operator < (sinhvien a);
        //cach2
        friend bool operator < (sinhvien a, sinhvien b);
};
/* day la cua cach 1
bool sinhvien::operator < (sinhvien a){
    return this -> gpa < a.gpa;
}*/
// Cach2
/*bool operator < (sinhvien a, sinhvien b){
    return  a.gpa < b.gpa;
}
istream& operator >> (istream &in, sinhvien& a){
    cout << "Nhap id :";
    cin >> a.id;
    cout << "Nhap ten :";
    in.ignore();
    getline(in, a.ten);
    cout << "Nhap ngay sinh :";
    in >> a.ns;
    cout << "Nhap diem: ";
    in >> a.gpa;
    return in;

}
ostream & operator << (ostream &out, sinhvien a){
    cout << a.id << " " << a.ten <<" "<< a.ns <<" "<< fixed  << setprecision(2) << a.gpa <<endl;
    return out;
}
// insertion >> <<
int main(){
    /*sinhvien x,y;
    cin >> x >> y;
    cout << x << y;
    if(x <y) cout << "yes";
    else cout <<"No";*/
    /*int n;
    cin >> n;
    sinhvien a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for(sinhvien x : a){
        cout << x;
    }
}*/
class sophuc{
    private:
    int thuc, ao;
    public:
        friend istream& operator >> (istream& in, sophuc &a);
        friend ostream& operator << (ostream& out, sophuc a);
        sophuc operator + (sophuc anotther);
        sophuc operator - (sophuc anotther);
        // so samh 2 so phuc co bang nhau hay ko
        bool operator == (sophuc another);
};
    istream& operator >> (istream& in, sophuc &a){
        in >> a.thuc >> a.ao;
        return in;
    }
    ostream& operator << (ostream& out, sophuc a){
        out <<a.thuc << " " << a.ao;
        return out;
    }

    sophuc sophuc::operator+(sophuc another){
        sophuc tong;
        tong.thuc = this -> thuc + another.thuc;
        tong.ao = this -> ao + another.ao;
        return tong; 
    }
    sophuc sophuc::operator-(sophuc another){
        sophuc tru;
        tru.thuc = this -> thuc - another.thuc;
        tru.ao = this -> ao - another.ao;
        return tru; 
    }
    bool sophuc::operator== (sophuc another){
        return this -> thuc == another.thuc && this -> ao == another.ao;
    }
int main(){
    sophuc a,b;
    cin >> a >> b;
    sophuc tong = a + b;
    sophuc hieu = a-b;
    cout << tong << endl;
    cout << hieu << endl;
    if(a==b)
    cout << "yes\n";
    else
    cout << "No\n";
}
