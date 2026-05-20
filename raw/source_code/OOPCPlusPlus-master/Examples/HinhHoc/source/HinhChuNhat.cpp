#include "HinhChuNhat.h"

HinhChuNhat::HinhChuNhat(float chieuRong, float chieuDai): HinhHoc(chieuRong, chieuDai) {
}

float HinhChuNhat::chuVi() {
    if (kiemTra()) {
        return (_chieuDai + _chieuRong)*2;
    } else {
        return 0.0f;
    }
}

float HinhChuNhat::dienTich() {
    if (kiemTra()) {
        return _chieuDai*_chieuRong;
    } else {
        return 0.0f;
    }
}

bool HinhChuNhat::kiemTra() {
    return _chieuDai > 0 && _chieuRong > 0;
}

void HinhChuNhat::toString() {
    cout << "Hinh Chu Nhat:" << "\t"
         << "Chieu dai:" << _chieuDai << " "
         << "Chieu rong:" << _chieuRong << "\t"
         << "Chu vi:" << chuVi() << "\t"
         << "Dien tich:" << dienTich()
         << endl;
}
