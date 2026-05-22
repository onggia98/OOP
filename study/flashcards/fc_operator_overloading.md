# Flashcard — Operator Overloading
> Chủ đề: Buổi 2–3 | Tần suất thi: 4/6 đề gần nhất (2021–2026), bắt buộc từ 2024

---

## Q1: Operator overloading là gì? Tại sao cần?
**A:** Định nghĩa lại hành vi của toán tử (`+`, `>`, `[]`...) cho class tự định nghĩa.  
Tại sao: `phanSo1 + phanSo2` đọc tự nhiên hơn `phanSo1.cong(phanSo2)`.

---

## Q2: Viết `operator+` cho class PhanSo
**A:**
```cpp
PhanSo operator+(const PhanSo& other) const {
    // a/b + c/d = (a*d + b*c) / (b*d)
    return PhanSo(_tu * other._mau + _mau * other._tu,
                  _mau * other._mau);
}
```
> Chú ý 3 điểm: `const PhanSo&` (tham chiếu, không copy), `const` ở cuối (không sửa object), trả về object mới (không phải `&`).

---

## Q3: `operator+` khác `operator+=` như thế nào?
**A:**
```cpp
// operator+ → trả về object MỚI (không sửa *this)
PhanSo operator+(const PhanSo& other) const {
    return PhanSo(_tu + other._tu, _mau);  // tạo object mới
}

// operator+= → sửa *this, trả về *this
PhanSo& operator+=(const PhanSo& other) {
    _tu = _tu * other._mau + _mau * other._tu;
    _mau *= other._mau;
    return *this;   // trả về reference
}
```

---

## Q4: `operator<<` tại sao phải là `friend`? Viết thế nào?
**A:** Vì `ostream` là class của thư viện chuẩn — ta không thể thêm method vào đó.  
`operator<<` phải được gọi như: `cout << ps` → `operator<<(cout, ps)` → toán hạng trái là `ostream`, không phải class ta.
```cpp
// Trong class:
friend ostream& operator<<(ostream& os, const PhanSo& ps);

// Ngoài class (định nghĩa):
ostream& operator<<(ostream& os, const PhanSo& ps) {
    os << ps._tu << "/" << ps._mau;
    return os;   // return os để chain: cout << a << b
}
```

---

## Q5: `operator[]` — tại sao cần 2 phiên bản?
**A:**
```cpp
// Phiên bản 1: cho phép GÁN vào phần tử (a[i] = 5)
int& operator[](int i) { return _data[i]; }

// Phiên bản 2: chỉ ĐỌC, dùng trên const object (cout << a[i])
int operator[](int i) const { return _data[i]; }
```
> Nếu chỉ có phiên bản non-const → không thể gọi trên `const CMyArray&`.

---

## Q6: Prefix `++` và postfix `++` khác nhau thế nào?
**A:**
```cpp
// Prefix: ++a → tăng trước, trả về *this (sau khi tăng)
PhanSo& operator++() {
    _tu += _mau;   // tăng giá trị
    return *this;
}

// Postfix: a++ → lưu bản cũ, tăng, trả về bản cũ
PhanSo operator++(int) {   // tham số int là dấu hiệu postfix
    PhanSo old = *this;    // lưu giá trị cũ
    _tu += _mau;           // tăng
    return old;            // trả về bản cũ
}
```
> Prefix nhanh hơn (không tạo copy tạm). Postfix phải tạo copy → dùng prefix khi có thể.

---

## Q7: Toán tử so sánh — viết thế nào?
**A:**
```cpp
bool operator>(const PhanSo& other) const {
    // a/b > c/d ↔ a*d > b*c (b, d > 0)
    return _tu * other._mau > _mau * other._tu;
}

bool operator==(const PhanSo& other) const {
    // rút gọn trước để so sánh chính xác
    return _tu * other._mau == _mau * other._tu;
}

bool operator<(const PhanSo& other) const {
    return other > *this;   // dùng lại operator> đã viết
}
```

---

## Q8: `operator=` (assignment) — sự khác biệt với copy constructor?
**A:**
```cpp
PhanSo a(1, 2);
PhanSo b = a;    // gọi COPY CONSTRUCTOR (b chưa tồn tại)
PhanSo c(3, 4);
c = a;           // gọi ASSIGNMENT OPERATOR (c đã tồn tại)
```
```cpp
// Assignment operator
PhanSo& operator=(const PhanSo& other) {
    if (this == &other) return *this;  // tự gán
    _tu  = other._tu;
    _mau = other._mau;
    return *this;
}
```

---

## Q9: Member function vs friend function — chọn khi nào?
**A:**
| Dùng member | Dùng friend |
|-------------|-------------|
| `operator+`, `-`, `*`, `/` | `operator<<`, `operator>>` |
| `operator[]`, `operator()` | Toán tử đối xứng (nếu cần) |
| `operator=`, `+=`, `-=` | Khi toán hạng trái không phải class ta |
| `operator++`, `operator--` | |

---

## Q10: Bảng signatures đầy đủ — học thuộc

```cpp
class X {
public:
    // Số học → object mới
    X operator+(const X& o) const;
    X operator-(const X& o) const;
    X operator*(const X& o) const;

    // So sánh → bool
    bool operator>(const X& o)  const;
    bool operator==(const X& o) const;
    bool operator<(const X& o)  const;

    // Gán kết hợp → *this
    X& operator+=(const X& o);
    X& operator=(const X& o);

    // Chỉ số → 2 phiên bản
    T& operator[](int i);
    T  operator[](int i) const;

    // Tăng/giảm
    X& operator++();        // prefix
    X  operator++(int);     // postfix

    // Xuất/nhập → friend
    friend ostream& operator<<(ostream& os, const X& x);
    friend istream& operator>>(istream& is, X& x);
};
```

---

## Quick Test — trả lời không nhìn

1. `operator<<` là member hay friend? Tại sao?
2. Prefix `++` trả về gì? Postfix `++` trả về gì?
3. `operator[]` cần mấy phiên bản? Tại sao?
4. `operator+` và `operator+=` trả về khác nhau thế nào?
5. Tham số `(int)` trong `operator++(int)` có nghĩa gì?
