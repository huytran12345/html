 /* #include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
class Monhoc
{
protected:
    string tenmon;
    float Diemtb,DiemT;
    int sotc;
public:
    Monhoc(){
        cout<<"Khoi tao khong tham so Monhoc\n";
        this->tenmon = "";
        this->DiemT = this->Diemtb =0;
        this->sotc =0;
    };
    ~Monhoc(){
        cout<<"Huy khoi tao\n";
        this->tenmon = "";
        this->DiemT = this->Diemtb =0;
        this->sotc =0;
    };
    
    void nhap(){
        cin.ignore();
        cout<<"TenMon: "; getline(cin,tenmon);
        cout<<"DemTB: "; cin>>Diemtb;
        cout<<"DiemT: "; cin>>DiemT;
        cout<<"Sotc: "; cin>>sotc;
    };
    void xuat();
    int TinChi(){
        return sotc;
    }
    float DTB(){
        return (Diemtb *0.3 + DiemT*0.7);
    };
};
void Monhoc::xuat(){
    cout<<"TenMon: " << tenmon << fixed << setprecision(2)<<" DiemTB: " << Diemtb << " DiemT: " << DiemT <<" Sotc: " << sotc;
    
}
class Sinhvien:public Monhoc 
{
private:
    string masv;
    string tensv;
    int SoMH;
    Monhoc *a;
public:
    Sinhvien(){
        cout<<"Khoi tao khong tham so Sinhvien\n";
        this->masv = this->tensv ="";
        this->SoMH =0;
    };
    ~Sinhvien(){
        cout<<"Huy khoi tao sinh vien\n";
        this->masv = this->tensv ="";
        this->SoMH =0;
    };
  
    void nhap(){
        
        cout<<"Masv: "; cin>>masv;
        cin.ignore();
        cout<<"TenSV: "; getline(cin,tensv);
        cout<<"SoMH: "; cin>>SoMH;
        // Monhoc::nhap();
        a = new Monhoc[SoMH];
        for (int i = 0; i < SoMH; i++)
        {
            cout<<"Nhap thong tin mon hon hoc thu " << i+1<<endl;
            a[i].nhap();
        }
        
    }
    void xuat(){
        
        cout<<"Masv: " << masv <<" TenSV: "<<tensv <<" SoMH: " << SoMH <<endl;
        for (int i = 0; i < SoMH; i++)
        {
            a[i].xuat();
            cout <<endl;
        }
        
    };

     float DTK() {
        float DiemTK = 0;
        int tongtc = 0;
        for (int i = 0; i < SoMH; i++) {
            DiemTK += a[i].DTB() * a[i].TinChi();
            tongtc += a[i].TinChi();
        }
        if (tongtc == 0) {
            cout << "Ko dk mon hoc\n";
            return 0;
        } else {
            return (DiemTK / tongtc);
        }
    }
     string XepLoai() {
        float dtk = DTK();
        if (dtk >= 9.0) {
            return "Xuat sac";
        } else if (dtk >= 8.0) {
            return "Gioi";
        } else if (dtk >= 7.0) {
            return "Kha";
        } else if (dtk >= 6.0) {
            return "Trung binh";
        } else {
            return "Yeu";
        }
     }
};
int main() {
    int n;
    cout << "Nhap ds sv";
    cin >> n;
    Sinhvien *sv = new Sinhvien[n];
    
    for (int i = 0; i < n; i++)
    {
        sv[i].nhap();
        cout<<endl;
    }
    for (int i = 0; i < n; i++)
    {
        sv[i].xuat();
        cout<<"DTK: " <<sv[i].DTK();
        cout<<endl;
    }
    cout<<"Ds sv Gioi tro len: \n";
    bool ktr = false;
    for (int i = 0; i < n; i++)
    {
        if (sv[i].XepLoai() == "Gioi" || sv[i].XepLoai() == "Xuat sac"){
            ktr = true;
            sv[i].xuat();
            cout<<" DiemTK: " <<sv[i].DTK() << endl;
        }
        
    }
    if (!ktr)
    {
        cout<<"Ko co sv nao\n";
    }
    
    delete [] sv;
    return 0;
}






 */
#include<iostream>
#include<string>
using namespace std;
class Monhoc{
private:
	string tenmon;
	float DiemTP,DiemT;
	int sotc;
public:
	void nhap(){
		cin.ignore();
		cout<<"TenMon: "; getline(cin,tenmon);
		cout<<"DiemTP: ";cin>>DiemTP;
		cout<<"DiemT: "; cin>>DiemT;
		cout<<"Sotc: "; cin>>sotc;
	}
	void xuat(){
		cout<<"TenMon: " << tenmon <<" DiemTP: " << DiemTP << " DiemT: "
		<<DiemT <<" Sotc: " <<sotc;
	}
	float DTB(){
		return DiemTP*0.3+DiemT*0.7;
	}
	int TinChi(){
		return sotc;
	}
	Monhoc(){
		cout<<"Khoi tao khong tham so\n";
		this->tenmon ="";
		this->DiemTP = this->DiemT =0;
		this->sotc =0;
	}
	~Monhoc(){
		cout<<"Huy Khoi tao\n";
		this->tenmon ="";
		this->DiemTP = this->DiemT =0;
		this->sotc =0;
	}
	
};
class Sinhvien{
private:
	string Masv,Tensv;
	int SoMH;
	Monhoc *a;
public:
	void nhap(){
		cout<<"Masv: "; cin>>Masv;
		cin.ignore();
		cout<<"TenSv: "; getline(cin,Tensv);
		cout<<"SoMH: "; cin>>SoMH;
		a = new Monhoc[SoMH];
		for(int i =0 ; i<SoMH;i++){
			a[i].nhap();
		}
	}
	void xuat(){
		cout<<"Masv: " <<Masv<< " Tensv: "<<Tensv<<" SoMH: "<<SoMH;
		for (int i = 0; i < SoMH; i++)
        {
            a[i].xuat();
            cout <<endl;
        }
	}
	Sinhvien(){
		cout<<"Khoi tao khong tham so\n";
		this->Masv = "";
		this->Tensv ="";
		this->SoMH =0;
		this->a = NULL;
	}
	~Sinhvien(){
		cout<<"Huy khoi tao\n";
		this->Masv = "";
		this->Tensv ="";
		this->SoMH =0;
		this->a = NULL;
	}
	
	float DTK(){
		float sumdtk =0;
		float tongtc =0;
		for(int i=0;i<SoMH ; i++){
			sumdtk = a[i].DTB() * a[i].TinChi();
			tongtc +=a[i].TinChi();
		}
		if(tongtc == 0){
			cout<<"Sv khong dk\n";return 0;
		}else{
			return sumdtk / tongtc;
		}
	}
	string xeploai(){
		float dtk = DTK();
		if(dtk >= 9.0){
			return "Xuat sac";
		}else if(dtk >= 8.0){
			return "Gioi";
		}else if(dtk >= 7.0){
			return "Kha";
		}else if(dtk>=6.0){
			return "Trung binh";
		}else{
			return "Yeu";
		}
	}
};
int main(){
	int n;
	cout<<"Nhap ds sinh vien: "; cin>>n;
	Sinhvien *sv=new Sinhvien[n];
	for(int i=0;i<n;i++){
		sv[i].nhap();
	}
	for(int i=0;i<n;i++){
		sv[i].xuat();
	}
	cout<<"\n----------------------------------------\n";
	bool ktr =false;
	for(int i=0;i<n;i++){
		if(sv[i].xeploai() =="Gioi" ||sv[i].xeploai() == "Xuat sac"){
			sv[i].xuat();
			cout<<"DTK: " <<sv[i].DTK();
			ktr = true;
			cout<<endl;
		}
	}
	if(!ktr){
		cout<<"Ko co sv du dk\n";
	}
	
	delete[] sv;
}







