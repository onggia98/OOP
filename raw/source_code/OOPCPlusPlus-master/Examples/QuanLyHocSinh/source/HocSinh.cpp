#include "HocSinh.h"

HocSinh::HocSinh() {

}

void HocSinh::nhap() {
    system("cls");
    cout << "Nhap thong tin hoc sinh" << endl;
    
    fflush(stdin);
    cout << "Ho ten hoc sinh: ";
    getline(cin, hoTen);

    cout << "Lop: ";
    getline(cin, lop);

    cout << "Diem Toan: ";
    cin >> diemToan;

    cout << "Diem Ly: ";
    cin >> diemLy;

    cout << "Diem Hoa: ";
    cin >> diemHoa;

}

void HocSinh::xuat(ostream &os) {
    os << "Hoc sinh: " << hoTen << " - Lop: " << lop << " - Diem Toan: " << diemToan << " - Diem Ly: " << diemLy << " - Diem Hoa: " << diemHoa << " - Diem TB: " << diemTrungBinh() << endl;
}

float HocSinh::diemTrungBinh() {
    return (diemToan + diemLy + diemHoa)/3.0f;
}