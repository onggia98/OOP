# Slide 08 — Vòng đời đối tượng trong kế thừa
**GV. Nguyễn Minh Huy | Phương pháp lập trình hướng đối tượng**

---

## Trang 1 — Trang bìa

**Vòng đời đối tượng trong kế thừa**
GV. Nguyễn Minh Huy — Phương pháp lập trình hướng đối tượng.

---

## Trang 2 — Nội dung tổng quan

Ba chủ đề chính của chương:
- Khởi tạo trong kế thừa.
- Hủy trong kế thừa.
- Vấn đề con trỏ trong kế thừa.

---

## Trang 3 — Nội dung (animation: highlight mục 1)

*(Trang animation — nội dung giống trang 2, mục "Khởi tạo trong kế thừa" được highlight vàng. Ghi nhận một lần.)*

---

## Trang 4 — Khởi tạo trong kế thừa: Nguyên lý

Trình tự tạo lập đối tượng kế thừa:
- Nhà được xây từ móng đến mái.
- Khái niệm được định nghĩa từ thấp đến cao.
- Đối tượng kế thừa được tạo lập từ "lõi" đến "vỏ".
- **→ Thành phần cơ sở được tạo trước.**

**📊 Diagram:** Ba hình minh họa song song:
1. Hình nhà: "Xây móng đến mái" — móng xây trước, mái xây sau.
2. Hình các lớp xếp chồng (tam giác định nghĩa): "Định nghĩa thấp đến cao" — lớp dưới (rộng/nền) được định nghĩa trước.
3. Hộp lồng nhau (nested box): "Tạo lập từ lõi đến vỏ":
   ```
   ┌─────────────────────────┐
   │    Đối tượng kế thừa    │
   │  ┌───────────────────┐  │
   │  │ Đối tượng cơ sở   │  │
   │  │  Thành phần cơ sở │  │
   │  └───────────────────┘  │
   │  Thành phần mới         │
   └─────────────────────────┘
   ```
   Thành phần cơ sở (lõi đỏ) được tạo trước → Thành phần mới (vỏ xanh) được tạo sau.

---

## Trang 5 — Khởi tạo trong kế thừa: Thứ tự & Cú pháp

Thứ tự khởi tạo ở đối tượng kế thừa:
- **Phương thức khởi tạo lớp cơ sở được gọi trước** → Khởi tạo phần lõi cơ sở.
- **Phương thức khởi tạo lớp kế thừa gọi sau** → Khởi tạo phần vỏ mới.
- Lớp kế thừa có thể **lựa chọn** cách tạo phần lõi:
  - **→ Chỉ định phương thức khởi tạo lớp cơ sở** (dùng initializer list).
  - **→ Không chỉ định: khởi tạo mặc định được gọi** (constructor mặc định của lớp cơ sở tự động kích hoạt).

**📊 Diagram — Constructor Call Chain:**
```
Tạo đối tượng lớp Derived
         │
         ▼
[1] Constructor của Base được gọi  ← "lõi" tạo trước
         │
         ▼
[2] Constructor của Derived được gọi ← "vỏ" tạo sau
         │
         ▼
  Đối tượng hoàn chỉnh sẵn sàng
```
Nếu Derived không chỉ định constructor Base trong initializer list → Base() (mặc định) tự động được gọi ở bước [1].

---

## Trang 6 — Khởi tạo trong kế thừa: Ví dụ khai báo lớp

**Ví dụ:**

**💻 Code:**
```cpp
class GiaoVien
{
private:
    char    *m_hoTen;
    float   m_mucLuong;
    int     m_ngayNghi;
public:
    GiaoVien();
    GiaoVien(char *hoTen,
             float mucLuong,
             int ngayNghi);
};

class GVCN : public GiaoVien
{
private:
    char    *m_lopCN;
public:
    GVCN();
    GVCN(char *lopCN);
    GVCN(char *hoTen, float mucLuong,
         int ngayNghi, char *lopCN);
};
```

**📊 Diagram — Memory layout của đối tượng GVCN:**
```
┌────────────────────────────────┐
│         Object GVCN            │
│  ┌──────────────────────────┐  │
│  │   Phần GiaoVien (Base)   │  │
│  │   char  *m_hoTen         │  │
│  │   float  m_mucLuong      │  │
│  │   int    m_ngayNghi      │  │
│  └──────────────────────────┘  │
│   char  *m_lopCN  (phần mới)   │
└────────────────────────────────┘
```
Phần GiaoVien nằm ở địa chỉ thấp hơn trong bộ nhớ; phần GVCN riêng nằm bên dưới.

---

## Trang 7 — Khởi tạo trong kế thừa: Ví dụ cài đặt constructor

**Ví dụ cài đặt constructor GVCN (initializer list gọi constructor GiaoVien):**

**💻 Code:**
```cpp
GVCN::GVCN(char *lopCN) : GiaoVien("Minh", 500000, 0)
{
    m_lopCN = new char[strlen(lopCN) + 1];
    strcpy(m_lopCN, lopCN);
}

GVCN::GVCN(char *hoTen, float mucLuong, int ngayNghi, char *lopCN)
    : GiaoVien(hoTen, mucLuong, ngayNghi)
{
    m_lopCN = new char[strlen(lopCN) + 1];
    strcpy(m_lopCN, lopCN);
}

GVCN::GVCN()   // ← GiaoVien() được gọi trước (tự động)
{
}
```

**📊 Diagram — Constructor call chain với initializer list:**
```
GVCN::GVCN(char *lopCN)
    │
    ├─ [Initializer list]: GiaoVien("Minh", 500000, 0)
    │         │
    │         └─ Chạy body GiaoVien(char*, float, int)
    │                → khởi tạo m_hoTen, m_mucLuong, m_ngayNghi
    │
    └─ [Body GVCN]: m_lopCN = new char[...]; strcpy(...)

GVCN::GVCN()
    │
    ├─ [Không có initializer list] → GiaoVien() tự động gọi
    │         └─ Chạy body GiaoVien() mặc định
    └─ [Body GVCN rỗng]
```
Ghi chú quan trọng: `GVCN::GVCN()` — dù không viết initializer list, `GiaoVien()` vẫn được gọi trước (mặc định).

---

## Trang 8 — Nội dung (animation: highlight mục 2)

*(Trang animation — nội dung giống trang 2, mục "Hủy trong kế thừa" được highlight vàng. Ghi nhận một lần.)*

---

## Trang 9 — Hủy trong kế thừa: Nguyên lý

Trình tự hủy đối tượng kế thừa:
- **Ngược lại với trình tự tạo lập.**
- Phương thức hủy lớp kế thừa được gọi **trước** → Hủy phần vỏ bên ngoài.
- Phương thức hủy lớp cơ sở được gọi **sau** → Hủy phần lõi cơ sở.
- Mỗi lớp chỉ có một cách hủy.
- **→ Lớp kế thừa không cần chỉ định cách hủy lớp cơ sở** (tự động).

**📊 Diagram — Destructor Call Order (ngược với constructor):**
```
Hủy đối tượng lớp Derived
         │
         ▼
[1] ~Derived() được gọi trước  ← hủy "vỏ" bên ngoài
         │
         ▼
[2] ~Base() được gọi sau       ← hủy "lõi" cơ sở (tự động)
         │
         ▼
  Bộ nhớ được giải phóng hoàn toàn

So sánh đối xứng:
  Khởi tạo:  Base() → Derived()   (lõi → vỏ)
  Hủy:      ~Derived() → ~Base()  (vỏ → lõi)
```

Memory layout — chiều hủy ngược chiều xây:
```
┌──────────────────────────────────┐
│ [2] Phần Base bị hủy sau cùng   │  ← ~Base() gọi sau
│  ┌────────────────────────────┐  │
│  │ Phần GiaoVien              │  │
│  └────────────────────────────┘  │
│ [1] Phần Derived bị hủy trước   │  ← ~GVCN() gọi trước
│  m_lopCN được delete            │
└──────────────────────────────────┘
```

---

## Trang 10 — Hủy trong kế thừa: Ví dụ

**Ví dụ:**

**💻 Code:**
```cpp
GiaoVien::~GiaoVien()
{
    delete m_hoTen;
}

GVCN::~GVCN()
{
    delete m_lopCN;
}
```

**📊 Diagram — Thứ tự gọi destructor:**
```
Khi đối tượng GVCN bị hủy:

Bước 1: ~GVCN() được gọi TRƯỚC
        │  delete m_lopCN;   ← giải phóng bộ nhớ phần GVCN
        └──────────────────

Bước 2: ~GiaoVien() được gọi SAU (tự động)
        │  delete m_hoTen;   ← giải phóng bộ nhớ phần GiaoVien
        └──────────────────
```
Lưu ý: `~GVCN()` KHÔNG cần gọi `~GiaoVien()` tường minh — trình biên dịch tự động gọi sau khi body `~GVCN()` hoàn tất.

---

## Trang 11 — Nội dung (animation: highlight mục 3)

*(Trang animation — nội dung giống trang 2, mục "Vấn đề con trỏ trong kế thừa" được highlight vàng. Ghi nhận một lần.)*

---

## Trang 12 — Vấn đề con trỏ trong kế thừa: Luật "ba ông lớn"

**Luật "ba ông lớn" (Rule of Three):**
- Lớp có thuộc tính con trỏ (cấp phát bộ nhớ động):
  - **→ Phải cài đặt tường minh "ba ông lớn":**
    - Phương thức hủy (destructor).
    - Phương thức khởi tạo sao chép (copy constructor).
    - Toán tử gán (operator=).
- **Lớp kế thừa có thuộc tính con trỏ?** → Phải áp dụng luật tương tự.

---

## Trang 13 — Vấn đề con trỏ trong kế thừa: Lời khuyên Dr. Guru

**Dr. Guru khuyên — Luật "ba ông lớn" trong kế thừa:**

Nếu lớp kế thừa có thuộc tính con trỏ (cấp phát bộ nhớ):
- Trang bị "ba ông lớn" cho lớp kế thừa.
- **"Ông lớn" lớp kế thừa kích hoạt "ông lớn" lớp cơ sở.**
  - Copy constructor của Derived gọi copy constructor của Base.
  - operator= của Derived gọi operator= của Base.
  - ~Derived() tự động kích hoạt ~Base() (không cần gọi tường minh).

**📊 Diagram — Chain kích hoạt "ba ông lớn":**
```
Lớp B (kế thừa từ A):

Copy constructor:    B::B(const B &b)   → gọi A::A(b)   (tường minh trong init-list)
operator=:           B::operator=(b)    → gọi A::operator=(b) (tường minh trong body)
Destructor:          B::~B()            → ~A() tự động gọi sau khi ~B() hoàn tất
```

---

## Trang 14 — Vấn đề con trỏ trong kế thừa: Ví dụ đầy đủ

**Ví dụ:**

**💻 Code:**
```cpp
class A
{
public:
    A(const A &a);
    A& operator =(const A &a);
    virtual ~A();
};

class B : public A
{
public:
    B(const B &b);
    B& operator =(const B &b);
    ~B();
};

// Copy constructor của B — kích hoạt copy constructor của A
B::B(const B &b) : A(b)
{
    // Cài đặt khởi tạo sao chép B.
}

// Operator= của B — kích hoạt operator= của A
B& operator =(const B &b)
{
    A::operator =(b);
    // Cài đặt toán tử = cho B.
}

// Destructor của B — tự động gọi ~A()
~B()
{
    // Cài đặt hủy cho B.
}   // → ~A() tự động gọi sau đây
```

**📊 Diagram — "Ba ông lớn" kích hoạt chuỗi trong kế thừa:**
```
                     "Ông lớn" lớp cơ sở (A)
                     ┌─────────────────────────┐
                     │  A(const A &a)          │  ← copy ctor
                     │  A& operator=(const A&) │  ← assign
                     │  virtual ~A()           │  ← destructor
                     └─────────┬───────────────┘
                               │  kế thừa & kích hoạt
                     ┌─────────▼───────────────┐
                     │  B(const B &b): A(b)    │  ← gọi tường minh A(b)
                     │  B& operator=(b):       │  ← gọi A::operator=(b)
                     │    A::operator=(b)      │
                     │  ~B(): ... // ~A() auto │  ← ~A() tự động sau
                     └─────────────────────────┘
                     "Ông lớn" lớp kế thừa (B)

Lưu ý: ~A() khai báo virtual → đảm bảo hủy đúng khi dùng con trỏ Base*
```

---

## Trang 15 — Tóm tắt

**Tóm tắt toàn chương:**

**Khởi tạo trong kế thừa:**
- Khởi tạo từ lõi đến vỏ.
- Tạo lõi: phương thức khởi tạo lớp cơ sở gọi trước.
- Tạo vỏ: phương thức khởi tạo lớp kế thừa gọi sau.
- Có thể chỉ định phương thức khởi tạo lớp cơ sở (initializer list).

**Hủy trong kế thừa:**
- Hủy từ vỏ vào lõi.
- Hủy lõi: phương thức hủy lớp kế thừa (đây là "hủy vỏ" — gọi trước).
- Hủy vỏ: phương thức hủy lớp cơ sở (gọi sau, tự động).

**Luật "ba ông lớn" trong kế thừa.**

**📊 Diagram — Tổng kết thứ tự Constructor vs Destructor:**
```
KHỞI TẠO (từ lõi → vỏ):        HỦY (từ vỏ → lõi):
────────────────────             ───────────────────
1. Base::Base()       ──┐        1. ~Derived()   ──┐
2. Derived::Derived() ──┘        2. ~Base()      ──┘
   (vỏ tạo sau)                     (lõi hủy sau)

→ Đối xứng hoàn toàn: thứ tự hủy = đảo ngược thứ tự khởi tạo
```

---

## Trang 16 — Bài tập 8.1: Thứ tự gọi constructor chuỗi kế thừa

**Bài tập 8.1:**

**💻 Code:**
```cpp
class A
{ public:
    A( int iX ) {   }
};

class B: public A
{ public:
    B( ) {   }
    B( int iX, int iY ): A( iX ) {  }
};

class C: public B
{ public:
    C( ) {   }
    C( int iZ ) {   }
    C( int iX, int iY, int iZ ): B( iX, iY ) {   }
};
```

Cho biết thứ tự gọi khởi tạo với:
- a) `void main() {  C  obj( 1, 2, 3 );  }`
- b) `void main() {  C  obj( 4 );        }`
- c) `void main() {  C  obj;             }`

**📊 Diagram — Phân tích thứ tự gọi:**
```
a) C obj(1, 2, 3):
   C(1,2,3) → B(1,2) trong init-list → A(1) trong init-list
   Thứ tự thực thi: A(1) → B(1,2) → C(1,2,3)

b) C obj(4):
   C(4) → không có init-list → B() tự động
   B() → không có init-list → A() tự động? KHÔNG — A không có ctor mặc định!
   → LỖI BIÊN DỊCH (A chỉ có A(int), không có A())

c) C obj:
   C() → B() → A() — tương tự bài b, cũng LỖI vì A() không tồn tại.
```
*Lưu ý quan trọng cho thi: nếu lớp cơ sở chỉ có constructor có tham số mà lớp kế thừa không chỉ định initializer list → lỗi biên dịch.*

---

## Trang 17 — Bài tập 8.2

**Bài tập 8.2:**

Giải quyết ba vấn đề con trỏ cho lớp `GiaoVien` và `GVCN`.

*(Yêu cầu: cài đặt đủ destructor, copy constructor, operator= cho cả hai lớp GiaoVien và GVCN theo luật "ba ông lớn" trong kế thừa — GVCN kích hoạt "ông lớn" của GiaoVien.)*

---

## Trang 18 — Bài tập 8.3: Copy constructor trong chuỗi kế thừa

**Bài tập 8.3:**

**💻 Code:**
```cpp
class X {  };

class Y: public X
{
public:
    Y( int i ) {   }
};

class Z: public Y
{
public:
    Z( int i ): Y( i++ ) {   }
};
```

Cho biết thứ tự gọi khởi tạo với:
- a) `void main( )  {  Z  obj( 5 );  }`
- b) `void main( )  {  Y  obj1( 6 );  Y  obj2( obj1 );  }`
- c) `void main( )  {  Z  obj1( 7 );  Z  obj2( obj1 );  }`

**📊 Diagram — Phân tích:**
```
a) Z obj(5):
   Z(5) → Y(i++) trong init-list, i=5 → Y(5) được gọi với i=5,
   sau đó i++ → i=6 (nhưng Y nhận 5)
   Y(5) → X() tự động (X có ctor mặc định vì không khai báo ctor nào)
   Thứ tự: X() → Y(5) → Z(5)

b) Y obj1(6); Y obj2(obj1):
   obj1: X() → Y(6)
   obj2: dùng copy constructor → Y(const Y&) — không khai báo → compiler sinh tự động
   Y copy ctor tự động gọi X copy ctor tự động
   Thứ tự: X() → Y(6) | X(copy) → Y(copy)

c) Z obj1(7); Z obj2(obj1):
   obj1: X() → Y(7) → Z(7)
   obj2: Z copy ctor không khai báo → compiler sinh tự động
   Tự động gọi Y copy ctor → X copy ctor
   Thứ tự: X() → Y(7) → Z(7) | X(copy) → Y(copy) → Z(copy)
```

---

## Trang 19 — Bài tập 8.4: Thiết kế cây kế thừa hình học

**Bài tập 8.4:**

Hãy vẽ cây kế thừa cho những lớp đối tượng hình học (có thể phát sinh những lớp cơ sở cần thiết để tái sử dụng hiệu quả):
- Vuông, Tròn, Ellipse, Chữ nhật, Thoi, Bình hành, Thang vuông, Thang cân.
- Tam giác vuông, Tam giác cân, Tam giác vuông cân, Tam giác đều.

**📊 Diagram — Gợi ý cây kế thừa:**
```
                    HinhHoc (base)
                    /            \
           HinhBonCanh         HinhTron
          /    |    \          /       \
     HinhChuNhat  HinhThang  Tron    Ellipse
      /      \     /    \
  Vuong    Thoi  ThangVuong ThangCan
    |
  BinhHanh

                    TamGiac (base)
                   /       |      \
            TGVuong   TGCan    TGDeu
                \      /
              TGVuongCan
```
*(Gợi ý: Bình hành → Chữ nhật → Vuông; Ellipse → Tròn; Tam giác → Tam giác cân → Tam giác đều; Tam giác → Tam giác vuông → Tam giác vuông cân)*

---

## Trang 20 — Bài tập 8.5 (phần mô tả)

**Bài tập 8.5:**

Một rạp chiếu phim có M hàng ghế, mỗi hàng ghế có N ghế.
Giá vé được tính theo vị trí ngồi sao cho càng xa hàng ghế trung tâm (cả trước lẫn sau) thì giá vé càng rẻ, xa hơn một hàng ghế giảm 3,000.

Có 2 loại rạp:
- **Rạp thường**: giá vé ở hàng ghế trung tâm là 80,000.
- **Rạp cao cấp**: giá vé ở hàng ghế trung tâm là 120,000, ngoài ra rạp có khuyến mãi giảm 20% giá vé vào ngày thứ năm hàng tuần.

---

## Trang 21 — Bài tập 8.5 (yêu cầu cài đặt)

**Bài tập 8.5 (tiếp theo):**

Hãy xây dựng lớp `RapThuong` và `RapCaoCap`, cho phép:
- Khởi tạo rạp phim với số lương ghế M x N cho trước.
- Cho biết một vị trí ghế nào đó còn trống không.
- Cho biết giá vé tại một vị trí ghế nào đó.
- Đặt vé tại một vị trí ghế nào đó.
- Tính tổng số tiền vé bán được.

**📊 Diagram — Thiết kế kế thừa RapPhim:**
```
            RapPhim (base)
            ─────────────
            - M hàng, N ghế
            - mảng ghế (bool[][])
            + RapPhim(M, N)
            + ~RapPhim()
            + isTrong(hang, ghe): bool
            + datVe(hang, ghe): void
            + tongTien(): float
            + giaVe(hang, ghe): float  ← virtual (override ở derived)
                  /                \
        RapThuong               RapCaoCap
        ─────────               ─────────
        giaCenter=80,000        giaCenter=120,000
        + giaVe(): float        + giaVe(): float  ← giảm 20% thứ 5
```

---

## Phụ lục: Tổng kết quan trọng cho thi

### 1. Thứ tự constructor/destructor — LUẬT VÀNG

```
Khởi tạo:   Base1() → Base2() → ... → Derived()   [lõi → vỏ]
Hủy:        ~Derived() → ... → ~Base2() → ~Base1() [vỏ → lõi]
Đối xứng hoàn toàn — thứ tự hủy = đảo ngược thứ tự khởi tạo.
```

### 2. Chỉ định constructor cơ sở — cú pháp initializer list

```cpp
Derived::Derived(params) : Base(base_params)
{
    // Thân constructor Derived
}
// Nếu không có ": Base(...)" → Base() mặc định tự động gọi
// Nếu Base không có ctor mặc định → LỖI BIÊN DỊCH
```

### 3. Luật "ba ông lớn" trong kế thừa — chain kích hoạt

| Ông lớn | Cần làm trong lớp Derived |
|---------|--------------------------|
| Copy constructor | `Derived(const Derived &d) : Base(d)` — gọi Base copy ctor trong init-list |
| operator= | `Base::operator=(d);` — gọi tường minh trong body |
| Destructor | `~Derived()` rồi `~Base()` tự động — KHÔNG cần gọi tường minh |

### 4. Memory layout đối tượng kế thừa

```
Địa chỉ thấp hơn:
┌─────────────────────────────┐
│   Phần Base (thành phần cơ sở) │  ← được tạo trước, hủy sau
│   field1, field2, ...       │
├─────────────────────────────┤
│   Phần Derived (thành phần mới)│  ← được tạo sau, hủy trước
│   field_new1, field_new2... │
└─────────────────────────────┘
Địa chỉ cao hơn
```

### 5. Destructor virtual — cần thiết khi dùng con trỏ Base*

```cpp
Base *p = new Derived(...);
delete p;  // Nếu ~Base() KHÔNG virtual → chỉ gọi ~Base(), BỎ SÓT ~Derived()
           // Nếu ~Base() virtual        → gọi ~Derived() rồi ~Base() ✓
```
→ Khi thiết kế lớp cơ sở để kế thừa: **luôn khai báo destructor là `virtual`**.
