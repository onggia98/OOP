#ifndef GiangVien_h
#define GiangVien_h
#include "CanBo.h"

class GiangVien : public CanBo
{
  private:
    string khoa;
    string trinhDo;
    unsigned short soTietDay;

  public:
    GiangVien();
    void nhap();
    void xuat(ostream &os);
    unsigned int tinhLuong();
    unsigned char getID();
};
#endif
