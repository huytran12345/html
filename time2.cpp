#include<iostream>
using namespace std;

class Time{
private:
    int gio,phut,giay;
public:
    Time();
    Time(int gio,int phut,int giay);
    Time(const Time &tg);
    ~Time();
    // phuong thuc la ham cua  1 lop
    void nhap();
    void xuat();
    int tosecond() const;// danh dau khong chinh sua thanh phan con tro this
    bool operator>(const Time &tg);
};

Time::Time(){
    cout << "Khoi tao mac dinh khong tham so\n";
    this->gio=this->phut=this->giay=0;
}

Time::Time(int gio,int phut,int giay){
    cout <<"Khoi tao co tham so:";
    this->gio=gio;
    this->phut=phut;
    this->giay=giay;
}

Time::Time(const Time &tg){
    cout<<"Khoi tao sao chep";
    this->gio = tg.gio;
    this->phut = tg.phut;
    this->giay = tg.giay;
}

Time::~Time(){
    cout<<"Huy doi tuong\n";
    this->gio=this->phut=this->giay=0;
}

void Time::nhap(){
    cout<<"Nhap gio:";cin >> this->gio;
    cout<<"Nhap phut:";cin >> this->phut;
    cout<<"Nhap giay:";cin >> this->giay;
}

void Time::xuat(){
    cout<<"Thoi gian: "<< this->gio <<":"<< this->phut<<":"<< this->giay << endl;
}

int Time::tosecond() const{
    return this->gio*3600+this->phut*60+this->giay;
}

bool Time::operator>(const Time &tg) {
    return this->tosecond() < tg.tosecond();
}

int main(){
   /* Time s1,s2(12,32,60),s3=s2;
    s1.xuat();
    s2.xuat();
    s3.xuat();*/
    int n;
    do{
        cout <<"Nhap so thoi gian";
        cin >> n;
    }while(n<=0);
    Time a[n];
    for(int i=0;i<n;i++){
        a[i].nhap();
    }
    for(int i=0;i<n;i++){
        a[i].xuat();
    }
    Time trg;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]); 
            }
        }
    }

    for(int i=0;i<n;i++){
        a[i].xuat();
    }
    return 0;
}