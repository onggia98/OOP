# Bài Tập — Ngày 5: Inheritance + Polymorphism
> Câu 2 bắt buộc 100% mọi đề. Không làm được = mất 5/10 điểm.

---

## Bài 1 — Nhận diện cấu trúc (5 phút — KHÔNG code)

Đọc đề sau và vẽ/liệt kê:
> "Hệ thống quản lý phương tiện giao thông gồm Ô tô, Xe máy, Xe tải. Mỗi loại có cách tính phí cầu đường khác nhau."

Xác định:
1. Base class là gì?
2. Lớp con là gì (bao nhiêu)?
3. Method nào cần `virtual` / pure virtual?
4. Container nên dùng kiểu gì?

<details>
<summary>Đáp án</summary>

1. Base class: `PhuongTien` (hoặc `Vehicle`)
2. 3 lớp con: `OTo`, `XeMay`, `XeTai`
3. `virtual double tinhPhiCauDuong() const = 0` — pure virtual
4. `vector<PhuongTien*>` — pointer đến base class (bắt buộc để polymorphism hoạt động)
</details>

---

## Bài 2 — Viết skeleton (15 phút)

Viết **skeleton** (chỉ khai báo, không cần logic đầy đủ) cho bài toán trên:
- Base class với virtual destructor + pure virtual method
- 2 lớp con (OTo, XeMay) — override method
- Container class

Mục tiêu: viết được khung trong < 15 phút không nhìn mẫu.

<details>
<summary>Đáp án</summary>

```cpp
class PhuongTien {
protected:
    string _ten, _bienSo;
public:
    PhuongTien(string ten, string bienSo) : _ten(ten), _bienSo(bienSo) {}
    virtual ~PhuongTien() {}
    virtual double tinhPhi() const = 0;
    virtual void xuat() const { cout << _ten << " [" << _bienSo << "]\n"; }
};

class OTo : public PhuongTien {
    int _soChoNgoi;
public:
    OTo(string ten, string bs, int cho) : PhuongTien(ten, bs), _soChoNgoi(cho) {}
    double tinhPhi() const override {
        return 1.5 + (_soChoNgoi >= 7 ? 0.5 : 0);
    }
};

class XeMay : public PhuongTien {
public:
    XeMay(string ten, string bs) : PhuongTien(ten, bs) {}
    double tinhPhi() const override { return 0.5; }
};

class CongTy {
    vector<PhuongTien*> _ds;
public:
    ~CongTy() { for (auto p : _ds) delete p; }
    void them(PhuongTien* pt) { _ds.push_back(pt); }
    double tongPhi() const {
        double t = 0;
        for (auto p : _ds) t += p->tinhPhi();
        return t;
    }
};
```
</details>

---

## Bài 3 — Đề thật 2019 HK2 câu 2 (35 phút)

> Nguồn: `knowledge/de_thi_analysis/de_thi_transcript.md`

Xét chương trình quản lý sinh viên với 3 hệ đào tạo:
- **Chính quy**: TB ≥ 8.0 → 1,000,000; TB ≥ 9.0 → 1,500,000
- **Cử nhân tài năng**: TB ≥ 8.0 → 1,500,000; TB ≥ 9.0 → 2,000,000
- **Chất lượng cao**: TB ≥ 8.0 → 2,000,000; TB ≥ 9.0 → 2,500,000

Nhập danh sách sinh viên hỗn hợp. Tính tổng học bổng. **Bắt buộc đa hình.**

<details>
<summary>Đáp án</summary>

```cpp
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SinhVien {
protected:
    string _hoTen;
    float  _diemTB;
public:
    SinhVien(string ht, float dtb) : _hoTen(ht), _diemTB(dtb) {}
    virtual ~SinhVien() {}
    virtual double tinhHocBong() const = 0;
    virtual string loaiHe() const = 0;
    void xuat() const {
        cout << _hoTen << " [" << loaiHe() << "]"
             << " TB=" << _diemTB
             << " HB=" << tinhHocBong() << "\n";
    }
};

class SVChinhQuy : public SinhVien {
public:
    SVChinhQuy(string ht, float dtb) : SinhVien(ht, dtb) {}
    double tinhHocBong() const override {
        if (_diemTB >= 9.0) return 1500000;
        if (_diemTB >= 8.0) return 1000000;
        return 0;
    }
    string loaiHe() const override { return "Chinh quy"; }
};

class SVTaiNang : public SinhVien {
public:
    SVTaiNang(string ht, float dtb) : SinhVien(ht, dtb) {}
    double tinhHocBong() const override {
        if (_diemTB >= 9.0) return 2000000;
        if (_diemTB >= 8.0) return 1500000;
        return 0;
    }
    string loaiHe() const override { return "Cu nhan tai nang"; }
};

class SVChatLuongCao : public SinhVien {
public:
    SVChatLuongCao(string ht, float dtb) : SinhVien(ht, dtb) {}
    double tinhHocBong() const override {
        if (_diemTB >= 9.0) return 2500000;
        if (_diemTB >= 8.0) return 2000000;
        return 0;
    }
    string loaiHe() const override { return "Chat luong cao"; }
};

class QuanLySV {
    vector<SinhVien*> _ds;
public:
    ~QuanLySV() { for (auto p : _ds) delete p; }
    void them(SinhVien* sv) { _ds.push_back(sv); }
    void xuatTatCa() const { for (auto p : _ds) p->xuat(); }
    double tongHocBong() const {
        double t = 0;
        for (auto p : _ds) t += p->tinhHocBong();
        return t;
    }
};

int main() {
    QuanLySV ql;
    ql.them(new SVChinhQuy("Nguyen Van A", 9.2));
    ql.them(new SVTaiNang("Tran Thi B", 8.5));
    ql.them(new SVChatLuongCao("Le Van C", 7.5));

    ql.xuatTatCa();
    cout << "Tong hoc bong: " << ql.tongHocBong() << "\n";
    return 0;
}
```
</details>

---

## Bài 4 — Đề thật 2025 HK2 câu 2 (35 phút)

> Nguồn: `knowledge/de_thi_analysis/de_thi_transcript.md` + `study/mock_exams/ans_2025HK2.md`

Hệ thống thiết bị hiển thị: Monitor, Projector, SmartTV.  
Xem yêu cầu đầy đủ trong `de_thi_transcript.md` (2025 HK2).

Làm không nhìn đáp án trước. Sau đó so sánh với `ans_2025HK2.md`.

---

## Bài 5 — Nhận diện lỗi (10 phút)

Tìm tất cả lỗi trong đoạn code sau:

```cpp
class Animal {
public:
    string _name;
    Animal(string n) : _name(n) {}
    void speak() { cout << "..."; }        // (A)
};

class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}
    void speak() { cout << "Woof!"; }      // (B)
};

class Cat : public Animal {
public:
    Cat(string n) : Animal(n) {}
    void speak() { cout << "Meow!"; }      // (C)
};

int main() {
    vector<Animal> animals;                // (D)
    animals.push_back(Dog("Rex"));
    animals.push_back(Cat("Kitty"));
    for (auto& a : animals)
        a.speak();                         // (E)
    return 0;
}
```

<details>
<summary>Đáp án — 4 lỗi</summary>

(A) `speak()` không có `virtual` → không thể override đúng  
(B)(C) `speak()` cần thêm `override` để compiler kiểm tra  
(D) `vector<Animal>` thay vì `vector<Animal*>` → **object slicing**: Dog/Cat bị cắt thành Animal  
(E) gọi `Animal::speak()` hết — không đúng lớp con  

**Sửa:** `vector<Animal*>`, push `new Dog(...)`, dùng `virtual`, thêm `virtual ~Animal()`.
</details>

---

## Checklist

- [ ] Bài 1: nhận diện cấu trúc từ đề bài trong < 5 phút
- [ ] Bài 2: viết skeleton không nhìn mẫu trong < 15 phút
- [ ] Bài 3: làm đúng đề 2019 HK2 câu 2
- [ ] Bài 4: làm đúng đề 2025 HK2 câu 2 (khó nhất)
- [ ] Bài 5: tìm đủ 4 lỗi

**Điểm hay quên nhất:**
- `virtual ~Animal() {}` trong base class
- `vector<Animal*>` chứ không phải `vector<Animal>`
- `override` keyword ở lớp con
