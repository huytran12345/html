#include <iostream>
using namespace std;
class Date {
private:
    int day;
    int month;
    int year;
public:
    // Constructors
    Date();
    Date(int d, int m, int y);
    // Destructor
    ~Date();
    // Input method
    void Input();
    // Output method
    void Output();
    // Overloading > operator
    bool operator>(const Date& other) const;
};
// Constructors
Date::Date() : day(0), month(0), year(0) {
    cout << "Ham mac dinh duoc tao o day" << endl;
}
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    cout << "Ham duoc khoi tao o day" << endl;
}
// Destructor
Date::~Date() {
    cout << "Ham da huy" << endl;
}
// Input method
void Date::Input() {
    cout << "Nhap ngay: ";
    cin >> this->day;
    cout << "Nhap thang: ";
    cin >> this->month;
    cout << "Nhap nam: ";
    cin >> this->year;
}
// Output method
void Date::Output() {
    cout << "Date: " << this->day << "/" << this->month << "/" << this->year << endl;
}
// Overloading > operator
bool Date::operator>(const Date& other) const {
    if (this->year > other.year)
        return true;
    else if (this->year == other.year && this->month > other.month)
        return true;
    else if (this->year == other.year && this->month == other.month && this->day > other.day)
        return true;
    return false;
}
int main() {
    int n;
    cout << "Nhap so ngay: ";
    cin >> n;
    // Input dates
    Date* dates = new Date[n];
    for (int i = 0; i < n; ++i) {
        cout << "Nhap date " << i + 1 << ":\n";
        dates[i].Input();
    }
    // Find and display the maximum date
    Date maxDate = dates[0];
    for (int i = 1; i < n; ++i) {
        if (dates[i] > maxDate)
            maxDate = dates[i];
    }
    cout << "Date lon nhat:\n";
    maxDate.Output();
    delete[] dates;
    return 0;
}
