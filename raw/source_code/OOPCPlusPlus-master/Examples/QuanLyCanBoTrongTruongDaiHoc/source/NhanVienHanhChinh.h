#ifndef NhanVienHanhChinh_h
#define NhanVienHanhChinh_h
#include "CanBo.h"

class NhanVienHanhChinh : public CanBo
{
  private:
    string phongBan;
    unsigned short soNgayCong;
    string chucVu;

  public:
    NhanVienHanhChinh();
    void nhap();
    void xuat(ostream &os);
    unsigned int tinhLuong();
    unsigned char getID();
};
#endif
