# Code Review — raw/source_code
> Cập nhật: 2026-05-19  
> Mục tiêu: Đánh giá tính đúng đắn C++/OOP và mức độ hữu ích cho ôn thi CSC10003  
> Trạng thái: **Đã sửa tất cả 6 lỗi trực tiếp vào file gốc** (xem tag `[FIX]` trong source code)

---

## 📦 Tổng quan 4 thư mục

| Thư mục | Nguồn gốc | Chủ đề chính | Đánh giá tổng |
|---------|-----------|-------------|---------------|
| `Object-oriented-Programming-main` | GitHub cá nhân | Fraction, Shape, DynamicArray, StarterOOP | ⭐⭐⭐ Tốt, có vài lỗi cần học hỏi |
| `OOPCPlusPlus-master` | Tài liệu giảng dạy | HinhHoc, QuanLyCanBo, QuanLyHocSinh | ⭐⭐⭐⭐ Tốt nhất — gần sát đề thi |
| `MTH10407-HCMUS-master` | HCMUS Lab/Exam | PhanSo, Polymorphism, Final 2022 | ⭐⭐⭐⭐ Rất tốt, có lỗi nhỏ cần nhận biết |
| `HCMUS-OOP-PROJECTS-main` | Project môn học | MockData, EmployeeSalary (Factory) | ⭐⭐⭐ Tốt — kiến trúc phức tạp, ít liên quan đề thi |

---

## 📁 1. Object-oriented-Programming-main

### 1.1 `StarterOOP/DynamicArray.cpp` ✅ ĐÃ SỬA (lỗi Rule of Three)

**Chủ đề:** Template class, dynamic memory, operator[]

**Code tốt:**
```cpp
template <class T>
class DynamicArray {
    T* _a = NULL;
    int _maxSize, _currentSize;
public:
    DynamicArray() { _a = new T[5]; _maxSize = 5; _currentSize = 0; }
    void push_back(T value) { /* mở rộng mảng đúng */ }
    T operator[](int index) { return getAt(index); }
    ~DynamicArray() { if (_a != NULL) delete[] _a; }
};
```

**🔴 LỖI GỐC — Vi phạm Rule of Three** `(dòng 49–51 file gốc)`:
```
✗ Có destructor (delete[] _a)
✗ KHÔNG có Copy Constructor    ← thiếu dòng 49
✗ KHÔNG có Assignment Operator ← thiếu dòng 49
→ Nếu copy: DynamicArray<int> b = a;
  cả hai trỏ cùng 1 vùng nhớ → double-free khi destructor gọi!
```

**✅ ĐÃ SỬA** — Thêm ngay sau dòng `size()`, trước `~DynamicArray()`:
```cpp
// [FIX] Copy constructor (deep copy)
DynamicArray(const DynamicArray& other) {
    _maxSize = other._maxSize;
    _currentSize = other._currentSize;
    _a = new T[_maxSize];
    for (int i = 0; i < _currentSize; i++) _a[i] = other._a[i];
}

// [FIX] Assignment operator (deep copy + self-check)
DynamicArray& operator=(const DynamicArray& other) {
    if (this == &other) return *this;
    delete[] _a;
    _maxSize = other._maxSize;
    _currentSize = other._currentSize;
    _a = new T[_maxSize];
    for (int i = 0; i < _currentSize; i++) _a[i] = other._a[i];
    return *this;
}
```

**Bài học:** Đây chính xác là dạng đề 2025 HK2 (CMyArray) và 2026 HK1 (CMyString) kiểm tra.

---

### 1.2 `StarterOOP/Property_Constructor_Behaviour.cpp` ✅ ĐÚNG

**Chủ đề:** Encapsulation, getter/setter, constructor, Composition (Line có Point)

**Đánh giá:** Code cơ bản, đúng hoàn toàn. Là ví dụ tốt về Tầng 1 OOP:
- `Soldier`, `Fraction`, `Point` — encapsulation rõ ràng
- `Line` — composition, chứa 2 đối tượng `Point`
- Constructor đầy đủ (default + parameterized)

**✅ Hữu ích:** Ôn tập Tầng 1 — class design cơ bản.

---

### 1.3 `ReadFileAndCalculateAreaAndPerimeter/Source.cpp` ✅ ĐÃ SỬA (4 lỗi)

**Chủ đề:** Shape hierarchy (Rectangle, Circle, Triangle), File I/O

**Code tốt:** Polymorphism bằng `vector<Shape*>`, đọc file, delete đúng.

**🔴 LỖI 1 — Thiếu virtual destructor** `(dòng 19–28 file gốc)`:
```cpp
class Shape {
public:
    virtual string printAllInformation() { ... }
    // ← THIẾU: virtual ~Shape() {}
    // Khi delete shapes[i] → chỉ gọi ~Shape(), bỏ qua ~Rectangle()... → memory leak
};
```
**✅ ĐÃ SỬA** — Thêm `virtual ~Shape() {}` vào class Shape.

**🟡 VẤN ĐỀ 2 — Shape không phải abstract class** `(dòng 21)`:
```cpp
virtual string printAllInformation() { return "Shape:\n"; } // có body → có thể tạo Shape()
```
**✅ ĐÃ SỬA** — Đổi thành `virtual string printAllInformation() = 0;` (pure virtual).

**🟡 VẤN ĐỀ 3 — Dùng `3.14`** `(dòng 87–91)`:
```cpp
float ans = 2 * 3.14 * _radius; // kém chính xác
```
**✅ ĐÃ SỬA** — Đổi thành `M_PI` (từ `<cmath>`).

**🟡 VẤN ĐỀ 4 — `while (!file.eof())`** `(dòng 172)`:
```cpp
while (!file.eof()) { getline(file, line); ... } // đọc dư 1 vòng khi EOF
```
**✅ ĐÃ SỬA** — Đổi thành `while (getline(file, line)) { ... }`.

**Bài học:** Nhớ thêm `virtual ~Shape() {}` bất cứ khi nào dùng con trỏ base class.

---

### 1.4 `FractionHandling/Source.cpp` ✅ ĐÚNG (với lưu ý)

**Chủ đề:** Fraction class, GCD algorithm, File I/O, separation of concerns

**Code tốt:**
- GCD đệ quy chuẩn (Euclidean)
- Tách biệt rõ: `Fraction` (data), `FractionDataReader` (I/O), `FractionToLowestTermUIConverter` (display)
- Dùng `regex` validate input

**🟡 Lưu ý — không dùng operator overloading:**
```cpp
// Dùng static method thay vì operator+
static Fraction addTwoFractions(const Fraction& a, const Fraction& b);
// Đúng kiểu đề thi hơn là:
Fraction operator+(const Fraction& other) const;
```

**✅ Hữu ích:** Học cách tổ chức code nhiều lớp, file I/O pattern.

---

### 1.5 `StarterOOP/FractionDisplay.cpp` ✅ ĐÃ SỬA (bug num % den)

**Chủ đề:** Multiple UI Converter classes, Single Responsibility Principle

**Đánh giá:** Thiết kế rất tốt — mỗi class chỉ làm 1 việc:
- `FractionToLowestTermUIConverter`
- `FractionToDecimalUIConverter`
- `FractionToPercentageUIConverter`
- `FractionToStringUIConverter`

**🔴 BUG trong FractionToLowestTermUIConverter** `(dòng 93, class FractionToLowestTermUIConverter)`:
```cpp
if (num > den) {
    long long fullNum = num / den;
    ss << fullNum << " ";
    num = num / den;  // ← BUG: phải là num % den
    // Ví dụ: 7/3 → fullNum=2, num lẽ ra phải là 7%3=1 → in "2 1/3"
    //         nhưng thực tế: num = 7/3 = 2 → in "2 2/3" (sai!)
}
```
**✅ ĐÃ SỬA** — Đổi `num = num / den` thành `num = num % den`.

---

## 📁 2. OOPCPlusPlus-master ⭐ Gần sát đề thi nhất

### 2.1 `Examples/HinhHoc/` ✅ ĐÃ SỬA main.cpp (thêm polymorphism)

**Chủ đề:** Abstract base class, Inheritance, Polymorphism

```cpp
class HinhHoc {
protected:
    float _chieuDai, _chieuRong;
public:
    virtual bool kiemTra() = 0;    // pure virtual ✓
    virtual float chuVi() = 0;     // pure virtual ✓
    virtual float dienTich() = 0;  // pure virtual ✓
    virtual void toString() = 0;   // pure virtual ✓
};
class HinhChuNhat : public HinhHoc { ... };
class HinhVuong : public HinhHoc { ... };
```

**🟡 Hạn chế gốc trong main.cpp** `(dòng 7–11)`:
```cpp
HinhVuong hinhVuong = HinhVuong(5.0, 5.0); // object theo giá trị → KHÔNG có polymorphism
hinhVuong.toString();
```

**✅ ĐÃ SỬA** — Đổi main.cpp sang dùng `vector<HinhHoc*>` + base pointer:
```cpp
vector<HinhHoc*> danhSach;
danhSach.push_back(new HinhVuong(5.0, 5.0));
danhSach.push_back(new HinhChuNhat(4.0, 3.0));
for (int i = 0; i < danhSach.size(); i++) {
    if (danhSach[i]->kiemTra())
        danhSach[i]->toString(); // ← virtual dispatch đúng cách
}
// Giải phóng bộ nhớ
for (int i = 0; i < danhSach.size(); i++) delete danhSach[i];
```

**✅ Hữu ích:** Abstract class pattern rất sát Câu 2 đề thi (hình học 2024 HK2, 2025 HK1).

---

### 2.2 `Examples/QuanLyCanBoTrongTruongDaiHoc/` ✅ ĐÚNG

**Chủ đề:** Abstract class với business logic, file output, menu-driven program

```cpp
class CanBo {
protected:
    string hoTen;
    unsigned int phuCap;
    unsigned short heSoLuong;
public:
    virtual unsigned int tinhLuong() = 0;  // pure virtual ✓
    virtual unsigned char getID() = 0;     // pure virtual ✓
    virtual void nhap();
    virtual void xuat(ostream &os);
};
class GiangVien : public CanBo { ... };
class NhanVienHanhChinh : public CanBo { ... };
```

**Đánh giá:** Pattern này **rất giống Câu 2 đề thi** (quản lý nhân viên/sinh viên các hệ khác nhau).

**🟡 Lưu ý:** Dùng `system("cls")` và `system("pause")` — không portable, không nên dùng trong thi.

**✅ Hữu ích cao:** Template chuẩn cho bài Inheritance + Polymorphism.

---

### 2.3 `Examples/QuanLyHocSinh/` ✅ ĐÚNG

**Chủ đề:** HocSinh class, QuanLyHocSinh (container), I/O

**Đánh giá:** Class design đơn giản, đúng encapsulation. Phù hợp ôn tập Tầng 1-2.

---

## 📁 3. MTH10407-HCMUS-master ⭐ Rất hữu ích

### 3.1 `PhanSo/PhanSo.h` ✅ ĐÚNG — Mẫu operator overloading tốt nhất

**Chủ đề:** Operator overloading toàn diện

```cpp
class PhanSo {
public:
    PhanSo(int, int);
    PhanSo& operator+=(const PhanSo&);         // ✓ assignment-style
    const PhanSo operator+(const PhanSo&) const; // ✓ trả về const object mới
    bool operator==(const PhanSo&) const;        // ✓ const method
    PhanSo& operator++();    // ✓ Prefix: trả về *this
    PhanSo operator++(int);  // ✓ Postfix: trả về bản sao cũ
    operator int() const;    // ✓ Implicit conversion
    friend ostream& operator<<(ostream &out, const PhanSo& src); // ✓ friend
};
```

**Đây là mẫu operator overloading CHUẨN NHẤT trong bộ code.** Đặc biệt:
- Phân biệt prefix vs postfix `++`
- `const` correctness đúng chỗ
- `friend` cho `operator<<`

**✅ Hữu ích rất cao:** Ôn Operator Overloading (xuất hiện 4/6 đề gần nhất).

---

### 3.2 `Final Exam/final2022.cpp` ✅ ĐÃ SỬA (Stack UB + Shape virtual destructor)

**Chủ đề:** 3 câu bài tập tổng hợp — Point ops, Stack, Shape polymorphism

**Phần Point (Câu 1) — ✅ Tốt:**
```cpp
friend Point operator+(const Point&, const Point&);  // ✓
Point& operator+=(Point& point);                      // ✓ trả về *this
friend double operator*(const Point&, const Point&);  // ✓ dot product
```

**Phần Stack (Câu 2) — 🔴 LỖI GỐC** `(dòng 112–123)`:
```cpp
int pop() {
    if (!isEmpty()) { ... return top; }
    // ← KHÔNG có return khi isEmpty → undefined behavior!
}
int top() {
    if (!isEmpty()) return data.back();
    // ← KHÔNG có return khi isEmpty → undefined behavior!
}
```
**✅ ĐÃ SỬA** — Thêm `throw runtime_error("Stack is empty")` vào cả 2 hàm.

**Phần Shape (Câu 3) — Thiếu virtual destructor** `(dòng 173–177)`:
```cpp
class Shape {
public:
    Shape() {};
    virtual bool isSymmetry() = 0;
    // ← THIẾU: virtual ~Shape() {}
    // Khi dùng Shape* shapes[] và delete shapes[i] → memory leak
};
```
**✅ ĐÃ SỬA** — Thêm `virtual ~Shape() {}` vào class Shape.

**✅ Hữu ích:** Ví dụ thực tế đề thi 2022, pattern Circle kế thừa từ Ellipse.

---

### 3.3 `Chapter 4 - Polymorphism/polymorphism.cpp` ✅ ĐÚNG

**Chủ đề:** Basic virtual function, inheritance chain (Base→Derived→MoreDerived)

**Đánh giá:** Code tối giản, đúng. Dùng làm ví dụ runtime dispatch cơ bản.

---

### 3.4 `Chapter 3/operator_overloading.cpp` — (Không đọc được trong batch này)

---

## 📁 4. HCMUS-OOP-PROJECTS-main

### 4.1 `Project 2 - EmployeeSalary/` ✅ ĐÃ SỬA IEmployee.h (virtual destructor)

**Chủ đề:** Factory Pattern, Abstract class, nhiều lớp con, file I/O

```cpp
class IEmployee {
public:
    virtual double calculateSalary() = 0;                         // pure virtual ✓
    virtual IEmployee* generate(Fullname, double, double, double) = 0; // Factory method ✓
    virtual string className() = 0;
    // 🔴 THIẾU: virtual ~IEmployee() {}  → memory leak!
};
class DailyEmployee : public IEmployee { ... };   // lương theo ngày
class HourlyEmployee : public IEmployee { ... };  // lương theo giờ  
class Manager : public IEmployee { ... };          // lương quản lý
class ProductEmployee : public IEmployee { ... };  // lương theo sản phẩm
class EmployeeFactory { ... };                     // Factory pattern ✓
```

**🔴 LỖI GỐC — Thiếu virtual destructor** `(IEmployee.h dòng 4–10)`:
```cpp
class IEmployee {
public:
    virtual double calculateSalary() = 0;
    // ← THIẾU: virtual ~IEmployee() {}
    // delete emp; → ~IEmployee() gọi, ~DailyEmployee() KHÔNG gọi → memory leak
};
```
**✅ ĐÃ SỬA** — Thêm `virtual ~IEmployee() {}` vào `IEmployee.h`.

**🟡 Kiến trúc:** Rất tốt (Factory Pattern, Abstract Interface) nhưng phức tạp hơn mức đề thi yêu cầu.

**✅ Hữu ích:** Học Factory Pattern (slide 10) và mô hình abstract class tốt.

---

### 4.2 `Project 1 - MockStudentDataGenerator/` — Ít liên quan đề thi

**Chủ đề:** Sinh dữ liệu giả (tên, địa chỉ, email, điện thoại...)

**Đánh giá:** Code đúng, thiết kế tốt nhưng **không liên quan đến các chủ đề thi** (không có inheritance, polymorphism, operator overloading).

---

## 🎯 TỔNG KẾT: XẾP LOẠI THEO ƯU TIÊN ÔN THI

### ⭐⭐⭐⭐⭐ Học ngay — Trực tiếp sát đề thi

| File | Lý do |
|------|-------|
| `MTH10407/PhanSo/PhanSo.h` | Mẫu operator overloading chuẩn nhất |
| `OOPCPlusPlus/Examples/HinhHoc/` | Abstract class + pure virtual — đúng pattern câu 2 |
| `OOPCPlusPlus/Examples/QuanLyCanBoTrongTruongDaiHoc/` | Inheritance + Polymorphism — clone pattern câu 2 |

### ⭐⭐⭐⭐ Hữu ích cao — Học sau

| File | Lý do |
|------|-------|
| `MTH10407/Final Exam/final2022.cpp` | Giải đề thực tế, operator + polymorphism |
| `Object-oriented/ReadFileAndCalculateAreaAndPerimeter/Source.cpp` | Shape hierarchy, cần nhận ra lỗi thiếu virtual destructor |
| `Object-oriented/StarterOOP/DynamicArray.cpp` | Template + operator[] — cần nhận ra lỗi Rule of Three |

### ⭐⭐⭐ Tham khảo — Ôn nền tảng

| File | Lý do |
|------|-------|
| `Object-oriented/StarterOOP/Property_Constructor_Behaviour.cpp` | Tầng 1 cơ bản, encapsulation |
| `Object-oriented/StarterOOP/FractionDisplay.cpp` | Separation of concerns, UI converter pattern |
| `HCMUS-OOP-PROJECTS/Project 2 - EmployeeSalary/` | Factory Pattern, cấu trúc project thực tế |

### ❌ Bỏ qua — Không liên quan đề thi

| File | Lý do |
|------|-------|
| `HCMUS-OOP-PROJECTS/Project 1 - MockStudentDataGenerator/` | Không có inheritance/polymorphism |
| `MTH10407/Python/` | Python — sai ngôn ngữ |
| `MTH10407/Design Patterns/Iterator/main.py` | Python |
| `HCMUS-OOP-PROJECTS/Slides and Records/` | Slides thêm, không phải code |

---

## 🔴 BẢNG LỖI & TRẠNG THÁI SỬA

| # | Lỗi | File (dòng) | Hậu quả | Trạng thái |
|---|-----|------------|---------|-----------|
| 1 | **Vi phạm Rule of Three** — thiếu copy ctor + op= | `DynamicArray.cpp` (sau dòng 46) | Double-free → crash khi copy | ✅ ĐÃ SỬA |
| 2 | **Thiếu virtual destructor** | `ReadFileAndCalculateAreaAndPerimeter/Source.cpp` (dòng 19) | Memory leak khi `delete` qua base pointer | ✅ ĐÃ SỬA |
| 3 | **Shape có body → không phải abstract** | `ReadFileAndCalculateAreaAndPerimeter/Source.cpp` (dòng 21) | Có thể tạo `Shape()` trực tiếp | ✅ ĐÃ SỬA |
| 4 | **Dùng 3.14 thay M_PI** | `ReadFileAndCalculateAreaAndPerimeter/Source.cpp` (dòng 87) | Kết quả kém chính xác | ✅ ĐÃ SỬA |
| 5 | **`while (!file.eof())`** antipattern | `ReadFileAndCalculateAreaAndPerimeter/Source.cpp` (dòng 172) | Đọc dư 1 vòng cuối file | ✅ ĐÃ SỬA |
| 6 | **Thiếu virtual destructor** | `IEmployee.h` (dòng 4) | Memory leak với `IEmployee*` | ✅ ĐÃ SỬA |
| 7 | **Stack::pop() không return khi rỗng** | `final2022.cpp` (dòng 112) | Undefined behavior | ✅ ĐÃ SỬA |
| 8 | **Stack::top() không return khi rỗng** | `final2022.cpp` (dòng 120) | Undefined behavior | ✅ ĐÃ SỬA |
| 9 | **Thiếu virtual destructor trong Shape** | `final2022.cpp` (dòng 173) | Memory leak với `Shape*` array | ✅ ĐÃ SỬA |
| 10 | **`num = num / den`** thay vì `% den` | `FractionDisplay.cpp` (dòng 93) | Hiển thị sai phân số hỗn số | ✅ ĐÃ SỬA |
| 11 | **main.cpp không dùng polymorphism** | `HinhHoc/main.cpp` (dòng 7–11) | Không demo dynamic dispatch | ✅ ĐÃ SỬA |

---

## 💡 GỢI Ý SỬ DỤNG CHO ÔN TẬP

1. **Học PhanSo.h** → nắm vững ký hiệu operator overloading chuẩn C++
2. **Học HinhHoc/ + QuanLyCanBo/** → template câu 2 đề thi (abstract class pattern)
3. **Phân tích lỗi DynamicArray** → hiểu sâu Rule of Three (đề 2025, 2026)
4. **Phân tích lỗi thiếu virtual destructor** → điểm dễ mất trong bài thi
5. **Không dùng code từ Project 1 MockData** — không liên quan đề thi
