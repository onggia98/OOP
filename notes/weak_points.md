# Điểm Yếu / Hay Nhầm — CSC10003 OOP C++
> Cập nhật sau mỗi buổi học. File này là "bộ nhớ lỗi" cá nhân.
> Format: **Lỗi** → Đúng phải là gì → Cách nhớ

---

## 🔴 Nhóm 1 — Lỗi chết người (mất toàn bộ điểm câu)

### L01: Quên `virtual` ở base class
```cpp
// ❌ SAI — speak() không có virtual
class Animal {
public:
    void speak() { cout << "..."; }
};

// ✅ ĐÚNG
class Animal {
public:
    virtual void speak() { cout << "..."; }
    virtual ~Animal() {}   // ← cũng cần virtual!
};
```
**Hậu quả:** `vector<Animal*>` gọi `Animal::speak()` hết, không gọi được Dog/Cat  
**Cách nhớ:** "Câu 2 bắt buộc đa hình → bắt buộc `virtual`"

---

### L02: Dùng `vector<Animal>` thay `vector<Animal*>`
```cpp
// ❌ SAI — object slicing! Dog bị cắt thành Animal
vector<Animal> animals;
animals.push_back(Dog("Rex"));

// ✅ ĐÚNG
vector<Animal*> animals;
animals.push_back(new Dog("Rex"));
// Nhớ: destructor phải delete!
```
**Hậu quả:** Toàn bộ polymorphism mất tác dụng  
**Cách nhớ:** "Đa hình cần con trỏ → `vector<Base*>`"

---

### L03: Quên `virtual destructor` trong base class
```cpp
// ❌ SAI
class SinhVien {
public:
    virtual double tinhHocBong() const = 0;
    // THIẾU virtual destructor!
};

// ✅ ĐÚNG
class SinhVien {
public:
    virtual double tinhHocBong() const = 0;
    virtual ~SinhVien() {}  // ← BẮT BUỘC khi có base pointer
};
```
**Hậu quả:** `delete p` chỉ gọi `~SinhVien()` không gọi `~SVChinhQuy()` → memory leak  
**Quy tắc:** **Có virtual function → phải có virtual destructor**

---

## 🟠 Nhóm 2 — Lỗi Big Three (mất điểm câu 1 xu hướng mới)

### L04: Quên self-assignment check trong `operator=`
```cpp
// ❌ SAI — nếu a = a thì delete[] rồi copy chính nó → crash
Good& operator=(const Good& o) {
    delete[] _data;
    _size = o._size;
    _data = new int[_size];
    ...
}

// ✅ ĐÚNG
Good& operator=(const Good& o) {
    if (this == &o) return *this;  // ← PHẢI CÓ
    delete[] _data;
    ...
}
```
**Cách nhớ:** Dòng đầu tiên của `operator=` luôn là `if (this == &o) return *this;`

---

### L05: Quên `delete[] _data` trước khi copy trong `operator=`
```cpp
// ❌ SAI — memory leak! _data cũ bị bỏ rơi
Good& operator=(const Good& o) {
    if (this == &o) return *this;
    // THIẾU: delete[] _data;
    _size = o._size;
    _data = new int[_size];  // vùng nhớ cũ leak!
    ...
}
```
**Cách nhớ:** `operator=` = **"Giải phóng cũ → lấy mới"**

---

### L06: Quên `+1` khi cấp phát `char*`
```cpp
// ❌ SAI — không có chỗ cho '\0'
_data = new char[strlen(s)];

// ✅ ĐÚNG
_data = new char[strlen(s) + 1];  // +1 cho '\0'
strcpy(_data, s);
```
**Hậu quả:** Buffer overflow, crash khi in chuỗi  
**Cách nhớ:** `char*` luôn cần `+1` — không ngoại lệ

---

### L07: Shallow copy thay vì deep copy trong copy constructor
```cpp
// ❌ SAI — b._data trỏ cùng vùng với a._data
CMyArray(const CMyArray& o) {
    _size = o._size;
    _data = o._data;  // ← shallow copy!
}

// ✅ ĐÚNG
CMyArray(const CMyArray& o) {
    _size = o._size;
    _capacity = o._capacity;
    _data = new int[_capacity];
    for (int i = 0; i < _size; i++) _data[i] = o._data[i];
}
```

---

## 🟡 Nhóm 3 — Lỗi Operator Overloading

### L08: `operator<<` không khai báo `friend`
```cpp
// ❌ SAI — không thể thêm method vào ostream
ostream& operator<<(ostream& os, const PhanSo& p) { ... }  // phải là friend

// ✅ ĐÚNG — khai báo trong class
friend ostream& operator<<(ostream& os, const PhanSo& p) {
    return os << p._tu << "/" << p._mau;
}
```
**Quy tắc:** `operator<<` và `operator>>` **luôn luôn** là `friend`

---

### L09: Nhầm prefix và postfix `++`
```cpp
// ❌ HAY NHẦM
PhanSo operator++() { ... }      // tưởng là prefix
PhanSo& operator++(int) { ... }  // tưởng là postfix

// ✅ ĐÚNG
PhanSo& operator++() {           // PREFIX: trả về reference, không tham số
    _tu += _mau;
    return *this;
}
PhanSo operator++(int) {         // POSTFIX: tham số (int) giả, trả về copy
    PhanSo old = *this;
    _tu += _mau;
    return old;
}
```
**Cách nhớ:** "Postfix có `(int)` → trả về bản cũ (copy)"

---

### L10: Quên `const` cuối method
```cpp
// ❌ SAI — không dùng được với const object
PhanSo operator+(const PhanSo& o) { ... }
bool operator>(const PhanSo& o) { ... }

// ✅ ĐÚNG
PhanSo operator+(const PhanSo& o) const { ... }  // ← const cuối
bool operator>(const PhanSo& o) const { ... }     // ← const cuối
```
**Quy tắc:** Method **không sửa** object → phải có `const` cuối

---

### L11: Viết thiếu phiên bản `const` của `operator[]`
```cpp
// Chỉ viết 1 phiên bản → không dùng được với const object
int& operator[](int i) { return _data[i]; }

// ✅ ĐÚNG — cần cả 2
int& operator[](int i)       { return _data[i]; }       // non-const: gán được
int  operator[](int i) const { return _data[i]; }        // const: chỉ đọc
```

---

## 🟢 Nhóm 4 — Lỗi Nhỏ Hay Bị Bỏ Qua

### L12: Quên delete con trỏ trong destructor container
```cpp
// ❌ SAI — memory leak! vector<Base*> không tự delete
~QuanLySV() {}

// ✅ ĐÚNG
~QuanLySV() {
    for (auto p : _ds) delete p;
}
```

### L13: Không gọi constructor base class trong lớp con
```cpp
// ❌ SAI — _hoTen và _diemTB không được khởi tạo
SVChinhQuy(string ht, float dtb) {}

// ✅ ĐÚNG
SVChinhQuy(string ht, float dtb) : SinhVien(ht, dtb) {}
```
**Cách nhớ:** Constructor lớp con **luôn gọi** constructor lớp cha trong initializer list

### L14: `Min()` trong CMyArray trả về value thay vì index
```cpp
// ❌ SAI — đề 2025 yêu cầu trả INDEX
int Min() const { return *min_element(_data, _data+_size); }  // trả value

// ✅ ĐÚNG — đọc kỹ main: int minIndex = arr.Min(); arr[minIndex]
int Min() const {
    if (_size == 0) return -1;
    int minIdx = 0;
    for (int i = 1; i < _size; i++)
        if (_data[i] < _data[minIdx]) minIdx = i;
    return minIdx;  // trả INDEX
}
```

### L15: Dùng `if/else` theo loại thay vì polymorphism
```cpp
// ❌ SAI — đề yêu cầu "bắt buộc đa hình" → mất điểm
double tinhHocBong(SinhVien* sv) {
    if (sv->loai == "CQ") return ...;
    else if (sv->loai == "TN") return ...;
}

// ✅ ĐÚNG — mỗi lớp con override riêng
double tinhHocBong() const override { ... }
```

---

## 📋 Quick Check Trước Khi Nộp Bài

```
□ Base class có virtual function → có virtual destructor chưa?
□ vector<Base*> chứ không phải vector<Base>?
□ Mỗi lớp con có override keyword chưa?
□ operator= có if (this == &o) return *this không?
□ operator= có delete[] trước khi new không?
□ char* constructor có +1 không?
□ operator<< là friend không?
□ Method không sửa object có const cuối không?
□ Container destructor có for (auto p : _ds) delete p không?
□ Constructor lớp con có gọi SinhVien(ht, dtb) trong : không?
```

---

## 📝 Ghi Chú Cá Nhân (thêm sau mỗi buổi học)
<!-- Ghi những lỗi mới phát hiện khi luyện đề -->

