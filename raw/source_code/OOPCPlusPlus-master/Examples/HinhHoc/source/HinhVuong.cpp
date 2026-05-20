#include "HinhVuong.h"

HinhVuong::HinhVuong(float chieuRong, float chieuDai): HinhHoc(chieuRong, chieuDai) {
}

float HinhVuong::chuVi() {
    if (kiemTra()) {
        return 4*_chieuDai;
    } else {
        return 0.0f;
    }
}

float HinhVuong::dienTich() {
    if (kiemTra()) {
        return _chieuDai*_chieuRong;
    } else {
        return 0.0f;
    }
}

bool HinhVuong::kiemTra() {
    return _chieuDai > 0 && _chieuRong > 0  && _chieuDai== _chieuRong;
}

void HinhVuong::toString() {
    cout << "Hinh Vuong:" << "\t"
         << "Chieu dai:" << _chieuDai << " "
         << "Chieu rong:" << _chieuRong << "\t"
         << "Chu vi:" << chuVi() << "\t"
         << "Dien tich:" << dienTich()
         << endl;
}
