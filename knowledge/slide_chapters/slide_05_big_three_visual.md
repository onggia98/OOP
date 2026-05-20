# Slide 05 — Vấn đề con trỏ & Tính đóng gói (The Law of the Big Three)
**Giảng viên:** GV. Nguyễn Minh Huy  
**Môn:** Phương pháp lập trình hướng đối tượng  

---

## Trang 1 — Trang bìa

**Tiêu đề:** Vấn đề con trỏ, Tính đóng gói

Slide bìa của chương 05, trình bày hai chủ đề chính:
1. Vấn đề con trỏ (The Law of the Big Three)
2. Tính đóng gói (Encapsulation)

---

## Trang 2 — Nội dung tổng quan

**Tiêu đề:** Nội dung

Hai chủ đề chính của slide:
- Vấn đề con trỏ.
- Tính đóng gói.

---

## Trang 3 — Nội dung (chuyển phần)

**Tiêu đề:** Nội dung

Phần đang học được highlight:
- **Vấn đề con trỏ.** (đang học)
- Tính đóng gói.

---

## Trang 4 — Vấn đề con trỏ: Các phương thức mặc định

**Tiêu đề:** Vấn đề con trỏ

### Các phương thức mặc định trong lớp:
- Được trình biên dịch cung cấp khi không khai báo.
- Ba phương thức mặc định:
  - Phương thức hủy mặc định.
  - Phương thức khởi tạo sao chép mặc định.
  - Toán tử gán mặc định.

**💻 Code:**
```cpp
class PhanSo
{
private:
    int m_tu;
    int m_mau;
public:
    PhanSo(int tu, int mau);
};

void main()
{
    PhanSo p1(1, 3);
    // Mặc định có phương thức khởi tạo sao chép.
    PhanSo p2(p1);

    // Mặc định có toán tử gán.
    p1 = p2;
}
```

**Ghi chú:** Class `PhanSo` chỉ có thuộc tính kiểu `int` (không có con trỏ/cấp phát động) nên ba phương thức mặc định hoạt động đúng — sao chép giá trị từng thuộc tính là đủ.

---

## Trang 5 — Ví dụ 1: Class Array với con trỏ

**Tiêu đề:** Vấn đề con trỏ — Ví dụ 1

### Vấn đề: Class có thuộc tính con trỏ (cấp phát động trên heap)

**💻 Code:**
```cpp
class Array
{
private:
    int  m_size;
    int  *m_data;
public:
    Array(int size);
};

Array::Array(int size)
{
    m_size = size;
    m_data = new int[m_size];
}

void main()
{
    Array a1(5);
    ...
}
```

**Phân tích:** Constructor cấp phát `m_data` trên heap với `new int[m_size]`. Khi `a1` ra khỏi scope, nếu không có destructor tường minh thì vùng nhớ trên heap **không được thu hồi** → rò rỉ bộ nhớ.

---

## Trang 6 — Vấn đề hủy mặc định: Rò rỉ bộ nhớ

**Tiêu đề:** Vấn đề con trỏ — Vấn đề hủy mặc định

### Nguyên nhân:
- Lớp có thuộc tính con trỏ (có cấp phát bộ nhớ).
- Phương thức hủy mặc định **không thu hồi bộ nhớ!!**

**📊 Diagram — Memory Layout (Rò rỉ bộ nhớ):**

```
┌─────────────────────┐
│     a1: Array       │         Heap
│                     │    ┌───┬───┬───┬───┬───┐
│  m_size  │  5       │    │ 1 │ 2 │ 3 │ 4 │ 5 │
│  m_data  │  101  ───┼───►│   │   │   │   │   │
│          │          │    └───┴───┴───┴───┴───┘
└─────────────────────┘        addr: 101
         Stack
```

- `a1` nằm trên **stack**, chứa `m_size = 5` và `m_data = 101` (địa chỉ trên heap).
- Khi `a1` bị hủy (ra khỏi scope), destructor mặc định chỉ hủy phần stack.
- **Vùng nhớ heap (địa chỉ 101, chứa mảng 5 phần tử) KHÔNG được giải phóng!**
- Kết quả: **Rò rỉ bộ nhớ (memory leak)!!**

**Kết luận:** Phải cài đặt TƯỜNG MINH phương thức hủy để dọn dẹp!!

---

## Trang 7 — Giải pháp: Destructor tường minh

**Tiêu đề:** Vấn đề con trỏ — Ví dụ 1 (với destructor)

**💻 Code:**
```cpp
class Array
{
private:
    int  m_size;
    int  *m_data;
public:
    Array(int size);
    ~Array();       // Khai báo destructor
};

Array::~Array()
{
    delete []m_data;    // Thu hồi mảng động trên heap
}

void main()
{
    Array a1(5);
    ...
}   // ~Array() tự động gọi khi a1 ra khỏi scope
```

**Giải thích:**
- `~Array()` được compiler tự động gọi khi đối tượng ra khỏi scope.
- `delete []m_data` giải phóng toàn bộ mảng đã cấp phát bằng `new int[]`.
- Phải dùng `delete []` (có `[]`) vì cấp phát bằng `new[]`.

---

## Trang 8 — Ví dụ 2: Vấn đề sao chép mặc định

**Tiêu đề:** Vấn đề con trỏ — Ví dụ 2

### Kịch bản: Tạo đối tượng bằng copy constructor mặc định

**💻 Code:**
```cpp
class Array
{
private:
    int  m_size;
    int  *m_data;
public:
    Array(int size);
    ~Array();
};

void main()
{
    Array a1(5);
    Array a2(a1);   // Gọi copy constructor MẶC ĐỊNH
    ...
}
```

**Vấn đề:** Copy constructor mặc định sao chép giá trị từng thuộc tính — bao gồm cả con trỏ `m_data`. Kết quả: `a1.m_data` và `a2.m_data` cùng trỏ đến một vùng nhớ heap → **shallow copy (sao chép nông)**.

---

## Trang 9 — Diagram: Vấn đề sao chép nông (Shallow Copy)

**Tiêu đề:** Vấn đề con trỏ — Vấn đề sao chép mặc định

**📊 Diagram — Shallow Copy (Dùng chung bộ nhớ + Mất bộ nhớ):**

```
┌─────────────────────┐                    ┌─────────────────────┐
│     a1: Array       │                    │     a2: Array       │
│                     │    Heap            │                     │
│  m_size  │  5       │  ┌───┬───┬───┬───┬───┐  m_size  │  ?   │
│  m_data  │  101  ───┼─►│ 1 │ 2 │ 3 │ 4 │ 5 │◄─── m_data │   │
└─────────────────────┘  └───┴───┴───┴───┴───┘  └─────────────────┘
         Stack              addr: 101                  Stack
              ↑                                            ↑
       "Dùng chung bộ nhớ!!"                    "Mất bộ nhớ!!"
```

**Hai vấn đề nghiêm trọng:**
1. **Dùng chung bộ nhớ:** `a1.m_data == a2.m_data` → sửa `a2` sẽ ảnh hưởng `a1`.
2. **Mất bộ nhớ (dangling pointer):** Khi `a2` bị hủy trước, `delete []m_data` giải phóng vùng heap → `a1.m_data` trở thành **dangling pointer** (con trỏ trỏ đến vùng nhớ đã giải phóng). Khi `a1` bị hủy, `delete` lần 2 vào vùng nhớ đã free → **undefined behavior / crash**.

**Kết luận:** Phải cài đặt TƯỜNG MINH phương thức khởi tạo sao chép!!

---

## Trang 10 — Giải pháp: Copy Constructor tường minh (Deep Copy)

**Tiêu đề:** Vấn đề con trỏ — Ví dụ 2 (với copy constructor)

**💻 Code:**
```cpp
class Array
{
private:
    int  m_size;
    int  *m_data;
public:
    Array(int size);
    Array(const Array &a);  // Copy constructor tường minh
    ~Array();
};

Array::Array(const Array &a)
{
    m_size = a.m_size;
    m_data = new int[m_size];           // Cấp phát vùng nhớ MỚI
    for (int i = 0; i < m_size; i++)
        m_data[i] = a.m_data[i];        // Sao chép từng phần tử
}

void main()
{
    Array a1(5);
    Array a2(a1);   // Gọi copy constructor TƯỜNG MINH → deep copy
    ...
}
```

**Deep Copy vs Shallow Copy:**
- **Shallow copy (mặc định):** Sao chép địa chỉ con trỏ → hai đối tượng dùng chung heap.
- **Deep copy (tường minh):** Cấp phát vùng nhớ mới, sao chép từng phần tử → hai đối tượng độc lập.

---

## Trang 11 — Ví dụ 3: Vấn đề toán tử gán mặc định

**Tiêu đề:** Vấn đề con trỏ — Ví dụ 3

### Kịch bản: Gán giữa hai đối tượng đã tồn tại

**💻 Code:**
```cpp
class Array
{
private:
    int  m_size;
    int  *m_data;
public:
    Array(int size);
    Array(const Array &a);
    ~Array();
};

void main()
{
    Array a1(5);
    Array a2(6);    // a2 đã có vùng nhớ riêng (6 phần tử)
    ...
    a2 = a1;        // Toán tử gán MẶC ĐỊNH
    ...
}
```

**Vấn đề:** Toán tử gán mặc định sao chép từng thuộc tính — `a2.m_data` bị ghi đè bằng `a1.m_data` (shallow copy). Kết quả tương tự trang 9: dùng chung bộ nhớ + rò rỉ bộ nhớ của `a2` cũ.

---

## Trang 12 — Diagram: Vấn đề gán mặc định

**Tiêu đề:** Vấn đề con trỏ — Vấn đề gán mặc định

**📊 Diagram — Assignment Operator mặc định (3 vấn đề cùng lúc):**

```
Trước khi a2 = a1:

┌──────────────┐        Heap (101)        ┌──────────────┐        Heap (405)
│  a1: Array   │   ┌───┬───┬───┬───┬───┐  │  a2: Array   │   ┌───┬───┬───┬───┬───┬───┐
│  m_size=5    │   │ 1 │ 2 │ 3 │ 4 │ 5 │  │  m_size=6    │   │...│...│...│...│...│...│
│  m_data=101 ─┼──►│   │   │   │   │   │  │  m_data=405 ─┼──►│   │   │   │   │   │   │
└──────────────┘   └───┴───┴───┴───┴───┘  └──────────────┘   └───┴───┴───┴───┴───┴───┘

Sau khi a2 = a1 (shallow copy mặc định):

                         ↑                                              ↑
                "Dùng chung bộ nhớ!!"          "Rò rỉ bộ nhớ!!"   "Mất bộ nhớ!!"
┌──────────────┐        Heap (101)        ┌──────────────┐
│  a1: Array   │   ┌───┬───┬───┬───┬───┐  │  a2: Array   │
│  m_size=5    │   │ 1 │ 2 │ 3 │ 4 │ 5 │  │  m_size=5    │
│  m_data=101 ─┼──►│   │   │   │   │   │◄─┼─ m_data=101  │
└──────────────┘   └───┴───┴───┴───┴───┘  └──────────────┘
                                                    Vùng 405 (6 phần tử) bị orphan → LEAK!
```

**Ba vấn đề:**
1. **Dùng chung bộ nhớ:** a1, a2 cùng trỏ heap(101).
2. **Rò rỉ bộ nhớ:** Vùng heap(405) của a2 cũ không ai quản lý → leak.
3. **Mất bộ nhớ:** Khi một trong hai bị hủy, vùng heap(101) bị free → đối tượng còn lại có dangling pointer.

**Kết luận:** Phải cài đặt TƯỜNG MINH toán tử gán!!

---

## Trang 13 — Giải pháp: Toán tử gán tường minh

**Tiêu đề:** Vấn đề con trỏ — Ví dụ 2 (toán tử gán)

**💻 Code:**
```cpp
class Array
{
private:
    int  m_size;
    int  *m_data;
public:
    Array(int size);
    Array(const Array &a);
    ~Array();
    Array & operator =(const Array &a); // Toán tử gán tường minh
};

Array & Array::operator =(const Array &a)
{
    delete []m_data;                    // 1. Hủy vùng nhớ cũ
    m_size = a.m_size;
    m_data = new int[m_size];           // 2. Cấp phát vùng nhớ mới
    for (int i = 0; i < m_size; i++)
        m_data[i] = a.m_data[i];        // 3. Sao chép từng phần tử
    return *this;                       // 4. Trả về *this để hỗ trợ chuỗi gán (a=b=c)
}

void main()
{
    Array a1(5);
    Array a2(6);
    ...
    a2 = a1;    // Gọi operator= tường minh
    ...
}
```

**Lưu ý quan trọng về self-assignment:** Code trên chưa xử lý trường hợp `a = a` (tự gán) — `delete []m_data` sẽ xóa dữ liệu trước khi sao chép. Phiên bản an toàn cần thêm kiểm tra: `if (this != &a)`.

---

## Trang 14 — Luật "Ba Ông Lớn" (The Law of the Big Three)

**Tiêu đề:** Vấn đề con trỏ — Dr. Guru khuyên: luật "ba ông lớn"

### Quy tắc vàng:
> **Lớp có thuộc tính con trỏ (có cấp phát bộ nhớ) → Phải cài đặt TƯỜNG MINH:**
> 1. Phương thức hủy: thu hồi bộ nhớ.
> 2. Phương thức khởi tạo sao chép: sao chép bộ nhớ (deep copy).
> 3. Toán tử gán: hủy bộ nhớ cũ, sao chép bộ nhớ mới.

**💻 Code — Ví dụ áp dụng Big Three cho class HocSinh:**
```cpp
class HocSinh
{
private:
    char  *m_hoTen;     // Con trỏ → BẮT BUỘC cài Big Three
public:
    HocSinh(const HocSinh &h);              // Copy constructor
    ~HocSinh();                             // Destructor
    HocSinh & operator =(const HocSinh &h); // Assignment operator
};
```

**Tóm tắt "Ba Ông Lớn":**

| Phương thức | Tên | Khi nào được gọi |
|---|---|---|
| Destructor | `~ClassName()` | Đối tượng ra khỏi scope / `delete` |
| Copy Constructor | `ClassName(const ClassName &)` | `ClassName b(a)` hoặc `ClassName b = a` (khởi tạo) |
| Assignment Operator | `operator=(const ClassName &)` | `b = a` (sau khi cả hai đã tồn tại) |

---

## Trang 15 — Chuyển sang phần Tính đóng gói

**Tiêu đề:** Nội dung

- Vấn đề con trỏ. (đã học xong)
- **Tính đóng gói.** (bắt đầu học)

---

## Trang 16 — Tính đóng gói: Quy tắc hộp đen

**Tiêu đề:** Tính đóng gói — Quy tắc hộp đen (rule of blackbox)

### Nguyên tắc:
- **Thuộc tính: `private`** để hạn chế truy xuất từ bên ngoài.
- **Phương thức: `public`** để cung cấp tính năng cho bên ngoài sử dụng.

**📊 Diagram — Mô hình hộp đen (Blackbox):**

```
        ┌──────────────────────────────┐
        │   Tính năng (Phương thức)    │  ← public (lớp ngoài xanh lá)
        │   ┌──────────────────────┐   │
        │   │   Dữ liệu (Thuộc tính)│  │  ← private (vòng trong cam)
        │   └──────────────────────┘   │
        └──────────────────────────────┘
```

Biểu đồ tròn đồng tâm: vòng trong (màu cam) = **Dữ liệu (Thuộc tính)** — private, vòng ngoài (màu xanh lá) = **Tính năng (Phương thức)** — public. Bên ngoài chỉ tiếp cận được tính năng, không trực tiếp chạm dữ liệu.

**💻 Code:**
```cpp
class HocSinh
{
private:
    char*  m_hoTen;
    float  m_diemVan;
    float  m_diemToan;
};
```

---

## Trang 17 — Tính đóng gói: Quy tắc hộp đen vs. Nhu cầu truy xuất

**Tiêu đề:** Tính đóng gói — Quy tắc hộp đen vs. Nhu cầu truy xuất

### Vấn đề: Khi cần truy xuất thuộc tính từ bên ngoài, có hai phương án — **cả hai đều vi phạm quy tắc hộp đen!**

**Phương án 1 (SAI): Đặt thuộc tính `public`**
```cpp
class HocSinh
{
public:             // Vi phạm! Dữ liệu bị lộ hoàn toàn
    char*  m_hoTen;
    float  m_diemVan;
    float  m_diemToan;
};
```

**Phương án 2 (CŨNG SAI): Cung cấp getter truy xuất trực tiếp**
```cpp
class HocSinh
{
private:
    char*  m_hoTen;
    float  m_diemVan;
    float  m_diemToan;
public:
    float  layDiemVan();    // Vẫn vi phạm! Để bên ngoài "hỏi" dữ liệu
    float  layDiemToan();   // và tự xử lý là trái với tinh thần đóng gói
};
```

**Nguyên tắc:** Cả hai đều vi phạm vì chúng để bên ngoài truy xuất dữ liệu và tự xử lý → trái với quy tắc "Tell, Don't Ask".

---

## Trang 18 — Tính đóng gói: Làm sao tuân thủ quy tắc hộp đen?

**Tiêu đề:** Tính đóng gói — Làm sao tuân thủ quy tắc hộp đen?

### Nguyên tắc đúng:
> **Cần xử lý gì thì đưa cho đối tượng thực hiện.**

Thay vì lấy dữ liệu ra rồi tính toán bên ngoài, hãy giao luôn việc tính toán cho đối tượng.

**💻 Code — Đúng tinh thần đóng gói:**
```cpp
class HocSinh
{
private:
    char*  m_hoTen;
    float  m_diemVan;
    float  m_diemToan;
public:
    float tinhDTB();    // Đối tượng tự tính điểm trung bình
    int   xepLoai();    // Đối tượng tự xếp loại
};

void main()
{
    HocSinh hs;

    // Cần tính điểm trung bình? → Trang bị cho học sinh tính.
    float dtb = hs.tinhDTB();

    // Cần xếp loại? → Trang bị cho học sinh xếp.
    int loai = hs.xepLoai();
}
```

---

## Trang 19 — Tính đóng gói: Quy tắc "Tell, Don't Ask"

**Tiêu đề:** Tính đóng gói — Dr. Guru khuyên: quy tắc "Tell, Don't Ask"

### Nguyên tắc "Tell, Don't Ask":
- **Thông tin đối tượng** → Không thể truy xuất từ bên ngoài.
- **Đối tượng nắm giữ thông tin** → Chịu trách nhiệm xử lý thông tin.
- **"Đừng hỏi tôi thông tin"** → **"Hãy nhờ tôi làm giùm!!"**
- **Đã giao thông tin** → Giao luôn xử lý thông tin.

### So sánh:

| Cách sai ("Ask") | Cách đúng ("Tell") |
|---|---|
| Lấy dữ liệu ra, tự tính bên ngoài | Nhờ đối tượng tính và trả kết quả |
| `float dv = hs.layDiemVan(); float dt = hs.layDiemToan(); float dtb = (dv+dt)/2;` | `float dtb = hs.tinhDTB();` |
| Vi phạm đóng gói | Tuân thủ đóng gói |

---

## Trang 20 — Luyện tập: Áp dụng tính đóng gói

**Tiêu đề:** Tính đóng gói — Luyện tập

### Bài tập 1: Tính trọng tâm tam giác

**💻 Code:**
```cpp
class Diem
{
private:
    float  m_X;
    float  m_Y;
};

class TamGiac
{
private:
    Diem  m_A;
    Diem  m_B;
    Diem  m_C;
};
// Câu hỏi: Tính trọng tâm tam giác??
// → Phương thức tinhTrongTam() nên đặt trong TamGiac
```

### Bài tập 2: Xuất danh sách học sinh giỏi (ĐTB >= 8.0)

**💻 Code:**
```cpp
class HocSinh
{
private:
    char   *m_hoTen;
    float  m_diemVan;
    float  m_diemToan;
};

class BangDiem
{
private:
    vector<HocSinh>  m_danhSach;
};
// Câu hỏi: Xuất danh sách học sinh giỏi??
// → Phương thức xuatHocSinhGioi() nên đặt trong BangDiem
```

**Hướng giải:** Theo quy tắc "Tell, Don't Ask" + đóng gói:
- `HocSinh` cần có phương thức `tinhDTB()` và `isGioi()` (hoặc `xepLoai()`).
- `BangDiem` cần có phương thức `xuatHocSinhGioi()` — duyệt `m_danhSach`, nhờ từng `HocSinh` tự kiểm tra.

---

## Tóm tắt toàn chương

### Phần 1: Vấn đề con trỏ — Luật Ba Ông Lớn (Law of the Big Three)

| Vấn đề | Phương thức mặc định | Hậu quả | Giải pháp |
|---|---|---|---|
| Destructor | Không thu hồi heap | Memory leak (rò rỉ bộ nhớ) | `~Array() { delete []m_data; }` |
| Copy constructor | Shallow copy (sao chép địa chỉ) | Dùng chung heap + dangling pointer | `Array(const Array &a)` → deep copy |
| Assignment operator | Shallow copy + không hủy cũ | Leak + dùng chung + dangling | `operator=` → delete cũ + deep copy |

**Quy tắc:** Nếu lớp cần destructor → hầu như chắc chắn cần cả copy constructor lẫn assignment operator.

### Phần 2: Tính đóng gói (Encapsulation)

| Nguyên tắc | Nội dung |
|---|---|
| Quy tắc hộp đen | Thuộc tính `private`, phương thức `public` |
| Tell, Don't Ask | Nhờ đối tượng xử lý, không lấy dữ liệu ra xử lý ngoài |
| Thiết kế đúng | Đặt phương thức vào lớp sở hữu dữ liệu liên quan |

### Các lỗi phổ biến cần tránh:
1. **Quên destructor** khi lớp có `new` → memory leak.
2. **Dùng copy constructor mặc định** khi lớp có con trỏ → shallow copy → dangling pointer.
3. **Dùng assignment operator mặc định** khi lớp có con trỏ → shallow copy + leak.
4. **Double delete** (delete cùng vùng nhớ 2 lần) → undefined behavior / crash.
5. **Quên `delete []`** (phải có `[]` khi xóa mảng cấp phát bằng `new[]`).
6. **Không kiểm tra self-assignment** trong `operator=` → `delete` chính mình rồi copy.
