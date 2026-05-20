#ifndef HocSinh_h
#define HocSinh_h

#include <iostream>
#include <string>
using namespace std;

class HocSinh {
    private:
        string hoTen;
        string lop;
        float diemToan;
        float diemLy;
        float diemHoa;
    public:
        HocSinh();
        void nhap();
        void xuat(ostream &os);
        float diemTrungBinh();
};
#endif