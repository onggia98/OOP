#include <iostream>
#include <vector>
#include "HinhVuong.h"
#include "HinhChuNhat.h"
using namespace std;

int main() {
    // --- Cách cũ: tạo object theo giá trị, KHÔNG có polymorphism ---
    // HinhVuong hinhVuong = HinhVuong(5.0, 5.0);
    // hinhVuong.toString();
    // HinhChuNhat hinhChuNhat = HinhChuNhat(4.0, 3.0);
    // hinhChuNhat.toString();

    // [FIX] Dùng base pointer để có runtime polymorphism (đúng kiểu đề thi)
    vector<HinhHoc*> danhSach;
    danhSach.push_back(new HinhVuong(5.0, 5.0));
    danhSach.push_back(new HinhChuNhat(4.0, 3.0));

    for (int i = 0; i < danhSach.size(); i++) {
        if (danhSach[i]->kiemTra()) {   // gọi qua base pointer → virtual dispatch
            danhSach[i]->toString();
        }
    }

    // [FIX] Giải phóng bộ nhớ
    for (int i = 0; i < danhSach.size(); i++) {
        delete danhSach[i];
    }

    return 0;
}
