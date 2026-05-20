#include "QuanLyHocSinh.h"

QuanLyHocSinh::QuanLyHocSinh() {

}

void QuanLyHocSinh::nhapDanhSach() {
    HocSinh hocSinh;
    int chon;
    do {
        system("cls");
        cout << "1. Nhap Thong Tin" << endl;
        cout << "2. Tro ve" << endl;
        
        cin >> chon;
        switch (chon) {
            case 1:
                hocSinh.nhap();
                dsHocSinh.push_back(hocSinh);
                break;
            case 2:
                break;
            default:
                break;
        }
    } while (chon != 2);
}

void QuanLyHocSinh::xuatDanhSach(ostream &os) {
    for (int i = 0; i < dsHocSinh.size(); i++) {
        dsHocSinh[i].xuat(os);
    }
}

void QuanLyHocSinh::timDiemTrungBinhLonHon5() {
    ofstream outfile;
    outfile.open("DiemTB.txt");
    for (int i = 0; i < dsHocSinh.size(); i++) {
        if (dsHocSinh[i].diemTrungBinh() >= 5) {
            dsHocSinh[i].xuat(outfile);
        }
    }
    outfile.close();
}