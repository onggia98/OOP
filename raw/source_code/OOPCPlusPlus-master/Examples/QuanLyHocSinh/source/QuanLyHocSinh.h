#ifndef QuanLyHocSinh_h
#define QuanLyHocSinh_h
#include <vector>
#include <fstream>
#include "HocSinh.h"

class QuanLyHocSinh {
    private:
        vector<HocSinh> dsHocSinh;
    public:
        QuanLyHocSinh();
        void nhapDanhSach();
        void xuatDanhSach(ostream &os);
        void timDiemTrungBinhLonHon5();
};

#endif