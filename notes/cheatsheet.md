# CHEATSHEET — OOP C++ CSC10003
> Ôn nhanh 30 phút cuối trước khi thi. Đọc từ trên xuống.

---

## ① CLASS CƠ BẢN

```cpp
class TenClass {
private:
    int  _field1;
    float _field2;

public:
    // Constructor
    TenClass(int f1, float f2) : _field1(f1), _field2(f2) {}

    // Getter/Setter
    int   getField1() const { return _field1; }
    void  setField1(int v)  { _field1 = v; }

    // Method
    void  xuat() const { cout << _field1 << "\n"; }
    float tinh() const { return _field1 * _field2; }
};
```

---

## ② BIG THREE TEMPLATE (khi có `new`/`delete[]`)

```cpp
class MyArray {
    int* _data;
    int  _size, _cap;

public:
    // Constructor
    MyArray() : _data(nullptr), _size(0), _cap(0) {}

    // Destructor
    ~MyArray() { delete[] _data; _data = nullptr; }

    // Copy Constructor — DEEP COPY
    MyArray(const MyArray& o) {
        _size = o._size; _cap = o._cap;
        _data = new int[_cap];
        for (int i = 0; i < _size; i++) _data[i] = o._data[i];
    }

    // Assignment Operator — DEEP COPY
    MyArray& operator=(const MyArray& o) {
        if (this == &o) return *this;    // ← self-assignment guard
        delete[] _data;                  // ← giải phóng cũ
        _size = o._size; _cap = o._cap;
        _data = new int[_cap];
        for (int i = 0; i < _size; i++) _data[i] = o._data[i];
        return *this;
    }

    // operator[] — cần cả 2 phiên bản
    int& operator[](int i)       { return _data[i]; }
    int  operator[](int i) const { return _data[i]; }

    // Add với resize
    void Add(int val) {
        if (_size == _cap) {
            _cap = (_cap == 0) ? 4 : _cap * 2;
            int* tmp = new int[_cap];
            for (int i = 0; i < _size; i++) tmp[i] = _data[i];
            delete[] _data;
            _data = tmp;
        }
        _data[_size++] = val;
    }

    int Size() const { return _size; }

    // Min → trả về INDEX (đọc kỹ đề!)
    int Min() const {
        if (_size == 0) return -1;
        int idx = 0;
        for (int i = 1; i < _size; i++)
            if (_data[i] < _data[idx]) idx = i;
        return idx;
    }
};
```

---

## ③ CHAR* STRING TEMPLATE (CMyString kiểu)

```cpp
class MyString {
    char* _data;
    int   _len;

public:
    MyString() : _data(nullptr), _len(0) {}

    MyString(const char* s) {
        _len  = strlen(s);
        _data = new char[_len + 1];  // +1 cho '\0'
        strcpy(_data, s);
    }

    ~MyString() { delete[] _data; _data = nullptr; }

    MyString(const MyString& o) {
        _len  = o._len;
        _data = new char[_len + 1];
        strcpy(_data, o._data);
    }

    MyString& operator=(const MyString& o) {
        if (this == &o) return *this;
        delete[] _data;
        _len  = o._len;
        _data = new char[_len + 1];
        strcpy(_data, o._data);
        return *this;
    }

    void Append(const char* s) {
        int newLen = _len + strlen(s);
        char* tmp = new char[newLen + 1];
        if (_data) strcpy(tmp, _data); else tmp[0] = '\0';
        strcat(tmp, s);
        delete[] _data;
        _data = tmp; _len = newLen;
    }

    int Find(const char* sub) const {
        if (!_data) return -1;
        char* pos = strstr(_data, sub);
        return pos ? (int)(pos - _data) : -1;
    }

    MyString operator+(const MyString& o) const {
        int newLen = _len + o._len;
        char* tmp = new char[newLen + 1];
        strcpy(tmp, _data ? _data : "");
        strcat(tmp, o._data ? o._data : "");
        MyString result(tmp);
        delete[] tmp;
        return result;
    }

    char& operator[](int i)       { return _data[i]; }
    char  operator[](int i) const { return _data[i]; }

    friend ostream& operator<<(ostream& os, const MyString& s) {
        return os << (s._data ? s._data : "");
    }
};
```

---

## ④ OPERATOR OVERLOADING — CHỮ KÝ CHUẨN

```cpp
// Arithmetic — member, trả về object mới
PhanSo operator+(const PhanSo& o) const;
PhanSo operator-(const PhanSo& o) const;
PhanSo operator*(const PhanSo& o) const;
PhanSo operator/(const PhanSo& o) const;

// Compound assignment — member, trả về reference
PhanSo& operator+=(const PhanSo& o);
PhanSo& operator=(const PhanSo& o);   // copy assign

// Comparison — member, trả về bool
bool operator==(const PhanSo& o) const;
bool operator!=(const PhanSo& o) const;
bool operator> (const PhanSo& o) const;
bool operator< (const PhanSo& o) const;

// Increment — prefix trả T&, postfix trả T (copy)
PhanSo& operator++();          // prefix:  ++a
PhanSo  operator++(int);       // postfix: a++  (tham số (int) giả)

// Stream — PHẢI LÀ FRIEND
friend ostream& operator<<(ostream& os, const PhanSo& p);
friend istream& operator>>(istream& is, PhanSo& p);

// Index — cần 2 phiên bản
int& operator[](int i);
int  operator[](int i) const;
```

**Phân số cộng:**
```cpp
PhanSo operator+(const PhanSo& o) const {
    return PhanSo(_tu * o._mau + _mau * o._tu, _mau * o._mau);
}
```

---

## ⑤ INHERITANCE + POLYMORPHISM TEMPLATE (câu 2)

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// BASE CLASS — abstract
class Base {
protected:
    string _ten;
    float  _diemTB;   // hoặc các trường cần thiết

public:
    Base(string ten, float dtb) : _ten(ten), _diemTB(dtb) {}
    virtual ~Base() {}                          // ← BẮT BUỘC

    virtual double tinhGiaTri() const = 0;      // ← pure virtual
    virtual string loai() const = 0;            // ← pure virtual

    void xuat() const {
        cout << _ten << " [" << loai() << "] "
             << "= " << tinhGiaTri() << "\n";
    }
};

// DERIVED CLASS A
class DerivedA : public Base {
    // thêm trường riêng nếu cần
public:
    DerivedA(string ten, float dtb) : Base(ten, dtb) {}

    double tinhGiaTri() const override {
        if (_diemTB >= 9.0) return 2000000;
        if (_diemTB >= 8.0) return 1000000;
        return 0;
    }
    string loai() const override { return "Loai A"; }
};

// DERIVED CLASS B
class DerivedB : public Base {
public:
    DerivedB(string ten, float dtb) : Base(ten, dtb) {}
    double tinhGiaTri() const override { return _diemTB * 500000; }
    string loai() const override { return "Loai B"; }
};

// CONTAINER CLASS
class Manager {
    vector<Base*> _ds;

public:
    ~Manager() { for (auto p : _ds) delete p; }  // ← BẮT BUỘC

    void them(Base* b) { _ds.push_back(b); }

    void xuatTatCa() const {
        for (auto p : _ds) p->xuat();
    }

    double tongGiaTri() const {
        double t = 0;
        for (auto p : _ds) t += p->tinhGiaTri();
        return t;
    }

    Base* timMax() const {
        if (_ds.empty()) return nullptr;
        Base* max = _ds[0];
        for (auto p : _ds)
            if (p->tinhGiaTri() > max->tinhGiaTri()) max = p;
        return max;
    }
};

int main() {
    Manager mgr;
    mgr.them(new DerivedA("Nguyen Van A", 9.2));
    mgr.them(new DerivedB("Tran Thi B", 8.5));
    mgr.xuatTatCa();
    cout << "Tong: " << mgr.tongGiaTri() << "\n";
    return 0;
}
```

---

## ⑥ BẢNG QUYẾT ĐỊNH NHANH

| Tình huống | Phải làm |
|-----------|----------|
| Class có `delete[]` | → Big Three bắt buộc |
| Base pointer (`Base* p = new Derived()`) | → `virtual ~Base() {}` |
| Method không sửa object | → `const` cuối hàm |
| `operator<<` hoặc `>>` | → `friend` |
| Postfix `++` | → thêm `(int)` giả, trả copy |
| Abstract class | → ít nhất 1 `= 0` |
| Container chứa nhiều loại | → `vector<Base*>`, delete trong dtor |
| Deep copy string | → `new char[strlen+1]` + `strcpy` |

---

## ⑦ LỖI CHẾT NGƯỜI — KIỂM TRA TRƯỚC KHI NỘP

```
□ 1. virtual ~Base() {}  ← có chưa?
□ 2. vector<Base*>       ← không phải vector<Base>?
□ 3. for(auto p:_ds) delete p  ← có trong ~Manager()?
□ 4. if (this == &o) return *this  ← đầu operator=?
□ 5. delete[] _data trước new[]  ← trong operator=?
□ 6. new char[strlen(s)+1]  ← có +1 không?
□ 7. friend operator<<  ← có friend không?
□ 8. override  ← các method lớp con có override không?
□ 9. const cuối method  ← các method getter/tính có const không?
□ 10. Base ctor call  ← Derived(args) : Base(args) {} không?
```

---

## ⑧ INCLUDES CẦN THIẾT

```cpp
#include <iostream>   // cout, cin, ostream
#include <string>     // string
#include <vector>     // vector
#include <cstring>    // strlen, strcpy, strcat, strstr (cho char*)
#include <cmath>      // sqrt, abs (nếu cần)
using namespace std;
```

---

*Chúc thi tốt! Đọc kỹ đề, phân tích main() trước khi code.*
