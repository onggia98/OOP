# Slide 06 — Thư viện STL, Tính đóng gói
**Môn:** Phương pháp lập trình hướng đối tượng — GV. Nguyễn Minh Huy

---

## Trang 1 — Trang bìa

Tiêu đề: **Thư viện STL, Tính đóng gói**

GV. Nguyễn Minh Huy — Phương pháp lập trình hướng đối tượng.

---

## Trang 2 — Nội dung (mục lục)

Ba chủ đề chính của slide:
- Thư viện C++.
- Thư viện STL.
- Tính đóng gói.

*(Trang 3 là animation highlight "Thư viện C++" — nội dung giống trang 2, bỏ qua.)*

---

## Trang 4 — Thư viện C++

**Khái niệm thư viện:**
- Thợ xây dựng dùng gì để xây nhà?
  - Tay không.
  - Công cụ hỗ trợ.
- Thư viện lập trình:
  - Bộ công cụ hỗ trợ của lập trình viên.
  - Tập hợp tri thức của người đi trước.
  - Các lớp, hàm dựng sẵn (file .lib).
- Các thư viện C++ phổ biến:
  - Thư viện chuẩn C++.
  - Thư viện boost: hơn 80 thư viện hỗ trợ lập trình C++.
  - Thư viện MFC: hỗ trợ lập trình C++ trên Windows.

**📊 Diagram:** Hình minh họa công cụ (búa, cờ lê, xe xúc đất, máy trộn bê tông) — ẩn dụ thư viện là "công cụ" của lập trình viên giống công cụ xây dựng của thợ xây.

---

## Trang 5 — Thư viện C++ (tiếp)

**Thư viện chuẩn (C++ Standard Library):**
- Phát triển và chuẩn hóa vào 1990s.
- Bộ công cụ lập trình nền tảng.
- Tập hợp các lớp trong namespace `std`.
- Đặc điểm: file header không có đuôi `.h`.
- Cấu trúc:
  - Thư viện nhập xuất: `iostream`, `fstream`, `iomanip`, …
  - Thư viện STL.
  - Thư viện chuẩn C: file header `cxxx.h`.

---

## Trang 6 — Nội dung (chuyển sang STL)

*(Animation highlight "Thư viện STL" — nội dung giống trang 2, bỏ qua.)*

---

## Trang 7 — Thư viện STL

**Giới thiệu STL — Standard Template Library:**
- Tác giả: Alexander Stepanov, 1994.
- Phần chính yếu của thư viện chuẩn.
- Tập hợp class template dựng sẵn.
- Hỗ trợ cấu trúc dữ liệu tổng quát.
- Cấu trúc thư viện gồm 4 nhóm:
  - Nhóm containers.
  - Nhóm iterators.
  - Nhóm algorithms.
  - Nhóm functors.

**📊 Diagram:** Sơ đồ lồng nhau — hộp ngoài "Thư viện chuẩn" (màu trắng/hồng nhạt), bên trong là hộp "Thư viện STL" (màu xanh lá), bên trong STL có 4 ô vàng: `containers`, `iterators`, `algorithms`, `functions`.

```
+----------------------------------------------+
|             Thư viện chuẩn                   |
|  +----------------------------------------+  |
|  |          Thư viện STL                  |  |
|  |  +------------+  +------------+        |  |
|  |  | containers |  | iterators  |        |  |
|  |  +------------+  +------------+        |  |
|  |  +------------+  +------------+        |  |
|  |  | algorithms |  | functions  |        |  |
|  |  +------------+  +------------+        |  |
|  +----------------------------------------+  |
+----------------------------------------------+
```

---

## Trang 8 — Thư viện STL — Lớp string

**Lớp string (header `<string>`):**
- Lớp đại diện cho chuỗi ký tự.
- **Giải quyết 3 vấn đề con trỏ.**
- Các phương thức chính:

| Phương thức | Ý nghĩa |
|---|---|
| `string(char *)` | Khởi tạo từ một chuỗi char *. |
| `length()` | Lấy chiều dài chuỗi. |
| Toán tử `[ ]` | Lấy ký tự tại vị trí nào đó. |
| Toán tử `>`, `<`, `>=`, `<=`, `==`, `!=` | So sánh chuỗi theo thứ tự từ điển. |
| Toán tử `+`, `+=` | Nối chuỗi. |
| `find(char *)` | Tìm vị trí chuỗi con. |
| `substr(int, int)` | Trích chuỗi con. |

---

## Trang 9 — Thư viện STL — Ví dụ lớp string

**Lớp string — ví dụ code:**

**💻 Code:**
```cpp
void main()
{
    string  s1("software");
    string  s2("SoftWare");
    if (s1 == s2)
        cout << "equal." << endl;
    else
        cout << "not equal." << endl;

    s2 = s1.substr(4, 4);
    cout << s2;

    string  s3 = s1 + s2;
    cout << s3 << endl;
}
```

*Giải thích: So sánh chuỗi bằng `==`, trích chuỗi con bằng `substr(vị_trí, độ_dài)`, nối chuỗi bằng toán tử `+`.*

---

## Trang 10 — Thư viện STL — Lớp vector

**Lớp vector (header `<vector>`):**
- Lớp mảng kiểu tổng quát T.
- **Giải quyết 3 vấn đề con trỏ.**
- Các phương thức chính:

| Phương thức | Ý nghĩa |
|---|---|
| `vector<T>()` | Khởi tạo mảng kiểu T. |
| `size()` | Lấy kích thước mảng. |
| `resize(int)` | Thay đổi kích thước mảng. |
| Toán tử `[ ]` | Lấy phần tử tại vị trí nào đó. |
| `push_back(T)` | Thêm phần tử vào cuối mảng. |
| `insert(position, T)` | Chèn phần tử vào vị trí nào đó. |

---

## Trang 11 — Thư viện STL — Ví dụ lớp vector

**Lớp vector — ví dụ code:**

**💻 Code:**
```cpp
void main()
{
    vector<int>     v1;
    v1.push_back(1);
    v1.push_back(2);

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    vector<PhanSo *>  v2;
    v2.push_back(new PhanSo(1, 3));
    v2[0]->rutGon();
}
```

*Giải thích: `vector<int>` là mảng số nguyên động; `vector<PhanSo *>` là mảng con trỏ đối tượng — truy xuất qua `->`. Duyệt mảng dùng chỉ số `[]` hoặc iterator.*

---

## Trang 12 — Thư viện STL — Luyện tập

**Luyện tập:**

Viết chương trình thực hiện:
- Nhập vào danh sách N chuỗi ký tự.
- Nối các chuỗi vừa nhập và xuất kết quả.

Cài đặt theo hai cách:
- Sử dụng lớp mảng động thuần túy.
- Sử dụng lớp `string` và `vector` của thư viện STL.

---

## Trang 13 — Nội dung (chuyển sang Tính đóng gói)

*(Animation highlight "Tính đóng gói" — nội dung giống trang 2, bỏ qua.)*

---

## Trang 14 — Tính đóng gói — Quy tắc hộp đen

**Quy tắc hộp đen (Black Box Rule):**
- Thuộc tính: **`private`** để hạn chế truy xuất.
- Phương thức: **`public`** để cung cấp tính năng.

**📊 Diagram:** Sơ đồ hình tròn lồng nhau (encapsulation layers):
- Vòng trong (màu cam/đỏ): **Dữ liệu (Thuộc tính)** — private, bị che khuất.
- Vòng ngoài (màu xanh lá): **Tính năng (Phương thức)** — public, lớp vỏ bảo vệ.

```
        +---------------------------+
        |      Tính năng            |
        |    (Phương thức)          |
        |   +---------------+       |
        |   |  Dữ liệu      |       |
        |   | (Thuộc tính)  |       |
        |   +---------------+       |
        +---------------------------+
```

**💻 Code:**
```cpp
class HocSinh
{
private:
    char*   m_hoTen;
    float   m_diemVan;
    float   m_diemToan;
};
```

---

## Trang 15 — Tính đóng gói — Nhu cầu xử lý vs. quy tắc hộp đen

**Nhu cầu xử lý vs. quy tắc hộp đen:**

Khi có nhu cầu truy xuất thuộc tính đối tượng từ bên ngoài, có 2 phương án:
- **Phương án 1:** `private` → `public` (vi phạm hộp đen hoàn toàn).
- **Phương án 2:** Phương thức truy xuất (getter/setter) — VẪN vi phạm quy tắc hộp đen vì lộ dữ liệu ra ngoài.

**📊 Diagram:** Hai cột code so sánh:

*Cách sai — public trực tiếp:*
```cpp
class HocSinh
{
public:
    char*   m_hoTen;
    float   m_diemVan;
    float   m_diemToan;
};
```

*Vẫn sai — getter trả về reference:*
```cpp
class HocSinh
{
private:
    char*   m_hoTen;
    float   m_diemVan;
    float   m_diemToan;
public:
    float&  layDiemVan();
    float&  layDiemToan();
};
```

*Lý do cả 2 đều sai: bên ngoài có thể thay đổi dữ liệu nội bộ thông qua reference — vi phạm đóng gói.*

---

## Trang 16 — Tính đóng gói — Cách tuân thủ quy tắc hộp đen

**Làm sao vẫn tuân thủ quy tắc hộp đen?**

Nguyên tắc: **Đưa xử lý cho đối tượng thực hiện** — thay vì lộ dữ liệu, cung cấp phương thức thực hiện nghiệp vụ.

**💻 Code:**
```cpp
class HocSinh
{
private:
    char*   m_hoTen;
    float   m_diemVan;
    float   m_diemToan;
public:
    float tinhDTB();
    int   xepLoai();
};
```

*Thay vì trả về `m_diemVan` và `m_diemToan` rồi tính bên ngoài, đối tượng tự tính `tinhDTB()` và `xepLoai()` — dữ liệu không bị lộ.*

---

## Trang 17 — Tính đóng gói — Tell, Don't Ask

**Dr. Guru khuyên: quy tắc "Tell, Don't Ask"**

- Thông tin đối tượng → **Không thể truy xuất từ bên ngoài.**
- Đối tượng nắm giữ thông tin → **Chịu trách nhiệm xử lý thông tin.**
- "Đừng hỏi tôi thông tin để thực hiện công việc"
  → "Hãy nhờ tôi làm giùm!!"
- Đã giao thông tin → **Giao luôn xử lý thông tin.**

**📊 Diagram (Tell Don't Ask):**

```
BAD — "Ask then act":          GOOD — "Tell, Don't Ask":
+----------+                   +----------+
|  Client  |                   |  Client  |
+----+-----+                   +----+-----+
     |  getData()                   |  doWork()
     v                              v
+----------+                   +----------+
|  Object  |                   |  Object  |
| (lộ dữ  |                   | (tự xử  |
|  liệu)  |                   |  lý)    |
+----------+                   +----------+
```

*Minh họa trực quan: hình ông guru ngồi thiền (Dr. Guru) — biểu tượng trí tuệ thiết kế OOP.*

---

## Trang 18 — Tính đóng gói — Luyện tập

**Luyện tập — Áp dụng Tell Don't Ask:**

*Bài toán 1: Tính trọng tâm tam giác*

**💻 Code:**
```cpp
class Diem
{
private:
    float   m_X;
    float   m_Y;
};

class TamGiac
{
private:
    Diem    m_A;
    Diem    m_B;
    Diem    m_C;
};
```

*Bài toán 2: Xuất danh sách học sinh đậu (ĐTB >= 5.0)*

**💻 Code:**
```cpp
class HocSinh
{
private:
    char    *m_hoTen;
    float   m_diemVan;
    float   m_diemToan;
};

class BangDiem
{
private:
    vector<HocSinh>  m_danhSach;
};
```

*Yêu cầu: thiết kế phương thức đúng hướng Tell Don't Ask — `TamGiac` tự tính trọng tâm, `BangDiem` tự lọc học sinh đậu.*

---

## Trang 19 — Tóm tắt

**Tóm tắt chương 6:**

- **Thư viện C++:**
  - Bộ công cụ dựng sẵn hỗ trợ lập trình C++.
  - Các thư viện phổ biến: Thư viện chuẩn, Thư viện boost, Thư viện MFC.

- **Thư viện STL:**
  - Phần chính yếu của thư viện chuẩn.
  - Các lớp dựng sẵn: `string`, `vector`.

- **Tính đóng gói:**
  - Tell, Don't Ask.

---

## Trang 20 — Bài tập 6.1

**Bài tập 6.1:**

Với mỗi thư viện bên dưới, hãy liệt kê tên và cho biết tính năng của ít nhất 3 lớp đối tượng trong thư viện:
- Thư viện chuẩn.
- Thư viện boost.
- Thư viện MFC.

---

## Trang 21 — Bài tập 6.2

**Bài tập 6.2:**

Một đoạn văn bao gồm nhiều câu. Mỗi câu bao gồm nhiều từ và kết thúc bằng dấu câu (dấu `.`, `?`, `!`). Xây dựng các lớp cần thiết để:
- Đọc một đoạn văn từ file văn bản.
- Đếm số lượng câu và số lượng từ có trong đoạn văn.
- Tìm từ xuất hiện nhiều nhất trong đoạn văn.
- Sắp xếp tăng dần (thứ tự từ điển) các từ trong mỗi câu.
- Ghi đoạn văn đã chỉnh sửa vào file văn bản.

*Gợi ý áp dụng: dùng `string` để xử lý chuỗi, `vector<string>` để lưu từ/câu, `sort()` để sắp xếp.*

---

## Trang 22 — Bài tập 6.3

**Bài tập 6.3:**

Xây dựng lớp **đa thức** có những phương thức sau:

*(Nhóm tạo hủy)*
- Khởi tạo mặc định đa thức = 0.
- Khởi tạo với bậc và mảng hệ số cho trước.
- Khởi tạo từ một đối tượng đa thức khác.
- Hủy đa thức, thu hồi bộ nhớ.

*(Nhóm truy xuất thông tin)*
- Lấy bậc đa thức.
- Lấy hệ số tại bậc nào đó.

---

## Trang 23 — Bài tập 6.3 (tiếp)

**Bài tập 6.3 (tiếp theo):**

Xây dựng lớp **đa thức** (tiếp):

*(Nhóm xử lý nghiệp vụ)*
- So sánh với đa thức khác.
- Rút gọn đa thức.
- Tính giá trị, đạo hàm, nguyên hàm.

*(Nhóm toán tử)*
- Toán tử số học: `+`, `-`, `*`, `/`, `=`.
- Toán tử so sánh: `>`, `<`, `==`, `>=`, `<=`, `!=`.
- Toán tử đạo hàm (`!`), nguyên hàm (`~`).
- Toán tử nhập xuất: `>>`, `<<`.

---

## Trang 24 — Bài tập 6.4

**Bài tập 6.4:**

Xây dựng các lớp cần thiết để thực hiện các thao tác trên tam giác:
- Tính chu vi và diện tích.
- Tìm trọng tâm (giao 3 đường trung tuyến).
- Tìm đường trung trực của một cạnh (vuông góc tại trung điểm).
- Tìm tâm đường tròn ngoại tiếp (giao 3 đường trung trực).

*Gợi ý: áp dụng nguyên tắc Tell Don't Ask — lớp `TamGiac` tự thực hiện tất cả các phép tính, không lộ tọa độ điểm ra ngoài.*

---

## Tổng kết kiến thức quan trọng

### STL Container — string vs vector

| | `string` | `vector<T>` |
|---|---|---|
| Header | `<string>` | `<vector>` |
| Mục đích | Chuỗi ký tự | Mảng động kiểu T |
| Truy cập | `s[i]`, `s.length()` | `v[i]`, `v.size()` |
| Thêm phần tử | `s += "abc"`, `s.find()` | `v.push_back(x)` |
| Trích/tìm | `s.substr(pos, len)` | `v.insert(pos, x)` |
| Giải quyết | 3 vấn đề con trỏ | 3 vấn đề con trỏ |

### Encapsulation — Quy tắc cốt lõi

```
Sai:  Client hỏi dữ liệu → tự xử lý
      client.getData() → client tính toán

Đúng: Client yêu cầu đối tượng làm
      object.doWork() → object tự tính và trả kết quả
```

### Kiến trúc lớp đúng chuẩn đóng gói

```
class MyClass
{
private:           // Dữ liệu — bị ẩn hoàn toàn
    T m_data;

public:            // Hành vi — cung cấp ra ngoài
    void doWork();  // Không: getData() rồi xử lý bên ngoài
};
```
