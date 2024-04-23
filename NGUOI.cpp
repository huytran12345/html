#include <iostream>
#include <string>

using namespace std;

class Nguoi {
private:
    string maDinhDanh;
    string hoTen;

public:
    Nguoi() {}

    Nguoi(string ma, string ten) : maDinhDanh(ma), hoTen(ten) {}

    void nhap() {
        cout << "Nhap ma dinh danh: ";
        getline(cin, maDinhDanh);
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);
    }

    void xuat() {
        cout << "Ma dinh danh: " << maDinhDanh << endl;
        cout << "Ho ten: " << hoTen << endl;
    }
};

class NhanVien : public Nguoi {
private:
    int namSinh;
    float heSoLuong;
    static float tienPhuCap;

public:
    NhanVien() {}

    NhanVien(string ma, string ten, int nam, float hsl) : Nguoi(ma, ten), namSinh(nam), heSoLuong(hsl) {}

    static void setTienPhuCap(float tpc) {
        tienPhuCap = tpc;
    }

    void nhap() {
        Nguoi::nhap();
        cout << "Nhap nam sinh: ";
        cin >> namSinh;
        cout << "Nhap he so luong: ";
        cin >> heSoLuong;
        cin.ignore();
    }

    void xuat() {
        Nguoi::xuat();
        cout << "Nam sinh: " << namSinh << endl;
        cout << "He so luong: " << heSoLuong << endl;
        cout << "Luong: " << tinhLuong() << endl;
    }

    float tinhLuong() {
        return heSoLuong * 1550 + tienPhuCap;
    }

    bool operator>(const NhanVien &nv) const {
        return heSoLuong > nv.heSoLuong;
    }
};

float NhanVien::tienPhuCap = 0;

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    cin.ignore(); 

    NhanVien danhSachNV[n];
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin cho nhan vien thu " << i + 1 << ":" << endl;
        danhSachNV[i].nhap();
    }
    cout << "\nThong tin cac nhan vien va luong:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachNV[i].xuat();
        cout << endl;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (danhSachNV[i] > danhSachNV[j]) {
                NhanVien temp = danhSachNV[i];
                danhSachNV[i] = danhSachNV[j];
                danhSachNV[j] = temp;
            }
        }
    }
    cout << "Danh sach nhan vien sau khi sap xep theo he so luong giam dan:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachNV[i].xuat();
        cout << endl;
    }
    return 0;
}
