#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class CauThu
{
private:
    string Hoten;
    int tuoi;
    string vitri;
    float cannang,chieucao;

public:
    friend ostream &operator<<(ostream &os,CauThu &ct);
    friend istream &operator>>(istream &is, CauThu &ct);
    bool operator <(const CauThu &ct) const;
    CauThu();
    ~CauThu();
};

CauThu::CauThu()
{
    cout<<"Khoi tao khong tham so\n";
    this->Hoten ="";
    this->tuoi =0;
    this->vitri="";
    this->cannang = this->chieucao =0;
}

CauThu::~CauThu()
{
    cout<<"Huy khoi tao\n";
}
istream &operator>>(istream &is, CauThu &ct){
    is.ignore();
    cout<<"HoTen: ";getline(is,ct.Hoten);
    cout<<"Tuoi: "; is>>ct.tuoi;
    is.ignore();
    cout<<"Vitri: "; getline(is,ct.vitri);
    cout<<"CanNang: "; is>>ct.cannang;
    cout<<"ChieuCao: "; is>>ct.chieucao;
    return is;
}
ostream &operator<<(ostream &os,CauThu &ct){
    os<<"HoTen: " << ct.Hoten << " Tuoi: "<<ct.tuoi<<" Vitri: "<<ct.vitri
    <<" CanNang: "<<ct.cannang<<" ChieuCao: "<<ct.chieucao <<endl;
}
bool CauThu::operator<(const CauThu &ct)const{
    if (this->chieucao != ct.chieucao)
    {
        return this->chieucao < ct.chieucao;
    }else{
        return this->cannang > ct.cannang;
    }
}

template<class T>
class DanhSach
{
private:
    int size;
    T *ds;
public:
    DanhSach(){
        cout<<"Khoi tao khong tham so\n";
        this->size =0;
        this->ds = NULL;
    };
    DanhSach(int size, T *ds){
        cout<<"Khoi tao co tham so";
        this->size = size;
        this->ds =new T[size];
        
    }
    ~DanhSach(){
        cout<<"Huy khoi tao\n";
        this->size =0;
        delete [] ds;
    };
    friend istream &operator>>(istream &is, DanhSach<T> &dslist){
        cout<<"Nhap so luong phan tu\n";
        is>>dslist.size;

        delete []dslist.ds;
        dslist.ds = new T[dslist.size];
        for (int i = 0; i < dslist.size; i++)
        {
            is>>dslist.ds[i];
        }
        return is;
    }
    friend ostream &operator<<(ostream &os, DanhSach<T> &dslist){
        os<<"Danh Sach\n";
        for (int i = 0; i < dslist.size; i++)
        {
            os<<dslist.ds[i];
        }
        return os;
    }
    void sapxep(){
        for (int i = 0; i < size-1; i++)
        {
            for (int j = i+1; j < size; j++)
            {
                if (ds[i] < ds[j])
                {
                    swap (ds[i],ds[j]);
                }
                
            }
            
        }
        for (int i = 0; i < size; i++)
        {
            cout<<ds[i];
        }
        
    }
};
int main(){
    DanhSach<CauThu> ds;
    cin>>ds;
    cout<<"Danh sach vua Nhap\n";
    cout<<ds;
    cout<<"Ds sau khi sap xep\n";
    ds.sapxep();
}




