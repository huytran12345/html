#include<stdio.h>
#include<stdlib.h>
// em khong hieu thay viet tat DTB la gi nen em khong viet 
class phanSo
{
	private:
		int tuSo;
		int mauSo;
	public:
		// khoi tao mac dinh
		phanSo() : tuSo(0), mauSo(1){}; 
		
		// khoi tao co tham so
		phanSo(int a, int b) : tuSo(a), mauSo(b){};
		
		// khoi tao sao chep
		phanSo(phanSo &phanSoKhac) : tuSo(phanSoKhac.tuSo), mauSo(phanSoKhac.mauSo){};
		
		// ham huy
		~phanSo(){};
		
		void nhap(){
			printf("Nhap tu so: ");
			scanf("%d", &this->tuSo);
			
			printf("Nhap mau so: ");
			scanf("%d", &this->mauSo);
		}
		
		void xuat(){
			printf("Phan so la: %d/%d", this->tuSo, this->mauSo);
		};
		
		int UCLN(int a, int b)
		{
			if(a==b)
			{
				return a;
			}
			if(a>b){
				return UCLN(a-b,b);
			} else {
				return UCLN(a,b-a);
			}
		};
		
		void rutGon(){
			printf("\nPhan so rut gon la: %d/%d", this->tuSo/UCLN(this->tuSo,this->mauSo), this->mauSo/UCLN(this->tuSo,this->mauSo));
		};	
};

class hoaDon
{
	private:
		int maHoaDon;
		int soLuong;
		double donGia;
	public:
		hoaDon(): maHoaDon(0), soLuong(0), donGia(0){};
		hoaDon(int a, int b, double c) : maHoaDon(a), soLuong(b), donGia(c){};
		hoaDon(const hoaDon &hoaDonKhac) : maHoaDon(hoaDonKhac.maHoaDon), soLuong(hoaDonKhac.soLuong), donGia(hoaDonKhac.donGia){};
	
	void nhap()
	{
		printf("Nhap ma hoa don: ");
		scanf("%d", &this->maHoaDon);
		
		printf("Nhap so luong hang: ");
		scanf("%d", &this->soLuong);
		
		printf("Nhap don gia: ");
		scanf("%lf", &this->donGia);
	}
	
	double tinhThanhTien()
	{
		return this->soLuong*this->donGia;	
	}
	
	void xuat()
	{
		printf("Ma hoa don: %d\n", this->maHoaDon);
		printf("So luong hang: %d\n", this->soLuong);
		printf("Don gia: %.2lf\n", this->donGia);
		printf("Thanh tien: %.2lf\n", tinhThanhTien());
	}

};

int main()
{
	phanSo ps1,ps2,ps3;
	printf("PS1:\n");
	ps1.xuat();
	
	printf("\nPS2:\n");
	ps2.nhap();
	ps2.xuat();
	ps2.rutGon();
	
	printf("\nPS3:\n");
	ps3 = phanSo(ps2);
	ps3.xuat();
	
	hoaDon hd1, hd2, hd3;
	printf("\nHD1:\n");
	hd1.xuat();
	
	printf("HD2:\n");
	hd2.nhap();
	hd2.xuat();
	
	hd3 = hoaDon(hd2);
	hd3.xuat();
}
