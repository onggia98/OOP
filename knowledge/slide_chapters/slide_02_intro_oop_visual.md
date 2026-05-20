# Slide 02 — Tổng quan về lập trình hướng đối tượng
**Giảng viên:** GV. Nguyễn Minh Huy  
**Môn:** Phương pháp lập trình hướng đối tượng

---

## Trang 1 — Trang bìa

Tiêu đề: **Tổng quan về lập trình hướng đối tượng**  
Giảng viên: GV. Nguyễn Minh Huy

---

## Trang 2 — Nội dung (Mục lục)

Các chủ đề trong slide:
- Đối tượng và lớp.
- Sử dụng đối tượng trong C++.
- Tầm vực.
- Bài tập.

*(Trang 3 là animation của trang 2 — highlight mục "Đối tượng và lớp", bỏ qua vì trùng nội dung.)*

---

## Trang 4 — Đối tượng và lớp: Hướng thủ tục vs. Hướng đối tượng

**Hướng thủ tục vs. Hướng đối tượng:**  
Bài toán minh họa: nấu món thịt kho trứng + rau muống xào.

**Bảng so sánh:**

| Hành động | Hướng thủ tục | Hướng đối tượng |
|-----------|--------------|----------------|
| Lặt       | Ướp(Thịt)    | Trứng.Luộc()   |
| Luộc      | Luộc(Trứng)  | Trứng.BócVỏ()  |
| Ướp       | Lặt(Rau)     | Rau.Lặt()      |
| Kho       | BócVỏ(Trứng) | Rau.Xào()      |
| Xào       | Kho(Thịt, Trứng) | Thịt.Ướp() |
| Bóc vỏ    | Xào(Rau)     | Thịt.Kho(Trứng)|

**Nguyên liệu:** Thịt, Trứng, Rau.

**Tóm tắt tư duy:**
- **Hướng thủ tục:** Hành động làm gốc. Hàm + Dữ liệu. **(Verb) + (Object)**
- **Hướng đối tượng:** Dữ liệu làm gốc. Dữ liệu thực hiện hàm. **(Object) does (Verb)** — Thay đổi tư duy lập trình.

**📊 Diagram:** Bảng 3 cột so sánh song song: cột trái liệt kê hành động thuần túy (Lặt, Luộc, Ướp...), cột giữa là gọi hàm kiểu thủ tục (Ướp(Thịt)), cột phải là gọi method OOP (Thịt.Ướp()). Bên dưới là 2 hộp tóm tắt tư duy.

---

## Trang 5 — Đối tượng và lớp: Đối tượng là gì?

**Đối tượng là gì?**
- Chương trình là "cỗ máy" phức tạp.
- Cấu thành từ các "chi tiết":
  - Chi tiết cơ bản: hàm, biến dữ liệu.
  - Tổ chức hướng thủ tục: hàm + biến dữ liệu → **Chưa đủ tạo chương trình tổng quát!**
  - Tổ chức hướng đối tượng: biến dữ liệu "thực hiện" hàm → **Cần có "chi tiết" mới.**

**Kết luận nổi bật:** "Chi tiết" mới: **Đối tượng!!**

**📊 Diagram:** Hình ảnh đồng hồ cơ học phức tạp nhiều bánh răng — ẩn dụ cho chương trình là "cỗ máy". Hộp kết luận màu hồng nổi bật ở giữa slide.

---

## Trang 6 — Đối tượng và lớp: Tính chất của đối tượng

**Tính chất của đối tượng:**
- Cấu trúc dữ liệu mới.
- Bao gồm cả dữ liệu và xử lý:
  - **Thuộc tính (attribute):** dữ liệu của đối tượng.
  - **Phương thức (method):** xử lý của đối tượng.

**📊 Diagram:** Ba hình ảnh minh họa sự tiến hóa:
1. **Function** (hàm) — hình ảnh các bánh răng rời (chỉ xử lý)
2. **Struct** (cấu trúc) — hình ảnh hộp các tờ giấy (chỉ dữ liệu)
3. **Object** (đối tượng) — hình ảnh hộp + bánh răng bên trong (dữ liệu + xử lý gộp lại, được đóng khung hồng)

---

## Trang 7 — Đối tượng và lớp: Khái niệm lớp

**Khái niệm lớp:**
- Biến ~ kiểu.
- Biến cấu trúc ~ kiểu cấu trúc.
- **Đối tượng ~ lớp:**
  - Kiểu của đối tượng.
  - Bản mô tả đối tượng gồm: Thuộc tính (dữ liệu) + Phương thức (hàm xử lý).

**📊 Diagram:** Sơ đồ class-to-object quan trọng:
- Ô trên (class `Person`): Name, Age, Hair Color, Eat(), Work() — không có giá trị cụ thể.
- Hai mũi tên dashed từ class Person xuống hai object:
  - **Person1** (ảnh thợ xây): Name: Peter, Age: 25, Hair Color: Brown, Eat(), Work()
  - **Person2** (ảnh bác sĩ): Name: Thomas, Age: 50, Hair Color: White, Eat(), Work()
- Minh họa rõ ràng: lớp là khuôn mẫu chung, đối tượng là thực thể cụ thể với giá trị riêng.

---

## Trang 8 — Nội dung (chuyển sang phần 2)

*(Animation slide mục lục — highlight mục "Sử dụng đối tượng trong C++". Bỏ qua vì trùng nội dung.)*

---

## Trang 9 — Sử dụng đối tượng trong C++: Cách sử dụng

**Cách sử dụng đối tượng:**
- Tương tự sử dụng biến cấu trúc.
- Các bước sử dụng:
  1. **Khai báo lớp (file .h):** tạo kiểu cho đối tượng.
  2. **Cài đặt lớp (file .cpp):** cài đặt phương thức cho đối tượng — tương tự cài đặt hàm, kèm tên lớp và toán tử `::`.
  3. **Sử dụng đối tượng từ lớp:**
     - Khai báo biến có kiểu là lớp.
     - Truy xuất thành phần đối tượng: dùng dấu `.` hoặc `->` (con trỏ).

**💻 Code — Cú pháp khai báo lớp:**
```cpp
class <Tên lớp>
{
    <Khai báo thuộc tính>;
    <Khai báo phương thức>;
};
```

---

## Trang 10 — Sử dụng đối tượng trong C++: So sánh class vs struct (phần 1 — khai báo & cài đặt)

**Ví dụ: so sánh đối tượng và biến cấu trúc.**

**📊 Diagram:** Bố cục 2 cột song song:

**Cột trái — Khai báo lớp (file PhanSo.h):**
```cpp
// Khai báo lớp, file PhanSo.h
class PhanSo
{
private:
    int  m_tuSo;
    int  m_mauSo;
public:
    PhanSo cong(PhanSo p);
};

// Cài đặt lớp, file PhanSo.cpp
PhanSo PhanSo::cong(PhanSo p)
{
    // Cài đặt cộng phân số…
}
```

**Cột phải — Khai báo kiểu cấu trúc (file PhanSo.h):**
```cpp
// Khai báo kiểu cấu trúc, file PhanSo.h
struct PhanSo
{
    int  m_tuSo;
    int  m_mauSo;
};

PhanSo cong(PhanSo p1, PhanSo p2);

// Cài đặt hàm cộng, file PhanSo.cpp
PhanSo cong(PhanSo p1, PhanSo p2)
{
    // Cài đặt cộng phân số…
}
```

**Điểm khác biệt quan trọng:** Class có `private:`/`public:` và method được khai báo bên trong. Cài đặt ngoài lớp dùng `PhanSo::cong`. Struct không có access modifier, hàm là global function.

---

## Trang 11 — Sử dụng đối tượng trong C++: So sánh class vs struct (phần 2 — sử dụng trong main)

**Ví dụ: so sánh sử dụng đối tượng và cấu trúc trong main.**

**💻 Code:**

**Cột trái — Sử dụng đối tượng (file main.cpp):**
```cpp
// Sử dụng đối tượng, file main.cpp
void main()
{
    PhanSo  p1;
    PhanSo  p2;

    p1.cong( p2 );
}
```

**Cột phải — Sử dụng cấu trúc (file main.cpp):**
```cpp
// Sử dụng cấu trúc, file main.cpp
void main()
{
    PhanSo  p1;
    PhanSo  p2;

    cong( p1, p2 );
}
```

**Điểm khác biệt:** OOP gọi `p1.cong(p2)` — đối tượng p1 chủ động thực hiện hàm. Thủ tục gọi `cong(p1, p2)` — hàm nhận cả hai tham số.

---

## Trang 12 — Nội dung (chuyển sang phần 3)

*(Animation slide mục lục — highlight mục "Tầm vực". Bỏ qua vì trùng nội dung.)*

---

## Trang 13 — Tầm vực: Khái niệm và bảng phân loại

**Khái niệm tầm vực:**
- Tầm ảnh hưởng, phạm vi hoạt động của:
  - Biến → **Block khai báo**
  - Hàm → **Toàn chương trình**
  - Thành phần của cấu trúc → **Block khai báo biến cấu trúc**
  - Thành phần của đối tượng → **Có thể điều chỉnh!!** (điểm mới so với struct)
- Tầm ảnh hưởng càng hẹp, truy xuất càng hạn chế.

**Bảng phân loại tầm vực đối tượng:**

| Tầm vực   | Tầm ảnh hưởng | Phạm vi hoạt động               |
|-----------|--------------|--------------------------------|
| private   | Hẹp          | Bên trong lớp.                 |
| public    | Rộng         | Bên trong lẫn bên ngoài lớp.  |
| protected | Vừa          | Bên trong lớp và lớp kế thừa. |

**📊 Diagram:** Bảng 3 hàng 3 cột với màu nền xanh lá header. Các nhãn highlight màu trong slide: "Block khai báo" (xanh dương), "Toàn chương trình" (xanh dương), "Block khai báo biến cấu trúc" (xanh dương), "Có thể điều chỉnh!!" (hồng — nhấn mạnh tính mới của OOP).

---

## Trang 14 — Tầm vực: Ví dụ hoạt động các loại tầm vực

**Ví dụ: hoạt động của các loại tầm vực.**

**💻 Code:**

```cpp
class A
{
private:
    int  x;
public:
    int  y;

public:
    int getX( );
private:
    void calculate( );
};

void main()
{
    A   obj;

    int  x = obj.x;      // Sai  (x là private)
    obj.x = 1;           // Sai  (x là private)

    int  y = obj.y;      // Đúng (y là public)
    obj.y = 2;           // Đúng (y là public)

    int  t = obj.getX( ); // Đúng (getX là public)
    obj.calculate( );    // Sai  (calculate là private)
}
```

**Giải thích:** Từ bên ngoài lớp (trong main), chỉ được phép truy xuất các thành phần `public`. Truy xuất `private` sẽ gây lỗi biên dịch.

---

## Trang 15 — Tầm vực: Quy tắc hộp đen (Dr. Guru khuyên)

**Dr. Guru khuyên — Quy tắc hộp đen (Black Box Rule):**
- **Thuộc tính** có tầm vực `private` để **hạn chế truy xuất**.
- **Phương thức** có tầm vực `public` để **cung cấp tính năng**.

**💻 Code — Ví dụ áp dụng quy tắc hộp đen:**
```cpp
class PhanSo
{
private:
    int  m_tu;
    int  m_mau;
public:
    PhanSo cong( PhanSo p );
    PhanSo rutGon( );
};
```

**📊 Diagram:** Hình vẽ 2 vòng tròn đồng tâm:
- Vòng trong (màu đỏ cam): **Dữ liệu (Thuộc tính)** — tầm vực `private`, bị bao bọc bên trong.
- Vòng ngoài (màu xanh lá): **Tính năng (Phương thức)** — tầm vực `public`, là lớp bên ngoài tiếp xúc.
- Ẩn dụ "hộp đen": bên ngoài chỉ thấy tính năng, không thấy dữ liệu bên trong.

---

## Trang 16 — Tầm vực: Toán tử :: (bốn chấm)

**Toán tử :: (scope resolution operator):**
- Ví dụ: Lớp 5A và 5B đều có học sinh tên Lê Phương — làm sao phân biệt?
  - Trường hợp 1: đứng **trong lớp** → gọi thẳng tên.
  - Trường hợp 2: đứng **ngoài lớp** → dùng `::` để chỉ rõ thuộc lớp nào.
- **Toán tử ::** dùng gọi tên thành phần của lớp **từ bên ngoài**.
- Cú pháp: `<Tên lớp>::<Tên thành phần>`

**📊 Diagram:** Hai hộp riêng biệt:
- **Lớp 5A** (nền hồng): ảnh thầy giáo + học sinh nam tên Lê Phương
- **Lớp 5B** (nền hồng): ảnh thầy giáo + học sinh nữ tên Lê Phương
- Minh họa: cùng tên nhưng khác lớp → cần `TenLop::TenThanhPhan` để phân biệt.

---

## Trang 17 — Tầm vực: Ví dụ cài đặt phương thức trong/ngoài lớp

**Ví dụ: cài đặt phương thức bên trong và bên ngoài lớp.**

**💻 Code:**

**Cột trái — Cài đặt bên trong lớp (inline):**
```cpp
class PhanSo
{
private:
    int  m_tu;
    int  m_mau;
public:
    PhanSo cong(PhanSo p)
    {
        // Cài đặt bên trong lớp.
    }
};
```

**Cột phải — Cài đặt bên ngoài lớp (dùng ::):**
```cpp
PhanSo PhanSo::cong(PhanSo p)
{
    // Cài đặt bên ngoài lớp.
}
```

**Giải thích:** Khi cài đặt ngoài lớp, phải dùng `PhanSo::cong` để trình biên dịch biết `cong` thuộc về class `PhanSo`. Cả hai cách đều hợp lệ, nhưng thông thường khai báo trong `.h` và cài đặt trong `.cpp` (ngoài lớp).

---

## Trang 18 — Tóm tắt

**Tóm tắt toàn bộ slide 02:**

- **Đối tượng và lớp:**
  - Đối tượng là một cấu trúc dữ liệu mới.
  - Đối tượng chứa dữ liệu lẫn xử lý.
  - Lớp là bản mô tả / kiểu của đối tượng.

- **Sử dụng đối tượng:**
  - Khai báo lớp bằng từ khóa `class`.
  - Giống sử dụng cấu trúc.

- **Tầm vực:**
  - Tầm ảnh hưởng, phạm vi hoạt động.
  - Có 3 mức: `public`, `private`, `protected`.

---

## Trang 19 — Bài tập 2.1: Lớp Phân số

**Bài tập 2.1:**  
Xây dựng lớp **phân số** cho phép thực hiện các thao tác:
- Nhập, xuất.
- Lấy tử số, mẫu số.
- Gán giá trị cho tử số, mẫu số.
- Nghịch đảo, rút gọn.
- Cộng, nhân, so sánh với phân số khác.

---

## Trang 20 — Bài tập 2.2: Lớp Đơn thức

**Bài tập 2.2:**  
Xây dựng lớp **đơn thức** cho phép thực hiện các thao tác:
- Nhập, xuất.
- Lấy hệ số, số mũ.
- Gán giá trị cho hệ số, số mũ.
- Tính giá trị, đạo hàm.
- Cộng (cùng bậc), nhân, so sánh với đơn thức khác.

---

## Trang 21 — Bài tập 2.3: Lớp Học sinh

**Bài tập 2.3:**  
Thông tin một học sinh bao gồm: Họ tên, Điểm văn, Điểm toán.  
Xây dựng lớp **học sinh** cho phép thực hiện các thao tác:
- Nhập, xuất.
- Lấy họ tên, điểm văn, toán.
- Gán giá trị cho họ tên, điểm văn, điểm toán.
- Tính điểm trung bình.
- Xếp loại theo tiêu chí:
  - Giỏi (>= 8.0), Khá (>= 7.0).
  - Trung bình (>= 5.0), Yếu (< 5).

---

## Trang 22 — Bài tập 2.4: Lớp Mảng số nguyên

**Bài tập 2.4:**  
Xây dựng lớp **mảng** số nguyên cho phép thực hiện các thao tác sau:
- Nhập, xuất mảng.
- Lấy kích thước mảng.
- Lấy phần tử tại vị trí nào đó.
- Gán giá trị cho phần tử tại vị trí nào đó.
- Tìm phần tử nào đó trong mảng.
- Sắp xếp tăng, giảm.
- **Lưu ý:** không dùng vector.

---

## Ghi chú tổng hợp kiến thức

### Sơ đồ tư duy: Class vs Object

```
Class (Lớp)                    Object (Đối tượng)
+------------------+           +------------------+
| Person           |  ---->    | Person1          |
|------------------|  (tạo)    |------------------|
| - name           |           | - name: "Peter"  |
| - age            |           | - age: 25        |
| - hairColor      |           | - hairColor: "Brown" |
|------------------|           |------------------|
| + eat()          |           | + eat()          |
| + work()         |           | + work()         |
+------------------+           +------------------+
       Khuôn mẫu                     Thực thể
```

### Quy tắc hộp đen (Black Box Rule)

```
[  public methods  ]  <-- bên ngoài chỉ thấy đây
   [ private data ]   <-- bên trong được ẩn đi
```

### Bảng tổng hợp tầm vực

| Từ khóa   | Trong lớp | Ngoài lớp | Lớp con |
|-----------|-----------|-----------|---------|
| private   | Có        | Không     | Không   |
| public    | Có        | Có        | Có      |
| protected | Có        | Không     | Có      |

### Cú pháp cốt lõi

```cpp
// Khai báo lớp (file .h)
class TenLop
{
private:
    // Thuộc tính (data members)
    int m_thuocTinh;

public:
    // Phương thức (member functions)
    KieuTraVe tenPhuongThuc(ThamSo);
};

// Cài đặt ngoài lớp (file .cpp)
KieuTraVe TenLop::tenPhuongThuc(ThamSo)
{
    // Thân hàm
}

// Sử dụng đối tượng
void main()
{
    TenLop obj;       // Khai báo đối tượng
    obj.tenPhuongThuc(giaTriThamSo);  // Gọi phương thức
}
```
