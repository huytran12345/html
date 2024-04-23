#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Cauthu {
	private:
		string Hoten, Vitri;
		float cannang, chieucao;
		int namsinh;
	public: 
		//khoi tao kh tham so
		Cauthu();
		//khoi tao co tham so
		Cauthu(string Hoten, string Vitri, float cannang, float chieucao, int namsinh);
		//ham huy
		~Cauthu();
		void Nhap();
		void Xuat();
		int Tinhtuoi();
		void Thuoc(string vt);
		bool ktr();
		bool operator > (int value);
};
Cauthu::Cauthu() {
	cout<<"---khoi tao khong tham sao\n";
	this->Hoten="";
	this->Vitri="";
	this->namsinh=0;
	this->cannang=this->chieucao=0;
}
Cauthu::Cauthu(string Hoten, string Vitri, float cannang, float chieucao, int namsinh) {
	cout<<"---khoi tao co tham sao\n";
	this->Hoten=Hoten;
	this->Vitri=Vitri;
	this->cannang=cannang;
	this->chieucao=chieucao;
	this->namsinh=namsinh;
}
Cauthu::~Cauthu() {
	cout<<"----Huy doi tuong!!";
}
void Cauthu::Nhap() {
	cout<<"Nhap ho ten: ", cin.ignore();getline(cin,this->Hoten);
	cout<<"Nhap vi tri: ", cin.ignore();getline(cin,this->Vitri);
	cout<<"Nhap namsinh: ", cin>>this->namsinh;
	cout<<"Nhap can nang: ", cin>>this->cannang;
	cout<<"Nhap chieucao: ", cin>>this->chieucao;
}
void Cauthu::Xuat() {
	cout<<"ho ten: "<<this->Hoten<<endl;
	cout<<"vi tri: "<<this->Vitri<<endl;
	cout<<"nam sinh: "<<this->namsinh<<endl;
	cout<<"can nang: "<<this->cannang<<endl; 
	cout<<"chieu cao: "<<this->chieucao<<endl;
}
int Cauthu::Tinhtuoi() {
	
	return 2024-this->namsinh;
}
void Cauthu::Thuoc(string vt) {
	if(this->Vitri==vt) {
		cout<<"=> cau thu"<<this->Hoten<<"thuoc vi tri"<<vt<<endl;
	} else {
		cout<<"=> cau thu"<<this->Hoten<<"khong thuoc vi tri"<<vt<<endl;
	}
}
bool Cauthu::ktr() {
	if(this->Vitri=="tien dao") {
		return true;
	} else {
		return false;
	}
}
bool Cauthu::operator >(int value) {
	if(this->Tinhtuoi()>value) 
		return true;
	return false;
}
int main() {
	Cauthu ct1;
	ct1.Xuat();
	Cauthu ct2("tu","thu mon",50,2,2000);
	ct2.Xuat();
	int n;
	cout<<"Nhap n"; cin>>n;
	Cauthu ct[n];
	for(int i = 0; i<n; i++) {
		cout<<"Nhap thong tin"<<i+1<<endl;
		ct[i].Nhap();
	}
	for(int i = 0; i<n; i++) {
		cout<<"Xuat thong tin"<<i+1<<endl;
		ct[i].Xuat();
	}
	for(int i = 0;i <n; i++) {
		cout<<"Tuoi cau thu"<<i+1<<":"<<ct[i].Tinhtuoi()<<endl; 
	}
	string vt; cout<<"Nhap vi tri can kiem tra: ";cin.ignore();getline(cin,vt);
	for(int i = 0;i<n; i++) {
		ct[i].Thuoc(vt);
	}
	cout<<"Danh sach cau thu tren 30"<<endl;
	for(int i = 0; i<n; i++) {
		if(ct[i]>30&&ct[i].ktr()==true) {
			ct[i].Xuat();
		}
	}
}
