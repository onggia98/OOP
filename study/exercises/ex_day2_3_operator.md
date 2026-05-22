# Bài Tập — Ngày 2–3: Operator Overloading
> Tần suất thi: 4/6 đề gần nhất. Đây là dạng câu 1 chủ đạo từ 2021.

---

## Bài 1 — Dễ (15 phút): class PhanSo cơ bản

Viết class `PhanSo` với tử số và mẫu số nguyên dương, cài đặt:
- `operator+` : cộng hai phân số
- `operator>` : so sánh hai phân số  
- `operator<<`: in dạng `tu/mau`

**Test:**
```cpp
PhanSo a(1, 2), b(1, 3);
cout << a + b << "\n";    // → 5/6
cout << (a > b) << "\n";  // → 1 (true)
```

<details>
<summary>Đáp án</summary>

```cpp
#include <iostream>
using namespace std;

class PhanSo {
private:
    int _tu, _mau;
    int ucln(int a, int b) { return b == 0 ? a : ucln(b, a % b); }
    void rutGon() {
        int u = ucln(abs(_tu), abs(_mau));
        _tu /= u; _mau /= u;
        if (_mau < 0) { _tu = -_tu; _mau = -_mau; }
    }
public:
    PhanSo(int tu = 0, int mau = 1) : _tu(tu), _mau(mau) { rutGon(); }

    PhanSo operator+(const PhanSo& o) const {
        return PhanSo(_tu * o._mau + _mau * o._tu, _mau * o._mau);
    }
    bool operator>(const PhanSo& o) const {
        return _tu * o._mau > _mau * o._tu;
    }
    friend ostream& operator<<(ostream& os, const PhanSo& p) {
        return os << p._tu << "/" << p._mau;
    }
};
```
</details>

---

## Bài 2 — Trung bình (25 phút): PhanSo đầy đủ

Mở rộng bài 1, thêm:
- `operator-`, `operator*`, `operator/`
- `operator==`, `operator<`
- `operator+=`
- `operator++` (prefix và postfix) — tăng tử số lên 1
- `void nhap()` từ cin

**Test:**
```cpp
PhanSo a(3, 4), b(1, 4);
cout << a - b << "\n";    // → 1/2
cout << a * b << "\n";    // → 3/16
cout << (a == PhanSo(3,4)) << "\n";  // → 1

PhanSo c(1, 3);
cout << ++c << "\n";      // → 4/3 (prefix: tăng rồi in)
cout << c++ << "\n";      // → 4/3 (postfix: in rồi tăng)
cout << c   << "\n";      // → 7/3
```

<details>
<summary>Đáp án</summary>

```cpp
PhanSo operator-(const PhanSo& o) const {
    return PhanSo(_tu * o._mau - _mau * o._tu, _mau * o._mau);
}
PhanSo operator*(const PhanSo& o) const {
    return PhanSo(_tu * o._tu, _mau * o._mau);
}
PhanSo operator/(const PhanSo& o) const {
    return PhanSo(_tu * o._mau, _mau * o._tu);
}
bool operator==(const PhanSo& o) const {
    return _tu * o._mau == _mau * o._tu;
}
bool operator<(const PhanSo& o) const { return o > *this; }

PhanSo& operator+=(const PhanSo& o) {
    *this = *this + o;  // dùng lại operator+
    return *this;
}
PhanSo& operator++() {          // prefix
    _tu += _mau;
    return *this;
}
PhanSo operator++(int) {        // postfix
    PhanSo old = *this;
    _tu += _mau;
    return old;
}
```
</details>

---

## Bài 3 — Đề thật 2024 HK2 (35 phút)

> Nguồn: `knowledge/de_thi_analysis/de_thi_transcript.md` — 2024 HK2

Viết chương trình tính **trung bình cộng các phân số dương** trong mảng một chiều.
- **Bắt buộc** cài đặt `operator+` để cộng phân số
- **Bắt buộc** cài đặt `operator>` để so sánh phân số với 0
- Dùng `a + b` không dùng method `cong()`

**Thuật toán:**
```
tong = 0/1
dem = 0
for each ps in mang:
    if ps > PhanSo(0):     // dương → dùng operator>
        tong += ps          // dùng operator+=
        dem++
trungBinh = tong / dem      // dùng operator/
```

---

## Bài 4 — Nâng cao: class Vector2D (30 phút)

Viết class `Vector2D` đại diện vector 2 chiều (x, y):
- `operator+`, `operator-`
- `operator*` với scalar: `v * 2.0` → nhân từng thành phần với 2.0
- `operator==`
- `operator<<`: in dạng `(x, y)`
- `double length() const` — độ dài vector

**Test:**
```cpp
Vector2D v1(3, 4), v2(1, 2);
cout << v1 + v2 << "\n";   // → (4, 6)
cout << v1 - v2 << "\n";   // → (2, 2)
cout << v1 * 2.0 << "\n";  // → (6, 8)
cout << v1.length() << "\n"; // → 5
```

<details>
<summary>Gợi ý</summary>

```cpp
class Vector2D {
    double _x, _y;
public:
    Vector2D(double x=0, double y=0) : _x(x), _y(y) {}
    Vector2D operator+(const Vector2D& o) const { return {_x+o._x, _y+o._y}; }
    Vector2D operator*(double s) const { return {_x*s, _y*s}; }
    double length() const { return sqrt(_x*_x + _y*_y); }  // #include <cmath>
    friend ostream& operator<<(ostream& os, const Vector2D& v) {
        return os << "(" << v._x << ", " << v._y << ")";
    }
};
```
</details>

---

## Checklist

- [ ] Bài 1: PhanSo cơ bản — 3 toán tử, < 15 phút
- [ ] Bài 2: PhanSo đầy đủ — 8 toán tử, prefix/postfix đúng
- [ ] Bài 3: Làm đúng đề 2024 HK2
- [ ] Bài 4 (nếu có thời gian): Vector2D

**Hay sai nhất:**  
- Quên `const` cuối method  
- `operator<<` không phải `friend`  
- Prefix trả về `T&`, postfix trả về `T` (bản copy)
