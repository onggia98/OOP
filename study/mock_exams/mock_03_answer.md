# Đáp Án — Đề Thi Thử 03

---

## Câu 1 (5 điểm) — CMyMatrix

### Phân tích yêu cầu từ main

| Lệnh trong main | Suy ra |
|----------------|--------|
| `CMyMatrix m1(2, 3)` | Constructor nhận rows, cols → cấp phát 2D động |
| `m1.Set(r, c, val)` | Setter |
| `m1.Get(r, c)` | Getter const |
| `m1.Print()` | In từng hàng |
| `m1.Sum()`, `m1.Max()` | Tính toán trên toàn ma trận |
| `CMyMatrix m2 = m1` | Copy constructor → deep copy |
| `m3 = m1` | operator= → deep copy |
| `m1 + m2` | operator+ → object mới |

### Code đầy đủ

```cpp
#include <iostream>
#include <climits>
using namespace std;

class CMyMatrix {
private:
    int** _data;
    int   _rows, _cols;

    void allocate() {
        _data = new int*[_rows];
        for (int i = 0; i < _rows; i++) {
            _data[i] = new int[_cols]();  // () → khởi tạo 0
        }
    }

    void deallocate() {
        if (_data) {
            for (int i = 0; i < _rows; i++) delete[] _data[i];
            delete[] _data;
            _data = nullptr;
        }
    }

    void copyFrom(const CMyMatrix& o) {
        _rows = o._rows; _cols = o._cols;
        allocate();
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                _data[i][j] = o._data[i][j];
    }

public:
    CMyMatrix(int rows, int cols) : _rows(rows), _cols(cols), _data(nullptr) {
        allocate();
    }

    ~CMyMatrix() { deallocate(); }

    CMyMatrix(const CMyMatrix& o) : _data(nullptr) {
        copyFrom(o);
    }

    CMyMatrix& operator=(const CMyMatrix& o) {
        if (this == &o) return *this;
        deallocate();
        copyFrom(o);
        return *this;
    }

    void Set(int r, int c, int val) { _data[r][c] = val; }
    int  Get(int r, int c) const    { return _data[r][c]; }

    void Print() const {
        for (int i = 0; i < _rows; i++) {
            for (int j = 0; j < _cols; j++)
                cout << _data[i][j] << " ";
            cout << "\n";
        }
    }

    int Sum() const {
        int s = 0;
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                s += _data[i][j];
        return s;
    }

    int Max() const {
        int m = INT_MIN;
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                if (_data[i][j] > m) m = _data[i][j];
        return m;
    }

    CMyMatrix operator+(const CMyMatrix& o) const {
        // Giả định 2 ma trận cùng kích thước
        CMyMatrix result(_rows, _cols);
        for (int i = 0; i < _rows; i++)
            for (int j = 0; j < _cols; j++)
                result._data[i][j] = _data[i][j] + o._data[i][j];
        return result;
    }
};

int main() {
    CMyMatrix m1(2, 3);
    m1.Set(0,0,1); m1.Set(0,1,2); m1.Set(0,2,3);
    m1.Set(1,0,4); m1.Set(1,1,5); m1.Set(1,2,6);

    cout << "m1:\n"; m1.Print();
    cout << "Sum = " << m1.Sum() << "\n";   // 21
    cout << "Max = " << m1.Max() << "\n";   // 6

    CMyMatrix m2 = m1;
    m2.Set(0, 0, 99);
    cout << "m1[0][0] = " << m1.Get(0,0) << "\n";  // 1
    cout << "m2[0][0] = " << m2.Get(0,0) << "\n";  // 99

    CMyMatrix m3(1, 1);
    m3 = m1;
    m3.Set(1, 1, 100);
    cout << "m1[1][1] = " << m1.Get(1,1) << "\n";  // 5

    CMyMatrix m4 = m1 + m2;
    cout << "m4[0][0] = " << m4.Get(0,0) << "\n";  // 100
    cout << "m4[0][1] = " << m4.Get(0,1) << "\n";  // 4

    return 0;
}
```

### Điểm quan trọng

- **Cấp phát 2D:** `new int*[rows]` + vòng for cấp phát từng hàng `new int[cols]()`
- **Giải phóng 2D:** vòng for `delete[] _data[i]` rồi `delete[] _data`
- **Helper method** `allocate()`, `deallocate()`, `copyFrom()` để tránh lặp code
- **`operator+` trả object mới** — không sửa `*this` hay `o`

---

## Câu 2 (5 điểm) — NganHang

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// BASE CLASS
class TaiKhoan {
protected:
    string _soTK, _chuTK;
    double _soDu;

public:
    TaiKhoan(string soTK, string chuTK, double soDu)
        : _soTK(soTK), _chuTK(chuTK), _soDu(soDu) {}

    virtual ~TaiKhoan() {}

    virtual double tinhLai()   const = 0;
    virtual string loaiTK()    const = 0;

    void xuat() const {
        cout << "[" << loaiTK() << "] "
             << _soTK << " | " << _chuTK
             << " | Du: " << _soDu
             << " | Lai/thang: " << tinhLai() << "\n";
    }

    double getSoDu() const { return _soDu; }
};

// TIET KIEM
class TKTietKiem : public TaiKhoan {
    double _laiSuat;  // % năm

public:
    TKTietKiem(string soTK, string chuTK, double soDu, double laiSuat)
        : TaiKhoan(soTK, chuTK, soDu), _laiSuat(laiSuat) {}

    double tinhLai() const override {
        return _soDu * _laiSuat / 100.0 / 12.0;
    }
    string loaiTK() const override { return "Tiet kiem"; }
};

// THANH TOAN
class TKThanhToan : public TaiKhoan {
public:
    TKThanhToan(string soTK, string chuTK, double soDu)
        : TaiKhoan(soTK, chuTK, soDu) {}

    double tinhLai() const override {
        if (_soDu < 50000) return 0;
        return _soDu * 0.001;
    }
    string loaiTK() const override { return "Thanh toan"; }
};

// DAU TU
class TKDauTu : public TaiKhoan {
    double _laiSuat;  // % năm

public:
    TKDauTu(string soTK, string chuTK, double soDu, double laiSuat)
        : TaiKhoan(soTK, chuTK, soDu), _laiSuat(laiSuat) {}

    double tinhLai() const override {
        double lai = _soDu * _laiSuat / 100.0 / 12.0;
        if (_soDu < 1000000) lai *= 0.8;  // hệ số rủi ro
        return lai;
    }
    string loaiTK() const override { return "Dau tu"; }
};

// CONTAINER
class NganHang {
    vector<TaiKhoan*> _ds;

public:
    ~NganHang() { for (auto p : _ds) delete p; }

    void them(TaiKhoan* tk) { _ds.push_back(tk); }

    void xuatTatCa() const {
        cout << "=== DANH SACH TAI KHOAN ===\n";
        for (auto p : _ds) p->xuat();
    }

    double tongLaiThang() const {
        double t = 0;
        for (auto p : _ds) t += p->tinhLai();
        return t;
    }

    TaiKhoan* timMaxLai() const {
        if (_ds.empty()) return nullptr;
        TaiKhoan* max = _ds[0];
        for (auto p : _ds)
            if (p->tinhLai() > max->tinhLai()) max = p;
        return max;
    }

    void inTKLaiCao(double nguong) const {
        cout << "=== TK lai > " << nguong << " ===\n";
        for (auto p : _ds)
            if (p->tinhLai() > nguong) p->xuat();
    }
};

int main() {
    NganHang nh;
    nh.them(new TKTietKiem("TK001", "Nguyen Van A", 10000000, 6.5));
    nh.them(new TKThanhToan("TK002", "Tran Thi B", 30000));
    nh.them(new TKThanhToan("TK003", "Le Van C", 500000));
    nh.them(new TKDauTu("TK004", "Pham Thi D", 5000000, 8.0));

    nh.xuatTatCa();
    cout << "Tong lai thang: " << nh.tongLaiThang() << "\n";

    cout << "TK lai cao nhat:\n";
    nh.timMaxLai()->xuat();

    nh.inTKLaiCao(1000);
    return 0;
}
```

### Kết quả chạy mẫu

```
TK001 Tiet kiem:  10,000,000 × 6.5/100/12 = 5,416.67 VND/tháng
TK002 Thanh toan: 30,000 < 50,000           = 0 VND/tháng
TK003 Thanh toan: 500,000 × 0.001           = 500 VND/tháng
TK004 Dau tu:     5,000,000 × 8/100/12      = 3,333.33 VND/tháng (>= 1M, không nhân 0.8)
Tổng: 5416.67 + 0 + 500 + 3333.33 = 9250 VND/tháng
TK lai cao nhat: TK001
TK lai > 1000: TK001, TK004
```

---

## Thang Điểm

| Tiêu chí | Điểm |
|---------|------|
| **Câu 1** | **5đ** |
| Constructor cấp phát 2D đúng | 0.5 |
| Destructor giải phóng đúng (loop + delete[]) | 0.75 |
| Copy constructor deep copy | 0.75 |
| operator= với self-assignment guard + delete cũ | 1.0 |
| Set, Get, Print, Sum, Max | 0.5 |
| operator+ trả object mới | 0.5 |
| **Câu 2** | **5đ** |
| Base class abstract với virtual destructor | 0.5 |
| 3 lớp con override tinhLai() đúng logic | 2.25 (0.75 mỗi lớp) |
| NganHang với vector<TaiKhoan*> | 0.25 |
| ~NganHang() delete đúng | 0.5 |
| tongLaiThang(), timMaxLai(), inTKLaiCao() | 1.0 |
| Polymorphism hoạt động (virtual dispatch) | 0.5 |
