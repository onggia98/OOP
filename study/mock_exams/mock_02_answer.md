# Đáp Án — Mock Exam 02

---

## Câu 1 — CStack với Big Three

### Phân tích yêu cầu từ main
| Lệnh | Cần |
|------|-----|
| `CStack st;` | Default constructor |
| `st.Push(10)` | `void Push(int val)` |
| `st.Size()` | `int Size() const` |
| `st.Top()` | `int Top() const` — xem đỉnh, không xóa |
| `st.Pop()` | `void Pop()` — xóa đỉnh |
| `CStack st2 = st;` | **Copy constructor (deep copy)** |
| `st3 = st;` | **Assignment operator (deep copy)** |

```cpp
#include <iostream>
using namespace std;

class CStack {
private:
    int* _data;
    int  _size;
    int  _capacity;

    void resize() {
        int newCap = (_capacity == 0) ? 4 : _capacity * 2;
        int* newData = new int[newCap];
        for (int i = 0; i < _size; i++) newData[i] = _data[i];
        delete[] _data;
        _data     = newData;
        _capacity = newCap;
    }

public:
    // ── Constructor ───────────────────────────────────────────────
    CStack() : _data(nullptr), _size(0), _capacity(0) {}

    // ── Destructor (Big Three #1) ──────────────────────────────────
    ~CStack() {
        delete[] _data;
        _data = nullptr;
    }

    // ── Copy Constructor (Big Three #2) — deep copy ────────────────
    CStack(const CStack& other) {
        _size     = other._size;
        _capacity = other._capacity;
        _data     = new int[_capacity];
        for (int i = 0; i < _size; i++) _data[i] = other._data[i];
    }

    // ── Assignment Operator (Big Three #3) ─────────────────────────
    CStack& operator=(const CStack& other) {
        if (this == &other) return *this;   // tự gán
        delete[] _data;                      // giải phóng cũ
        _size     = other._size;
        _capacity = other._capacity;
        _data     = new int[_capacity];
        for (int i = 0; i < _size; i++) _data[i] = other._data[i];
        return *this;
    }

    // ── Stack operations ──────────────────────────────────────────
    void Push(int val) {
        if (_size == _capacity) resize();
        _data[_size++] = val;
    }

    void Pop() {
        if (_size > 0) _size--;
    }

    int Top() const {
        if (_size == 0) throw runtime_error("Stack rong");
        return _data[_size - 1];
    }

    int Size() const { return _size; }
    bool Empty() const { return _size == 0; }
};

int main() {
    CStack st;
    st.Push(10); st.Push(20); st.Push(30);

    cout << "Size: " << st.Size() << "\n";   // 3
    cout << "Top: "  << st.Top()  << "\n";   // 30

    CStack st2 = st;    // copy constructor
    st2.Pop();
    cout << "st2 top: " << st2.Top() << "\n";  // 20
    cout << "st top: "  << st.Top()  << "\n";  // 30 (không đổi)

    CStack st3;
    st3 = st;           // assignment operator
    st3.Push(99);
    cout << "st3 size: " << st3.Size() << "\n";  // 4
    cout << "st size: "  << st.Size()  << "\n";  // 3 (không đổi)
    return 0;
}
```

### Điểm quan trọng câu 1
- Stack lưu element theo thứ tự LIFO: `_data[_size-1]` là đỉnh
- `Pop()` chỉ giảm `_size` — không cần xóa data (vùng đó sẽ bị ghi đè khi Push tiếp)
- Deep copy đảm bảo `st2` và `st` có vùng nhớ độc lập → thay đổi `st2` không ảnh hưởng `st`

---

## Câu 2 — Tài khoản ngân hàng

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ── BASE CLASS ────────────────────────────────────────────────────
class TaiKhoan {
protected:
    string _soTK;
    string _chuTK;
    double _soDu;
public:
    TaiKhoan(string soTK, string chuTK, double soDu)
        : _soTK(soTK), _chuTK(chuTK), _soDu(soDu) {}

    virtual ~TaiKhoan() {}

    double getSoDu() const { return _soDu; }
    string getSoTK() const { return _soTK; }
    string getChuTK() const { return _chuTK; }

    virtual double tinhChiPhi() const = 0;     // pure virtual
    virtual string loaiTK() const = 0;
    virtual void xuat() const {
        cout << _soTK << " - " << _chuTK
             << " [" << loaiTK() << "]"
             << " - So du: " << _soDu;
    }
};

// ── LỚP CON 1 — Tiết kiệm ────────────────────────────────────────
class TKTietKiem : public TaiKhoan {
    double _laiSuat;   // %/năm
public:
    TKTietKiem(string soTK, string chu, double soDu, double ls)
        : TaiKhoan(soTK, chu, soDu), _laiSuat(ls) {}

    double tinhChiPhi() const override {
        return _soDu * _laiSuat / 100.0;   // tiền lãi
    }
    string loaiTK() const override { return "Tiet kiem"; }
    void xuat() const override {
        TaiKhoan::xuat();
        cout << " - Lai/nam: " << tinhChiPhi() << "\n";
    }
};

// ── LỚP CON 2 — Thanh toán ────────────────────────────────────────
class TKThanhToan : public TaiKhoan {
    double _phiDuyTri;   // phí/tháng
public:
    TKThanhToan(string soTK, string chu, double soDu, double phi)
        : TaiKhoan(soTK, chu, soDu), _phiDuyTri(phi) {}

    double tinhChiPhi() const override {
        return _phiDuyTri * 12;   // chi phí 1 năm
    }
    string loaiTK() const override { return "Thanh toan"; }
    void xuat() const override {
        TaiKhoan::xuat();
        cout << " - Phi/nam: " << tinhChiPhi() << "\n";
    }
};

// ── CONTAINER ─────────────────────────────────────────────────────
class NganHang {
    vector<TaiKhoan*> _ds;
public:
    ~NganHang() { for (auto p : _ds) delete p; }
    void them(TaiKhoan* tk) { _ds.push_back(tk); }

    void xuatDanhSach() const {
        cout << "=== Danh sach tai khoan ===\n";
        for (auto p : _ds) p->xuat();
    }

    TaiKhoan* timMaxSoDu() const {
        if (_ds.empty()) return nullptr;
        TaiKhoan* max = _ds[0];
        for (auto p : _ds)
            if (p->getSoDu() > max->getSoDu()) max = p;
        return max;
    }
};

int main() {
    NganHang nh;
    nh.them(new TKTietKiem("TK001", "Nguyen Van A", 50000000, 5.0));
    nh.them(new TKThanhToan("TK002", "Tran Thi B", 10000000, 20000));
    nh.them(new TKTietKiem("TK003", "Le Van C", 100000000, 5.0));

    nh.xuatDanhSach();

    TaiKhoan* maxTK = nh.timMaxSoDu();
    if (maxTK)
        cout << "TK so du cao nhat: "
             << maxTK->getSoTK() << " - "
             << maxTK->getChuTK()
             << " (" << maxTK->getSoDu() << ")\n";
    return 0;
}
```

---

## Thang điểm tự chấm

| Phần | Điểm | Tự chấm |
|------|------|---------|
| C1: Big Three đủ 3, đúng cú pháp | 2 | |
| C1: Push/Pop/Top/Size đúng logic | 1.5 | |
| C1: Self-assignment check trong op= | 0.5 | |
| C1: delete[] trong dtor + op= | 1 | |
| C2: Base + virtual destructor + pure virtual | 1.5 | |
| C2: 2 lớp con override đúng | 2 | |
| C2: Container + timMaxSoDu | 1.5 | |
| **Tổng** | **10** | |

### So sánh mock 01 vs mock 02
| | Mock 01 | Mock 02 |
|---|---|---|
| Câu 1 | Operator overloading | **Big Three** (khó hơn) |
| Câu 2 | Nhân viên (đơn giản) | Ngân hàng (có base method gọi từ lớp con) |
| Khó | ⭐⭐⭐ | ⭐⭐⭐⭐ |
