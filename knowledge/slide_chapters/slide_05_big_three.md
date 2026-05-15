# Luật Ba Ông Lớn và Tính Đóng Gói — OOP Slide 05
> Nguồn: raw/slides/OOP-05-The Law Of The Big Three.pptx
> Ngôn ngữ: C++

## Tóm tắt nội dung chính
Slide 05 trình bày ba vấn đề nguy hiểm xảy ra khi lớp có thuộc tính con trỏ cấp phát động: phương thức hủy mặc định không thu hồi bộ nhớ, copy constructor mặc định chia sẻ vùng nhớ, và toán tử gán mặc định gây rò rỉ và mất bộ nhớ. Từ đó đề xuất "Luật Ba Ông Lớn". Phần hai trình bày tính đóng gói (encapsulation) và nguyên tắc "Tell, Don't Ask".

## Các khái niệm core

### 1. Ba phương thức mặc định của lớp
Khi không khai báo, trình biên dịch tự cấp:
1. **Destructor mặc định**: không làm gì với con trỏ → rò rỉ bộ nhớ
2. **Copy constructor mặc định**: sao chép giá trị từng thuộc tính (shallow copy) → hai đối tượng dùng chung vùng nhớ
3. **Toán tử gán mặc định**: sao chép giá trị từng thuộc tính → rò rỉ + mất bộ nhớ

### 2. Luật Ba Ông Lớn (Law of the Big Three)
> **Khi lớp có thuộc tính con trỏ được cấp phát động (dùng `new`), PHẢI cài đặt tường minh:**
> 1. **Destructor** — thu hồi bộ nhớ
> 2. **Copy constructor** — deep copy (sao chép bộ nhớ, không chia sẻ con trỏ)
> 3. **Toán tử gán `=`** — hủy bộ nhớ cũ, deep copy bộ nhớ mới

### 3. Tính đóng gói (Encapsulation)
- **Quy tắc hộp đen**: thuộc tính `private`, phương thức `public`
- **Tell, Don't Ask**: đừng lấy dữ liệu từ đối tượng rồi tự xử lý — hãy nhờ đối tượng làm giùm
- Đối tượng **nắm giữ** thông tin → **chịu trách nhiệm** xử lý thông tin đó

## Code examples / Syntax quan trọng

### Vấn đề với hủy mặc định
```cpp
class Array {
private:
    int m_size;
    int *m_data;       // Con trỏ cấp phát động
public:
    Array(int size) {
        m_size = size;
        m_data = new int[m_size];  // Cấp phát
    }
    // THIẾU destructor → m_data KHÔNG được thu hồi → memory leak!
};
```

### Destructor đúng
```cpp
Array::~Array() {
    delete[] m_data;   // Thu hồi mảng động
}
```

### Vấn đề với copy constructor mặc định (shallow copy)
```cpp
void main() {
    Array a1(5);
    Array a2(a1);  // Mặc định: a2.m_data = a1.m_data (cùng địa chỉ!)
    // Khi hủy a1 → delete[] a1.m_data
    // Khi hủy a2 → delete[] a2.m_data (địa chỉ đã bị xóa → crash!)
}
```

### Copy constructor đúng (deep copy)
```cpp
Array::Array(const Array &a) {
    m_size = a.m_size;
    m_data = new int[m_size];            // Cấp phát vùng nhớ MỚI
    for (int i = 0; i < m_size; i++)
        m_data[i] = a.m_data[i];         // Sao chép dữ liệu
}
```

### Vấn đề với toán tử gán mặc định
```cpp
void main() {
    Array a1(5);
    Array a2(6);
    a2 = a1;
    // Mặc định: a2.m_data = a1.m_data → a2 mất con trỏ cũ (rò rỉ) + dùng chung (nguy hiểm)
}
```

### Toán tử gán đúng
```cpp
Array& Array::operator=(const Array &a) {
    if (this == &a) return *this;   // Kiểm tra tự gán: a = a

    delete[] m_data;                // Hủy bộ nhớ CŨ
    m_size = a.m_size;
    m_data = new int[m_size];       // Cấp phát BỘ NHỚ MỚI
    for (int i = 0; i < m_size; i++)
        m_data[i] = a.m_data[i];
    return *this;                   // Trả về tham chiếu để hỗ trợ a = b = c
}
```

### Tổng hợp: Lớp có luật Ba Ông Lớn
```cpp
class HocSinh {
private:
    char *m_hoTen;   // Con trỏ → bắt buộc có Ba Ông Lớn
public:
    HocSinh(const HocSinh &h);        // Copy constructor
    ~HocSinh();                        // Destructor
    HocSinh& operator=(const HocSinh &h);  // Toán tử gán
};
```

### Tell, Don't Ask — Ví dụ
```cpp
// SAI — "Ask" (lấy dữ liệu rồi tự xử lý bên ngoài)
float dtb = (hs.layDiemVan() + hs.layDiemToan()) / 2.0;

// ĐÚNG — "Tell" (nhờ đối tượng tự làm)
class HocSinh {
private:
    float m_diemVan;
    float m_diemToan;
public:
    float tinhDTB();   // Đối tượng tự tính
    int xepLoai();     // Đối tượng tự xếp loại
};
float dtb = hs.tinhDTB();
```

## Điểm hay thi / Lưu ý
- **Kiểm tra tự gán** (`if (this == &a)`) trong `operator=` — điểm hay bị quên
- **Thứ tự trong `operator=`**: delete cũ → cấp phát mới → sao chép. Không làm ngược!
- **Copy constructor vs toán tử gán**: `Array a2(a1)` → copy constructor; `a2 = a1` (cả hai đã tồn tại) → toán tử gán
- Lớp KHÔNG có con trỏ động (chỉ có `int`, `float`, `string`...) → các phương thức mặc định là an toàn
- **Tell, Don't Ask** là nguyên tắc thiết kế — thường ra câu hỏi về thiết kế lớp tốt
- Getter/setter cũng vi phạm đóng gói nếu chỉ để lộ dữ liệu raw mà không có xử lý gì thêm

## Thuật ngữ
- **Law of the Big Three** (Luật Ba Ông Lớn): khi có con trỏ động → phải có destructor + copy constructor + operator=
- **Shallow copy**: sao chép nông — sao chép địa chỉ con trỏ (nguy hiểm)
- **Deep copy**: sao chép sâu — sao chép toàn bộ vùng nhớ được trỏ đến (an toàn)
- **Memory leak** (Rò rỉ bộ nhớ): cấp phát mà không thu hồi
- **Dangling pointer**: con trỏ trỏ đến vùng nhớ đã bị giải phóng
- **Encapsulation** (Tính đóng gói): ẩn dữ liệu, chỉ lộ interface
- **Tell, Don't Ask**: nguyên tắc nhờ đối tượng làm thay vì lấy dữ liệu về tự làm
