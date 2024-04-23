#include<iostream>
using namespace std;
class tamgiac{
	private:
		float canh1, canh2, canh3;
	public:
		tamgiac();
		tamgiac(float canh1,float canh2,float canh3);
		~tamgiac();
		void nhap();
		void xuat();
		bool kiemtra();
		
};
tamgiac::tamgiac()
{
	cout <<"Khoi tao mac dinh\n";
	this->canh1=this->canh2=this->canh3=0;
}
tamgiac::tamgiac(float canh1,float canh2,float canh3){
	cout <<"Khoi tao co tham so\n";
	this->canh1=canh1;
	this->canh2=canh2;
	this->canh3=canh3;
}
tamgiac::~tamgiac(){
	cout << "Huy doi tuong\n";
	this->canh1=this->canh2=this->canh3=0;
}
void tamgiac::nhap(){
	cout << "Nhap canh 1: ";
	cin >> this->canh1;
	cout << "Nhap canh 2: ";
	cin >> this->canh2;
	cout << "Nhap canh 3: ";
	cin >> this->canh3;
	
}
void tamgiac::xuat(){
	cout <<"Canh 1: " << this->canh1 << " canh 2: " << this->canh2 <<" canh 3: "<<this->canh3 <<endl;
}
bool tamgiac::kiemtra(){
	return this->canh1+this->canh2 > this->canh3 && this->canh1+this->canh3 > this->canh2 && this->canh2 + this->canh3 > this->canh1;
}
int main(){
	tamgiac s1,s2(1,2,3);
	s1.xuat();
	s2.xuat();
	int n;
	cout << "Nhap n:";
	cin >> n;	
	tamgiac a[n];
	for(int i=0;i<n;i++){
		a[i].nhap();
	}
	for(int i=0;i<n;i++){
		if(a[i].kiemtra())
		a[i].xuat();
	}
	
}

