#include "CanBo.h"

CanBo::CanBo() {

} 

void CanBo::nhap() {
    fflush(stdin);
    
    cout << "Nhap ho ten: ";
    getline(cin, hoTen);

    cout << "Nhap he so luong: ";
    cin >> heSoLuong;
}

void CanBo::xuat(ostream &os) {
    os << "Ho Ten: " << hoTen << " - He so luong: " << heSoLuong << endl;
}
