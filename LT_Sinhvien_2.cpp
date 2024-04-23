#include<iostream>
#include<string.h>
using namespace std;
class sinhvien{
	private:
		int masv;
		string ten;
		string lop;
		int ngay, thang ,nam;
		string email;
	public:
		sinhvien();
		sinhvien(int masv, string ten, string lop, int ngay, int thang, int nam, string email);
		~sinhvien();
		friend istream& operator >> (istream &in, sinhvien &sv);
		friend ostream& operator << (ostream &out, sinhvien sv);
};
sinhvien::sinhvien(){
	cout << "Khoi tao khong tham so\n";
	this->masv=this->ngay=this->thang=this->nam=0;
	this->ten=this->lop=this->email=" ";
}
sinhvien::sinhvien(int masv, string ten, string lop, int ngay, int thang, int nam, string email){
	cout << "Khoi tao co tham so\n";
	this->masv=masv;
	this->ten=ten;
	this->lop = lop;
	this->ngay=ngay;
	this->thang=thang;
	this->nam=nam;
	this->email=email;
}
sinhvien::~sinhvien(){
	cout<<"Huy doi tuong\n";
	this->masv=this->ngay=this->thang=this->nam=0;
	this->ten=this->lop=this->email=" ";
}
istream& operator >> (istream &in, sinhvien &sv){
	cout <<"Nhap MASV: "; in >> sv.masv;
	cout<<"Nhap ten: "; in.ignore(); getline(in,sv.ten);
	cout<<"Nhap lop: ";in.ignore(); getline(in,sv.lop);
	cout<<"Nhap ngay: "; in >> sv.ngay;
	cout<<"Nhap thang: "; in >> sv.thang;
	cout<<"Nhap nam: "; in >> sv.nam;
	cout<<"Nhap email: ";in.ignore(); getline(in,sv.email);
	return in;
}
ostream& operator << (ostream &out, sinhvien sv){
	out << "MASV: " << sv.masv <<", Ho Ten: " <<sv.ten<<", Lop: " <<sv.lop<<", Ngay sinh: "
	<< sv.ngay <<"/"<< sv.thang <<"/"<< sv.nam <<", Email: "<< sv.email <<endl;
	return out;
}
int main(){
	/*sinhvien s1;
	cout << s1;
	sinhvien s2(123,"Tran Quang Huy","D17CNPM2",25,10,2004,"huy12412515@gmail.com");
	cout << s2;*/
	int  n=0;
	do{
		cout << "Nhap n: ";
		cin >> n;
	}while(n<=0);
	sinhvien a[n];
	for(int i=0;i<n;i++){
		cout << "Nhap thong tin cho sinh vien thu " << i+1 << ":"<<endl;
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		cout << "Thong tin cho sinh vien thu " << i+1 << ": ";
		cout << a[i];
	}
	return 0;
}
