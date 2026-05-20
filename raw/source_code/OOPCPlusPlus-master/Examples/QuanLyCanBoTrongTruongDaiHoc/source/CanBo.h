#ifndef CanBo_h
#define CanBo_h
#include <iostream>
#include <string>
using namespace std;

class CanBo
{
  protected:
    string hoTen;
    unsigned int phuCap;
    unsigned short heSoLuong;

  public:
    CanBo();
    virtual void nhap();
    virtual void xuat(ostream &os);
    virtual unsigned int tinhLuong() = 0;
    virtual unsigned char getID() = 0;
};
#endif
