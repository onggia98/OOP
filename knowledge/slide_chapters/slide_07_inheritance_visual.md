# Slide 07 — Kế thừa (Inheritance)
**Môn:** Phương pháp lập trình hướng đối tượng — GV. Nguyễn Minh Huy
**Tổng số trang:** 26

---

## Trang 1 — Trang bìa

Tiêu đề: **Kế thừa**
Giảng viên: GV. Nguyễn Minh Huy
Môn học: Phương pháp lập trình hướng đối tượng

---

## Trang 2 — Nội dung (Mục lục)

Các chủ đề trong bài:
- Khái niệm kế thừa.
- Tầm vực trong kế thừa.
- Định nghĩa lại phương thức.
- Quan hệ IS-A và HAS-A.

*(Trang này không có mục nào được highlight — đây là slide mục lục tổng quát.)*

---

## Trang 3 — Nội dung (Mục lục — animation bước 1)

Giống trang 2, nhưng mục **"Khái niệm kế thừa."** được in đậm/highlight màu vàng, báo hiệu phần sắp học.

*(Animation: highlight từng mục theo thứ tự học.)*

---

## Trang 4 — Khái niệm kế thừa — Vấn đề trùng lắp thông tin

**Vấn đề trùng lắp thông tin:**
- Xét nhiều lớp có thông tin trùng nhau.
- Có 2 dạng:
  - Dạng chia sẻ: A ∩ B ≠ Ø (hai lớp có phần chung).
  - Dạng mở rộng: B = A + ε (lớp B là lớp A cộng thêm thành phần).
- Nhược điểm:
  - Tốn thời gian, công sức.
  - Dung lượng lưu trữ lớn.
  - Thay đổi phần chung khó khăn.

**Kết luận:** Giải quyết: tái sử dụng!!

**📊 Diagram:** Hai cặp hộp class minh họa 2 dạng trùng lắp:
- Cặp 1 (dạng chia sẻ): Hộp **A** chứa `x, y, z` và `a, b, c` — Hộp **B** chứa `x, y, z` và `u, v, w`. Phần `x, y, z` trùng nhau giữa A và B.
- Cặp 2 (dạng mở rộng): Hộp **A** chứa `x, y, z` — Hộp **B** chứa `x, y, z` và `a, b, c`. B chứa toàn bộ A cộng thêm `a, b, c`.

---

## Trang 5 — Khái niệm kế thừa — Định nghĩa

**Khái niệm kế thừa:**
- Định nghĩa lớp mới dựa trên những lớp đã có.
- **Lớp kế thừa:** lớp được định nghĩa từ lớp đã có.
- **Lớp cơ sở:** lớp dùng để định nghĩa lớp mới.
- Lớp kế thừa thừa hưởng **TẤT CẢ** từ lớp cơ sở.

**📊 Diagram — 2 ví dụ minh họa kế thừa:**

*Ví dụ 1 — Đa kế thừa (Multiple Inheritance):*
- Hộp **O** (lớp cơ sở) ở trên, chứa `x, y, z`
- Hộp **A** ở dưới trái, chứa `x, y, z` và `a, b, c`
- Hộp **B** ở dưới phải, chứa `x, y, z` và `u, v, w`
- Mũi tên xanh lá (tam giác rỗng, chỉ lên trên) từ A → O và B → O: cả A và B đều kế thừa từ O.

*Ví dụ 2 — Đơn kế thừa (Single Inheritance):*
- Hộp **A** (lớp cơ sở) ở trên, chứa `x, y, z`
- Hộp **B** ở dưới, chứa `x, y, z` và `a, b, c`
- Mũi tên xanh lá từ B → A: B kế thừa từ A.

---

## Trang 6 — Khái niệm kế thừa — Khai báo trong C++

**Khai báo trong C++:**

```
class <Lớp kế thừa> : <Loại kế thừa> <Lớp cơ sở>
```

**Loại kế thừa:** public, private, protected.

**💻 Code:**
```cpp
class A : public O
{
private:
        // Khai báo thuộc tính mới của A.
public:
        // Khai báo phương thức mới của A.
};
```

---

## Trang 7 — Khái niệm kế thừa — Ví dụ thực tế (Giáo viên / GVCN)

**Ví dụ thực tế:** So sánh lớp **Giáo viên** và **GVCN** (Giáo viên chủ nhiệm).

**Giáo viên:**
- Thông tin: Họ tên, Mức lương, Số ngày nghỉ.
- Công việc: Giảng dạy, Tính lương.

**GVCN:**
- Thông tin: Họ tên, Mức lương, Số ngày nghỉ, **Lớp chủ nhiệm** (thêm mới).
- Công việc: Giảng dạy, Tính lương, **Sinh hoạt chủ nhiệm** (thêm mới).

**📊 Diagram:** Hai ảnh minh họa:
- Bên trái: hình vẽ giáo viên đứng trước bảng viết (Giáo viên — lớp cơ sở).
- Bên phải: hình vẽ GVCN đang đọc sách (GVCN — lớp kế thừa, có thêm thông tin màu vàng/đỏ).
- Phần bôi vàng/đỏ là những thông tin GVCN có thêm so với GiaoVien.

*(Animation: các mục lớp GVCN xuất hiện từng bước, phần thêm mới highlight màu vàng.)*

---

## Trang 8 — Khái niệm kế thừa — Ví dụ code GiaoVien / GVCN

**Ví dụ code C++ — lớp cơ sở GiaoVien và lớp kế thừa GVCN:**

**📊 Diagram:** Hai nhãn chú thích ở đầu trang:
- Hộp nhãn xám bên trái: **"Lớp kế thừa"** trỏ vào code GVCN bên phải.
- Hộp nhãn xám bên phải: **"Lớp cơ sở"** trỏ vào code GiaoVien bên trái.

Hộp thông báo màu hồng cuối trang: **"GVCN thừa hưởng TẤT CẢ thuộc tính và phương thức của GiaoVien"**

**💻 Code:**
```cpp
class GiaoVien
{
private:
        char    *m_hoTen;
        float   m_mucLuong;
        int     m_ngayNghi;
public:
        GiaoVien(char *hoTen,
                 float mucLuong,
                 int ngayNghi);
        void giangDay();
        float tinhLuong();
};

class GVCN : public GiaoVien
{
private:
        char    *m_lopCN;
public:
        GVCN(char *hoTen,
             float mucLuong,
             int ngayNghi,
             char *lopCN);
        void sinhHoatCN();
};
```

---

## Trang 9 — Khái niệm kế thừa — Ví dụ sử dụng đối tượng

**Ví dụ sử dụng đối tượng GiaoVien và GVCN trong hàm main:**

- `gv2.giangDay()` — GVCN gọi phương thức thừa hưởng từ GiaoVien (highlight vàng).
- `gv2.tinhLuong()` — GVCN gọi phương thức thừa hưởng từ GiaoVien (highlight vàng).

**💻 Code:**
```cpp
void main()
{
        GiaoVien  gv1("Minh", 500000, 5);
        gv1.giangDay();
        float luong1 = gv1.tinhLuong();

        GVCN  gv2("Hanh", 700000, 3, "10A5");
        gv2.giangDay();      // kế thừa từ GiaoVien
        gv2.sinhHoatCN();
        float luong2 = gv2.tinhLuong();  // kế thừa từ GiaoVien
}
```

---

## Trang 10 — Nội dung (Mục lục — animation bước 2)

Slide mục lục, mục **"Tầm vực trong kế thừa."** được highlight màu vàng/đậm, báo hiệu chuyển sang phần mới.

*(Animation: highlight mục tiếp theo trong danh sách nội dung.)*

---

## Trang 11 — Tầm vực trong kế thừa — Giới thiệu

**Xét lớp A kế thừa lớp O:**
- A kế thừa toàn bộ thuộc tính và phương thức của O.
- Tầm vực của những thành phần này thế nào?
- Kết luận: **Do loại kế thừa quyết định!!**

**📊 Diagram — So sánh tầm vực lớp O và lớp A sau kế thừa:**

- Hộp **Lớp O** (bên trái):
  - `private:` → `m_iX`
  - `protected:` → `m_iY`
  - `public:` → `m_iZ`
- Mũi tên xanh lá (tam giác đặc, chỉ sang trái) với nhãn **"Kế thừa"** ở giữa, nối từ A sang O (theo chiều kế thừa).
- Hộp **Lớp A** (bên phải) — tầm vực của các thành phần kế thừa được hỏi dấu `???`:
  - `???:` → `m_iX` (kế thừa từ private của O)
  - `???:` → `m_iY` (kế thừa từ protected của O)
  - `???:` → `m_iZ` (kế thừa từ public của O)

*(Câu hỏi: tầm vực của m_iX, m_iY, m_iZ trong lớp A là gì? → Đáp án ở trang 12.)*

---

## Trang 12 — Tầm vực trong kế thừa — Bảng tầm vực

**Bảng tầm vực trong kế thừa:**

**📊 Diagram — Bảng 4 cột x 4 hàng (có header):**

| Tầm vực (trong lớp cơ sở) | Kế thừa public | Kế thừa protected | Kế thừa private |
|---|---|---|---|
| **public** | public | protected | private |
| **protected** | protected | protected | private |
| **private** | *Không thể truy xuất* | *Không thể truy xuất* | *Không thể truy xuất* |

- Header hàng đầu nền xanh lá.
- Các ô "Không thể truy xuất" chữ màu vàng, nền tối, nhấn mạnh thuộc tính `private` của lớp cơ sở **không bao giờ** truy xuất được từ lớp kế thừa dù kế thừa kiểu gì.

**Quy tắc quan trọng:**
- Kế thừa `public`: tầm vực giữ nguyên (public→public, protected→protected).
- Kế thừa `protected`: public hạ xuống protected, protected giữ nguyên.
- Kế thừa `private`: tất cả đều thành private.
- `private` của lớp cơ sở: KHÔNG BAO GIỜ truy xuất được từ lớp kế thừa.

---

## Trang 13 — Nội dung (Mục lục — animation bước 3)

Slide mục lục, mục **"Định nghĩa lại phương thức."** được highlight màu vàng/đậm.

*(Animation: báo hiệu chuyển sang phần tiếp theo.)*

---

## Trang 14 — Định nghĩa lại phương thức — Khái niệm

**Kế thừa một phần:**
- Có thể thay đổi những phần đã kế thừa?
- Không kế thừa "máy móc" tất cả.
- **Lớp kế thừa có thể thay đổi những gì đã kế thừa!!**
  - Định nghĩa lại phương thức đã kế thừa.

**Kết luận (hộp hồng):**
> Lớp kế thừa thừa hưởng **TẤT CẢ** thuộc tính và phương thức của lớp cơ sở **TRỪ** những phương thức được định nghĩa lại!!

*(Thuật ngữ: "định nghĩa lại phương thức" = method overriding — viết lại phương thức cùng tên trong lớp con.)*

---

## Trang 15 — Định nghĩa lại phương thức — Ví dụ bài toán

**Ví dụ:**
- GVCN kế thừa từ GiaoVien.
- GVCN tính lương khác GiaoVien:
  - Lương GV = Mức lương – Số ngày nghỉ * 100,000.
  - Lương GVCN = Lương GV + Phụ cấp 1,000,000.
- Kết luận: **Viết lại phương thức `tinhLuong()` cho lớp GVCN.**

---

## Trang 16 — Định nghĩa lại phương thức — Code lớp GiaoVien

**Code lớp GiaoVien với phương thức `tinhLuong()` được highlight (màu vàng):**

**💻 Code:**
```cpp
class GiaoVien
{
private:
        char    *m_hoTen;
        float   m_mucLuong;
        int     m_ngayNghi;
public:
        GiaoVien(char *hoTen, float mucLuong, int ngayNghi);
        void giangDay();
        float tinhLuong()
        {
                return m_mucLuong - m_ngayNghi * 100000;
        }
};
```

*(Phần highlight vàng: thân hàm `tinhLuong()` — công thức tính lương GV gốc.)*

---

## Trang 17 — Định nghĩa lại phương thức — Code lớp GVCN với override

**Code lớp GVCN định nghĩa lại `tinhLuong()`, gọi lại `GiaoVien::tinhLuong()` qua scope resolution operator `::` (highlight vàng):**

**💻 Code:**
```cpp
class GVCN : public GiaoVien
{
private:
        char    *m_lopCN;
public:
        GVCN(char *hoTen,
             float mucLuong,
             int ngayNghi,
             char *lopCN);
        void sinhHoatCN();
        float tinhLuong()
        {
                return GiaoVien::tinhLuong() + 1000000;
        }
};

void main()
{
        GiaoVien  gv1("Minh", 500000, 5);
        gv1.giangDay();
        float luong1 = gv1.tinhLuong();

        GVCN  gv2("Hanh", 700000, 3);
        gv2.giangDay();       // highlight vàng: gọi hàm kế thừa
        float luong2 = gv2.tinhLuong();  // highlight vàng: gọi hàm override
}
```

**Điểm quan trọng:**
- `GiaoVien::tinhLuong()` — dùng scope resolution `::` để gọi phiên bản của lớp cơ sở, tránh đệ quy vô tận.
- `gv2.giangDay()` — GVCN vẫn kế thừa `giangDay()` từ GiaoVien (không override).
- `gv2.tinhLuong()` — GVCN dùng phiên bản override của chính mình.

---

## Trang 18 — Nội dung (Mục lục — animation bước 4)

Slide mục lục, mục **"Quan hệ IS-A và HAS-A."** được highlight màu vàng/đậm.

*(Animation: báo hiệu phần cuối của bài.)*

---

## Trang 19 — Quan hệ IS-A và HAS-A — Quan hệ IS-A

**Quan hệ IS-A:**
- Lớp A quan hệ IS-A với lớp B:
  - A là một trường hợp đặc biệt của B.
  - A cùng loại với B.
- Ví dụ:
  - GVCN là một GiaoVien đặc biệt.
  - HinhVuong là một HinhChuNhat đặc biệt.
  - ConMeo là một ConVat đặc biệt.
- **Nguyên tắc:** Chúng ta chỉ cho class A kế thừa class B **khi và chỉ khi "A is a B"**

*(Đây là nguyên tắc Liskov Substitution Principle (LSP) ở mức cơ bản.)*

---

## Trang 20 — Quan hệ IS-A và HAS-A — Quan hệ HAS-A

**Quan hệ HAS-A:**
- Lớp A quan hệ HAS-A với lớp B:
  - A bao hàm B.
  - A chứa B.
  - B là một bộ phận của A.
- Ví dụ:
  - ChiecXe chứa BanhXe.
  - QuyenSach chứa TrangSach.

*(HAS-A được thể hiện qua composition — B là thuộc tính (member) của A, không phải kế thừa.)*

---

## Trang 21 — Quan hệ IS-A và HAS-A — Luật xây dựng lớp

**Dr. Guru khuyên: luật xây dựng lớp.**
- A có quan hệ IS-A với B → **Cho A kế thừa B.**
- A có quan hệ HAS-A với B → **Cho B là một thuộc tính của A.**

**Ví dụ áp dụng:**

**📊 Diagram:** Hình ảnh "Dr. Guru" (nhân vật ông già ngồi thiền) ở góc phải — biểu tượng lời khuyên kinh điển OOP.

**💻 Code:**
```cpp
// IS-A: ConMeo là một ConVat → ConMeo kế thừa ConVat
class ConMeo : public ConVat { };

// HAS-A: ChiecXe chứa BanhXe → BanhXe là thuộc tính của ChiecXe
class ChiecXe
{
private:
        BanhXe  *m_banhXe;
};
```

---

## Trang 22 — Tóm tắt

**Tóm tắt toàn bộ bài:**

- **Khái niệm kế thừa:**
  - Định nghĩa lớp mới dựa trên những lớp đã có.
  - Lớp kế thừa thừa hưởng TẤT CẢ từ lớp cơ sở.

- **Tầm vực trong kế thừa:**
  - Tầm vực thay đổi tùy theo loại kế thừa.

- **Định nghĩa lại phương thức:**
  - "Cải biên" những phương thức kế thừa.

- **Quan hệ IS-A và HAS-A:**
  - IS-A: A là trường hợp đặc biệt của B → dùng kế thừa.
  - HAS-A: A bao hàm B → dùng thuộc tính (composition).

**📊 Diagram:** Hình ảnh clipboard với dấu check đỏ ở góc phải — biểu tượng tóm tắt/kiểm tra.

---

## Trang 23 — Bài tập 7.1 — Xác định IS-A / HAS-A

**Bài tập 7.1:**
Những cặp đối tượng sau có quan hệ IS-A hay HAS-A?
Khai báo lớp cho từng cặp thể hiện quan hệ giữa chúng.

- Hình vuông / Hình chữ nhật.
- Đa giác / Cạnh.
- Giám đốc / Nhân viên.
- Hình tròn / Hình Ellipse.
- Máy bay / Động cơ.
- Câu / Từ.
- Mỹ phẩm / Hàng hóa.
- Cây lúa / Cây lương thực.
- Thư viện / Sách.
- Phim hoạt hình / Phim ảnh.

*(Gợi ý đáp án:*
- *IS-A: Hình vuông IS-A Hình chữ nhật; Giám đốc IS-A Nhân viên; Hình tròn IS-A Hình Ellipse; Mỹ phẩm IS-A Hàng hóa; Cây lúa IS-A Cây lương thực; Phim hoạt hình IS-A Phim ảnh.*
- *HAS-A: Đa giác HAS-A Cạnh; Máy bay HAS-A Động cơ; Câu HAS-A Từ; Thư viện HAS-A Sách.)*

---

## Trang 24 — Bài tập 7.2 — Lớp TaiKhoan (phần 1)

**Bài tập 7.2:**
Cho lớp TaiKhoan như sau:

**💻 Code:**
```cpp
class TaiKhoan
{
private:
        float   m_soDu;
public:
        float baoSoDu() {   return m_soDu;   }
        void napTien(float soTien) {   m_soDu += soTien;   }
        bool rutTien(float soTien)
        {
                if (soTien <= m_soDu) {
                        m_soDu -= soTien;
                        return true; }
                return false;
        }
};
```

*(Trang tiếp theo mô tả yêu cầu xây dựng lớp TaiKhoanTietKiem kế thừa TaiKhoan.)*

---

## Trang 25 — Bài tập 7.2 — Lớp TaiKhoanTietKiem (phần 2)

**Yêu cầu:** Dựa trên lớp TaiKhoan, xây dựng lớp **TaiKhoanTietKiem** như sau:

- Có thêm thông tin:
  - Kỳ hạn gửi.
  - Lãi suất.
  - Số tháng đã gửi.
- Khi **nạp tiền**: tính lãi và số tháng gửi tính lại từ đầu.
- Khi **rút tiền**: tính lãi và số tháng gửi tính lại từ đầu.
- Cho phép tăng số tháng đã gửi.

*(Đây là bài tập thực hành kế thừa + định nghĩa lại phương thức: `napTien()` và `rutTien()` sẽ được override trong TaiKhoanTietKiem.)*

**📊 Diagram (quan hệ):**
```
TaiKhoan
    ^
    |  (IS-A / public inheritance)
    |
TaiKhoanTietKiem
  + m_kyHan
  + m_laiSuat
  + m_soThangGui
  + override napTien()
  + override rutTien()
  + tangSoThang()
```

---

## Trang 26 — Bài tập 7.3 — Lớp XeMay / XeTai

**Bài tập 7.3:**
- Một chiếc xe máy chạy không tải 100km tốn 2 lit xăng, cứ chở thêm 10kg hàng xe tốn thêm 0.1 lit xăng (mỗi 100km).
- Một chiếc xe tải chạy không tải 100km tốn 20 lit xăng, cứ chở thêm 1000kg hàng xe tốn thêm 1 lit xăng (mỗi 100km).

**Dùng kế thừa để xây dựng lớp XeMay và XeTai cho phép:**
- Chất một lượng hàng lên xe.
- Bỏ bớt một lượng hàng xuống xe.
- Đổ một lượng xăng vào xe.
- Cho xe chạy một đoạn đường.
- Kiểm tra xem xe đã hết xăng chưa.
- Cho biết lượng xăng còn trong xe.

**📊 Diagram (quan hệ kế thừa gợi ý):**
```
Xe (lớp cơ sở)
  - m_hang (kg)
  - m_xang (lit)
  + chatHang(kg)
  + boHang(kg)
  + doXang(lit)
  + chay(km)         // override ở từng lớp con
  + hetXang(): bool
  + xangConLai(): float
       ^
       |
  _____|_____
  |         |
XeMay     XeTai
  + override chay()   + override chay()
  (2lit/100km +        (20lit/100km +
   0.1lit/10kg)         1lit/1000kg)
```

*(Bài tập tổng hợp: kế thừa + override phương thức `chay()` khác nhau cho từng loại xe.)*

---

## Tổng kết — Sơ đồ tư duy Slide 07

```
Kế thừa (Inheritance)
├── Khái niệm
│   ├── Lớp cơ sở (Base class)
│   ├── Lớp kế thừa (Derived class)
│   ├── Cú pháp: class A : <loại> B { }
│   └── Lớp kế thừa thừa hưởng TẤT CẢ
│
├── Tầm vực (Access Specifier)
│   ├── Kế thừa public:   public→public, protected→protected
│   ├── Kế thừa protected: public→protected, protected→protected
│   ├── Kế thừa private:  public→private, protected→private
│   └── private của base: KHÔNG BAO GIỜ truy xuất được
│
├── Định nghĩa lại phương thức (Method Overriding)
│   ├── Viết lại hàm cùng tên trong lớp con
│   ├── Gọi lại hàm cơ sở: BaseName::method()
│   └── Lớp con dùng phiên bản của mình
│
└── Quan hệ IS-A / HAS-A
    ├── IS-A: A là dạng đặc biệt của B → A kế thừa B
    └── HAS-A: A chứa B → B là thuộc tính của A
```

---

*Nguồn: Slide OOP-07-Inheritance, GV. Nguyễn Minh Huy, Phương pháp lập trình hướng đối tượng, HCMUS.*
