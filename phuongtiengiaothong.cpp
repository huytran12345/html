#include <iostream>
#include <string>

using namespace std;

class PhuongTienGiaoThong {
protected:
    string hangSanXuat;
    string tenPhuongTien;
    int namSanXuat;
    float vanTocToiDa;

public:
    PhuongTienGiaoThong() {}

    PhuongTienGiaoThong(string hang, string ten, int nam, float vanToc) {
        hangSanXuat = hang;
        tenPhuongTien = ten;
        namSanXuat = nam;
        vanTocToiDa = vanToc;
    }

    void nhap() {
        cout << "Nhap hang san xuat: ";cin.ignore();
        getline(cin , hangSanXuat);
        cout << "Nhap ten phuong tien: ";
        cin.ignore();
        getline(cin , tenPhuongTien);
        cout << "Nhap nam san xuat: ";
        cin >> namSanXuat;
        cout << "Nhap van toc toi da: ";
        cin >> vanTocToiDa;
    }

    void xuat() {
        cout << "Hang san xuat: " << hangSanXuat << endl;
        cout << "Ten phuong tien: " << tenPhuongTien << endl;
        cout << "Nam san xuat: " << namSanXuat << endl;
        cout << "Van toc toi da: " << vanTocToiDa << endl;
    }

    float getVanTocToiDa() const {
        return vanTocToiDa;
    }
};

class OTo : public PhuongTienGiaoThong {
private:
    int soChoNgoi;
    string kieuDongCo;

public:
    OTo() {}

    OTo(string hang, string ten, int nam, float vanToc, int soCho, string kieuDong)
        : PhuongTienGiaoThong(hang, ten, nam, vanToc), soChoNgoi(soCho), kieuDongCo(kieuDong) {}

    void nhap() {
        PhuongTienGiaoThong::nhap();
        cout << "Nhap so cho ngoi: ";
        cin >> soChoNgoi;
        cout << "Nhap kieu dong co: ";
        cin >> kieuDongCo;
    }

    void xuat() {
        PhuongTienGiaoThong::xuat();
        cout << "So cho ngoi: " << soChoNgoi << endl;
        cout << "Kieu dong co: " << kieuDongCo << endl;
        cout << "Van toc co so: " << getVanTocCoSo() << endl;
    }

    float getVanTocCoSo() const {
        return vanTocToiDa / 4;
    }

    bool operator<(const OTo& other) const {
        return getVanTocCoSo() < other.getVanTocCoSo();
    }
};

void swap(OTo& a, OTo& b) {
    OTo temp = a;
    a = b;
    b = temp;
}

void sortDescending(OTo arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap so luong OTo: ";
    cin >> n;

    OTo* danhSachOTo = new OTo[n];
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin cho OTo thu " << i + 1 << ":" << endl;
        danhSachOTo[i].nhap();
    }
    cout << "Thong tin OTo:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "OTo thu " << i + 1 << ":" << endl;
        danhSachOTo[i].xuat();
        cout << endl;
    }
    sortDescending(danhSachOTo, n);
    cout << "Danh sach OTo sau khi sap xep:" << endl;
    for (int i = 0; i < n; ++i) {
        danhSachOTo[i].xuat();
        cout << endl;
    }

    delete[] danhSachOTo;

    return 0;
}
