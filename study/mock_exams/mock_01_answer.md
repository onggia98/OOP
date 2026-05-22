# Đáp Án — Mock Exam 01

---

## Câu 1 — Lớp SoPhuc với Operator Overloading

```cpp
#include <iostream>
#include <vector>
using namespace std;

class SoPhuc {
private:
    double _re;   // phần thực
    double _im;   // phần ảo

public:
    SoPhuc(double re = 0, double im = 0) : _re(re), _im(im) {}

    // operator+ → trả về object mới
    SoPhuc operator+(const SoPhuc& other) const {
        return SoPhuc(_re + other._re, _im + other._im);
    }

    // operator+= → cộng dồn vào *this
    SoPhuc& operator+=(const SoPhuc& other) {
        _re += other._re;
        _im += other._im;
        return *this;
    }

    // operator<< → phải là friend
    friend ostream& operator<<(ostream& os, const SoPhuc& s) {
        os << s._re;
        if (s._im >= 0) os << " + " << s._im  << "i";
        else            os << " - " << -s._im << "i";
        return os;
    }

    void nhap() { cin >> _re >> _im; }
};

int main() {
    int n;
    cout << "Nhap so phan tu: "; cin >> n;

    vector<SoPhuc> ds(n);
    for (int i = 0; i < n; i++) {
        cout << "Nhap so phuc " << i+1 << ": ";
        ds[i].nhap();
    }

    SoPhuc tong(0, 0);
    for (const auto& sp : ds) tong += sp;

    cout << "Tong: " << tong << endl;
    return 0;
}
```

### Checklist câu 1
- [ ] `operator+` có `const` ở cuối và `const&` ở tham số
- [ ] `operator<<` là `friend`, trả về `ostream&`
- [ ] Xử lý dấu phần ảo (không in `+ -4i`)

---

## Câu 2 — Inheritance + Polymorphism (Nhân viên)

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ── BASE CLASS ────────────────────────────────────────────────────
class NhanVien {
protected:
    string _hoTen;
public:
    NhanVien(string hoTen) : _hoTen(hoTen) {}
    virtual ~NhanVien() {}                       // ← KHÔNG quên
    virtual double tinhLuong() const = 0;        // pure virtual
    virtual string loai() const = 0;
    void xuat() const {
        cout << _hoTen << " (" << loai() << ")"
             << " - Luong: " << tinhLuong() << "\n";
    }
};

// ── LỚP CON 1 ────────────────────────────────────────────────────
class NhanVienChinhThuc : public NhanVien {
    double _luongCB;
    double _phuCap;
public:
    NhanVienChinhThuc(string ht, double lcb, double pc)
        : NhanVien(ht), _luongCB(lcb), _phuCap(pc) {}
    double tinhLuong() const override { return _luongCB + _phuCap; }
    string loai() const override { return "Chinh thuc"; }
};

// ── LỚP CON 2 ────────────────────────────────────────────────────
class NhanVienHopDong : public NhanVien {
    double _luongNgay;
    int    _soNgayLam;
public:
    NhanVienHopDong(string ht, double luongNgay, int soNgay)
        : NhanVien(ht), _luongNgay(luongNgay), _soNgayLam(soNgay) {}
    double tinhLuong() const override { return _luongNgay * _soNgayLam; }
    string loai() const override { return "Hop dong"; }
};

// ── CONTAINER ─────────────────────────────────────────────────────
class CongTy {
    vector<NhanVien*> _ds;
public:
    ~CongTy() { for (auto p : _ds) delete p; }
    void them(NhanVien* nv) { _ds.push_back(nv); }
    void xuatDanhSach() const {
        cout << "=== Danh sach nhan vien ===\n";
        for (auto p : _ds) p->xuat();          // virtual dispatch
        cout << "Tong quy luong: " << tongLuong() << "\n";
    }
    double tongLuong() const {
        double tong = 0;
        for (auto p : _ds) tong += p->tinhLuong();
        return tong;
    }
};

int main() {
    CongTy cty;
    cty.them(new NhanVienChinhThuc("Nguyen Van A", 7000000, 1500000));
    cty.them(new NhanVienHopDong("Tran Thi B", 300000, 14));
    cty.them(new NhanVienChinhThuc("Le Van C", 10000000, 2000000));
    cty.xuatDanhSach();
    return 0;
}
```

### Checklist câu 2
- [ ] `virtual ~NhanVien() {}` có mặt trong base class
- [ ] `tinhLuong()` và `loai()` là pure virtual
- [ ] Lớp con dùng `override`
- [ ] Container dùng `vector<NhanVien*>` (pointer, không phải value)
- [ ] `~CongTy()` có `delete` từng pointer

---

## Thang điểm tự chấm

| Phần | Điểm tối đa | Tự chấm |
|------|-------------|---------|
| C1: SoPhuc constructor + nhap/xuat | 1 | |
| C1: operator+ đúng signature | 1.5 | |
| C1: operator<< là friend, xử lý dấu | 1.5 | |
| C1: main đúng logic | 1 | |
| C2: Base class + virtual destructor | 1.5 | |
| C2: 2 lớp con override đúng | 2 | |
| C2: Container + delete đúng | 1.5 | |
| **Tổng** | **10** | |

**Nếu tổng < 7:** Xem lại buổi nào yếu → ôn lại trước khi làm mock 02.
