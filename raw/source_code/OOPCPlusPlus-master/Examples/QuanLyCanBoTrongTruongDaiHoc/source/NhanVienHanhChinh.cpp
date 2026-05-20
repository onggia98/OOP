#include "NhanVienHanhChinh.h"

NhanVienHanhChinh::NhanVienHanhChinh() {
	
}

void NhanVienHanhChinh::nhap() {
    CanBo::nhap();

    fflush(stdin);
    cout << "Nhap phong ban: ";
    getline(cin, phongBan);

    int chon;    
    do
    {
        cout << "Chon chuc vu: " << "1. Truong Phong\t2. Pho Phong\t3. Nhan Vien: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
            chucVu = "Truong Phong";
            phuCap = 2000;
            break;
        case 2:
            chucVu = "Pho Phong";
            phuCap = 1000;
            break;
        case 3:
            chucVu = "Nhan Vien";
            phuCap = 500;
            break;
        default:
            cout << "Ban chon sai. Hay chon trong pham vi tu [1-3]" << endl;
            system("pause");
            break;
        }
    } while (chon < 1 || chon > 3);

    cout << "Nhap so ngay cong: ";
    cin >> soNgayCong;
    cout << endl;
}

void NhanVienHanhChinh::xuat(ostream& os) {
    CanBo::xuat(os);
    os << "Phong ban: " << phongBan << " - Chuc vu: " << chucVu << " - So ngay cong: " << soNgayCong << endl;
}

unsigned int NhanVienHanhChinh::tinhLuong() {
    return heSoLuong*730 + phuCap + soNgayCong*200;
}

unsigned char NhanVienHanhChinh::getID() {
	return 2;
}
