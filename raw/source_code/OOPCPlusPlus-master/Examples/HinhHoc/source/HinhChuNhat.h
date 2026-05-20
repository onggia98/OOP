#ifndef HinhChuNhat_h
#define HinhChuNhat_h

#include <iostream>
#include "HinhHoc.h"
using namespace std;

class HinhChuNhat: public HinhHoc {
public:
    HinhChuNhat(float chieuRong, float chieuDai);

    bool kiemTra();

    float chuVi();
    float dienTich();

    void toString();
};
#endif
