#ifndef HinhVuong_h
#define HinhVuong_h

#include <iostream>
#include "HinhHoc.h"
using namespace std;

class HinhVuong: public HinhHoc {
public:
    HinhVuong(float chieuRong, float chieuDai);

    bool kiemTra();

    float chuVi();
    float dienTich();

    void toString();
};
#endif
