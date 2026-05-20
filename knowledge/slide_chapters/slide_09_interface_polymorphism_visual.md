# Slide 09 — Interface và Đa Hình (Visual Edition)
> GV. Nguyễn Minh Huy | Phương pháp Lập trình Hướng đối tượng C++

---

## Trang 1 — Trang bìa
**Tiêu đề:** Interface và Đa hình

Slide mở đầu chương 09. Nền hai tông: phần trên màu xanh nhạt có lưới mờ, phần dưới màu xanh đậm. Tên môn học ở footer: *Phương pháp lập trình hướng đối tượng - GV. Nguyễn Minh Huy*.

---

## Trang 2 — Nội dung (Menu chương)
**Tiêu đề:** Nội dung

Danh sách ba chủ đề chính của chương, mỗi mục có biểu tượng vuông màu vàng:
- Khái niệm interface.
- Hàm ảo và liên kết động.
- Phương thức hủy ảo.

*(Trang menu — không có nội dung mới, đây là trang điều hướng.)*

---

## Trang 3 — Nội dung (animation: highlight mục 1)
**Tiêu đề:** Nội dung

Nội dung giống trang 2, nhưng mục **"Khái niệm interface."** được in đậm và màu vàng nổi bật — cho thấy đây là phần sắp học.

*(Trang animation — chỉ ghi chú điểm khác: mục 1 được highlight.)*

---

## Trang 4 — Khái niệm Interface (phần 1: giao tiếp đối tượng)
**Tiêu đề:** Khái niệm interface

**Nội dung:**
- **Giao tiếp giữa đối tượng và bên ngoài:**
  - Quy tắc hộp đen:
    - Thuộc tính: `private`, hạn chế truy xuất.
    - Phương thức: `public`, cung cấp tính năng.
  - Đối tượng giao tiếp qua phương thức.
  - Phần khai báo `public` → **INTERFACE**.

**📊 Diagram:** Hình vẽ đồng tâm (concentric circles) ở góc dưới phải của slide:
- Vòng trong cùng (màu cam/nâu): nhãn **"Dữ liệu (Thuộc tính)"** — đại diện phần `private`.
- Vòng giữa (màu xanh lá đậm): nhãn **"Tính năng (Phương thức)"** — đại diện phần `public`/interface.
- Vòng ngoài (viền đỏ): ranh giới với bên ngoài.
- Ý nghĩa: dữ liệu nằm sâu bên trong, được bảo vệ; phương thức là lớp vỏ giao tiếp ra ngoài.

---

## Trang 5 — Khái niệm Interface (phần 2: đặc điểm interface)
**Tiêu đề:** Khái niệm interface

**Nội dung:**
- **Đặc điểm Interface:**
  - Là "phần vỏ" của lớp.
    - Lớp = **Interface** + Khai báo private + Cài đặt.
  - Không chứa cài đặt.
  - Giao thức giao tiếp của đối tượng.

**💻 Code:**
```cpp
class PhanSo
{
private:
    int  m_tu;
    int  m_mau;
public:
    PhanSo( int tu, int mau );
    PhanSo rutGon( );
    PhanSo nghichDao( );
};

void xuLy( PhanSo p )
{      // Xử lý trên p…
}

void main()
{
    PhanSo p1( 1, 2 );
    PhanSo p2( 1, 3 );
    xuLy( p1 );
    xuLy( p2 );
}
```

**📊 Diagram:** Callout bubble màu xám/trắng trỏ vào phần khai báo `public` của `PhanSo`, nhãn **"Nhận interface PhanSo"** — minh họa hàm `xuLy` chỉ cần biết interface (phần `public`) của `PhanSo`, không cần biết cài đặt bên trong.

---

## Trang 6 — Khái niệm Interface (phần 3: interface trong kế thừa)
**Tiêu đề:** Khái niệm interface

**Nội dung:**
- **Interface trong kế thừa:**
  - Lớp kế thừa:
    - Thừa hưởng thuộc tính/phương thức từ lớp cơ sở.
    - Thừa hưởng interface của lớp cơ sở.
    - Có cùng giao thức giao tiếp của lớp cơ sở.
  - Tính đa hình trong kế thừa:
    - Hàm nhận đối tượng lớp cơ sở → Cũng nhận đối tượng lớp kế thừa.
    - Con trỏ kiểu lớp cơ sở → Có thể trỏ đến đối tượng lớp kế thừa.

---

## Trang 7 — Khái niệm Interface (phần 4: ví dụ Animal/Cat/Dog)
**Tiêu đề:** Khái niệm interface

**Nội dung:**
- **Interface trong kế thừa** — ví dụ minh họa bằng `Animal`, `Cat`, `Dog`.

**💻 Code:**
```cpp
class Animal
{
public:
    void talk() { cout << "Don't talk"; }
};

class Cat : public Animal
{
public:
    void talk() { cout << "Meo meo"; }
};

class Dog : public Animal
{
public:
    void talk() { cout << "Gau gau"; }
};

void xuLy(Animal p)
{
    p.talk();
}

void main()
{
    Animal a;
    Cat    c;
    Dog    d;
    xuLy(a);
    xuLy(c);
    xuLy(d);

    Animal *p;
    p = &a;
    p = &c;
    p = &d;
}
```

**📊 Diagram:** Hai callout bubble màu xám:
- Bubble 1 (góc trên phải): **"Chấp nhận interface Animal"** — trỏ vào tham số `Animal p` của `xuLy`.
- Bubble 2 (giữa phải): **"Chấp nhận các đối tượng có interface Animal"** — trỏ vào các lời gọi `xuLy(c)`, `xuLy(d)`, cho thấy Cat và Dog đều có interface Animal do kế thừa.

> **Lưu ý quan trọng:** Ở trang này, `talk()` chưa phải `virtual` — đây là liên kết tĩnh. Dù truyền `Cat c` vào `xuLy(Animal p)`, hàm vẫn gọi `Animal::talk()` chứ không phải `Cat::talk()`.

---

## Trang 8 — Nội dung (animation: highlight mục 2)
**Tiêu đề:** Nội dung

Menu chương, mục **"Hàm ảo và liên kết động."** được in đậm và màu vàng — báo hiệu phần tiếp theo.

*(Trang animation chuyển mục — bỏ qua, nội dung giống trang 2.)*

---

## Trang 9 — Hàm ảo và liên kết động (phần 1: vấn đề liên kết tĩnh)
**Tiêu đề:** Hàm ảo và liên kết động

**Nội dung:**
- **Vấn đề liên kết tĩnh trong C++:** Khi dùng hàm thường (không `virtual`), lời gọi hàm bị gắn với cài đặt của kiểu *khai báo* (lúc dịch), không phải kiểu *thực tế* (lúc chạy).

**💻 Code:**
```cpp
class Animal
{
public:
    void talk() { cout << "Don't talk"; }
};

class Cat : public Animal
{
public:
    void talk() { cout << "Meo meo"; }
};

class Dog : public Animal
{
public:
    void talk() { cout << "Gau gau"; }
};

void xuLy(Animal p)
{
    p.talk();    // Luôn gọi Animal::talk()
}

void main()
{
    Cat c;
    Dog d;
    xuLy(c);     // In "Don't talk" (sai!)
    xuLy(d);     // In "Don't talk" (sai!)

    Animal *p;
    p = &c;
    p->talk();   // In "Don't talk" (sai!)
    p = &d;
    p->talk();   // In "Don't talk" (sai!)
}
```

**📊 Diagram:** Hai callout bubble màu xanh đậm:
- Bubble 1 (trên): **"Liên kết cài đặt Animal khi dịch"** — trỏ vào `p.talk()` bên trong `xuLy`.
- Bubble 2 (dưới): **"Liên kết cài đặt Animal khi dịch"** — trỏ vào `p->talk()` trong `main`.
- Ý nghĩa: vì `talk()` không phải `virtual`, trình dịch bind ngay vào `Animal::talk` tại compile-time.

---

## Trang 10 — Hàm ảo và liên kết động (phần 2: khái niệm hàm ảo)
**Tiêu đề:** Hàm ảo và liên kết động

**Nội dung:**
- **Khái niệm hàm ảo:**
  - Hàm bình thường:
    - Lời gọi hàm gắn với cài đặt hàm lúc dịch → **Liên kết tĩnh**.
  - Hàm ảo:
    - Hàm đặc biệt.
    - Lời gọi hàm chỉ gắn với **interface**.
    - Bỏ ngỏ phần cài đặt → **Liên kết động**.
      - Được gắn động vào lúc chạy.
      - Tùy thuộc đối tượng lúc chạy.
  - Trong C++:
    - Khai báo: **`virtual`** `<Chữ ký hàm>;`
    - Chỉ dùng được với **con trỏ đối tượng**.

> **Tóm tắt:** Hàm thường = liên kết tĩnh (compile-time). Hàm `virtual` = liên kết động (runtime), gọi đúng cài đặt của đối tượng thực tế.

---

## Trang 11 — Hàm ảo và liên kết động (phần 3: ví dụ virtual với con trỏ)
**Tiêu đề:** Hàm ảo và liên kết động

**Nội dung:**
- **Liên kết động trong C++** — thêm `virtual` vào `Animal::talk()`.

**💻 Code:**
```cpp
class Animal
{
public:
    virtual void talk() { cout << "Don't talk"; }
};

class Cat : public Animal
{
public:
    void talk() { cout << "Meo meo"; }
};

class Dog : public Animal
{
public:
    void talk() { cout << "Gau gau"; }
};

void xuLy(Animal *p)
{
    p->talk();   // Liên kết động: gọi đúng talk() của đối tượng thực
}

void main()
{
    Cat c;
    Dog d;
    xuLy(&c);    // In "Meo meo"
    xuLy(&d);    // In "Gau gau"

    Animal *p;
    p = &c;
    p->talk();   // In "Meo meo"
    p = &d;
    p->talk();   // In "Gau gau"
}
```

**📊 Diagram:** Hai callout bubble màu xanh đậm:
- Bubble 1 (trên): **"Liên kết interface Animal, Bỏ ngỏ cài đặt"** — trỏ vào `p->talk()` trong `xuLy` (tham số giờ là `Animal *p` — con trỏ).
- Bubble 2 (dưới): **"Liên kết interface Animal, Bỏ ngỏ cài đặt"** — trỏ vào `p->talk()` trong `main`.
- **Điểm mấu chốt:** Phải dùng **con trỏ** (`Animal *p`), không phải giá trị (`Animal p`), thì `virtual` mới có tác dụng.

---

## Trang 12 — Hàm ảo và liên kết động (phần 4: hàm thuần ảo và lớp trừu tượng)
**Tiêu đề:** Hàm ảo và liên kết động

**Nội dung:**
- **Xây dựng interface trong C++:**
  - C++ cài đặt interface bằng **"hàm thuần ảo"**.
  - Đặc điểm "hàm thuần ảo":
    - Hàm ảo, có thêm **`= 0`** ở cuối khai báo.
    - Chỉ có khai báo, không có cài đặt.
    - Là "phần vỏ" để liên kết động.
    - Bỏ ngỏ phần cài đặt cho lớp kế thừa.
  - Lớp có chứa hàm thuần ảo là **lớp trừu tượng**.
  - Không thể tạo đối tượng từ lớp trừu tượng.

**💻 Code:**
```cpp
class Animal
{
public:
    virtual void talk() = 0;   // Hàm thuần ảo, không có cài đặt!!
};
```

**📊 Diagram:** Callout bubble màu xám trỏ vào `virtual void talk() = 0;` với nhãn **"Hàm thuần ảo, không có cài đặt!!"**.

---

## Trang 13 — Hàm ảo và liên kết động (phần 5: ví dụ đầy đủ với hàm thuần ảo)
**Tiêu đề:** Hàm ảo và liên kết động

**Nội dung:**
- **Xây dựng interface trong C++** — ví dụ hoàn chỉnh với `Animal` là lớp trừu tượng.

**💻 Code:**
```cpp
class Animal          // Lớp trừu tượng
{
public:
    virtual void talk() = 0;
};

class Cat : public Animal
{
public:
    void talk() { cout << "Meo meo"; }
};

class Dog : public Animal
{
public:
    void talk() { cout << "Gau gau"; }
};

void xuLy(Animal *p)
{
    p->talk();   // Liên kết interface Animal, Bỏ ngỏ cài đặt
}

void main()
{
    Cat c;
    Dog d;
    xuLy(&c);    // In "Meo meo"
    xuLy(&d);    // In "Gau gau"

    Animal *p;
    p = new Animal;  // Sai — không thể tạo đối tượng lớp trừu tượng!
    p = new Cat;     // Đúng
    p->talk();       // In "Meo meo"
}
```

**📊 Diagram:**
- Callout bubble **"Lớp trừu tượng"** trỏ vào khai báo `class Animal`.
- Callout bubble **"Liên kết interface Animal, Bỏ ngỏ cài đặt"** trỏ vào `p->talk()` trong `xuLy`.
- Dòng `p = new Animal; // Sai` — lỗi biên dịch vì `Animal` là lớp trừu tượng.
- Dòng `p = new Cat; // Đúng` — hợp lệ vì `Cat` cài đặt đầy đủ hàm thuần ảo.

---

## Trang 14 — Hàm ảo và liên kết động (phần 6: ý nghĩa liên kết động)
**Tiêu đề:** Hàm ảo và liên kết động

**Nội dung:**
- **Ý nghĩa của liên kết động:**
  - Giao tiếp thông qua interface.
  - Cài đặt thay đổi động, tùy nhu cầu người dùng.
    - Mã nguồn tổng quát.

**💻 Code — So sánh hai cách tiếp cận:**

Cách dùng liên kết động (tổng quát, không cần thay đổi khi thêm loại mới):
```cpp
void giveATalk( Animal *p )
{
    p->talk( );
}
```

Cách không dùng liên kết động (phải sửa code mỗi khi thêm loại mới):
```cpp
void giveATalk( int type )
{
    if ( type == 0 )
    {
        Cat c;
        c.talk( );
    }
    else if ( type == 1 )
    {
        Dog d;
        d.talk( );
    }
}
```

> **Kết luận:** Liên kết động giúp viết hàm `giveATalk` một lần — khi thêm loại `Bird`, `Fish`... không cần sửa `giveATalk`, chỉ cần tạo lớp mới kế thừa `Animal` và cài đặt `talk()`.

---

## Trang 15 — Nội dung (animation: highlight mục 3)
**Tiêu đề:** Nội dung

Menu chương, mục **"Phương thức hủy ảo."** được in đậm và màu vàng.

*(Trang animation chuyển mục — bỏ qua.)*

---

## Trang 16 — Phương thức hủy ảo (phần 1: ví dụ vấn đề)
**Tiêu đề:** Phương thức hủy ảo

**Nội dung:**
- **Xét ví dụ:** Lớp `GiaoVien` và lớp kế thừa `GVCN` (Giáo viên chủ nhiệm).

**💻 Code:**
```cpp
class GiaoVien
{
private:
    char    *m_hoTen;
public:
    ~GiaoVien() { delete m_hoTen; }
};

class GVCN : public GiaoVien
{
private:
    char    *m_lopCN;
public:
    ~GVCN() { delete m_lopCN; }
};

void main()
{
    GVCN    *p1 = new GVCN;
    delete p1;          // Gọi ~GVCN() rồi ~GiaoVien() — ĐÚNG

    GiaoVien *p2 = new GVCN;
    delete p2;          // Chỉ gọi ~GiaoVien() — SAI! ~GVCN() không được gọi!
}
```

**📊 Diagram:** Hai callout bubble:
- Bubble 1 trỏ vào `delete p1`: **"~GVCN() ~GiaoVien()"** — cả hai hàm hủy được gọi đúng thứ tự.
- Bubble 2 trỏ vào `delete p2`: **"~GiaoVien()"** — chỉ gọi hàm hủy của lớp cơ sở, **rò rỉ bộ nhớ** `m_lopCN`.
- Câu hỏi đặt ra: **"Vì sao thứ tự gọi phương thức hủy khác nhau??"**

> **Giải thích:** `p2` có kiểu tĩnh là `GiaoVien*`, nên khi `delete p2` mà `~GiaoVien()` không phải `virtual`, trình biên dịch bind tĩnh vào `~GiaoVien()`, bỏ qua `~GVCN()` → rò rỉ `m_lopCN`.

---

## Trang 17 — Phương thức hủy ảo (phần 2: giải pháp — virtual destructor)
**Tiêu đề:** Phương thức hủy ảo

**Nội dung:**
- **Dr. Guru khuyên:**
  - **Phương thức hủy của lớp phải luôn là hàm ảo.**
    - Liên kết động đến phương thức hủy lớp kế thừa.

**💻 Code:**
```cpp
class GiaoVien
{
public:
    virtual ~GiaoVien() { delete m_hoTen; }   // Khai báo virtual!
};

class GVCN : public GiaoVien
{
public:
    ~GVCN() { delete m_lopCN; }
};

GiaoVien *p3 = new GVCN;
delete p3;    // ~GVCN() → ~GiaoVien() — ĐÚNG nhờ virtual destructor
```

**📊 Diagram:**
- Callout bubble trỏ vào `delete p3`: **"~GVCN() ~GiaoVien()"** — cả hai hàm hủy được gọi đúng thứ tự.
- Hình minh họa: nhân vật "Dr. Guru" (ông già đang ngồi thiền, kiểu phim hoạt hình) ở góc phải.

> **Quy tắc:** Bất cứ lớp nào có thể được kế thừa và quản lý qua con trỏ lớp cơ sở → **bắt buộc** khai báo `virtual` cho destructor.

---

## Trang 18 — Tóm tắt chương
**Tiêu đề:** Tóm tắt

**Nội dung đầy đủ:**
- **Khái niệm interface:**
  - Lớp = Interface + Khai báo private + Cài đặt.
  - Lớp kế thừa thừa hưởng interface lớp cơ sở.
  - Giả lập interface trong C++: hàm thuần ảo.
- **Hàm ảo:**
  - Chỉ ràng buộc với interface, không ràng buộc cài đặt.
  - Khai báo dùng **"virtual"**.
- **Phương thức hủy ảo:**
  - Phương thức hủy phải luôn là hàm ảo.

**📊 Diagram:** Hình ảnh clipboard với dấu tick màu đỏ lớn ở góc phải dưới — biểu tượng tóm tắt/checklist.

---

## Trang 19 — Bài tập 9.1
**Tiêu đề:** Bài tập

**Nội dung:**
- **Bài tập 9.1:** Cho biết những gì xuất hiện trên màn hình trong các trường hợp:
  - a) [yyy] trống, [zzz] trống.
  - b) [yyy] trống, [zzz] virtual.
  - c) [yyy] virtual, [zzz] trống.
  - d) [yyy] virtual, [zzz] virtual.

**💻 Code:**
```cpp
class A {
public:
    [yyy] void f1() { cout << "Good morning.\n"; f2(); }
    [zzz] void f2() { cout << "Good afternoon.\n"; }
};
class B: public A {
public:
    void f1() { cout << "Good evening.\n"; f2(); }
    void f2() { cout << "Good night.\n"; }
};
void main()
{
    A   *p = new B;
    p->f1();
}
```

> **Phân tích các trường hợp:**
> - a) [yyy] trống, [zzz] trống: `f1` không virtual → gọi `A::f1` → in "Good morning." → `f2` cũng không virtual → gọi `A::f2` → in "Good afternoon."
> - b) [yyy] trống, [zzz] virtual: tương tự (a) vì `f1` không virtual nên `A::f1` được gọi, nhưng bên trong `A::f1` gọi `this->f2()` qua con trỏ → `f2` là virtual → gọi `B::f2` → in "Good morning." + "Good night."
> - c) [yyy] virtual, [zzz] trống: `f1` là virtual → gọi `B::f1` → in "Good evening." → `f2` không virtual → gọi `A::f2` (vì `this` trong `B::f1` là `B*`, nhưng `f2` được gọi qua `A::f2` do không virtual) → in "Good night." *(Gọi `B::f2`)*
> - d) [yyy] virtual, [zzz] virtual: `f1` virtual → `B::f1` → "Good evening." → `f2` virtual → `B::f2` → "Good night."

---

## Trang 20 — Bài tập 9.2
**Tiêu đề:** Bài tập

**Nội dung:**
- **Bài tập 9.2:**

Cho 2 loại hình:
- Hình tam giác: biểu diễn bởi 3 đỉnh.
- Hình chữ nhật: biểu diễn bởi 2 điểm — trên trái và dưới phải.

Viết hàm nhận vào danh sách 2 loại hình trên và xuất thông tin các hình có trong danh sách.

Nếu thêm vào loại hình mới là hình tròn:
- Hình tròn: biểu diễn bởi tâm và bán kính.

Khi đó, chương trình sẽ thay đổi như thế nào?

> **Gợi ý thiết kế:** Tạo lớp cơ sở trừu tượng `Shape` với hàm thuần ảo `virtual void print() = 0`. Hàm nhận `vector<Shape*>` và gọi `p->print()` → khi thêm `Circle` chỉ cần tạo lớp mới, hàm in không đổi.

---

## Trang 21 — Bài tập 9.3
**Tiêu đề:** Bài tập

**Nội dung:**
- **Bài tập 9.3:** Cho bảng tốc độ chạy của các động vật:

**📊 Diagram:** Bảng hai cột nền xanh dương:

| Động vật | Tốc độ |
|----------|--------|
| Báo | 100km/h |
| Linh dương | 80km/h |
| Sư tử | 70km/h |
| Chó | 60km/h |
| Người | 30km/h |

Viết hàm nhận vào 2 động vật trong bảng trên và so sánh tốc độ chạy giữa chúng.

Nếu thêm vào con ngựa chạy 60km/h, khi đó chương trình sẽ thay đổi như thế nào?

> **Gợi ý:** Dùng lớp trừu tượng `Animal` với `virtual int getSpeed() = 0`. Hàm so sánh nhận `Animal*` → khi thêm `Horse` không cần sửa hàm so sánh.

---

## Trang 22 — Bài tập 9.4 (phần 1: bảng động vật)
**Tiêu đề:** Bài tập

**Nội dung:**
- **Bài tập 9.4:** Cho bảng cách thức hoạt động của các loài động vật:

**📊 Diagram:** Bảng 4 cột, tiêu đề nền xanh lá:

|  | Ăn | Di chuyển | Sinh sản |
|---|---|---|---|
| **Cá mập** | Tạp | Bơi | Đẻ trứng |
| **Cá chép** | Phiêu sinh | Bơi | Đẻ trứng |
| **Sư tử** | Tạp | Chạy | Đẻ con |
| **Bò** | Cỏ | Chạy | Đẻ con |
| **Cá voi** | Phiêu sinh | Bơi | Đẻ con |
| **Chim sẻ** | Sâu bọ | Bay | Đẻ trứng |
| **Đại bàng** | Tạp | Bay | Đẻ trứng |
| **Cá sấu** | Tạp | Bò, Bơi | Đẻ trứng |
| **Tắc kè** | Tạp | Bò | Đẻ trứng |
| **Dơi** | Tạp | Bay | Đẻ con |

---

## Trang 23 — Bài tập 9.4 (phần 2: xây dựng interfaces)
**Tiêu đề:** Bài tập

**Nội dung:**
- **Bài tập 9.4 (tiếp):** Hãy xây dựng các interface **X, Y, Z, U, V** và áp dụng cho những động vật trong bảng để chúng có thể tham gia vào những hoạt động sau:

**💻 Code:**
```cpp
void thiBoi(X dv1, X dv2)
{
    dv1.boi();
    dv2.boi();
}

void thiBay(Y dv1, Y dv2)
{
    dv1.bay();
    dv2.bay();
}

void thuanHoaThu(Z dv)
{
    Z con = dv.deCon();
}

void nuoiCa(U dv)
{
    dv.boi();
    U con = dv.deTrung();
}

void nuoiBoSat(V dv)
{
    dv.bo();
    dv.anTap();
    V con = dv.deTrung();
}
```

> **Phân tích:** 
> - Interface **X**: có method `boi()` → áp dụng cho: Cá mập, Cá chép, Cá voi, Cá sấu.
> - Interface **Y**: có method `bay()` → áp dụng cho: Chim sẻ, Đại bàng, Dơi.
> - Interface **Z**: có method `deCon()` → áp dụng cho: Sư tử, Bò, Cá voi, Dơi.
> - Interface **U**: có `boi()` + `deTrung()` → áp dụng cho: Cá mập, Cá chép.
> - Interface **V**: có `bo()` + `anTap()` + `deTrung()` → áp dụng cho: Cá sấu, Tắc kè.

---

## Trang 24 — Bài tập 9.5 (*) — Nâng cao
**Tiêu đề:** Bài tập

**Nội dung:**
- **Bài tập 9.5 (*):** Cho lớp `Line` và `Rectangle` dùng vẽ đường thẳng và hình chữ nhật:

**💻 Code:**
```cpp
class Line
{
private:
    Point  m_p1;
    Point  m_p2;
public:
    Line(Point, Point);
    void drawLine();
};

class Rectangle
{
private:
    Point  m_p1;
    Point  m_p2;
public:
    Rectangle(Point, Point);
    void drawRect();
};
```

Hãy viết hàm vẽ đường thẳng và hình chữ nhật từ một danh sách hình cho trước.

**Yêu cầu:**
- Sử dụng (không chỉnh sửa) lớp `Line` và `Rectangle`.
- Hàm vẽ phải không đổi khi thêm hình mới vào.

> **Gợi ý:** Tạo lớp wrapper hoặc lớp adapter kế thừa lớp trừu tượng `IDrawable` với `virtual void draw() = 0`. Bọc `Line` và `Rectangle` vào các wrapper, hàm vẽ nhận `vector<IDrawable*>` và gọi `p->draw()`.

---

## Trang 25 — Bài tập 9.6 — Bài toán thuê video
**Tiêu đề:** Bài tập 9.6

**Nội dung:**
Xây dựng sơ đồ class và tiến hành cài đặt các class cần thiết cho bài toán sau:

Xét một chương trình cho phép tính toán chi phí phải trả của khách hàng tại một cửa hàng cho thuê video. Người dùng nhập vào danh sách những bộ phim mà khách hàng thuê và thuê trong bao lâu. Sau đó, chương trình sẽ tính toán các khoản chi phí tùy thuộc vào thời gian phim được thuê và loại phim. Có ba loại phim: thông thường, dành cho trẻ em và mới phát hành. Cách tính phí như sau:

- **Phim thông thường:**
  - Phí thuê = 2 USD
  - Nếu thuê hơn 2 ngày thì tính thêm 1.5 USD mỗi ngày
- **Phim dành cho trẻ em:**
  - Phí thuê = 1.5 USD
  - Nếu thuê hơn 3 ngày thì tính thêm 1.5 USD mỗi ngày
- **Phim mới phát hành:**
  - Phí thuê = 3 USD mỗi ngày

Ngoài ra chương trình cũng cho phép tính tổng điểm thưởng của khách hàng với quy định sẽ được cộng 1 điểm thưởng cho mỗi ngày thuê phim mới phát hành. Thuê các loại phim còn lại thì không có điểm thưởng.

---

## Trang 26 — Bài tập 9.6 — Class diagram tham khảo
**Tiêu đề:** Class diagram for reference

**📊 Diagram:** UML Class Diagram hoàn chỉnh cho bài toán thuê video. Nền trắng, chữ đen kiểu monospace.

Các class và quan hệ:

**Class `Movie`** (góc trên trái):
- Methods:
  - `+getCharge(days:int)`
  - `+getFrequentRenterPoints(days:int)`
- Quan hệ: Association `1` → `Price` (1 Movie có 1 Price)

**Class `Price`** (góc trên phải) — lớp trừu tượng:
- Methods (in nghiêng — abstract):
  - `+getCharge(days:int)`
  - `+getFrequentPoints(days:int)`
- Quan hệ kế thừa (tam giác rỗng) xuống 3 lớp con:

**Class `Childrens Price`** (kế thừa `Price`):
- `+getCharge(days:int)`

**Class `Regular Price`** (kế thừa `Price`):
- `+getCharge(days:int)`

**Class `New Release Price`** (kế thừa `Price`):
- `+getCharge(days:int)`
- `+getFrequentRenterPoints(days:int)` — override thêm điểm thưởng

**Class `Rental`** (góc dưới trái):
- Attributes:
  - `+daysRented: int`
- Methods:
  - `+getCharge()`
  - `+getFrequentRenterPoints()`
- Quan hệ: `Movie` `1` ← `*` `Rental` (1 Movie có nhiều Rental)
- Quan hệ: `Rental` `*` ← `Customer` (Customer có nhiều Rental)

**Class `Customer`** (góc dưới phải):
- Attributes:
  - `+name: string`
- Methods:
  - `+statement()`
  - `+htmlStatement()`
  - `+getTotalCharge()`
  - `+getTotalFrequentRenterPoints()`

**Ý nghĩa thiết kế:** `Price` là lớp trừu tượng (interface), ba subclass cài đặt cách tính phí khác nhau. `Movie` chứa một `Price*` — đây là ví dụ điển hình của **Strategy Pattern** kết hợp đa hình.

---

## Tổng kết Slide 09

| Khái niệm | Từ khóa C++ | Mục đích |
|---|---|---|
| Interface | `public` methods | Giao thức giao tiếp của đối tượng |
| Hàm ảo | `virtual` | Liên kết động — gọi đúng cài đặt lúc chạy |
| Hàm thuần ảo | `virtual ... = 0` | Bắt buộc lớp con cài đặt |
| Lớp trừu tượng | Có hàm thuần ảo | Không thể tạo đối tượng trực tiếp |
| Destructor ảo | `virtual ~ClassName()` | Đảm bảo gọi đúng hàm hủy khi delete qua con trỏ lớp cơ sở |

**Quy tắc vàng:**
1. Khi dùng liên kết động, **bắt buộc** dùng **con trỏ** (hoặc reference) — không dùng value.
2. Lớp có thể được kế thừa → **luôn khai báo `virtual` cho destructor**.
3. Hàm thuần ảo (`= 0`) = interface contract — lớp kế thừa **phải** override.
