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
    friend istream& operator >>(istream& in, Time& time);
    friend ostream& operator <<(ostream& out,const Time& time);
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

istream& operator >>(istream& in, Time& time) {
    cout << "Nhap gio: ";
    in >> time.gio;
    cout << "Nhap phut: ";
    in >> time.phut;
    cout << "Nhap giay: ";
    in >> time.giay;
    return in;
}

ostream& operator << (ostream& out,const Time& time){
    out << time.gio <<":"<<time.phut<<":"<<time.giay<<endl;
    return out;
}

int Time::tosecond() const{
    return this->gio*3600+this->phut*60+this->giay;
}

bool Time::operator>(const Time &tg) {
    return this->tosecond() < tg.tosecond();
}

int main(){
    Time t(12,13,14), b(t);
    int n = 0;
    do {
        cout << "Nhap so thoi gian: ";
        cin >> n;
    } while(n<=0);
    Time a[n];
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cout << a[i];
    }

    Time trg;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                trg=a[i];
                a[i]=a[j];
                a[j]=trg;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << a[i];
    }
    
    return 0;
}