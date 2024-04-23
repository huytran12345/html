#include<stdio.h>
#include<stdlib.h>

class hinhKhoiCN
{
	private :
		float dai, rong, cao;
	public :
		hinhKhoiCN() :  dai(1), rong(2), cao(3){};
		hinhKhoiCN(float a, float b, float c) : dai(a), rong(b), cao(c){};
		~hinhKhoiCN(){};
		
		void nhap()
		{
			printf("Nhap chieu dai: ");
			scanf("%f", &this->dai);
			
			printf("Nhap chieu rong: ");
			scanf("%f", &this->rong);
			
			printf("Nhap chieu cao: ");
			scanf("%f", &this->cao);
		}
		
		void xuat()
		{
			printf("%.2f-%.2f-%.2f", this->dai, this->rong, this->cao);
		}
		
		int kiemTra()
		{
			return (this->dai > 0 && this->rong > 0 && this->cao > 0);
		}
		
		int hinhLapPhuong()
		{
			return (this->dai==this->rong && this->rong==this->cao);
		}
		
};


int main()
{
	hinhKhoiCN hcn1, hcn2;
	printf("\nHinh khoi chu nhat 1:\n");
	hcn1.xuat();
	
	printf("\nHinh khoi chu nhat 2:\n");
	hcn2.nhap();
	hcn2.xuat();
	
	printf("\nKiem tra khoi hinh chua nhat:\n");
	if(hcn1.kiemTra())
	{
		printf("Hinh khoi chu nhat 1 thoa man\n");
	}
	else
	{
		printf("Hinh khoi chu nhat 1 khong thoa man\n");
	}
	if(hcn2.kiemTra())
	{
		printf("Hinh khoi chu nhat 2 thoa man");
	}
	else
	{
		printf("Hinh khoi chu nhat 2 khong thoa man");
	}
	
	printf("\nHinh lap phuong:\n");
	if(hcn1.hinhLapPhuong())	
	{
		hcn1.xuat();
		printf("\n");
	}
	if(hcn2.hinhLapPhuong())	
	{
		hcn2.xuat();
	}
}
