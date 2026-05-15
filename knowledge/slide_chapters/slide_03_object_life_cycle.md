# Vòng Đời Đối Tượng — OOP Slide 03
> Nguồn: raw/slides/OOP-03-Object Life Cycle.pptx
> Ngôn ngữ: C++

## Tóm tắt nội dung chính
Slide 03 trình bày toàn bộ vòng đời của một đối tượng trong C++: từ khi được tạo ra (constructor) đến khi bị hủy (destructor). Ngoài ra còn giới thiệu thành phần tĩnh (static members) dùng chung giữa các đối tượng cùng lớp, và Class Template để tổng quát hóa kiểu dữ liệu bên trong lớp.

## Các khái niệm core

### 1. Phương thức khởi tạo (Constructor)
- Tự động gọi khi khai báo đối tượng — không thể quên gọi
- Không có kiểu trả về (kể cả `void`)
- Có tên trùng tên lớp
- Có thể **nạp chồng** nhiều constructor

**Ba loại constructor tối thiểu nên có (Dr. Guru):**

| Loại | Cú pháp | Mục đích |
|------|---------|----------|
| Mặc định | `PhanSo()` | Khởi tạo giá trị mặc định |
| Sao chép | `PhanSo(const PhanSo &p)` | Sao chép từ đối tượng khác |
| Đầy đủ thông tin | `PhanSo(int tu, int mau)` | Khởi tạo với giá trị cụ thể |

**Khi lớp không có constructor nào → trình biên dịch tự cấp constructor mặc định.**

### 2. Phương thức hủy (Destructor)
- Tự động gọi khi đối tượng ra khỏi phạm vi hoặc bị `delete`
- **Duy nhất một** destructor cho mỗi lớp (không nạp chồng)
- Tên: `~<TênLớp>()`
- Dùng để **thu hồi bộ nhớ động** (delete con trỏ) — tránh memory leak

### 3. Thành phần tĩnh (Static Members)
- Thuộc về **lớp** (không phải đối tượng) — dùng chung cho tất cả đối tượng
- **Khai báo**: từ khóa `static` bên trong lớp
- **Khởi tạo**: bắt buộc bên ngoài lớp
- **Truy xuất**: `TênLớp::thanhPhan` (không cần đối tượng)

### 4. Class Template
- Tham số hóa kiểu dữ liệu cho thuộc tính và phương thức
- Dùng `template <class T>` trước khai báo lớp
- Khi sử dụng: chỉ định kiểu cụ thể `Mang<int>`, `Mang<PhanSo>`

## Code examples / Syntax quan trọng

### Constructor — các loại
```cpp
class PhanSo {
private:
    int m_tu;
    int m_mau;
public:
    PhanSo();                     // Constructor mặc định
    PhanSo(const PhanSo &p);      // Copy constructor
    PhanSo(int tu, int mau);      // Constructor đầy đủ thông tin
};

// Cách sử dụng
void main() {
    PhanSo p1(1, 2);              // Gọi constructor đầy đủ thông tin
    PhanSo p2(5);                 // Gọi constructor với 1 tham số (nếu có)
    PhanSo p3(p1);                // Copy constructor — sao chép p1
    PhanSo p4 = p1;               // Cũng gọi copy constructor
    PhanSo *p5 = new PhanSo(2, 3); // Trên heap
}
```

### Destructor
```cpp
class HocSinh {
private:
    char *m_hoTen;    // Con trỏ — cấp phát động
    float m_diemVan;
public:
    ~HocSinh() {
        delete[] m_hoTen;  // Thu hồi bộ nhớ
    }
};

void main() {
    HocSinh hs;             // Destructor tự gọi khi hs ra khỏi scope
    HocSinh *p = new HocSinh;
    delete p;               // Destructor gọi tường minh
}
```

### Static Members
```cpp
class PhanSo {
private:
    static int m_giaTriLN;   // Thuộc tính static
public:
    static int layGiaTriLN(); // Phương thức static
};

// Khởi tạo NGOÀI lớp (bắt buộc)
int PhanSo::m_giaTriLN = 10000;

void main() {
    // Truy xuất qua tên lớp, không cần đối tượng
    int x = PhanSo::layGiaTriLN();
}
```

### Class Template
```cpp
template <class T>
class Mang {
private:
    int m_kichThuoc;
    T *m_duLieu;        // Mảng kiểu T tổng quát
public:
    Mang(int kichThuoc);
    T& layPhanTu(int i);
    T timMax();
};

void main() {
    Mang<int> m1(10);
    int a = m1.layPhanTu(5);
    int max1 = m1.timMax();

    Mang<PhanSo> m2(5);
    PhanSo p = m2.layPhanTu(2);
}
```

## Điểm hay thi / Lưu ý
- **Memory leak**: nếu lớp có `int *m_data = new int[n]` trong constructor nhưng KHÔNG có destructor → rò rỉ bộ nhớ khi đối tượng bị hủy
- **Compiler cấp constructor mặc định**: chỉ khi lớp KHÔNG khai báo constructor nào. Nếu đã khai báo constructor có tham số → compiler KHÔNG cấp mặc định nữa!
- **Copy constructor vs toán tử gán**: `PhanSo p2(p1)` → copy constructor; `p2 = p1` → toán tử gán (khác nhau!)
- Static thuộc tính **phải khởi tạo bên ngoài lớp** — đây là lỗi phổ biến hay quên
- Class Template: cài đặt phải đặt cùng file với khai báo (không tách .cpp như class thường)
- **Đếm số đối tượng**: dùng static member là cách cổ điển — tăng trong constructor, giảm trong destructor

## Thuật ngữ
- **Constructor** (Phương thức khởi tạo): "khai sinh" cho đối tượng
- **Destructor** (Phương thức hủy): "di chúc" — dọn dẹp trước khi đối tượng biến mất
- **Default constructor**: constructor không tham số
- **Copy constructor**: constructor nhận đối tượng cùng lớp làm tham số
- **Static member**: thành phần tĩnh — thuộc về lớp, dùng chung
- **Memory leak** (Rò rỉ bộ nhớ): bộ nhớ cấp phát không được thu hồi
- **Class Template**: lớp tham số hóa kiểu
