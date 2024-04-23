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
//toan tu nhap xuat operator overloading
// << >>
// cout : ostream
// cin : istream
// PHẦN NÀY Ở TRONG FILE C++ lT_ToanTu.cpp
class giaovien;
class sinhvien;

class sinhvien{
    friend class giaovien;
    // thuoc tinh va phuong thuc
    private:
        string id,ten,ns;
        double gpa;
        static int dem;
    public:
        sinhvien(); //constructor co ten cung class (mac dinh no c)
        sinhvien(string,string,string, double);
        void nhap();
        void in();
    /*  double getgpa();
        string getid();   // lay thuoc tinh nhung ko truy cap truc tiep vao thuoc tinh
        string getten(); // de dam bao tinh dong goi cua oop
        string getns();
        void setgpa(double);
    */
        void tangdem();
        int getdem(){
            return dem;
        }
       // ~sinhvien(); // Ham huy
      // friend void inthongtin(sinhvien);
        friend void chuanhoa(sinhvien&);

};
//void inthongtin(sinhvien a){
   // cout << a.id <<" "<<a.ten<<endl;
//}
void chuanhoa(sinhvien &a){
    string res = "";
    stringstream ss(a.ten);
    string token;
    while(ss >> token){
        res += toupper(token[0]);
        for(int i = 1; i < token.length(); i++){
            res += tolower(token[i]);
        }
        res += " ";
    }
    res.erase(res.length() - 1);
    a.ten = res;
}
int sinhvien::dem = 0;
void sinhvien::tangdem(){
    dem++;
}
//Imlementation
//constructor khong co tham so
sinhvien::sinhvien(){
    cout<<"Doi tuong mac dinh duoc tao o day!\n";
    this -> id = this -> ten = this -> ns ="";
    this -> gpa = 0;
}
//constructor co tham so
sinhvien::sinhvien(string id, string ten, string ns, double gpa){
    cout<<"Ham khoi tao co tham so duoc goi !\n";
    this -> id=id;
    this -> ten = ten;
    this -> ns = ns;
    this -> gpa = gpa;
}

// ham huy doi tuong
//sinhvien::~sinhvien(){
    //cout<<"Doi tuong duoc huy tai day !\n";
//}
void sinhvien::nhap(){
    //cout<<"Nhap id :"; cin >> this -> id;
    dem++; // dem =1
    this -> id = "SV" + string(3-to_string(dem).length(),'0')+ to_string(dem);
    // gan id bang ma sv001
    // truong hop ko day du so 0 dang truoc thi chen so 0 vao
    // dem = 1 => "1"
    //string(3-to_string(dem).length(),'0') co nghia la: xem xau co bao nhieu ki tu roi lay 3 tru di so ki tu do roi chen them so luong so 0 tuong ung roi cong them "sv"
    //cin.ignore();
    cout << "Nhap ten :"; getline(cin,this -> ten);
    cout << "Nhap ns :"; cin >> this -> ns;
    cout << "Nhap diem :"; cin >> this -> gpa;
    cin.ignore();
}
void sinhvien:: in(){
    cout << this -> id <<" " << this -> ten << " " << this -> ns <<" " << fixed << setprecision(2) << this -> gpa << endl;
}
/*double sinhvien::getgpa(){
    return this -> gpa; // return gpa;
}
void sinhvien:: setgpa(double gpa){ // ham nay gan gpa cua doi tuong nay bang 1 tham so gpa moi
    this -> gpa = gpa;
}
bool cmp(sinhvien a, sinhvien b){
    return a.getgpa() > b.getgpa();
}
*/
class giaovien{
    private:
        string khoa;
    public:
        void update(sinhvien& );
};

void giaovien::update(sinhvien& x){
    x.gpa = 3.20;
}
int main(){
   /* int n; 
    cout<<"Nhap so luong sinh vien: ";
    cin >> n;
    sinhvien a[100];
    for(int i=0;i<n;i++){
        a[i].nhap();
    }
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        a[i].in();
    }*/
    //(cai nay cua ham setgpa(double gpa) )
   // sinhvien x;
    //x.setgpa(2.18);
    // lay thuoc tinh thi dung get
    // chinh sua thuoc tinh thi dung set

// co the gan 2 sinh vien cho nhau

   /* sinhvien x;
    //x.nhap();
    //sinhvien y=x;
   // y.in();
   x.tangdem();//dem = 1
   x.tangdem();// dem = 2
   sinhvien y;
   cout << y.getdem() <<endl;
   y.tangdem();
   sinhvien z;
   cout << x.getdem() << " " << y.getdem() <<" "<<z.getdem();*/

//cai nay thuoc phan static
    /*sinhvien x;
    x.nhap();
    x.in();
    sinhvien y;
    y.nhap();
    y.in();*/

    sinhvien x;
    x.nhap();
    //inthongtin(x);
    giaovien y;
    y.update(x);
    //chuanhoa(x);
    x.in();
    return 0;
}
