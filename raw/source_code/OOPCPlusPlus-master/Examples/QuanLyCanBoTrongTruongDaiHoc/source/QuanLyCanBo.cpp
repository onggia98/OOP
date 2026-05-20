#include "QuanLyCanBo.h"

QuanLyCanBo::QuanLyCanBo() {

}

void QuanLyCanBo::nhapDanhSach() {
    CanBo* canBo;
    int chon;
    do {
        system("cls");
        cout << "1. Nhap Giang Vien" << endl;
        cout << "2. Nhap Nhan vien hanh chinh" << endl;
        cout << "3. Tro ve" << endl;
        cin >> chon;
        switch (chon) {
            case 1:
                canBo = new GiangVien();
                canBo->nhap();
                dsCanBo.push_back(canBo);
                break;
            case 2:
                canBo = new NhanVienHanhChinh();
                canBo->nhap();
                dsCanBo.push_back(canBo);
                break;
            case 3:
                break;
            default:
                break;
        }
    } while (chon != 3);
}

void QuanLyCanBo::inDanhSach(ostream& os) {
    for (int i = 0; i < dsCanBo.size(); i++) {
        dsCanBo[i]->xuat(os);
    }
}

unsigned int QuanLyCanBo::tinhTongLuong() {
    unsigned int tongLuong = 0;
    for (int i = 0; i < dsCanBo.size(); i++) {
        tongLuong += dsCanBo[i]->tinhLuong();
    }
    return tongLuong;
}

void QuanLyCanBo::timGiangVienLuongCaoNhat() {
	
    CanBo* canBoLuongCao = NULL;
	
    for (int i = 0; i < dsCanBo.size(); i++) {
        if (dsCanBo[i]->getID() == 1) {
            if (canBoLuongCao == NULL) {
                canBoLuongCao = dsCanBo[i];
            } else {
                if (dsCanBo[i]->tinhLuong() > canBoLuongCao->tinhLuong()) {
                    canBoLuongCao = dsCanBo[i];
                }
            }
        }
    }
    
    ofstream outfile;
    outfile.open("LuongCanBo.txt");
    for (int i = 0; i < dsCanBo.size(); i++) {
        if (dsCanBo[i]->tinhLuong() == canBoLuongCao->tinhLuong()) {
            dsCanBo[i]->xuat(outfile);
        }
    }
    outfile.close();
}
