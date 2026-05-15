# Tổng Quan Lập Trình Hướng Đối Tượng — OOP Slide 02
> Nguồn: raw/slides/OOP-02-Introduction to Object Oriented Programming.pptx
> Ngôn ngữ: C++

## Tóm tắt nội dung chính
Slide 02 giới thiệu sự chuyển dịch tư duy từ lập trình hướng thủ tục sang hướng đối tượng. Trình bày các khái niệm nền tảng: đối tượng, lớp, thuộc tính, phương thức, tầm vực (public/private/protected) và toán tử `::`. So sánh cú pháp khai báo lớp với cấu trúc (struct) trong C++.

## Các khái niệm core

### 1. Hướng thủ tục vs. Hướng đối tượng
| Tiêu chí | Hướng thủ tục | Hướng đối tượng |
|----------|--------------|-----------------|
| Trung tâm | Hành động (Verb) | Dữ liệu (Object) |
| Cách tổ chức | Hàm + Dữ liệu | Dữ liệu thực hiện hàm |
| Cú pháp | `ướp(Thịt)` | `Thịt.ướp()` |

### 2. Đối tượng (Object)
- "Chi tiết" mới trong lập trình — vừa chứa **dữ liệu** vừa chứa **xử lý**
- **Thuộc tính (attribute)**: dữ liệu của đối tượng
- **Phương thức (method)**: xử lý của đối tượng

### 3. Lớp (Class)
- Là **kiểu** / **bản mô tả** của đối tượng (như `int` với biến số nguyên)
- Khai báo bằng từ khóa `class`
- Một lớp → có thể tạo nhiều đối tượng (instances)

### 4. Tầm vực (Scope / Access Modifier)
| Từ khóa | Phạm vi | Truy xuất |
|---------|---------|-----------|
| `private` | Hẹp nhất | Chỉ bên trong lớp |
| `protected` | Vừa | Bên trong lớp + lớp kế thừa |
| `public` | Rộng nhất | Bên trong và ngoài lớp |

**Quy tắc hộp đen (Dr. Guru):** Thuộc tính → `private`; Phương thức → `public`

### 5. Toán tử `::` (Scope Resolution Operator)
Dùng gọi tên thành phần của lớp từ bên ngoài lớp.
Cú pháp: `<Tên lớp>::<Tên thành phần>`

## Code examples / Syntax quan trọng

### Khai báo lớp (file .h)
```cpp
class PhanSo {
private:
    int m_tuSo;    // Thuộc tính private
    int m_mauSo;
public:
    PhanSo cong(PhanSo p);   // Phương thức public
    PhanSo rutGon();
};
```

### Cài đặt phương thức (file .cpp)
```cpp
// Cài đặt bên ngoài lớp dùng toán tử ::
PhanSo PhanSo::cong(PhanSo p) {
    // Cài đặt cộng phân số...
}

// Hoặc cài đặt bên trong lớp (inline)
class PhanSo {
public:
    PhanSo cong(PhanSo p) {
        // Cài đặt trực tiếp trong khai báo
    }
};
```

### Sử dụng đối tượng
```cpp
void main() {
    PhanSo p1;        // Khai báo đối tượng
    PhanSo p2;
    p1.cong(p2);      // Gọi phương thức qua dấu "."

    PhanSo *p3 = new PhanSo;
    p3->cong(p2);     // Gọi qua con trỏ dùng "->"
}
```

### Ví dụ tầm vực
```cpp
class A {
private:
    int x;    // private
public:
    int y;    // public
    int getX();
private:
    void calculate();
};

void main() {
    A obj;
    int x = obj.x;      // Sai — truy xuất private
    int y = obj.y;      // Đúng — public
    int t = obj.getX(); // Đúng — phương thức public
    obj.calculate();    // Sai — phương thức private
}
```

## Điểm hay thi / Lưu ý
- **Khác biệt giữa struct và class trong C++**: struct mặc định `public`, class mặc định `private`
- `protected` chưa được giảng trong slide này (dành cho phần kế thừa)
- Khi truy xuất qua con trỏ dùng `->`, khi truy xuất qua đối tượng dùng `.`
- **Quy tắc hộp đen**: luôn đặt thuộc tính là `private` và phương thức là `public` — đây là nền tảng của tính đóng gói
- Toán tử `::` còn dùng để phân biệt thành phần của hai lớp khác nhau có cùng tên

## Thuật ngữ
- **Class** (Lớp): kiểu / bản mô tả đối tượng
- **Object** (Đối tượng): thực thể cụ thể được tạo từ lớp (instance)
- **Attribute** (Thuộc tính): dữ liệu thành phần của đối tượng
- **Method** (Phương thức): hàm thành phần của đối tượng
- **Scope** (Tầm vực): phạm vi hoạt động của thành phần
- **Scope Resolution Operator** (`::`): toán tử phân giải tầm vực
- **Encapsulation** (Đóng gói): ẩn dữ liệu trong lớp
