#include <iostream>
using namespace std;
class HinhKhoiCN {
private:
    float chieuDai;
    float chieuRong;
    float chieuCao;
public:
    // Hàm khởi tạo mặc định
    HinhKhoiCN();
    // Hàm khởi tạo có tham số
    HinhKhoiCN(float dai, float rong, float cao);
    // Ham huy
    ~HinhKhoiCN();
    // Phương thức nhập
    void Nhap();
    // Phương thức xuất
    void Xuat();
    // Phương thức kiểm tra hình khối có phải là hình chữ nhật hay không
    bool KiemTra();
    // Phương thức kiểm tra hình khối có phải là hình lập phương hay không
    bool KiemTraLapPhuong();
};
// Hàm khởi tạo mặc định
HinhKhoiCN::HinhKhoiCN() {
    cout << "Ham khoi tao mac dinh" << endl;
    this->chieuDai = 0;
    this->chieuRong = 0;
    this->chieuCao = 0;
}
// Hàm khởi tạo có tham số
HinhKhoiCN::HinhKhoiCN(float dai, float rong, float cao) {
    cout << "Ham khoi tao co tham so";
    this->chieuDai = dai;
    this->chieuRong = rong;
    this->chieuCao = cao;
}
// Ham huy
HinhKhoiCN::~HinhKhoiCN(){
    cout << "Ham da huy" << endl;
}
// Phương thức nhập
void HinhKhoiCN::Nhap() {
    cout << "Nhap chieu dai: ";
    cin >> this->chieuDai;
    cout << "Nhap chieu rong: ";
    cin >> this->chieuRong;
    cout << "Nhap chieu cao: ";
    cin >> this->chieuCao;
}
// Phương thức xuất
void HinhKhoiCN::Xuat() {
    cout << "Chieu dai: " << this->chieuDai << endl;
    cout << "Chieu rong: " << this->chieuRong << endl;
    cout << "Chieu cao: " << this->chieuCao << endl;
}
// Phương thức kiểm tra hình khối có phải là hình chữ nhật hay không
bool HinhKhoiCN::KiemTra() {
    return (this->chieuDai > 0 && this->chieuRong > 0 && this->chieuCao > 0);
}
// Phương thức kiểm tra hình khối có phải là hình lập phương hay không
bool HinhKhoiCN::KiemTraLapPhuong() {
    return (this->chieuDai == this->chieuRong && this->chieuRong == this->chieuCao);
}
int main() {
    int n;
    cout << "Nhap so luong hinh khoi: ";
    cin >> n;
    HinhKhoiCN* danhSachHinhKhoi = new HinhKhoiCN[n];
    // Nhập danh sách hình khối
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin cho hinh khoi " << i + 1 << endl;
        danhSachHinhKhoi[i].Nhap();
    }
    // Xuất danh sách hình khối và kiểm tra hình lập phương
    cout << "Danh sach hinh lap phuong: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Hinh khoi " << i + 1 << endl;
        danhSachHinhKhoi[i].Xuat();
        if (danhSachHinhKhoi[i].KiemTraLapPhuong()) {
            cout << "La hinh lap phuong" << endl;
        }
    }
    delete[] danhSachHinhKhoi;
    return 0;
}
