# Slide 03 — Vòng đời đối tượng (Object Life Cycle)
**Giảng viên:** Nguyễn Minh Huy | **Môn:** Phương pháp lập trình hướng đối tượng

---

## Trang 1 — Trang bìa

Tiêu đề: **Vòng đời đối tượng**
Giảng viên: GV. Nguyễn Minh Huy

---

## Trang 2 — Nội dung tổng quan

Bốn chủ đề chính của slide:
- Phương thức khởi tạo.
- Phương thức hủy.
- Thành phần tĩnh.
- Class Template.

---

## Trang 3 — Nội dung (animation — giống trang 2, highlight mục 1)

Trang animation highlight **Phương thức khởi tạo** (chữ in đậm vàng). Nội dung giống trang 2.

*(Trang animation — ghi 1 lần, không lặp)*

---

## Trang 4 — Phương thức khởi tạo: Vấn đề khởi tạo thông tin đối tượng

**Vấn đề:** Khi khai báo đối tượng, giá trị ban đầu của các thuộc tính chưa được xác định nếu không có cơ chế khởi tạo.

**Cách tiếp cận 1 — Không khởi tạo:** Giá trị `p.m_tu` và `p.m_mau` là rác (undefined behavior).

**Cách tiếp cận 2 — Dùng setter thủ công:** Người dùng có thể quên gọi hàm `ganTu()` / `ganMau()` dẫn đến lỗi logic.

**📊 Diagram:** Hai vấn đề song song — bên trái là class thiếu constructor (giá trị rác), bên phải là class dùng getter/setter nhưng có cảnh báo "Người dùng quên gọi?!" → dẫn đến nhu cầu constructor tự động.

**💻 Code:**
```cpp
// Cách 1: Không khởi tạo — giá trị rác
class PhanSo
{
private:
    int m_tu;
    int m_mau;
};

void main()
{
    PhanSo p;
    // Giá trị của p??
}

// Cách 2: Dùng setter — người dùng có thể quên gọi
class PhanSo
{
public:
    void ganTu(int tu);
    void ganMau(int mau);
};

void main()
{
    PhanSo p;
    p.ganTu(1);
    p.ganMau(3);
}
```

---

## Trang 5 — Phương thức khởi tạo: Tính chất

**Tính chất phương thức khởi tạo (Constructor):**
- "Làm khai sinh" cho đối tượng — gán giá trị ban đầu cho các thuộc tính.
- **Tự động gọi** khi khai báo đối tượng (stack hoặc heap).
- **Có thể nạp chồng** (overload) nhiều phương thức khởi tạo.
- **Không có giá trị trả về** (kể cả `void`).
- **Có tên trùng tên lớp** (trong C++).

**📊 Diagram:** Minh họa 3 cách khai báo đối tượng — stack (`PhanSo p1(1, 2)`), stack với 1 tham số (`PhanSo p2(5)`), và heap (`PhanSo *p3 = new PhanSo(2, 3)`). Cả ba đều tự động gọi constructor tương ứng.

**💻 Code:**
```cpp
class PhanSo
{
private:
    int m_tu;
    int m_mau;
public:
    PhanSo(int tu, int mau);
    PhanSo(int giaTri);
};

void main()
{
    PhanSo p1(1, 2);
    PhanSo p2(5);
    PhanSo *p3 = new PhanSo(2, 3);
}
```

---

## Trang 6 — Phương thức khởi tạo mặc định (Default Constructor)

**Phương thức khởi tạo mặc định:**
- "Làm khai sinh" mặc định — không cần tham số.
- **Không có tham số.**
- Nếu lớp không có bất kỳ constructor nào: trình biên dịch **tự tạo** một constructor mặc định rỗng.
- Nếu lớp đã có ít nhất 1 constructor nhưng **không có** default constructor, và người dùng cố khai báo đối tượng không tham số → **lỗi biên dịch**.

**📊 Diagram:** Vòng đời object trên stack:
```
[Khai báo PhanSo p] → [Compiler gọi PhanSo()] → [Object tồn tại trên stack] → [Hết scope → destructor]
```
Trên heap:
```
[new PhanSo] → [Cấp phát bộ nhớ heap] → [Gọi PhanSo()] → [Con trỏ trỏ tới object]
```

**💻 Code:**
```cpp
class PhanSo
{
private:
    int m_tu;
    int m_mau;
public:
    PhanSo();
};

void main()
{
    PhanSo p;
    PhanSo *q = new PhanSo;
}
```

---

## Trang 7 — Phương thức khởi tạo sao chép (Copy Constructor)

**Phương thức khởi tạo sao chép:**
- "Làm khai sinh" bằng cách sao chép từ đối tượng khác cùng lớp.
- **Tham số là đối tượng cùng lớp** (truyền bằng const reference).
- Nếu lớp không có copy constructor: trình biên dịch **tự tạo** một copy constructor (shallow copy — chỉ sao chép byte-by-byte, nguy hiểm khi có con trỏ).

**📊 Diagram:** Hai object trên stack — `p1` được tạo bằng constructor thường, `p2` được tạo bằng copy constructor từ `p1`, `p3` được gán bằng toán tử `=` từ `p2`.

Shallow copy vs Deep copy:
```
Shallow copy: p2.m_tu ---> cùng vùng nhớ <--- p1.m_tu  [NGUY HIỂM nếu là con trỏ]
Deep copy:    p2.m_tu ---> vùng nhớ riêng (copy nội dung)
```

**💻 Code:**
```cpp
class PhanSo
{
private:
    int m_tu;
    int m_mau;
public:
    PhanSo(const PhanSo &p);
};

void main()
{
    PhanSo p1(1, 2);
    // Sao chép p1...
    PhanSo p2(p1);
    // Sao chép p2...
    PhanSo p3 = p2;
}
```

---

## Trang 8 — Dr. Guru khuyên: 3 Constructor tối thiểu

**Dr. Guru khuyên:** Một lớp nên có **tối thiểu 3 phương thức khởi tạo:**
1. Khởi tạo mặc định (default constructor).
2. Khởi tạo sao chép (copy constructor).
3. Khởi tạo với đầy đủ thông tin (parameterized constructor).

**📊 Diagram:** Class template chuẩn với 3 constructor:
```
+------------------+
|    PhanSo        |
+------------------+
| - m_tu: int      |
| - m_mau: int     |
+------------------+
| + PhanSo()                    ← Default
| + PhanSo(const PhanSo &p)     ← Copy
| + PhanSo(int tu, int mau)     ← Parameterized
+------------------+
```

**💻 Code:**
```cpp
class PhanSo
{
private:
    int m_tu;
    int m_mau;
public:
    PhanSo();
    PhanSo(const PhanSo &p);
    PhanSo(int tu, int mau);
};
```

---

## Trang 9 — Nội dung (animation — highlight mục 2: Phương thức hủy)

Trang animation highlight **Phương thức hủy** (chữ in đậm vàng).

*(Trang animation — ghi 1 lần, không lặp)*

---

## Trang 10 — Phương thức hủy: Vấn đề rò rỉ bộ nhớ (Memory Leak)

**Vấn đề rò rỉ bộ nhớ (Memory Leak):**
Bộ nhớ được cấp phát động cho con trỏ thành viên **không tự thu hồi** khi đối tượng bị hủy.

**Cách tiếp cận thủ công:** Tạo hàm `thuHoiBoNho()` — nhưng người dùng vẫn có thể quên gọi → vẫn rò rỉ bộ nhớ.

**📊 Diagram:** Memory leak timeline:
```
STACK                   HEAP
[hs object]  ──────►  [m_hoTen: "Nguyen Van A"]
    |
[hết scope]
    |
[hs bị hủy]  ──────►  [m_hoTen: "Nguyen Van A"]  ← VẪN CÒN TRONG HEAP! LEAK!
```

**💻 Code:**
```cpp
// Vấn đề: bộ nhớ không được thu hồi
class HocSinh
{
private:
    char *m_hoTen;
};

void main()
{
    HocSinh hs;
}
// hs.m_hoTen được thu hồi? → KHÔNG!

// Giải pháp thủ công (vẫn có thể quên gọi):
class HocSinh
{
private:
    char *m_hoTen;
public:
    void thuHoiBoNho() {
        delete [ ]m_hoTen;
    }
};

void main()
{
    HocSinh hs;
    hs.thuHoiBoNho();
}
```

---

## Trang 11 — Phương thức hủy: Tính chất (Destructor)

**Tính chất phương thức hủy (Destructor):**
- "Làm di chúc" cho đối tượng — dọn dẹp tài nguyên trước khi object biến mất.
- **Tự động gọi** khi đối tượng bị hủy (hết scope trên stack, hoặc `delete` trên heap).
- **Duy nhất** cho mỗi lớp — không thể nạp chồng, không có tham số.
- Có tên **`~<Tên lớp>`** (trong C++).

**📊 Diagram — Vòng đời đầy đủ của một object:**
```
STACK OBJECT:
[khai báo HocSinh hs] → [Constructor chạy: cấp phát m_hoTen trên heap]
        ↓
[... sử dụng hs ...]
        ↓
[hết scope] → [Destructor ~HocSinh() tự động chạy: delete []m_hoTen]
        ↓
[m_hoTen trên heap được giải phóng] ✓

HEAP OBJECT:
[new HocSinh] → [Constructor chạy]
        ↓
[... sử dụng *p ...]
        ↓
[delete p] → [Destructor ~HocSinh() chạy: delete []m_hoTen]
        ↓
[m_hoTen trên heap được giải phóng] ✓
```

**💻 Code:**
```cpp
class HocSinh
{
private:
    char  *m_hoTen;
    float  m_diemVan;
    float  m_diemToan;
public:
    ~HocSinh() { delete [ ]m_hoTen; }
};

void main()
{
    HocSinh hs;
    HocSinh *p = new HocSinh;
    delete p;
    // p->m_hoTen được hủy.
    // hs.m_hoTen được hủy (khi hết scope).
}
```

---

## Trang 12 — Nội dung (animation — highlight mục 3: Thành phần tĩnh)

Trang animation highlight **Thành phần tĩnh** (chữ in đậm vàng).

*(Trang animation — ghi 1 lần, không lặp)*

---

## Trang 13 — Thành phần tĩnh: Khái niệm chia sẻ dữ liệu

**Chia sẻ giữa các đối tượng cùng lớp:**

- Mỗi đối tượng có **bản sao riêng** của:
  - Thuộc tính (instance variables).
  - Phương thức (instance methods, nhưng code dùng chung — chỉ data riêng).
  - → Gọi là **thành phần của đối tượng** (object members).

- Khi muốn **dùng chung thông tin** giữa tất cả đối tượng:
  - → Dùng **thành phần tĩnh** (static members).

**📊 Diagram — Object member vs Static member:**
```
         [Class PhanSo]
         ┌─────────────┐
         │  Tử số      │   ← định nghĩa thuộc tính
         │  Mẫu số     │
         │  Rút gọn()  │
         └─────────────┘
                │ (mỗi object có bản sao riêng)
        ┌───────┴────────┐
        ▼                ▼
[p1: PhanSo]       [p2: PhanSo]
 Tử số: 1           Tử số: 1
 Mẫu số: 2          Mẫu số: 3
 Rút gọn()          Rút gọn()
```
Static member nằm ở một vùng nhớ duy nhất, tất cả object cùng trỏ đến.

---

## Trang 14 — Thành phần tĩnh: Tính chất và cách dùng trong C++

**Tính chất thành phần tĩnh:**
- Thuộc phạm vi **lớp** (class scope), không phải đối tượng.
- **Dùng chung** cho mọi đối tượng của lớp.
- Cách sử dụng trong C++:
  - **Khai báo:** từ khóa `static` bên trong lớp.
  - **Khởi tạo:** bên ngoài lớp (bắt buộc).
  - **Truy xuất:** dùng `TênLớp::thanhPhanTinh` (toán tử `::` — scope resolution).

**📊 Diagram — Bộ nhớ static member:**
```
STACK                  STATIC AREA (Data Segment)
[p1: PhanSo] ─────►  [PhanSo::m_giaTriLN = 10000]  ◄─── [p2: PhanSo]
[p2: PhanSo] ─────►  (cùng vùng nhớ, không copy)        [p3: PhanSo]

Truy xuất:  PhanSo::layGiaTriLN()   ← dùng tên lớp, không cần object
```

**💻 Code:**
```cpp
class PhanSo
{
private:
    static int m_giaTriLN;
public:
    static int layGiaTriLN();
};

// Khởi tạo bên ngoài lớp (bắt buộc)
int PhanSo::m_giaTriLN = 10000;

void main()
{
    int x = PhanSo::layGiaTriLN();
}
```

---

## Trang 15 — Nội dung (animation — highlight mục 4: Class Template)

Trang animation highlight **Class Template** (chữ in đậm vàng).

*(Trang animation — ghi 1 lần, không lặp)*

---

## Trang 16 — Class Template: Động lực

**Xét lớp mảng:**
- Nếu các phần tử là số nguyên → code cụ thể cho `int`.
- Nếu muốn **tổng quát**: các phần tử có thể là kiểu bất kỳ (`int`, `float`, `PhanSo`, ...).
  - Giải pháp: **tham số hóa** thuộc tính và phương thức theo kiểu dữ liệu.
  - Cơ chế: **Class Template** (lớp mẫu).

**📊 Diagram — Motivation:**
```
Mang<int>    → m_duLieu: int*     → layPhanTu() trả int
Mang<float>  → m_duLieu: float*   → layPhanTu() trả float
Mang<PhanSo> → m_duLieu: PhanSo*  → layPhanTu() trả PhanSo

Cùng 1 template → compiler sinh ra code riêng cho từng kiểu
```

---

## Trang 17 — Class Template: Cách sử dụng

**Cách sử dụng Class Template trong C++:**
- Khai báo với `template <class T>` trước class.
- `T` là **type parameter** — thay thế cho kiểu dữ liệu bất kỳ.
- Sử dụng: `TênLớp<KiểuDữLiệu>` khi khai báo đối tượng.

**📊 Diagram — Template instantiation:**
```
template<class T>
class Mang { T* m_duLieu; ... }
        │
        ├── Mang<int>    → compiler tạo: int* m_duLieu; int& layPhanTu(int i); int timMax();
        └── Mang<PhanSo> → compiler tạo: PhanSo* m_duLieu; PhanSo& layPhanTu(int i); PhanSo timMax();
```

**💻 Code:**
```cpp
template <class T>
class Mang
{
private:
    int  m_kichThuoc;
    T   *m_duLieu;
public:
    Mang( int kichThuoc );
    T&  layPhanTu( int i );
    T   timMax( );
};

void main()
{
    Mang<int>    m1( 10 );
    int  a    = m1.layPhanTu(5);
    int  max1 = m1.timMax( );

    Mang<PhanSo> m2( 5 );
    PhanSo p    = m2.layPhanTu( 2 );
    PhanSo max2 = m2.timMax( );
}
```

---

## Trang 18 — Tóm tắt (phần 1): Constructor và Destructor

**Tóm tắt — Phương thức khởi tạo:**
- "Làm khai sinh" cho đối tượng.
- Bắt buộc gọi khi khai báo (tự động).
- Có thể nạp chồng (nhiều constructor).

**Tóm tắt — Phương thức hủy:**
- "Làm di chúc" cho đối tượng.
- Tự động gọi khi hủy.
- Có duy nhất một destructor.

---

## Trang 19 — Tóm tắt (phần 2): Static Members và Class Template

**Tóm tắt — Thành phần tĩnh:**
- Dùng chung cho đối tượng của lớp.
- Cách dùng (C++):
  - Khai báo bằng từ khóa `"static"`.
  - Khởi tạo bên ngoài lớp.
  - Truy xuất bằng toán tử `::`.

**Tóm tắt — Class Template:**
- Tham số hóa kiểu thuộc tính, phương thức.
- Lưu trữ và xử lý tổng quát trong lớp.

---

## Trang 20 — Bài tập 3.1: Lớp PhanSo

**Bài tập 3.1:**
Trang bị cho lớp **phân số** những cách khởi tạo sau:
- Khởi tạo mặc định: phân số = 0 (tử = 0, mẫu = 1).
- Khởi tạo với tử và mẫu cho trước.
- Khởi tạo từ giá trị nguyên cho trước (mẫu = 1).
- Khởi tạo từ một phân số khác (copy constructor).

**📊 Diagram — Kết quả cần cài đặt:**
```cpp
class PhanSo {
public:
    PhanSo();                        // 0/1
    PhanSo(int tu, int mau);         // tu/mau
    PhanSo(int giaTri);              // giaTri/1
    PhanSo(const PhanSo &p);         // copy
};
```

---

## Trang 21 — Bài tập 3.2: Lớp HocSinh

**Bài tập 3.2:**
Trang bị cho lớp **học sinh** những cách khởi tạo và hủy sau:
- Khởi tạo với họ tên và điểm văn, toán cho trước.
- Khởi tạo với họ tên cho trước, điểm văn và toán = 0.
- Khởi tạo từ một học sinh khác (copy constructor — deep copy vì `m_hoTen` là con trỏ).
- Hủy đối tượng học sinh, thu hồi bộ nhớ (destructor: `delete []m_hoTen`).

**📊 Diagram — Deep copy constructor:**
```
STACK                   HEAP
[hs1]  m_hoTen ──────► ["Nguyen Van A"] (vùng nhớ A)
[hs2]  m_hoTen ──────► ["Nguyen Van A"] (vùng nhớ B — bản sao riêng)
                                          ↑ Deep copy: cấp phát mới + strcpy
```

---

## Trang 22 — Bài tập 3.3: Lớp Mảng số nguyên

**Bài tập 3.3:**
Trang bị cho lớp **mảng** số nguyên những cách khởi tạo và hủy sau:
- Khởi tạo mặc định: mảng kích thước = 0.
- Khởi tạo với kích thước cho trước, các phần tử = 0.
- Khởi tạo từ một mảng `int[]` với kích thước cho trước.
- Khởi tạo từ một đối tượng mảng khác (copy constructor — deep copy).
- Hủy đối tượng mảng, thu hồi bộ nhớ (destructor: `delete []m_duLieu`).

**📊 Diagram — Constructor chain cho lớp Mang:**
```cpp
class Mang {
    int  m_kichThuoc;
    int *m_duLieu;       // ← cấp phát động → cần destructor
public:
    Mang();                          // m_kichThuoc=0, m_duLieu=nullptr
    Mang(int n);                     // new int[n], fill 0
    Mang(int arr[], int n);          // new int[n], memcpy
    Mang(const Mang &m);             // deep copy
    ~Mang();                         // delete []m_duLieu
};
```

---

## Trang 23 — Bài tập 3.4: Lớp Mảng tổng quát (Class Template)

**Bài tập 3.4:**
Làm lại bài 3.3 với lớp **mảng** có phần tử thuộc **một kiểu bất kỳ** (dùng Class Template).

Tức là chuyển lớp `Mang` từ bài 3.3 (phần tử `int`) thành `Mang<T>` (phần tử kiểu `T` bất kỳ).

**📊 Diagram — Từ Mang (int) sang Mang<T>:**
```
Bài 3.3:                        Bài 3.4:
class Mang {              →     template <class T>
    int *m_duLieu;              class Mang {
    Mang(int arr[], int n);         T *m_duLieu;
    int& layPhanTu(int i);          Mang(T arr[], int n);
};                                  T& layPhanTu(int i);
                                };
```

---

## Trang 24 — Bài tập 3.5 (*): Static member nâng cao

**Bài tập 3.5 (*):** *(Bài khó, đánh dấu sao)*
Trang bị cho lớp **phân số** những phương thức sau:
- **Đếm** tổng số lượng phân số được tạo ra trong hàm `main()`.
- **Hạn chế** số lượng phân số được tạo ra là N.

**📊 Diagram — Dùng static member để đếm/giới hạn:**
```
class PhanSo {
    static int s_soLuong;     // đếm tổng số object đang tồn tại
    static int s_gioiHan;     // N tối đa
public:
    PhanSo() {
        if (s_soLuong >= s_gioiHan) { /* báo lỗi / throw */ }
        s_soLuong++;
    }
    ~PhanSo() {
        s_soLuong--;           // giảm khi object bị hủy
    }
};

int PhanSo::s_soLuong = 0;
int PhanSo::s_gioiHan = N;
```

Gọi là **Object counting pattern** — dùng static member để theo dõi lifecycle toàn lớp.

---

## Phụ lục — Sơ đồ tổng hợp Vòng đời đối tượng

### Lifecycle đầy đủ trên Stack vs Heap

```
=== STACK OBJECT ===
{                                       ← vào scope
    PhanSo p(1, 2);                     ← Constructor PhanSo(int, int) được gọi
    // ... sử dụng p ...
}                                       ← hết scope → Destructor ~PhanSo() tự gọi

=== HEAP OBJECT ===
PhanSo *p = new PhanSo(1, 2);          ← new: cấp phát heap + gọi Constructor
// ... sử dụng *p ...
delete p;                               ← delete: gọi Destructor + giải phóng heap
p = nullptr;                            ← tránh dangling pointer
```

### Thứ tự gọi Constructor / Destructor (nhiều object)

```
{
    PhanSo a(1, 2);   // Constructor a
    PhanSo b(3, 4);   // Constructor b
    PhanSo c(5, 6);   // Constructor c
}
// Destructor c → b → a  (LIFO — ngược thứ tự khai báo)
```

### Memory Layout — Static Member

```
┌───────────────────────────────────────┐
│          MEMORY MAP                   │
├──────────────┬────────────────────────┤
│ Code Segment │ code của các hàm       │
├──────────────┼────────────────────────┤
│ Data Segment │ PhanSo::m_giaTriLN     │ ← static member (1 bản duy nhất)
│ (Static)     │ PhanSo::s_soLuong      │
├──────────────┼────────────────────────┤
│ Heap         │ m_hoTen (new char[])   │ ← cấp phát động, phải delete
├──────────────┼────────────────────────┤
│ Stack        │ PhanSo p1              │ ← local object, tự hủy khi hết scope
│              │ PhanSo p2              │
│              │ HocSinh hs             │
└──────────────┴────────────────────────┘
```

### Bảng so sánh Constructor / Destructor

| Đặc điểm | Constructor | Destructor |
|---|---|---|
| Mục đích | "Khai sinh" — khởi tạo | "Di chúc" — dọn dẹp |
| Gọi khi | Tạo object | Hủy object |
| Tên | Trùng tên lớp | `~TênLớp` |
| Số lượng | Nhiều (nạp chồng) | Duy nhất 1 |
| Tham số | Có thể có | Không có |
| Giá trị trả về | Không có | Không có |
| Tự động gọi | Có | Có |
