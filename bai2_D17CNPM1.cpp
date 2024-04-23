#include<stdio.h>
#include<stdlib.h>

class tamGiac
{
	private: 
		float a,b,c;
	public:
		tamGiac() : a(1), b(1), c(1){};
`		tamGiac(float canh1, float canh2, float canh3) : a(canh1), b(canh2), c(canh3){};
		~tamGiac(){	};
		void nhap()
		{
			printf("Nhap canh 1:");
			scanf("%f", &a);
			
			printf("Nhap canh 2:");
			scanf("%f", &b);
			
			printf("Nhap canh 3:");
			scanf("%f", &c);
		}
		
		void xuat()
		{
			printf("%.2f-%.2f-%.2f", a, b, c);
		}
		
		int kiemTraTamGiac()
		{
			return(a+b>c || b+c>a || c+a>b);
		}
};

int main()
{
	tamGiac tg1, tg2;
	printf("\nTam giac 1:\n");
	tg1.xuat();
	
	printf("\nTam giac 2:\n");
	tg2.nhap();
	tg2.xuat();
	
	printf("\nKiem tra tam giac:\n");
	if(tg1.kiemTraTamGiac())
	{
		printf("1 la tam giac\n");
	}
	if(tg2.kiemTraTamGiac())
	{
		printf("2 la tam giac\n");
	}
}
