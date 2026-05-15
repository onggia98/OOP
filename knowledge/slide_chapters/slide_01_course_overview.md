# Giới Thiệu Môn Học — OOP Slide 01
> Nguồn: raw/slides/OOP-01-Course Overview.pptx
> Ngôn ngữ: C++

## Tóm tắt nội dung chính
Slide 01 giới thiệu ba chủ đề nền tảng trước khi vào OOP: chuẩn và quy ước lập trình, nạp chồng hàm (function overloading), và lập trình tổng quát (generic programming). Ba kỹ thuật tổng quát hóa được trình bày: tham số hóa dữ liệu, tham số hóa kiểu (function template), và tham số hóa xử lý (con trỏ hàm).

## Các khái niệm core

### 1. Chuẩn và quy ước lập trình
Không có chuẩn chung duy nhất — phụ thuộc ngôn ngữ, doanh nghiệp, cộng đồng. Mục đích: tạo kỷ luật, phối hợp nhóm hiệu quả.
- **Naming convention**: đặt tên có nghĩa, ngắn gọn
- **Statement convention**: rõ ràng, rộng rãi (indentation)
- **Comment convention**: đầy đủ, dễ hiểu

### 2. Nạp chồng hàm (Function Overloading)
Chữ ký hàm (Function Signature) = **tên hàm** + **danh sách tham số** (KHÔNG bao gồm kiểu trả về).
Nhiều hàm cùng tên nhưng khác tham số — hợp lệ.

**Ví dụ không hợp lệ:**
- Hai hàm cùng tên, cùng tham số nhưng khác kiểu trả về → **SAI**
- Hai hàm cùng tên, tham số chỉ khác tên biến → **SAI**

### 3. Lập trình tổng quát (Generic Programming)
Ba mức độ tham số hóa:

| Loại | Cách làm | Ứng dụng |
|------|----------|----------|
| Tham số hóa dữ liệu | Truyền tham số thông thường | Tổng quát giá trị |
| Tham số hóa kiểu | Function Template | Tổng quát kiểu dữ liệu |
| Tham số hóa xử lý | Con trỏ hàm | Tổng quát thuật toán |

## Code examples / Syntax quan trọng

### Function Overloading
```cpp
double sapXep(int danhSach[], int kichThuoc);
double sapXep(float danhSach[], int kichThuoc); // Hợp lệ — khác kiểu tham số
```

### Function Template (Tham số hóa kiểu)
```cpp
template <class T>   // T là tham số kiểu, có thể dùng "typename" thay "class"
T tinhToan(T x, T y) {
    return x + y;
}

void main() {
    int x = tinhToan(3, 5);           // T = int
    double y = tinhToan(4.2, 6.3);    // T = double
    PhanSo p3 = tinhToan(p1, p2);     // T = PhanSo
}
```

### Con trỏ hàm (Tham số hóa xử lý)
```cpp
// B1: Tạo kiểu hàm
typedef int (*PhepTinh)(int, int);

// B2: Hàm tổng quát nhận hàm làm tham số
int tinhToan(int x, int y, PhepTinh p) {
    return p(x, y);
}

// B3: Hàm xử lý cụ thể
int cong(int x, int y) { return x + y; }
int nhan(int x, int y) { return x * y; }

// B4: Gọi hàm, truyền hàm cụ thể
tinhToan(3, 5, cong);
tinhToan(4, 6, nhan);
```

### Dùng con trỏ hàm trực tiếp (không typedef)
```cpp
int tinhToan(int x, int y, int (*p)(int, int));
```

## Điểm hay thi / Lưu ý
- **Giá trị trả về KHÔNG thuộc chữ ký hàm** — điểm dễ nhầm khi xác định nạp chồng hợp lệ
- Template: phần khai báo và cài đặt hàm **phải cùng file** với phần gọi hàm — không tách ra file .cpp riêng như hàm thường
- Khi dùng function template kết hợp con trỏ hàm → phải dùng con trỏ hàm trực tiếp, không dùng typedef
- Phân biệt: `template <class T>` và `template <typename T>` — **tương đương nhau**

## Thuật ngữ
- **Function Signature**: chữ ký hàm = tên + tham số
- **Function Overloading**: nạp chồng hàm — nhiều hàm cùng tên
- **Function Template**: khuôn hàm tổng quát cho nhiều kiểu dữ liệu
- **Function Pointer**: con trỏ hàm — hàm làm tham số của hàm khác
- **Generic Programming**: lập trình tổng quát — write once, use everywhere
