# Kế Hoạch Ôn Tập — OOP CSC10003
> Tạo: 2026-05-19 | Dựa trên phân tích 16 đề thi 2019–2026  
> Mục tiêu: Đạt ≥ 8/10 trong kỳ thi cuối kỳ (2 câu × 5đ, 90 phút, closed-book, 100% viết code C++)

---

## 🗓️ Tổng quan 5 buổi

| Buổi | Chủ đề | Ưu tiên | Thời gian |
|------|--------|---------|-----------|
| 1 | Class Design + Encapsulation | 🔴 Bắt buộc | ~2.5h |
| 2 | Operator Overloading | 🔴 Bắt buộc | ~2.5h |
| 3 | Big Three + Dynamic Memory | 🔴 Bắt buộc | ~3h |
| 4 | Inheritance + Polymorphism | 🔴 Bắt buộc | ~3h |
| 5 | Luyện đề thực tế | 🔴 Bắt buộc | ~4h |

**Tổng:** ~15 giờ. Nên trải đều 5–7 ngày trước thi, **không dồn 1 ngày**.

---

## 📌 Buổi 1 — Class Design + Encapsulation
> Nền tảng của mọi bài. Câu 1 từ 2019–2022 đều là dạng này.

### Mục tiêu cuối buổi
- [ ] Tự viết class C++ từ đầu không cần nhìn
- [ ] Biết dùng getter/setter, constructor có tham số + default
- [ ] Tổ chức class với mảng/vector thành viên (Composition)

### Tài liệu cần đọc (theo thứ tự)
1. `knowledge/slide_chapters/slide_02_intro_oop.md` — Lớp, đối tượng, tầm vực
2. `knowledge/slide_chapters/slide_03_object_life_cycle.md` — Constructor, Destructor, Static
3. `raw/source_code/Object-oriented-Programming-main/StarterOOP/Property_Constructor_Behaviour.cpp` — Code mẫu cơ bản

### Kiến thức cốt lõi cần nắm

```cpp
class SinhVien {
private:
    string _hoTen;
    float _diemTB;
public:
    // Constructor
    SinhVien() : _hoTen(""), _diemTB(0) {}
    SinhVien(string hoTen, float diemTB) : _hoTen(hoTen), _diemTB(diemTB) {}

    // Getter / Setter
    string getHoTen() const { return _hoTen; }
    float getDiemTB() const { return _diemTB; }
    void setHoTen(string hoTen) { _hoTen = hoTen; }
    void setDiemTB(float diemTB) { _diemTB = diemTB; }

    // Phương thức
    void nhap() { cin >> _hoTen >> _diemTB; }
    void xuat() const { cout << _hoTen << " - " << _diemTB << endl; }
};

class LopHoc {               // Composition: LopHoc HAS-A SinhVien
private:
    vector<SinhVien> _dsv;
public:
    void them(SinhVien sv) { _dsv.push_back(sv); }
    SinhVien timMax() { /* trả về sv có điểm cao nhất */ }
    void xuat() { for (auto& sv : _dsv) sv.xuat(); }
};
```

### Bài tập thực hành
1. **Dễ:** Viết class `HinhChuNhat` với chiều dài, chiều rộng; tính diện tích, chu vi.
2. **Trung bình:** Viết class `SinhVien` + class `LopHoc` có `vector<SinhVien>`. In ra SV có điểm TB cao nhất.
3. **Nâng cao:** Tham khảo đề 2019 HK2 trong `knowledge/de_thi_analysis/de_thi_transcript.md` → làm câu 1.

### Checklist hoàn thành
- [ ] Đọc xong slide 02 + 03
- [ ] Tự viết class không cần nhìn mẫu
- [ ] Làm bài tập 1 và 2
- [ ] Đọc và hiểu code `Property_Constructor_Behaviour.cpp`

---

## 📌 Buổi 2 — Operator Overloading
> Xuất hiện 4/6 đề gần nhất (2021–2026). Câu 1 dạng mới (2025–2026) bắt buộc có toán tử.

### Mục tiêu cuối buổi
- [ ] Viết đúng chữ ký (signature) cho các toán tử phổ biến
- [ ] Phân biệt member function vs friend function
- [ ] Viết được `operator[]`, `operator+`, `operator>`, `operator=`, `operator<<`

### Tài liệu cần đọc (theo thứ tự)
1. `knowledge/slide_chapters/slide_04_operators.md` — Lý thuyết operator overloading
2. `knowledge/slide_chapters/slide_04_operators_visual.md` — Xem ví dụ visual
3. `raw/source_code/MTH10407-HCMUS-master/PhanSo/PhanSo.h` — **Mẫu chuẩn nhất**

### Bảng chữ ký quan trọng

```cpp
// Toán tử số học — trả về object mới, không sửa *this
Fraction operator+(const Fraction& other) const;
Fraction operator-(const Fraction& other) const;

// Toán tử so sánh — trả về bool
bool operator>(const Fraction& other) const;
bool operator==(const Fraction& other) const;

// Toán tử gán kết hợp — trả về *this
Fraction& operator+=(const Fraction& other);

// Toán tử chỉ số — trả về phần tử
int& operator[](int index);          // dùng để gán: a[i] = 5
int operator[](int index) const;     // dùng để đọc: cout << a[i]

// Toán tử xuất — phải là friend
friend ostream& operator<<(ostream& os, const Fraction& f);

// Prefix / Postfix ++ 
Fraction& operator++();              // prefix: ++a
Fraction operator++(int);           // postfix: a++
```

### Bài tập thực hành
1. **Dễ:** Viết class `PhanSo` với `operator+`, `operator>`.
2. **Trung bình:** Thêm `operator<<` và `operator==`.
3. **Nâng cao:** Tham khảo đề 2024 HK2 trong `de_thi_transcript.md` → làm câu 1 (phân số với +, >, ==).

### Điểm hay sai

| Sai | Đúng |
|-----|------|
| `Fraction operator+(Fraction other)` | `Fraction operator+(const Fraction& other) const` |
| `operator<<` là member function | `operator<<` phải là `friend` |
| `operator[]` chỉ viết 1 phiên bản | Cần cả `const` lẫn non-const |
| `operator++()` trả về void | Prefix trả về `&`, postfix trả về copy |

### Checklist hoàn thành
- [ ] Đọc slide 04
- [ ] Đọc PhanSo.h và hiểu từng toán tử
- [ ] Tự viết class PhanSo với đủ toán tử không nhìn mẫu
- [ ] Làm bài tập 3 (đề thật 2024 HK2)

---

## 📌 Buổi 3 — Big Three + Dynamic Memory
> Dạng mới nhất, khó nhất — xuất hiện cả 2 đề 2025 và 2026. Đề cho main sẵn, yêu cầu cài class.

### Mục tiêu cuối buổi
- [ ] Biết khi nào cần Big Three (có `new`/`delete` bên trong class)
- [ ] Viết đúng copy constructor (deep copy), assignment operator, destructor
- [ ] Cài đặt được dạng `CMyArray` và `CMyString` theo main cho sẵn

### Tài liệu cần đọc (theo thứ tự)
1. `knowledge/slide_chapters/slide_05_big_three.md` — Rule of Three, shallow vs deep copy
2. `knowledge/slide_chapters/slide_05_big_three_visual.md` — Diagram bộ nhớ
3. `raw/source_code/Object-oriented-Programming-main/StarterOOP/DynamicArray.cpp` — Code mẫu đã sửa lỗi

### Template Big Three chuẩn

```cpp
class CMyArray {
private:
    int* _data;
    int _size;
public:
    // Constructor
    CMyArray() : _data(nullptr), _size(0) {}

    // Destructor ← Big Three #1
    ~CMyArray() {
        delete[] _data;
        _data = nullptr;
    }

    // Copy Constructor ← Big Three #2 (deep copy)
    CMyArray(const CMyArray& other) {
        _size = other._size;
        _data = new int[_size];
        for (int i = 0; i < _size; i++) _data[i] = other._data[i];
    }

    // Assignment Operator ← Big Three #3 (deep copy + self-check)
    CMyArray& operator=(const CMyArray& other) {
        if (this == &other) return *this;   // tự gán
        delete[] _data;                      // giải phóng cũ
        _size = other._size;
        _data = new int[_size];
        for (int i = 0; i < _size; i++) _data[i] = other._data[i];
        return *this;
    }

    // operator[]
    int& operator[](int index) { return _data[index]; }
    int operator[](int index) const { return _data[index]; }

    // Các phương thức khác
    void Add(int value) { /* mở rộng mảng và thêm */ }
    int Min() const { /* tìm min */ }
    int Size() const { return _size; }
};
```

### Bài tập thực hành
1. **Bắt buộc:** Tự viết `CMyArray` hoàn chỉnh theo main của đề 2025 HK2 (xem `de_thi_transcript.md`)
2. **Bắt buộc:** Tự viết `CMyString` theo main của đề 2026 HK1 (xem `de_thi_transcript.md`)
3. **Kiểm tra:** Viết `main()` test copy constructor: `CMyArray b = a;` rồi thay đổi `b[0]` → `a[0]` phải không đổi.

### Dấu hiệu nhận ra cần Big Three
```
Trong class có:        →    Phải có đủ:
delete[] trong dtor    →    copy ctor (deep copy)
                       →    operator= (deep copy)
```

### Checklist hoàn thành
- [ ] Đọc slide 05 (đặc biệt phần diagram bộ nhớ)
- [ ] Hiểu sự khác biệt shallow copy vs deep copy
- [ ] Viết xong CMyArray theo đề 2025 HK2
- [ ] Viết xong CMyString theo đề 2026 HK1

---

## 📌 Buổi 4 — Inheritance + Polymorphism
> Câu 2 bắt buộc 100% mọi đề. Nếu không làm được dạng này = mất 5/10 điểm.

### Mục tiêu cuối buổi
- [ ] Khai báo abstract class (pure virtual) đúng cú pháp
- [ ] Override phương thức trong lớp con
- [ ] Dùng `vector<BaseClass*>` gọi virtual function → đúng lớp con được gọi
- [ ] Nhớ `virtual ~BaseClass()` khi dùng base pointer

### Tài liệu cần đọc (theo thứ tự)
1. `knowledge/slide_chapters/slide_07_inheritance.md` — IS-A vs HAS-A
2. `knowledge/slide_chapters/slide_08_lifecycle_inheritance.md` — Constructor/Destructor trong kế thừa
3. `knowledge/slide_chapters/slide_09_interface_polymorphism.md` — Virtual, pure virtual, abstract
4. `raw/source_code/OOPCPlusPlus-master/Examples/QuanLyCanBoTrongTruongDaiHoc/` — Code mẫu tốt nhất

### Template Câu 2 chuẩn

```cpp
// Base class abstract
class SinhVien {
protected:
    string _hoTen;
    float _diemTB;
public:
    SinhVien(string hoTen, float diemTB) : _hoTen(hoTen), _diemTB(diemTB) {}
    virtual ~SinhVien() {}                    // ← KHÔNG được quên!
    virtual float tinhHocBong() = 0;          // pure virtual
    virtual void xuat() const {
        cout << _hoTen << " - " << _diemTB;
    }
};

// Lớp con
class SVCongLap : public SinhVien {
public:
    SVCongLap(string hoTen, float diemTB) : SinhVien(hoTen, diemTB) {}
    float tinhHocBong() override {            // ← từ khóa override giúp bắt lỗi
        if (_diemTB >= 8.0) return 3000000;
        return 0;
    }
};

class SVDanLap : public SinhVien {
public:
    SVDanLap(string hoTen, float diemTB) : SinhVien(hoTen, diemTB) {}
    float tinhHocBong() override {
        if (_diemTB >= 9.0) return 1500000;
        return 0;
    }
};

// Container
class LopHoc {
    vector<SinhVien*> _ds;                    // ← base pointer
public:
    ~LopHoc() { for (auto p : _ds) delete p; }
    void them(SinhVien* sv) { _ds.push_back(sv); }
    void xuatTatCa() {
        for (auto p : _ds) {
            p->xuat();                         // ← virtual dispatch
            cout << " | Học bổng: " << p->tinhHocBong() << endl;
        }
    }
};
```

### Bài tập thực hành
1. **Bắt buộc:** Làm câu 2 đề 2019 HK2 (sinh viên 3 hệ, học bổng khác nhau)
2. **Bắt buộc:** Làm câu 2 đề 2024 HK2 (hình học: tròn, chữ nhật)
3. **Bắt buộc:** Làm câu 2 đề 2025 HK2 (thiết bị: Monitor, Projector, SmartTV)

### 3 lỗi phổ biến nhất (dễ mất điểm)

| Lỗi | Hậu quả |
|-----|---------|
| Quên `virtual` ở base class | Static dispatch → sai lớp được gọi |
| Quên `virtual ~Base()` | Memory leak, undefined behavior |
| Dùng `if/else` kiểm tra type thay polymorphism | Không đạt yêu cầu "bắt buộc dùng đa hình" |

### Checklist hoàn thành
- [ ] Đọc slide 07, 08, 09
- [ ] Tự viết template abstract class + 2 lớp con không nhìn mẫu
- [ ] Làm đủ 3 bài tập, chạy thử trong đầu
- [ ] Kiểm tra: mọi base class dùng với pointer đều có `virtual destructor`

---

## 📌 Buổi 5 — Luyện Đề Thực Tế
> Mô phỏng điều kiện thi thật: **90 phút, không nhìn tài liệu**.

### Kế hoạch luyện đề

#### Vòng 1 — Đề cũ (làm quen dạng đề)
Làm theo thứ tự tăng dần độ khó, không áp thời gian. Đọc đề → nghĩ → viết code.

| Đề | Câu 1 | Câu 2 | Ghi chú |
|----|-------|-------|---------|
| 2019 HK2 | Danh sách HS | 3 hệ đào tạo | Dễ nhất, warmup |
| 2022 HK1 | Tam giác hợp lệ | 2 hệ SV, học bổng | Pattern cơ bản |
| 2023 HK2 | Đa giác, chu vi | SV + sort theo TB | Có sort |
| 2024 HK2 | **Phân số** (+, >, ==) | Hình học + điểm thuộc | Operator |
| 2025 HK1 | SinhVien + LopHoc | Hình cơ bản (tròn/vuông/chữ nhật) | Gần style mới |

Nguồn: `knowledge/de_thi_analysis/de_thi_transcript.md`

#### Vòng 2 — Đề mới nhất (ưu tiên cao nhất)
Đây là 2 đề khó nhất, dạng mới nhất, khả năng cao sẽ ra tương tự:

```
Đề 2025 HK2 — Câu 1: CMyArray
    int main() {
        CMyArray a;
        a.Add(5); a.Add(3); a.Add(8);
        cout << a.Min();     // → 3
        cout << a[1];        // → 3
        CMyArray b = a;      // copy constructor
        b[0] = 99;
        cout << a[0];        // → 5 (không đổi vì deep copy)
    }

Đề 2026 HK1 — Câu 1: CMyString
    int main() {
        CMyString s1("Hello");
        CMyString s2(" World");
        CMyString s3 = s1 + s2;   // operator+
        s1.Append("!");
        cout << s3.Find("World"); // → 6
        cout << s3[0];            // → 'H'
    }
```

#### Vòng 3 — Thi thử (đúng điều kiện)
- Đặt đồng hồ 90 phút
- Chọn 1 đề chưa làm trong `de_thi_transcript.md`
- Không xem bất kỳ tài liệu nào
- Sau đó tự chấm: câu nào không làm được → ghi vào `notes/weak_points.md`

### Tiêu chí tự đánh giá

| Điểm | Nghĩa là |
|------|----------|
| Câu 1 xong < 35 phút | Tốt — còn đủ thời gian cho câu 2 |
| Câu 2 có virtual đúng chỗ | Sẽ lấy được phần lớn điểm |
| Code không có syntax error trong đầu | Sẵn sàng đi thi |
| Câu 1 > 45 phút | Cần luyện thêm buổi 2–3 |

### Checklist hoàn thành
- [ ] Làm xong ít nhất 3 đề vòng 1
- [ ] Tự viết được CMyArray và CMyString hoàn chỉnh không nhìn mẫu
- [ ] Hoàn thành ít nhất 1 lần thi thử 90 phút
- [ ] Ghi lại điểm yếu vào `notes/weak_points.md`

---

## 📋 Tổng Checklist Toàn Khoá

### Kiến thức (phải biết trước ngày thi)
- [ ] Class design: constructor, getter/setter, Composition
- [ ] Operator: `+`, `>`, `==`, `[]`, `=`, `<<`, `++` prefix/postfix
- [ ] Big Three: copy ctor deep copy, op= deep copy, destructor delete[]
- [ ] Khi nào cần Big Three (dấu hiệu: có dynamic memory trong class)
- [ ] Abstract class + pure virtual + virtual destructor
- [ ] Override virtual function trong lớp con
- [ ] Dùng `vector<Base*>` → gọi virtual → đúng lớp con

### Kỹ năng (phải làm được trong 90 phút)
- [ ] Đọc `main()` cho sẵn → xác định interface class cần viết
- [ ] Viết class đầy đủ từ đầu trong ~35 phút (câu 1)
- [ ] Viết abstract class + 2–3 lớp con + container trong ~45 phút (câu 2)
- [ ] Không quên `virtual ~Base()`, không dùng `if/else` thay polymorphism

---

## 🗒️ Ghi Chú Sử Dụng Plan

- Sau mỗi buổi: Append vào `notes/session_log.md`
- Phát hiện điểm yếu: Ghi vào `notes/weak_points.md`
- Muốn flashcard: Nói "flashcard [chủ đề]" → tạo vào `study/flashcards/`
- Muốn đề thử: Nói "tạo đề thi" → tạo vào `study/mock_exams/`
- Muốn ôn sâu 1 chủ đề: Nói "ôn chương [X]"
