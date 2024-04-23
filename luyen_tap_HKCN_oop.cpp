#include<iostream>
using namespace std;
class hinhkhoicn{
	private:
		float dai,rong,cao;
	public:
		// khoi tao mac dinh
		hinhkhoicn();
		// khoi tao co tham so
		hinhkhoicn(float dai, float rong, float cao);
		// huy doi tuong
		~hinhkhoicn();
		friend istream& operator >> (istream& in, hinhkhoicn& cn);
		friend ostream& operator << (ostream& out,const hinhkhoicn cn);
		bool kiemtra();
		bool KiemTraLapPhuong();
};

hinhkhoicn::hinhkhoicn(){
	cout << "Khoi tao mac dinh\n";
	this->dai=this->rong=this->cao=0;
}
hinhkhoicn::hinhkhoicn(float dai, float rong, float cao){
	cout << "Khoi tao co tham so\n";
	this->dai=dai;
	this->rong=rong;
	this->cao=cao;
}
hinhkhoicn::~hinhkhoicn(){
	cout << "Huy doi tuong\n";
	this->dai=this->rong=this->cao=0;
}
istream& operator >> (istream& in,hinhkhoicn& cn){
	cout << "Nhap do dai :"; in >> cn.dai;
	cout << "Nhap do rong :"; in >> cn.rong;
	cout << "Nhap do cao :"; in >> cn.cao;
	return in;
}
ostream& operator << (ostream& out, hinhkhoicn cn){
	out << "Do dai: " << cn.dai << " Do rong: " << cn.rong << " Do cao: " << cn.cao << endl;
	return out;
}
bool hinhkhoicn::kiemtra(){
	return (this->dai > 0 && this->rong > 0 && this->cao > 0);
}
bool hinhkhoicn::KiemTraLapPhuong(){
	return (this->dai == this->rong && this->rong == this->cao && this->cao == this->dai);
}
int main(){
	hinhkhoicn s1,s2(1,2,3);
	cout << s1;
	cout << s2;
	int n;
	do{
		cout << "Nhap n:";
		cin >> n;
	}while(n<=0);
	hinhkhoicn a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(int i=0;i<n;i++)
	{
		cout << a[i];
	}
	for(int i=0;i<n;i++){
		
		if(a[i].KiemTraLapPhuong())
		cout << "Hinh " << i+1 << " la hinh lap phuong" << endl;
		if(a[i].kiemtra())
		cout << "Hinh " << i+1 << " la hinh chu nhat" << endl;
	}
	return 0;
}
