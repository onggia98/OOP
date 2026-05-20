#include "QuanLyCanBo.h"

int main() {
	QuanLyCanBo quanLyCanBo;

    int chon;
    do {
        system("cls");
        cout << "Moi ban chon menu:"<< endl;
        cout << "0. Thoat" << endl;
        cout << "1. Nhap danh sach" << endl;
        cout << "2. In danh sach ra man hinh" << endl;
        cout << "3. In danh sach ra file" << endl;
        cout << "4. Tinh tong luong" << endl;
        cout << "5. Tim Giang vien luong cao nhat" << endl;

        cin >> chon;
        
        ofstream outfile;
        
        switch (chon) {
        	case 0:
        		break;
            case 1:
                quanLyCanBo.nhapDanhSach();
                break;
            case 2:
                quanLyCanBo.inDanhSach(cout);
                system("pause");
                break;
            case 3:
            	outfile.open("DanhSach.txt");
                quanLyCanBo.inDanhSach(outfile);
                outfile.close();
                break;
            case 4:
                cout << "Tong luong: " << quanLyCanBo.tinhTongLuong() << endl;
                system("pause");
                break;
            case 5:
                quanLyCanBo.timGiangVienLuongCaoNhat();
                break;
            default:
                cout << "Ban chon sai" << endl;
                system("pause");
                break;
        }
    } while (chon != 0);
    
    return 0;
}
