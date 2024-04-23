#include<iostream>
using namespace std;
class PTGT{
    private:
        string hangsx,ten;
        int namsx;
        float maxspeed;
    public:
        PTGT();
        void nhap(){
            cout << "Nhap hang san xuat: "; getline(cin,hangsx);
            cout << "Nhap ten xe: "; getline(cin, ten);
            cout << "Nhap nam san xuat: "; cin >> namsx;
            cout << "Nhp van toc toi da: "; cin >> maxspeed;
        };

        void xuat(){
            cout << "Hang san xuat: " << this->hangsx << ", Ten xe: " << this->ten <<
            ", Nam san xuat: " << this->namsx << ", Van toc toi da: " << this->maxspeed << endl;
        };
};
class oto:public PTGT{

};