#include <iostream>
using namespace std;
class TamGiac {
private:
    float canh1, canh2, canh3;
public:
    // Hàm khởi tạo không có tham số
    TamGiac();
    // Hàm khởi tạo có tham số
    TamGiac(float c1, float c2, float c3);
    // Hàm hủy
    ~TamGiac();
    // Phương thức nhập
    void Nhap();
    // Phương thức xuất
    void Xuat();
    // Hàm kiểm tra xem có phải tam giác không
    bool KiemTraTamGiac();
};
// Hàm khởi tạo không có tham số
TamGiac::TamGiac() {
    cout << "Ham khoi tao khong tham so";
    this->canh1 = this->canh2 = this->canh3 = 0;
}
// Hàm khởi tạo có tham số
TamGiac::TamGiac(float c1, float c2, float c3) {
    cout << "Ham khoi tao co tham so";
    this->canh1 = c1;
    this->canh2 = c2;
    this->canh3 = c3;
}
TamGiac::~TamGiac(){
    cout << "Ham duoc huy tai day" << endl;
}
// Phương thức nhập
void TamGiac::Nhap() {
    cout << "Nhap do dai cua 3 canh tam giac:" << endl;
    cout << "Canh 1: ";
    cin >> this->canh1;
    cout << "Canh 2: ";
    cin >> this->canh2;
    cout << "Canh 3: ";
    cin >> this->canh3;
}
// Phương thức xuất
void TamGiac::Xuat() {
    cout << "3 canh cua tam giac la: " << this->canh1 << ", " << this->canh2 << ", " << this->canh3 << endl;
}
// Hàm kiểm tra xem có phải tam giác không
bool TamGiac::KiemTraTamGiac() {
    if (this->canh1 + this->canh2 > this->canh3 && this->canh1 + this->canh3 > this->canh2 && this->canh2 + this->canh3 > this->canh1)
        return true;
    return false;
}
int main() {
    int n;
    cout << "Nhap so luong tam giac: ";
    cin >> n;
    TamGiac *dsTamGiac = new TamGiac[n];
    cout << "Nhap thong tin cho cac tam giac:" << endl;
    for (int i = 0; i < n; ++i) {
        dsTamGiac[i].Nhap();
    }
    cout << "Cac tam giac thoa man dieu kien la:" << endl;
    for (int i = 0; i < n; ++i) {
        if (dsTamGiac[i].KiemTraTamGiac()) {
            dsTamGiac[i].Xuat();
        }
    }
    delete[] dsTamGiac;
    return 0;
}
