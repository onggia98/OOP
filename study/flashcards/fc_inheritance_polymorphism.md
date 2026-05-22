# Flashcard — Inheritance + Polymorphism
> Chủ đề: Buổi 5 | Tần suất thi: **100% mọi đề** (câu 2 bắt buộc)

---

## Q1: Inheritance là gì? Syntax trong C++?
**A:** Lớp con (derived) kế thừa thuộc tính và method của lớp cha (base).
```cpp
class SinhVien { ... };           // base class

class SinhVienCQ : public SinhVien {   // SinhVienCQ IS-A SinhVien
    // kế thừa tất cả public/protected của SinhVien
    // thêm thuộc tính/method riêng ở đây
};
```
> `public` inheritance → giữ nguyên access modifier. Dùng `public` trong đề thi.

---

## Q2: `virtual function` là gì? Tại sao cần?
**A:** Method được đánh dấu `virtual` cho phép lớp con override và được gọi đúng lúc runtime.
```cpp
class SinhVien {
public:
    virtual float tinhHocBong() { return 0; }   // có thể override
};

class SinhVienCQ : public SinhVien {
public:
    float tinhHocBong() override { return 1000000; }   // lớp con override
};

SinhVien* p = new SinhVienCQ();
p->tinhHocBong();   // gọi SinhVienCQ::tinhHocBong() → đúng (dynamic dispatch)
```
> Không có `virtual` → gọi SinhVien::tinhHocBong() dù p trỏ đến SinhVienCQ → **sai**.

---

## Q3: Pure virtual function là gì? Abstract class là gì?
**A:**
```cpp
class SinhVien {
public:
    virtual float tinhHocBong() = 0;   // pure virtual → abstract method
};
// SinhVien trở thành abstract class:
// - Không thể tạo object trực tiếp: SinhVien sv; ← COMPILE ERROR
// - Lớp con PHẢI implement tinhHocBong() nếu muốn tạo object
```

---

## Q4: `virtual ~Base()` — tại sao KHÔNG ĐƯỢC quên?
**A:**
```cpp
// Nếu KHÔNG có virtual destructor:
SinhVien* p = new SinhVienCQ();
delete p;   // chỉ gọi ~SinhVien(), KHÔNG gọi ~SinhVienCQ() → memory leak!

// Nếu CÓ virtual destructor:
class SinhVien {
public:
    virtual ~SinhVien() {}   // ← viết ngay sau constructor
};
delete p;   // gọi ~SinhVienCQ() trước, rồi ~SinhVien() → đúng!
```
> **Quy tắc vàng:** bất kỳ class nào dùng với base pointer → phải có `virtual ~ClassName()`.

---

## Q5: `override` keyword dùng để làm gì?
**A:** Báo cho compiler biết method này override method cha. Compiler sẽ báo lỗi nếu sai.
```cpp
class Base {
    virtual void func(int x) {}
};

class Child : public Base {
    void func(int x) override {}        // ✅ override đúng
    void func(double x) override {}     // ✅ COMPILE ERROR — không có method cha nào như này
    void func(int x) const override {}  // ✅ COMPILE ERROR — signature khác
};
```
> Luôn dùng `override` → bắt lỗi typo signature sớm.

---

## Q6: Upcasting và Downcasting là gì?
**A:**
```cpp
// UPCASTING — lớp con → lớp cha (an toàn, tự động)
SinhVienCQ* cq = new SinhVienCQ();
SinhVien* base = cq;              // upcasting: implicit, safe

// DOWNCASTING — lớp cha → lớp con (cần kiểm tra)
SinhVienCQ* cq2 = dynamic_cast<SinhVienCQ*>(base);
if (cq2 != nullptr) {             // kiểm tra trước khi dùng
    // safe to use cq2
}
```

---

## Q7: Template câu 2 chuẩn — viết từ đầu trong < 5 phút
**A:**
```cpp
// BƯỚC 1: Base class abstract
class NhanVien {
protected:
    string _hoTen;
    double _luongCB;
public:
    NhanVien(string ht, double lcb) : _hoTen(ht), _luongCB(lcb) {}
    virtual ~NhanVien() {}                  // ← KHÔNG quên
    virtual double tinhLuong() const = 0;   // ← pure virtual
    virtual void xuat() const {
        cout << _hoTen << " - Luong: " << tinhLuong() << "\n";
    }
};

// BƯỚC 2: Lớp con (implement pure virtual)
class NhanVienChinh : public NhanVien {
    double _phuCap;
public:
    NhanVienChinh(string ht, double lcb, double pc)
        : NhanVien(ht, lcb), _phuCap(pc) {}
    double tinhLuong() const override {
        return _luongCB + _phuCap;
    }
};

class NhanVienHopDong : public NhanVien {
    int _soNgayLam;
public:
    NhanVienHopDong(string ht, double lcb, int ngay)
        : NhanVien(ht, lcb), _soNgayLam(ngay) {}
    double tinhLuong() const override {
        return _luongCB / 26.0 * _soNgayLam;
    }
};

// BƯỚC 3: Container
class CongTy {
    vector<NhanVien*> _ds;
public:
    ~CongTy() { for (auto p : _ds) delete p; }
    void them(NhanVien* nv) { _ds.push_back(nv); }
    void xuatTatCa() const {
        for (auto p : _ds) p->xuat();   // virtual dispatch
    }
    double tongLuong() const {
        double tong = 0;
        for (auto p : _ds) tong += p->tinhLuong();
        return tong;
    }
};
```

---

## Q8: 3 lỗi phổ biến nhất trong câu 2
**A:**

| Lỗi | Hậu quả | Cách nhớ |
|-----|---------|----------|
| Quên `virtual ~Base()` | Memory leak, undefined behavior | Viết ngay dòng đầu tiên sau `{` của base class |
| Quên `virtual` ở function | Static dispatch → sai lớp | Mọi method cần override đều phải `virtual` ở base |
| Dùng `if/else` kiểm tra type | Không đạt yêu cầu "bắt buộc đa hình" | Xóa hết `if/else`, để virtual tự làm việc |

---

## Q9: Thứ tự gọi constructor/destructor trong kế thừa?
**A:**
```cpp
class A { A() { cout << "A ctor\n"; } ~A() { cout << "A dtor\n"; } };
class B : public A { B() { cout << "B ctor\n"; } ~B() { cout << "B dtor\n"; } };

B b;
// Output:
// A ctor   ← cha trước
// B ctor   ← con sau
// B dtor   ← con trước (khi b bị hủy)
// A dtor   ← cha sau
```
> Ngược chiều: tạo theo thứ tự cha→con, hủy theo thứ tự con→cha.

---

## Q10: Polymorphism hoạt động thế nào qua `vector<Base*>`?
**A:**
```cpp
vector<SinhVien*> ds;
ds.push_back(new SinhVienCQ("Dao", 9.0));    // upcasting
ds.push_back(new SinhVienTN("Minh", 8.5));

for (auto p : ds) {
    p->tinhHocBong();   // gọi phiên bản của ĐÚNG lớp con (dynamic dispatch)
}

// Khi xóa:
for (auto p : ds) delete p;   // gọi đúng destructor nhờ virtual ~SinhVien()
```

---

## Quick Test — trả lời không nhìn

1. Sự khác biệt giữa `virtual function` và `pure virtual function`?
2. Tại sao KHÔNG có `virtual ~Base()` gây memory leak?
3. Thứ tự gọi constructor khi tạo object lớp con?
4. `override` keyword làm gì? Tại sao nên dùng?
5. Viết skeleton câu 2 (base class + 1 lớp con + container) trong 3 phút.
6. Điều gì xảy ra nếu thay `vector<Base*>` bằng `vector<Base>` (không phải pointer)?
