#include "QuanLyHocSinh.h"

int main() {
    QuanLyHocSinh quanLyHocSinh;

    int chon;
    do {
        system("cls");
        cout << "Moi ban chon menu:" << endl;
        cout << "0. Thoat" << endl;
        cout << "1. Nhap danh sach" << endl;
        cout << "2. In danh sach ra man hinh" << endl;
        cout << "3. In danh sach ra file" << endl;
        cout << "4. Tim hoc sinh co diem trung binh >= 5" << endl;

        cin >> chon;

        ofstream outfile;

        switch (chon) {
            case 0:
                break;
            case 1:
                quanLyHocSinh.nhapDanhSach();
                break;
            case 2:
                quanLyHocSinh.xuatDanhSach(cout);
                system("pause");
                break;
            case 3:
                outfile.open("DanhSach.txt");
                quanLyHocSinh.xuatDanhSach(outfile);
                outfile.close();
                system("pause");
                break;
            case 4:
                quanLyHocSinh.timDiemTrungBinhLonHon5();
                system("pause");
                break;
            default:
                cout << "Ban chon sai" << endl;
                system("pause");
                break;
        }
    } while (chon != 0);
    return 0;
}
