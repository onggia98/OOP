# Kế Hoạch Ôn Tập 7 Ngày — OOP CSC10003
> Tạo: 2026-05-20 | Bắt đầu: 20/05 (T4) → Kết thúc: 26/05 (T3)  
> Mục tiêu: ≥ 8/10 — 2 câu × 5đ, 90 phút, closed-book, 100% viết code C++  
> Dựa trên phân tích 16 đề thi 2019–2026

---

## Tổng quan 7 ngày

| Ngày | Thứ | Chủ đề | Thời gian |
|------|-----|--------|-----------|
| 1 | T4 20/05 | Class Design + Encapsulation | ~2.5h |
| 2 | T5 21/05 | Operator Overloading — lý thuyết + signatures | ~2h |
| 3 | T6 22/05 | Operator Overloading — bài tập + đề thật | ~2h |
| 4 | T7 23/05 | Big Three + Dynamic Memory | ~3h |
| 5 | CN 24/05 | Inheritance + Polymorphism | ~3h |
| 6 | T2 25/05 | Luyện đề tổng hợp — không áp thời gian | ~3h |
| 7 | T3 26/05 | Thi thử 90 phút + review điểm yếu | ~3h |

**Tổng: ~18.5 giờ.** Trung bình 2.5h/ngày.

---

## Ngày 1 — T4 20/05 | Class Design + Encapsulation
> Câu 1 dạng này xuất hiện 100% đề thi. Nền tảng của mọi buổi còn lại.

### Lịch học
| Thời gian | Việc làm |
|-----------|----------|
| 30 phút | Đọc `knowledge/slide_chapters/slide_02_intro_oop.md` |
| 30 phút | Đọc `knowledge/slide_chapters/slide_03_object_life_cycle.md` |
| 20 phút | Đọc code mẫu `raw/source_code/.../Property_Constructor_Behaviour.cpp` |
| 40 phút | Viết class `SinhVien` + `LopHoc` từ đầu — không nhìn mẫu |
| 30 phút | Làm bài tập câu 1 đề 2019 HK2 (từ `de_thi_transcript.md`) |

### Mục tiêu tối thiểu cuối ngày
- [ ] Tự viết class C++ hoàn chỉnh với constructor, getter/setter, method
- [ ] Biết dùng `Composition` (class chứa `vector<OtherClass>`)
- [ ] Phân biệt `constructor` và `destructor` — khi nào gọi cái nào

### Code cần tự viết được (không nhìn mẫu)
```cpp
class SinhVien {
private:
    string _hoTen;
    float _diemTB;
public:
    SinhVien();
    SinhVien(string hoTen, float diemTB);
    string getHoTen() const;
    float getDiemTB() const;
    void nhap();
    void xuat() const;
};

class LopHoc {
private:
    vector<SinhVien> _dsv;
public:
    void them(SinhVien sv);
    SinhVien timMax() const;  // tìm SV điểm TB cao nhất
    void xuatTatCa() const;
};
```

### Dấu hiệu vượt qua ngày 1
✅ Viết class `HinhChuNhat` với chiều dài, chiều rộng, tính diện tích + chu vi trong < 10 phút

---

## Ngày 2 — T5 21/05 | Operator Overloading — Lý thuyết + Signatures
> Xuất hiện 4/6 đề gần nhất. Bắt buộc với câu 1 từ 2021 trở đi.

### Lịch học
| Thời gian | Việc làm |
|-----------|----------|
| 40 phút | Đọc `knowledge/slide_chapters/slide_04_operators.md` |
| 10 phút | Đọc `knowledge/slide_chapters/slide_04_operators_visual.md` |
| 30 phút | Đọc + hiểu từng toán tử trong `raw/source_code/.../PhanSo.h` |
| 40 phút | Tự viết class `PhanSo` với `operator+`, `operator>`, `operator==`, `operator<<` |

### Bảng signatures phải thuộc lòng
```cpp
// Số học — const ở cuối, trả về object mới
PhanSo operator+(const PhanSo& other) const;
PhanSo operator-(const PhanSo& other) const;

// So sánh — trả về bool
bool operator>(const PhanSo& other) const;
bool operator==(const PhanSo& other) const;

// Gán kết hợp — trả về *this
PhanSo& operator+=(const PhanSo& other);

// Chỉ số — 2 phiên bản (const và non-const)
int& operator[](int i);          // gán: a[i] = 5
int operator[](int i) const;     // đọc: cout << a[i]

// Xuất — PHẢI là friend (không phải member)
friend ostream& operator<<(ostream& os, const PhanSo& f);

// Tăng — prefix & postfix khác nhau
PhanSo& operator++();            // prefix ++a → trả về *this
PhanSo operator++(int);          // postfix a++ → trả về copy cũ
```

### Bảng lỗi hay gặp (học ngay hôm nay)
| Sai | Đúng | Lý do |
|-----|------|-------|
| `operator+(PhanSo other)` | `operator+(const PhanSo& other) const` | Phải const ref + const method |
| `operator<<` là member | `friend ostream& operator<<(...)` | ostream không thể sửa được |
| Chỉ viết 1 `operator[]` | Cần cả const và non-const | `const` object cần const version |
| `++a` trả về void | `PhanSo& operator++()` → return `*this` | Để viết `++(++a)` |

### Mục tiêu tối thiểu cuối ngày
- [ ] Thuộc bảng signatures — nhớ `const`, `&`, `friend` đúng chỗ
- [ ] Viết class `PhanSo` với 5 toán tử cơ bản không nhìn mẫu

---

## Ngày 3 — T6 22/05 | Operator Overloading — Bài tập + Đề thật
> Luyện tập trực tiếp trên đề thi cũ dạng toán tử.

### Lịch học
| Thời gian | Việc làm |
|-----------|----------|
| 35 phút | Làm câu 1 đề **2024 HK2** (Phân số: `+`, `>`, `==`) — không nhìn gì |
| 15 phút | Tự chấm, ghi lỗi vào `notes/weak_points.md` |
| 35 phút | Làm câu 1 đề **2021 HK1** (Mảng phân số, tìm max) |
| 15 phút | Tự chấm, ghi lỗi |
| 20 phút | Ôn nhanh ngày 1 + 2 — active recall: viết lại signatures từ trí nhớ |

### Nguồn đề: `knowledge/de_thi_analysis/de_thi_transcript.md`

### Checklist
- [ ] Làm xong đề 2024 HK2 câu 1
- [ ] Làm xong đề 2021 HK1 câu 1
- [ ] Ghi ít nhất 2 điểm yếu vào `notes/weak_points.md`

---

## Ngày 4 — T7 23/05 | Big Three + Dynamic Memory ⚠️
> Dạng MỚI NHẤT — cả 2 đề 2025 và 2026 đều ra. Khó nhất, cần nhiều thời gian nhất.

### Lịch học
| Thời gian | Việc làm |
|-----------|----------|
| 40 phút | Đọc `knowledge/slide_chapters/slide_05_big_three.md` (đặc biệt phần diagram bộ nhớ) |
| 10 phút | Đọc `knowledge/slide_chapters/slide_05_big_three_visual.md` |
| 20 phút | Đọc `raw/source_code/.../DynamicArray.cpp` — xem copy ctor + op= đã sửa |
| 50 phút | Tự viết `CMyArray` theo main đề **2025 HK2** (không nhìn mẫu) |
| 20 phút | Tự chấm + sửa |
| 30 phút | Tự viết `CMyString` theo main đề **2026 HK1** (nếu còn sức — nếu không, dời sang ngày 6) |

### Main đề 2025 HK2 — dùng để guide CMyArray
```cpp
int main() {
    CMyArray a;
    a.Add(5); a.Add(3); a.Add(8); a.Add(1);
    cout << a.Min() << endl;   // → 1
    cout << a[1] << endl;      // → 3
    CMyArray b = a;            // copy constructor
    b[0] = 99;
    cout << a[0] << endl;      // → 5 (không đổi — deep copy)
    return 0;
}
```

### Main đề 2026 HK1 — dùng để guide CMyString
```cpp
int main() {
    CMyString s1("Hello");
    CMyString s2(" World");
    CMyString s3 = s1 + s2;      // operator+ → "Hello World"
    s1.Append("!");
    cout << s3.Find("World") << endl;  // → 6
    cout << s3[0] << endl;             // → 'H'
    return 0;
}
```

### Rule of Three — dấu hiệu nhận biết
```
Nếu class có:           →   Bắt buộc thêm:
delete[] trong dtor     →   copy constructor (deep copy)
                        →   operator= (deep copy + self-check)
```

### Mục tiêu tối thiểu cuối ngày
- [ ] Hiểu rõ shallow copy vs deep copy (vẽ được diagram trong đầu)
- [ ] Viết xong `CMyArray` hoàn chỉnh với Big Three + `operator[]` + `Add()` + `Min()`
- [ ] Test trong đầu: `CMyArray b = a; b[0] = 99;` → `a[0]` có thay đổi không?

### ⚠️ Điểm cực kỳ hay quên
```cpp
CMyArray& operator=(const CMyArray& other) {
    if (this == &other) return *this;  // ← THIẾU DÒNG NÀY → crash khi tự gán
    delete[] _data;                     // ← THIẾU → memory leak
    // ... deep copy
    return *this;
}
```

---

## Ngày 5 — CN 24/05 | Inheritance + Polymorphism ⚠️
> Câu 2 BẮT BUỘC 100% mọi đề. Mất buổi này = mất 5/10 điểm.

### Lịch học
| Thời gian | Việc làm |
|-----------|----------|
| 30 phút | Đọc `knowledge/slide_chapters/slide_07_inheritance.md` |
| 20 phút | Đọc `knowledge/slide_chapters/slide_08_lifecycle_inheritance.md` |
| 30 phút | Đọc `knowledge/slide_chapters/slide_09_interface_polymorphism.md` |
| 50 phút | Làm câu 2 đề **2025 HK2** (Monitor/Projector/SmartTV) |
| 30 phút | Làm câu 2 đề **2019 HK2** (3 hệ đào tạo, học bổng khác nhau) |
| 20 phút | Ôn lại: template abstract class từ trí nhớ |

### Template câu 2 — thuộc lòng cấu trúc này
```cpp
// 1. Base class abstract
class Device {
protected:
    string _name;
public:
    Device(string name) : _name(name) {}
    virtual ~Device() {}                    // ← KHÔNG được quên!
    virtual void turnOn() = 0;             // pure virtual
    virtual void display() const {         // có thể override
        cout << "Device: " << _name;
    }
};

// 2. Lớp con (implement pure virtual)
class Monitor : public Device {
    int _size;
public:
    Monitor(string name, int size) : Device(name), _size(size) {}
    void turnOn() override { cout << "Monitor " << _name << " on\n"; }
};

// 3. Container dùng base pointer
class Manager {
    vector<Device*> _list;
public:
    ~Manager() { for (auto p : _list) delete p; }
    void add(Device* d) { _list.push_back(d); }
    void showAll() {
        for (auto p : _list) {
            p->display();         // virtual dispatch
            p->turnOn();
        }
    }
};

// 4. Dùng đúng cách
int main() {
    Manager mgr;
    mgr.add(new Monitor("Dell", 24));
    mgr.add(new Projector("Epson", 1080));
    mgr.showAll();
}
```

### 3 lỗi chết người (mất điểm ngay)
| Lỗi | Hậu quả | Sửa |
|-----|---------|-----|
| Quên `virtual ~Device()` | Memory leak + undefined behavior | Luôn thêm ngay sau khai báo class |
| Quên `virtual` ở base function | Static dispatch — sai lớp được gọi | Kiểm tra lại mọi method cần override |
| Dùng `if/else` kiểm tra type thay `virtual` | Không đạt yêu cầu "đa hình bắt buộc" | Viết `virtual` + `override` |

### Mục tiêu tối thiểu cuối ngày
- [ ] Tự viết abstract class + 2 lớp con + container không nhìn mẫu trong < 30 phút
- [ ] Làm xong câu 2 đề 2025 HK2 (khó nhất)
- [ ] Kiểm tra: mọi base class trong bài có `virtual destructor` chưa?

---

## Ngày 6 — T2 25/05 | Luyện Đề Tổng Hợp
> Làm đề không áp thời gian — mục tiêu là làm đúng, không phải làm nhanh.

### Lịch học
| Thời gian | Việc làm |
|-----------|----------|
| 90 phút | Làm **đầy đủ 2 câu** đề **2024 HK2** (Phân số + Hình học) |
| 20 phút | Tự chấm, ghi lỗi |
| 70 phút | Làm **đầy đủ 2 câu** đề **2025 HK1** (SinhVien + Hình cơ bản) |
| 20 phút | Tự chấm, ghi lỗi |
| 20 phút | Hoàn thiện `notes/weak_points.md` — tổng hợp mọi điểm yếu đã gặp |

### Đề làm theo thứ tự
1. **Đề 2024 HK2** — có cả Operator Overloading (câu 1) + Inheritance (câu 2)
2. **Đề 2025 HK1** — câu 1 kiểu classic, câu 2 hình học chuẩn

> Nguồn: `knowledge/de_thi_analysis/de_thi_transcript.md`

### Mục tiêu
- [ ] Làm xong 2 đề đầy đủ (4 câu tổng)
- [ ] Ghi tổng hợp điểm yếu vào `notes/weak_points.md`
- [ ] Không còn gặp lỗi signature toán tử hay quên virtual destructor

---

## Ngày 7 — T3 26/05 | Thi Thử 90 Phút
> Mô phỏng điều kiện thi thật. Đây là bài test quan trọng nhất.

### Lịch học
| Thời gian | Việc làm |
|-----------|----------|
| 90 phút | **THI THỬ** — 1 đề chưa làm, đặt đồng hồ, không xem tài liệu |
| 30 phút | Tự chấm nghiêm túc — ghi điểm từng phần |
| 30 phút | Review điểm yếu — ôn lại chỗ mắc lỗi |
| 30 phút | Đọc nhanh tất cả flashcard đã tạo |

### Chọn đề thi thử (chọn 1 trong các đề chưa làm)
- Đề 2022 HK2 (Quyển sách + Lớp học đồng phục)
- Đề 2023 HK2 (Đa giác + Lớp học sort theo điểm)
- Đề 2020 HK2 (Tam giác + Hóa đơn 2 loại)

### Thang điểm tự đánh giá
| Điểm | Nghĩa là |
|------|----------|
| Câu 1 xong trong 35 phút | Tốt — đủ thời gian câu 2 |
| Câu 2 có virtual đúng chỗ + 2 lớp con | 4–5đ câu 2 |
| Viết đủ 2 câu trong 90 phút | Sẵn sàng đi thi |
| Câu 1 > 45 phút | Cần luyện thêm Buổi 2–3 |
| Quên virtual destructor | Phải ôn lại ngay |

### Sau khi thi thử
- Ghi kết quả vào `notes/session_log.md`
- Ghi điểm yếu còn lại vào `notes/weak_points.md`
- Nếu điểm tự đánh giá < 7: lặp lại ngày 6–7 với đề khác

---

## Checklist Tổng Kết 7 Ngày

### Kiến thức (phải biết trước ngày thi)
- [ ] Ngày 1: Class design, constructor, getter/setter, Composition
- [ ] Ngày 2–3: Operator signatures — `const`, `&`, `friend` đúng chỗ
- [ ] Ngày 4: Rule of Three — dấu hiệu nhận biết + template đúng
- [ ] Ngày 5: Abstract class, pure virtual, `virtual ~Base()`, `vector<Base*>`

### Kỹ năng (phải làm được trong 90 phút)
- [ ] Đọc `main()` cho sẵn → xác định class cần viết trong < 5 phút
- [ ] Câu 1: viết class đầy đủ trong ~35 phút
- [ ] Câu 2: abstract class + 2–3 lớp con + container trong ~45 phút
- [ ] Không quên: `virtual ~Base()`, `override`, `if (this == &other) return *this`

### Tài liệu đã tạo
- [ ] `study/flashcards/` — tạo sau mỗi chủ đề
- [ ] `notes/weak_points.md` — cập nhật hàng ngày
- [ ] `notes/session_log.md` — ghi kết quả mỗi ngày

---

## Ghi Chú Sử Dụng Plan

| Nói với Claude | Claude sẽ làm |
|----------------|---------------|
| `"ôn ngày 1"` | Dạy Class Design theo 9 bước, lưu flashcard |
| `"flashcard operator"` | Tạo bộ Q/A cho Operator Overloading |
| `"đáp án đề 2025 HK2"` | Viết đáp án mẫu CMyArray + câu 2 |
| `"tạo đề thi"` | Tạo mock exam mới theo pattern thực tế |
| `"kết thúc buổi học"` | Cập nhật session_log.md + about.md |
