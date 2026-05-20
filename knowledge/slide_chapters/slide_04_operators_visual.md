# Slide 04 — Hàm Toán Tử (Operator Overloading)
**Môn:** Phương pháp lập trình hướng đối tượng  
**GV:** Nguyễn Minh Huy  
**Nội dung:** Khái niệm cơ bản | Các toán tử đặc biệt | Hàm Friend

---

## Trang 1 — Trang bìa

**Hàm toán tử** — GV. Nguyễn Minh Huy  
Phương pháp lập trình hướng đối tượng.

---

## Trang 2 — Nội dung (mục lục)

Ba chủ đề chính của chương:
- Khái niệm cơ bản.
- Các toán tử đặc biệt.
- Hàm Friend.

*(Trang animation — nội dung giống trang 3, ghi 1 lần)*

---

## Trang 4 — Khái niệm cơ bản — Vấn đề đặt ra

**Sự khác biệt giữa int và PhanSo?**

Với kiểu `int`, ta viết `c = a + b` rất tự nhiên. Với lớp `PhanSo`, phải gọi `p3 = p1.cong(p2)` — không tự nhiên.

**Chương trình tìm min có gì sai?**

Hàm template `timMin` dùng `<` để so sánh — hoạt động với `int` nhưng lỗi với `PhanSo` vì lớp chưa có toán tử `<`.

**💻 Code:**
```cpp
// Thao tác trên kiểu int
void main()
{
    int a, b;
    int c = a + b;
}

// Thao tác trên kiểu PhanSo
void main()
{
    PhanSo p1, p2;
    Phanso p3 = p1.cong(p2);
}

template <class T>
T timMin(T a, T b)
{
    return (a < b) ? a : b;
}

void main()
{
    int a, b;
    int c = timMin(a, b);       // OK

    PhanSo p1, p2;
    PhanSo p3 = timMin(p1, p2); // Lỗi: không có operator <
}
```

---

## Trang 5 — Khái niệm cơ bản — Định nghĩa hàm toán tử

**Hàm toán tử:**

- **Khái niệm:**
  - Một hàm đặc biệt trong chương trình.
  - Có tên là ký hiệu toán tử.
  - Khai báo: từ khóa `operator <toán tử>`.
  - Ví dụ: `PhanSo operator+(const PhanSo &p1, const PhanSo &p2);`

- **Công dụng:**
  - Sử dụng toán tử trên kiểu người dùng định nghĩa.
    - `PhanSo p3 = p1 + p2;`
  - Định nghĩa nhiều cách thực hiện toán tử (nạp chồng hàm).
    - `float operator+(const PhanSo &p, float so);`
    - `float x = p1 + 3.14;`

---

## Trang 6 — Khái niệm cơ bản — Phân loại hàm toán tử

**Phân loại hàm toán tử:**

| Loại | Mô tả | Số tham số | Ví dụ khai báo |
|------|-------|-----------|----------------|
| Toán tử độc lập | Không thuộc lớp nào | = ngôi toán tử | `PhanSo operator+(const PhanSo &p1, const PhanSo &p2);` |
| Toán tử thuộc lớp | Là phương thức của lớp | = ngôi toán tử - 1 | `PhanSo PhanSo::operator+(const PhanSo &p);` |

> **Lưu ý quan trọng:** Cách sử dụng 2 loại là như nhau!  
> Khi viết `p1 + p2`, compiler sẽ tự chọn phiên bản phù hợp.

**💻 Code — so sánh khai báo:**
```cpp
// Toán tử độc lập (standalone)
PhanSo operator+(const PhanSo &p1, const PhanSo &p2);

// Toán tử thuộc lớp (member)
PhanSo PhanSo::operator+(const PhanSo &p);
// this đóng vai trò toán hạng thứ nhất (p1)
// p đóng vai trò toán hạng thứ hai (p2)
```

---

## Trang 7 — Khái niệm cơ bản — Bảng toán tử CÓ THỂ định nghĩa lại

**Những toán tử có thể định nghĩa lại:**

| Ngôi | Nhóm | Toán tử |
|------|------|---------|
| 1 Ngôi (Unary) | Tăng giảm | ++, -- |
| | Dấu số học | +, - |
| | Logic | !, ~ |
| | Con trỏ | *, & |
| | Ép kiểu | int, float, double, ... |
| 2 Ngôi (Binary) | Số học | +, -, *, /, %, +=, -=, *=, /=, %= |
| | So sánh | >, <, ==, >=, <=, != |
| | Logic | &&, \|\|, &, \| |
| | Nhập xuất | <<, >> |
| | Gán | = |
| | Lấy chỉ số mảng | [ ] |

---

## Trang 8 — Khái niệm cơ bản — Bảng toán tử KHÔNG THỂ định nghĩa lại

**Những toán tử KHÔNG thể định nghĩa lại (quan trọng — hay thi):**

| Toán tử | Ý nghĩa |
|---------|---------|
| . | Truy xuất phần tử |
| .* | Truy xuất con trỏ phần tử |
| :: | Toán tử phạm vi |
| ?: | Toán tử điều kiện |
| # | Chỉ thị tiền xử lý |
| ## | Chỉ thị tiền xử lý |

---

## Trang 9 — Khái niệm cơ bản — Những hạn chế (4 không)

**Những hạn chế khi overload toán tử (4 KHÔNG):**

1. **Không thể** tạo toán tử mới.
2. **Không thể** định nghĩa lại toán tử trên kiểu cơ bản (int, float...).
3. **Không thể** thay đổi ngôi của toán tử.
4. **Không thể** thay đổi độ ưu tiên của toán tử.

---

## Trang 10 — Khái niệm cơ bản — Quy tắc định nghĩa (Dr. Guru khuyên)

**Quy tắc định nghĩa toán tử:**

- **Tên hàm:** `operator <tên toán tử>`
- **Số lượng tham số:** = ngôi toán tử (độc lập) hoặc ngôi - 1 (thuộc lớp)
- **Kiểu tham số:** kiểu toán hạng
- **Kiểu trả về:** kết quả toán tử (phải xác định rõ)

**Ví dụ áp dụng:**
- Toán tử `>` (lớp PhanSo)
- Toán tử `[ ]` (lớp Mang)

---

## Trang 11 — Nội dung (chuyển mục)

*(Trang animation chuyển sang phần: Các toán tử đặc biệt)*

---

## Trang 12 — Các toán tử đặc biệt — Toán tử gán (=, +=, -=, *=, /=, ...)

**Toán tử gán — ví dụ với `+=` cho lớp PhanSo:**

- Toán tử `+=` mấy ngôi? → **2 ngôi**
- Toán tử `+=` trả về gì? → **PhanSo& (tham chiếu tới *this)**
- Vì sao trả về tham chiếu? → Để hỗ trợ chuỗi gán: `a += b += c`

**💻 Code — khai báo:**
```cpp
// Khai báo trong class (member function)
PhanSo& PhanSo::operator+=(const PhanSo &p);

// Cài đặt ví dụ
PhanSo& PhanSo::operator+=(const PhanSo &p)
{
    m_tu   = m_tu * p.m_mau + p.m_tu * m_mau;
    m_mau  = m_mau * p.m_mau;
    rutGon();
    return *this;  // trả về tham chiếu tới chính đối tượng
}
```

> **Quy tắc return type của toán tử gán:**  
> - `=`, `+=`, `-=`, `*=`, `/=`, `%=` → trả về `T&` (tham chiếu)

---

## Trang 13 — Các toán tử đặc biệt — Toán tử tăng giảm (++, --)

**Toán tử `++` cho lớp PhanSo:**

- Toán tử `++` mấy ngôi? → **1 ngôi**
- Toán tử `++` trả về gì?
  - Tiền tố (`++p`): trả về `PhanSo&`
  - Hậu tố (`p++`): trả về `PhanSo` (bản sao trước khi tăng)
- **Phân biệt tiền tố và hậu tố:** dùng tham số giả `int` cho hậu tố

**💻 Code — khai báo phân biệt tiền tố / hậu tố:**
```cpp
// Tiền tố: ++p  (prefix)
// Trả về tham chiếu, không có tham số giả
PhanSo& PhanSo::operator++();

// Hậu tố: p++  (postfix)
// Có tham số giả int (không dùng đến giá trị)
PhanSo  PhanSo::operator++(int x);
```

**💻 Code — cài đặt điển hình:**
```cpp
// Tiền tố ++p
PhanSo& PhanSo::operator++()
{
    m_tu += m_mau;  // tăng phân số lên 1 đơn vị
    rutGon();
    return *this;
}

// Hậu tố p++
PhanSo PhanSo::operator++(int x)
{
    PhanSo temp = *this;  // lưu giá trị cũ
    m_tu += m_mau;
    rutGon();
    return temp;          // trả về bản sao trước khi tăng
}
```

> **Quy tắc nhớ:**  
> - `operator++()` → tiền tố, return `T&`  
> - `operator++(int)` → hậu tố, return `T` (by value)

---

## Trang 14 — Nội dung (chuyển mục)

*(Trang animation chuyển sang phần: Hàm Friend)*

---

## Trang 15 — Hàm Friend — Vấn đề đặt ra

**Vấn đề 1 — Toán tử `+` dùng độc lập:**

Nếu khai báo `operator+` là hàm độc lập:
```cpp
PhanSo operator+(const PhanSo &p1, const PhanSo &p2);
```
Hàm này không phải thành viên lớp → **không thể truy xuất thành phần `private`** (`m_tu`, `m_mau`) của lớp PhanSo.

**Vấn đề 2 — Toán tử xuất `<<`:**

Muốn viết `cout << p;` với `PhanSo p(1, 3);`  
Toán tử `<<` thuộc về lớp `ostream` — **không thể thêm member vào `ostream`**.  
Phải định nghĩa là hàm độc lập → lại cần truy xuất `private`.

**Giải pháp: Hàm Friend.**

---

## Trang 16 — Hàm Friend — Định nghĩa và cách dùng

**Hàm Friend:**

- Hàm có thể truy xuất thành phần `private` của lớp.
- **Cách sử dụng:**
  - Khai báo TRONG lớp: từ khóa `friend <chữ ký hàm>`.
  - Cài đặt NGOÀI lớp: **KHÔNG** có từ khóa `friend`.

**💻 Code — ví dụ operator<< là friend của PhanSo:**
```cpp
class PhanSo
{
    // ... thành phần private: m_tu, m_mau
    friend ostream& operator<<(ostream &os, const PhanSo &p);
};

// Cài đặt ngoài lớp — KHÔNG có từ khóa friend
ostream& operator<<(ostream &os, const PhanSo &p)
{
    os << p.m_tu << "/" << p.m_mau << endl;
    return os;  // trả về os để hỗ trợ chuỗi: cout << p1 << p2
}
```

**Sử dụng:**
```cpp
PhanSo p(1, 3);
cout << p;      // in ra: 1/3
cout << p1 << p2; // chain: nhờ return os;
```

> **Quy tắc return type của toán tử nhập/xuất:**  
> - `operator<<` → return `ostream&`  
> - `operator>>` → return `istream&`

---

## Trang 17 — Tóm tắt

**Hàm toán tử:**
- Hàm có tên là ký hiệu toán tử.
- Dùng để trang bị toán tử cho kiểu tự định nghĩa.
- Có 2 loại: toán tử độc lập và toán tử thuộc lớp.

**Các toán tử đặc biệt:**
- `=`, `+=`, `-=`, `++`, `--`.

**Hàm Friend:**
- Hàm truy xuất được thành phần private của lớp.

---

## Trang 18 — Bài tập 4.1 — Lớp Phân Số

Trang bị cho lớp **phân số** những toán tử sau:
- Toán tử số học: `+`, `*`
- Toán tử so sánh: `>`, `<`, `==`, `>=`, `<=`, `!=`
- Toán tử gán: `=`, `+=`, `*=`
- Toán tử một ngôi: `++`, `--` (tăng, giảm 1 đơn vị)
- Toán tử ép kiểu: `(float)`, `(int)`
- Toán tử nhập, xuất: `>>`, `<<`

---

## Trang 19 — Bài tập 4.2 — Lớp Đơn Thức

Trang bị cho lớp **đơn thức** những toán tử sau:
- Toán tử số học: `+` (cùng bậc), `*`
- Toán tử so sánh: `>`, `<`, `==`, `>=`, `<=`, `!=`
- Toán tử gán: `=`, `+=` (cùng bậc), `*=`
- Toán tử một ngôi:
  - `++`, `--` (tăng, giảm bậc)
  - `!` (đạo hàm)
- Toán tử nhập, xuất: `>>`, `<<`

---

## Trang 20 — Bài tập 4.3 — Lớp Mảng

Trang bị cho lớp **mảng** (phần kiểu bất kỳ) những toán tử sau:
- Toán tử gán: `=`
- Toán tử truy xuất phần tử: `[ ]`
- Toán tử ép kiểu: `(T *)` (ép về con trỏ kiểu T)
- Toán tử nhập, xuất: `>>`, `<<`

---

## Trang 21 — Bài tập 4.4 — Lớp Time (phần 1)

Xây dựng lớp **Time** có những phương thức sau:

*(Nhóm tạo hủy)*
- Khởi tạo mặc định vào thời điểm hiện tại.
- Khởi tạo từ giờ, phút, giây cho trước.
- Khởi tạo từ giây tuyệt đối trong ngày.
- Khởi tạo từ một đối tượng Time khác.

*(Nhóm truy xuất thông tin)*
- Lấy/gán giờ, phút, giây.
- Lấy/gán giây tuyệt đối trong ngày.

---

## Trang 22 — Bài tập 4.4 — Lớp Time (phần 2)

*(Nhóm xử lý nghiệp vụ)*
- So sánh thứ tự trước sau với đối tượng Time khác.
- Tính khoảng cách đến đối tượng Time khác (đơn vị giây).
- Cộng giờ, cộng phút, cộng giây.

*(Nhóm toán tử)*
- Toán tử so sánh: `>`, `<`, `==`, `>=`, `<=`, `!=`
- Toán tử cộng, trừ giây: `+`, `-`
- Toán tử tăng, giảm 1 giây: `++`, `--`
- Toán tử nhập xuất: `>>`, `<<`

---

## Trang 23 — Bài tập 4.5 — Lớp Date (phần 1)

Xây dựng lớp **Date** có những phương thức sau:

*(Nhóm tạo hủy)*
- Khởi tạo mặc định vào ngày hiện tại.
- Khởi tạo từ ngày, tháng, năm cho trước.
- Khởi tạo từ năm và ngày tuyệt đối trong năm.
- Khởi tạo từ một đối tượng Date khác.

*(Nhóm truy xuất thông tin)*
- Lấy/gán ngày, tháng, năm.
- Lấy/gán ngày tuyệt đối trong năm.
- Thông báo thứ trong tuần.
- Thông báo tuần trong năm.

---

## Trang 24 — Bài tập 4.5 — Lớp Date (phần 2)

*(Nhóm xử lý nghiệp vụ)*
- Kiểm tra năm nhuận.
- So sánh thứ tự trước sau với đối tượng Date khác.
- Tính khoảng cách đến đối tượng Date khác (đơn vị ngày).
- Cộng ngày, cộng tháng, cộng năm.

*(Nhóm toán tử)*
- Toán tử so sánh: `>`, `<`, `==`, `>=`, `<=`, `!=`
- Toán tử cộng, trừ ngày: `+`, `-`
- Toán tử tăng, giảm 1 ngày: `++`, `--`
- Toán tử nhập xuất: `>>`, `<<`

---

## TỔNG HỢP KIẾN THỨC THI — Slide 04

### 1. Bảng toán tử KHÔNG được overload (hay thi)

| Toán tử | Ý nghĩa |
|---------|---------|
| `.` | Truy xuất phần tử |
| `.*` | Truy xuất con trỏ phần tử |
| `::` | Phạm vi (scope) |
| `?:` | Điều kiện (ternary) |
| `#` | Tiền xử lý |
| `##` | Tiền xử lý nối chuỗi |

### 2. Quy tắc Member vs. Non-member (Friend)

| Tiêu chí | Toán tử thuộc lớp (Member) | Toán tử độc lập (Non-member) |
|----------|---------------------------|------------------------------|
| Số tham số | ngôi - 1 | = ngôi |
| Truy xuất private | Trực tiếp | Cần khai báo friend |
| Bắt buộc dùng | `=`, `[]`, `()`, `->` | `<<`, `>>` (nhập/xuất) |
| Khuyến nghị | `+=`, `-=`, `*=`... | `+`, `-`, `*`... (binary symmetric) |

### 3. Bảng return type chuẩn

| Toán tử | Return type | Ghi chú |
|---------|-------------|---------|
| `=`, `+=`, `-=`, `*=`, `/=`, `%=` | `T&` | Trả về `*this` |
| `++` tiền tố | `T&` | `operator++()` |
| `++` hậu tố | `T` (by value) | `operator++(int)` — tham số giả |
| `--` tiền tố | `T&` | `operator--()` |
| `--` hậu tố | `T` (by value) | `operator--(int)` — tham số giả |
| `+`, `-`, `*`, `/` | `T` (by value) | Toán tử số học binary |
| `==`, `!=`, `>`, `<` | `bool` | Toán tử so sánh |
| `<<` | `ostream&` | Luôn là friend |
| `>>` | `istream&` | Luôn là friend |
| `[]` | `T&` | Phải là member |

### 4. Mẫu code tổng hợp — Lớp PhanSo đầy đủ

```cpp
class PhanSo
{
private:
    int m_tu, m_mau;
    void rutGon();

public:
    PhanSo(int tu = 0, int mau = 1);

    // ---- Toán tử số học (member) ----
    PhanSo operator+(const PhanSo &p) const;
    PhanSo operator*(const PhanSo &p) const;

    // ---- Toán tử gán (member, return T&) ----
    PhanSo& operator=(const PhanSo &p);
    PhanSo& operator+=(const PhanSo &p);
    PhanSo& operator*=(const PhanSo &p);

    // ---- Toán tử so sánh (member, return bool) ----
    bool operator>(const PhanSo &p) const;
    bool operator<(const PhanSo &p) const;
    bool operator==(const PhanSo &p) const;
    bool operator!=(const PhanSo &p) const;
    bool operator>=(const PhanSo &p) const;
    bool operator<=(const PhanSo &p) const;

    // ---- Toán tử tăng giảm ----
    PhanSo& operator++();          // tiền tố: ++p
    PhanSo  operator++(int);       // hậu tố:  p++
    PhanSo& operator--();          // tiền tố: --p
    PhanSo  operator--(int);       // hậu tố:  p--

    // ---- Toán tử ép kiểu (member) ----
    operator float() const;
    operator int() const;

    // ---- Toán tử nhập xuất (friend) ----
    friend ostream& operator<<(ostream &os, const PhanSo &p);
    friend istream& operator>>(istream &is, PhanSo &p);
};

// ---- Cài đặt toán tử += ----
PhanSo& PhanSo::operator+=(const PhanSo &p)
{
    m_tu  = m_tu * p.m_mau + p.m_tu * m_mau;
    m_mau = m_mau * p.m_mau;
    rutGon();
    return *this;
}

// ---- Cài đặt tiền tố ++p ----
PhanSo& PhanSo::operator++()
{
    m_tu += m_mau;  // tăng lên 1 đơn vị
    rutGon();
    return *this;
}

// ---- Cài đặt hậu tố p++ ----
PhanSo PhanSo::operator++(int)
{
    PhanSo temp = *this;   // lưu giá trị cũ
    m_tu += m_mau;
    rutGon();
    return temp;           // trả về bản sao trước khi tăng
}

// ---- Cài đặt operator<< (friend, ngoài lớp không có friend) ----
ostream& operator<<(ostream &os, const PhanSo &p)
{
    os << p.m_tu << "/" << p.m_mau;
    return os;
}

// ---- Cài đặt operator>> (friend) ----
istream& operator>>(istream &is, PhanSo &p)
{
    is >> p.m_tu >> p.m_mau;
    p.rutGon();
    return is;
}

// ---- Cài đặt ép kiểu float ----
PhanSo::operator float() const
{
    return (float)m_tu / m_mau;
}
```

### 5. Tóm tắt quy tắc 4 KHÔNG

1. KHÔNG tạo toán tử mới (ví dụ: `**` không hợp lệ).
2. KHÔNG định nghĩa lại toán tử trên kiểu cơ bản (`int + int` không thể override).
3. KHÔNG thay đổi ngôi của toán tử (`+` luôn là 2 ngôi).
4. KHÔNG thay đổi độ ưu tiên của toán tử.

### 6. Phân biệt tiền tố vs. hậu tố

```cpp
PhanSo& operator++();     // tiền tố:  ++p  — không có tham số
PhanSo  operator++(int);  // hậu tố:   p++  — có tham số giả int (không dùng)
```

### 7. Quy tắc khi nào dùng friend

Dùng `friend` khi:
- Toán tử là hàm độc lập (non-member) nhưng cần truy xuất `private`.
- Bắt buộc: `operator<<` và `operator>>` vì toán hạng trái là `ostream`/`istream`, không phải object của lớp.
- Tùy chọn: `operator+`, `operator-`... khi muốn hỗ trợ cả hai chiều (`p + 3.14` và `3.14 + p`).
