# Flashcard — Class Design & Encapsulation
> Chủ đề: Buổi 1 | Tần suất thi: 100% (câu 1 mọi năm 2019–2024)

---

## Q1: Class là gì? Object là gì?
**A:** Class là bản thiết kế (blueprint). Object là thực thể được tạo ra từ bản thiết kế đó.  
Ví dụ: `SinhVien` là class. `SinhVien sv("Dao", 8.5)` là object.

---

## Q2: Viết constructor đúng chuẩn cho class `SinhVien`
**A:**
```cpp
class SinhVien {
private:
    string _hoTen;
    float  _diemTB;
public:
    SinhVien() : _hoTen(""), _diemTB(0) {}                        // default
    SinhVien(string hoTen, float diemTB)
        : _hoTen(hoTen), _diemTB(diemTB) {}                       // parameterized
};
```
> Dùng initializer list (`:`) thay gán trong thân — nhanh hơn, chuẩn hơn.

---

## Q3: Getter và Setter viết thế nào? Tại sao cần?
**A:**
```cpp
string getHoTen() const { return _hoTen; }          // getter: const, trả về value
void   setHoTen(string ht) { _hoTen = ht; }         // setter: validate nếu cần
float  getDiemTB() const { return _diemTB; }
void   setDiemTB(float d) {
    if (d >= 0 && d <= 10) _diemTB = d;             // setter có validation
}
```
> Tại sao: data `private` → bảo vệ khỏi gán giá trị sai; getter/setter kiểm soát truy cập.

---

## Q4: `const` ở cuối method có nghĩa gì?
**A:** Method không thay đổi bất kỳ thuộc tính nào của object.
```cpp
float getDiemTB() const { return _diemTB; }   // ✅ đọc, không ghi
void  setDiemTB(float d) { _diemTB = d; }     // không const — thay đổi object
```
> Nếu gọi method trên `const SinhVien&` → method phải có `const`, nếu không → compile error.

---

## Q5: IS-A vs HAS-A là gì? Cho ví dụ.
**A:**  
- **IS-A** = Inheritance: `SinhVienCQ IS-A SinhVien`
- **HAS-A** = Composition: `LopHoc HAS-A vector<SinhVien>` (chứa, không kế thừa)

```cpp
// IS-A
class SinhVienCQ : public SinhVien { ... };

// HAS-A
class LopHoc {
    vector<SinhVien> _dsv;   // LopHoc chứa SinhVien
};
```
> Quy tắc: khi muốn "dùng lại" nhưng không phải "là một loại của" → dùng Composition.

---

## Q6: Destructor là gì? Khi nào gọi tự động?
**A:** Destructor được gọi tự động khi object bị hủy (ra khỏi scope hoặc `delete`).
```cpp
~SinhVien() {
    // giải phóng tài nguyên nếu có (dynamic memory, file handle...)
    // class này không có dynamic memory → body rỗng hoặc không cần viết
}
```
> Nếu class có `new` bên trong → PHẢI viết destructor với `delete`.

---

## Q7: Static member là gì? Dùng khi nào?
**A:** Static member thuộc về class, không thuộc về object cụ thể.
```cpp
class SinhVien {
    static int _soLuong;               // dùng chung cho mọi object
public:
    SinhVien() { _soLuong++; }
    ~SinhVien() { _soLuong--; }
    static int getSoLuong() { return _soLuong; }
};
int SinhVien::_soLuong = 0;           // khởi tạo ngoài class

// Gọi:
SinhVien::getSoLuong();               // gọi qua tên class, không cần object
```

---

## Q8: Viết class `LopHoc` có chứa danh sách SinhVien
**A:**
```cpp
class LopHoc {
private:
    vector<SinhVien> _dsv;
    string _tenLop;
public:
    LopHoc(string tenLop) : _tenLop(tenLop) {}

    void them(SinhVien sv) { _dsv.push_back(sv); }

    SinhVien timMax() const {
        SinhVien kq = _dsv[0];
        for (const auto& sv : _dsv)
            if (sv.getDiemTB() > kq.getDiemTB())
                kq = sv;
        return kq;
    }

    void xuatTatCa() const {
        for (const auto& sv : _dsv) sv.xuat();
    }
};
```

---

## Q9: Sự khác biệt giữa `private`, `protected`, `public`?
**A:**
| | Class mình | Lớp con | Bên ngoài |
|---|---|---|---|
| `private` | ✅ | ❌ | ❌ |
| `protected` | ✅ | ✅ | ❌ |
| `public` | ✅ | ✅ | ✅ |

> Mặc định trong `class` là `private`. Mặc định trong `struct` là `public`.

---

## Q10: Khi nào dùng `struct`, khi nào dùng `class`?
**A:** Về kỹ thuật giống nhau. Quy ước:
- `struct` → dữ liệu đơn giản, không có behavior, mọi thứ `public` (ví dụ: `Point`, `Date`)
- `class` → có logic, behavior, encapsulation

---

## Bảng tóm tắt — Dấu hiệu đề thi câu 1 dạng Class Design

| Đề nói | Cần viết |
|--------|----------|
| "Tạo lớp X với các thuộc tính..." | class X, constructor, getter/setter |
| "Tính tổng/tìm max/lọc..." | method trong container class (LopHoc, DanhSach...) |
| "Nhập vào danh sách..." | `vector<X>`, vòng lặp nhập |
| "In ra..." | method `xuat() const` |
