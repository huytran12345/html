#include<stdio.h>
#include<string.h>
#include <stdlib.h>
class phanso{
    private:
    int tu,mau;
    public:
    // khoi tao khong tham so
    phanso();
    // khoi tao co tham so
    phanso(int a,int b);
    // khoi tao sao chep
    phanso(const phanso &ps);
    // khoi tao huy
    ~phanso();
    void nhap();
    void rutgon();
    void xuat();
};
phanso::phanso(){
    printf("Khoi tao khong tham so\n");
    this -> tu = 0;
    this -> mau = 1;
};
phanso::phanso(int a,int b){
    printf("Khoi tao co tham so\n");
    this -> tu = a;
    this -> mau = b;
};
phanso::phanso(const phanso &ps){
    printf("Khoi tao sao chep\n");
    this -> tu = ps.tu;
    this -> mau = ps.mau;

};
phanso::~phanso(){
    printf("Huy phan so\n");
};
void phanso::nhap(){
    printf("Nhap phan so: \n");
    printf("Tu so: ");
    scanf("%d", &this -> tu);
    do{
    printf("Mau so: ");
    scanf("%d", &this -> mau);
    }while(mau == 0);
}
int uocchungln(int m,int n){
    while( n!=0 ){
        int temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}
void phanso::rutgon(){
    int ucln = uocchungln(this -> tu, this -> mau);
    this -> tu /= ucln;
    this -> mau /= ucln;
}
void phanso::xuat(){
    printf("Phan so: %d/%d\n", this -> tu, this -> mau );
    rutgon();
    printf("Phan so sau khi rut gon: %d/%d\n", this -> tu, this -> mau);
}
int main(){
    phanso loai1;
    loai1.xuat();
    printf("\n");
    phanso loai2;
    loai2.nhap();
    loai2.xuat();
    printf("\n");
    phanso loai3 = loai2;
    loai3.xuat();
}