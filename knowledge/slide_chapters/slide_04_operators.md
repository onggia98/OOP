# Hàm Toán Tử (Operator Overloading) — OOP Slide 04
> Nguồn: raw/slides/OOP-04-Operators.pptx
> Ngôn ngữ: C++

## Tóm tắt nội dung chính
Slide 04 trình bày khái niệm và cách định nghĩa lại toán tử (operator overloading) cho kiểu người dùng tự định nghĩa trong C++. Phân loại thành toán tử độc lập và toán tử thuộc lớp. Trình bày các toán tử đặc biệt (+=, ++/--), và giới thiệu khái niệm hàm Friend để cho phép hàm bên ngoài truy xuất thành phần private.

## Các khái niệm core

### 1. Hàm toán tử (Operator Function)
- Hàm có **tên là ký hiệu toán tử**
- Khai báo: `operator <toán tử>`
- Mục đích: dùng toán tử quen thuộc trên kiểu tự định nghĩa (giúp code dễ đọc, tương thích template)

### 2. Phân loại hàm toán tử

| Loại | Đặc điểm | Số tham số |
|------|----------|-----------|
| **Toán tử độc lập** | Không thuộc lớp nào | = ngôi toán tử |
| **Toán tử thuộc lớp** | Là phương thức của lớp | = ngôi toán tử - 1 |

Cả 2 loại **sử dụng như nhau**.

### 3. Bốn hạn chế (4 không)
- Không thể **tạo toán tử mới**
- Không thể **định nghĩa lại toán tử trên kiểu cơ bản** (int, float...)
- Không thể **thay đổi ngôi** của toán tử
- Không thể **thay đổi độ ưu tiên** của toán tử

### 4. Toán tử KHÔNG thể định nghĩa lại
`.` , `.*` , `::` , `?:` , `#` , `##`

### 5. Hàm Friend
- Hàm bên ngoài lớp nhưng có thể truy xuất thành phần `private`
- Khai báo trong lớp với từ khóa `friend`
- Cài đặt bên ngoài — **không có** từ khóa `friend`
- Dùng khi toán tử độc lập cần truy cập private (ví dụ: `operator<<`)

## Code examples / Syntax quan trọng

### Toán tử độc lập (non-member)
```cpp
// Khai báo: 2 tham số vì toán tử + có 2 ngôi
PhanSo operator+(const PhanSo &p1, const PhanSo &p2);

// Sử dụng
PhanSo p3 = p1 + p2;  // Tương đương: operator+(p1, p2)
```

### Toán tử thuộc lớp (member)
```cpp
class PhanSo {
public:
    // 1 tham số vì toán tử + có 2 ngôi, lớp chiếm 1 ngôi (this)
    PhanSo operator+(const PhanSo &p);
};

// Sử dụng
PhanSo p3 = p1 + p2;  // Tương đương: p1.operator+(p2)
```

### Toán tử gán (+=, -=, *=, /=)
```cpp
// Trả về tham chiếu để hỗ trợ chuỗi gán: a += b += c
PhanSo& PhanSo::operator+=(const PhanSo &p) {
    // Cộng và cập nhật *this
    return *this;
}
```

### Toán tử tăng/giảm (++/--)
```cpp
// Tiền tố: ++p — trả về tham chiếu đối tượng đã tăng
PhanSo& PhanSo::operator++() {
    // Tăng giá trị
    return *this;
}

// Hậu tố: p++ — tham số giả (int) để phân biệt với tiền tố
// Trả về BẢN SAO trước khi tăng (không trả về tham chiếu)
PhanSo PhanSo::operator++(int x) {
    PhanSo temp(*this);  // Lưu trạng thái cũ
    ++(*this);           // Tăng
    return temp;         // Trả về trạng thái cũ
}
```

### Hàm Friend — toán tử xuất `<<`
```cpp
class PhanSo {
private:
    int m_tu;
    int m_mau;
public:
    // Khai báo friend trong lớp
    friend ostream& operator<<(ostream &os, const PhanSo &p);
};

// Cài đặt bên ngoài (không có từ khóa friend)
ostream& operator<<(ostream &os, const PhanSo &p) {
    os << p.m_tu << "/" << p.m_mau << endl;  // Truy xuất private được!
    return os;  // Trả về os để hỗ trợ chuỗi: cout << p1 << p2
}

// Sử dụng
cout << p;
```

### Toán tử ép kiểu
```cpp
class PhanSo {
public:
    operator float() {       // Ép về float
        return (float)m_tu / m_mau;
    }
    operator int() {         // Ép về int
        return m_tu / m_mau;
    }
};

float x = (float)p;  // Gọi operator float()
```

## Điểm hay thi / Lưu ý
- **Toán tử `<<` phải là hàm friend hoặc độc lập** vì toán hạng trái là `ostream`, không phải lớp của mình. Không thể là member function của PhanSo
- **Phân biệt tiền tố và hậu tố `++`**: tham số giả `int` trong hậu tố là quy ước của C++, không có ý nghĩa giá trị
- Toán tử gán `=` trả về `&` (tham chiếu) để hỗ trợ `a = b = c`
- Hậu tố `++` trả về **bản sao** (không phải tham chiếu) — vì cần lưu trạng thái trước khi tăng
- **Quy tắc Dr. Guru**: tên = `operator<tên>`, số tham số = ngôi, kiểu tham số = kiểu toán hạng, kiểu trả về = kết quả
- Lớp `timMin<T>` template chỉ hoạt động đúng nếu kiểu T có định nghĩa toán tử `<`

## Thuật ngữ
- **Operator Overloading**: nạp chồng toán tử — định nghĩa lại ý nghĩa toán tử cho kiểu mới
- **Unary Operator** (toán tử 1 ngôi): `++`, `--`, `!`, `~`, `+`, `-`
- **Binary Operator** (toán tử 2 ngôi): `+`, `-`, `*`, `/`, `>`, `<`, `==`, `<<`, `>>`...
- **Friend function**: hàm bạn — truy xuất được private của lớp
- **Prefix/Postfix**: tiền tố/hậu tố — `++x` vs `x++`
- **Chaining**: chuỗi toán tử — `cout << a << b` hoặc `a = b = c`
