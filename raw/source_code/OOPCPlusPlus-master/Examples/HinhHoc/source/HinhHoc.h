#ifndef HinhHoc_h
#define HinhHoc_h

class HinhHoc {
protected:
    float _chieuDai;
    float _chieuRong;
public:
    HinhHoc(float chieuDai, float chieuRong);

    virtual bool kiemTra() = 0;

    virtual float chuVi() = 0;
    virtual float dienTich() = 0;

    virtual void toString() = 0;
};
#endif
