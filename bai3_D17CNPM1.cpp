#include<stdio.h>
#include<stdlib.h>
#include<string.h>

class date
{
	private: 
		int ngay, thang, nam;
	public:
		date() : ngay(0), thang(0), nam(0){	};
		date(int a, int b, int c): ngay(a), thang(b), nam(c){};
		
		~date(){};
		
		void nhap(){
			printf("Nhap ngay: ");
			scanf("%d", &this->ngay);
			
			printf("Nhap thang: ");
			scanf("%d", &this->thang);
			
			printf("Nhap nam: ");
			scanf("%d", &this->nam);
		}
		
		void hien(){
			printf("%d-%d-%d", this->ngay, this->thang, this->nam);
		}
		
		int soSanh(date &d2){
			if(this->nam > d2.nam){
				return 1;
			}
			else if(this->nam < d2.nam){
				return 0;
			}
			else {
				if(this->thang > d2.thang){
					return 1;
				}
				else if(this->thang < d2.thang){
					return 0;
				}
				else{
					if(this->ngay > d2.ngay){
						return 1;
					}
					else{
						return 0;
					}
				}
			}	
		}
};	

int main()
{
	int n;
	printf("Nhap so luong ngay: ");
	scanf("%d", &n);
	
	date d[n];
	
	for(int i=0;i<n;i++){
		printf("Nhap ngay thu %d: \n", i+1);
		d[i].nhap();
	}
	
	printf("\nDanh sach cac ngay da nhap:\n");
	for(int i=0;i<n;i++){
		d[i].hien();
		printf("\n");
	}	
	
	printf("\nNgay lon nhat la: ");
	date max = d[0];
	for(int i=0;i<n;i++){
		if(d[i].soSanh(max)){
			max = d[i];
		}
	}
	max.hien();
}
