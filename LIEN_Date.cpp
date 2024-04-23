#include <iostream>
using namespace std;
class Date {
	private:
		int ngay, thang, nam;
	public:
		Date();
		Date(int, int, int);
		void Nhap();
		void Xuat();
		bool operator>(const Date &SoSanh);
};

Date::Date() {
    cout<<"Khoi tao khong tam so!\n";
	this->ngay = 0;
	this->thang = 0;
	this->nam = 0;
}

Date::Date(int ngay, int thang, int nam) {
    cout<<"Khoi tao co tam so!\n";
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}

void Date::Nhap() {
		cout<<"Nhap ngay: "; cin>>this->ngay;
		cout<<"Nhap thang: ";cin>>this->thang;
		cout<<"Nhap nam: ";cin>>this->nam;
}

void Date::Xuat() {
    cout<<"ngay : "<<this->ngay<<"thang: "<<this->thang<<"nam: "<<this->nam<<endl;
}

bool Date::operator>(const Date &SoSanh) {
    if (this->nam > SoSanh.nam)
        return true;
    else if (this->nam < SoSanh.nam)
        return false;
    else {
        if (this->thang > SoSanh.thang)
            return true;
        else if (this->thang < SoSanh.thang)
            return false;
        else {
            if (this->ngay > SoSanh.ngay)
                return true;
            else
                return false;
        }
    }
}



int main () { 
    Date d1;
    d1.Xuat();
    Date d2(12,12,2004);
    d2.Xuat();
	int n;
	cout<<"Nhap so ngay: ";cin>>n;
    Date *d= new Date[n];
	for (int i = 0; i < n; i++) {
        cout<<"Nhap ngay thang nam ";
        d[i].Nhap();
    }
    for (int i = 0; i < n; i++) {
        cout<<"ngay thang nam vua nhap ";
        d[i].Xuat();
    }

	Date MaxDate = d[0];
	for(int i = 0; i < n; i++) {
		if (d[i] > MaxDate) {
			MaxDate = d[i];
		}
	}
	printf("\n\nNgay lon nhat la: ");
	MaxDate.Xuat();
	delete[] d;
}