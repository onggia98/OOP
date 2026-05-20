#include "GiangVien.h"

GiangVien::GiangVien() {

}

void GiangVien::nhap() {
    CanBo::nhap();

    fflush(stdin);
    cout << "Nhap khoa: ";
    getline(cin, khoa);
    cout << endl;

    int chon;
    do {
        cout << "Chon trinh do: " << "1. Cu Nhan\t2. Thac Si\t3. Tien Si: ";
        cin >> chon;
        switch (chon) {
            case 1:
                trinhDo = "Cu Nhan";
                phuCap = 300;
                break;
            case 2:
                trinhDo = "Thac Si";
                phuCap = 500;
                break;
            case 3:
                trinhDo = "Tien Si";
                phuCap = 1000;
                break;
            default:
                cout << "Ban chon sai. Hay chon trong pham vi tu [1-3]" << endl;
                system("pause");
                break;
        }
    } while (chon < 1 || chon > 3);

    cout << "Nhap so tiet day: ";
    cin >> soTietDay;
    cout << endl;
}

void GiangVien::xuat(ostream &os) {
    CanBo::xuat(os);
    os <<"Khoa: " << khoa << " - Trinh do: " << trinhDo << " - Phu Cap: " << phuCap << " - So tiet day: " << soTietDay << endl;
}

unsigned int GiangVien::tinhLuong() {
    return heSoLuong*730 + phuCap + soTietDay*45;
}

unsigned char GiangVien::getID() {
	return 1;
}
