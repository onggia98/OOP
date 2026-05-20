# Slide OOP-01: Giới Thiệu Môn Học (Course Overview)

**Môn học:** Phương pháp lập trình hướng đối tượng  
**Giảng viên:** GV. Nguyễn Minh Huy  
**Tổng số trang:** 21

---

## Trang 1 — Trang bìa: Giới thiệu môn học

Tiêu đề: **Giới thiệu môn học**  
Giảng viên: GV. Nguyễn Minh Huy  
Footer: Phương pháp lập trình hướng đối tượng – GV. Nguyễn Minh Huy

---

## Trang 2 — Nội dung (Mục lục)

Ba chủ đề chính của slide này:

1. Chuẩn và quy ước lập trình.
2. Nạp chồng hàm.
3. Lập trình tổng quát.

---

## Trang 3 — Nội dung (animation: highlight chủ đề 1)

*(Trang animation — nội dung giống trang 2, nhưng mục "Chuẩn và quy ước lập trình" được làm nổi bật bằng chữ đậm/vàng để chỉ thị đang bước vào chủ đề này)*

---

## Trang 4 — Chuẩn và quy ước lập trình: Vì sao cần chuẩn?

**Vì sao phải có chuẩn và quy ước?**

- **Làm việc một mình:**
  - Tự làm tự hiểu.
  - Mình luôn hiểu mình? *(đặt câu hỏi nghi vấn)*

- **Làm việc nhóm:**
  - Mỗi người một việc.
  - Ráp nối công việc.
  - Mọi người luôn hiểu nhau? *(đặt câu hỏi nghi vấn)*

**Kết luận (hai hộp nổi bật):**
- "Để phối hợp công việc hiệu quả"
- "Phải áp đặt kỷ luật!! Phải có chuẩn!!"

**Diagram:** Hai hình minh họa — người làm việc một mình và nhóm người ghép puzzle cùng nhau.

---

## Trang 5 — Chuẩn và quy ước lập trình: Quy ước #0 và các loại quy ước

**Quy ước #0: Không có chuẩn chung!!**
- Tùy thuộc ngôn ngữ lập trình.
- Tùy thuộc doanh nghiệp.
- Tùy thuộc cộng đồng.

**Một vài quy ước thông dụng:**
- Quy ước đặt tên (naming convention).
- Quy ước viết câu lệnh (statement convention).
- Quy ước viết chú thích (comment convention).

*(Xem Coding Convention Guidelines)*

> **Lưu ý quan trọng:** Không tồn tại một chuẩn lập trình chung duy nhất — mỗi ngôn ngữ, doanh nghiệp, cộng đồng có quy ước riêng. Ba nhóm quy ước thông dụng nhất: đặt tên, viết câu lệnh, viết chú thích.

---

## Trang 6 — Nội dung (animation: highlight chủ đề 2)

*(Trang animation — mục "Nạp chồng hàm" được làm nổi bật)*

---

## Trang 7 — Nạp chồng hàm: Chữ ký hàm (Function Signature)

**Chữ ký hàm (Function Signature / Prototype):**
- Định danh một hàm.
- Thành phần của chữ ký:
  - Tên hàm.
  - Danh sách tham số.

**Ví dụ hai chữ ký cùng tên nhưng khác tham số:**

```cpp
double sapXep(int danhSach[], int kichThuoc);
double sapXep(float danhSach[], int kichThuoc);
```

> **Lưu ý quan trọng:** Giá trị trả về KHÔNG thuộc chữ ký hàm!!

**Kết luận (hộp nổi bật):**
"Chương trình có thể có nhiều hàm cùng tên!!"

> Đây là nền tảng của **Nạp chồng hàm (Function Overloading)**: phân biệt hàm qua chữ ký (tên + tham số), không qua kiểu trả về.

---

## Trang 8 — Nạp chồng hàm: Các trường hợp không hợp lệ

**Những trường hợp nạp chồng hàm nào không hợp lệ?**

```cpp
1. int tinhToan(int a, int b);
2. int tinhToan(int x, int y);
3. int tinhToan(int a, float b);
4. float tinhToan(int u, int v);
5. int tinhToan(int a, long b);
```

**Phân tích:**
- Khai báo 1 và 2: **KHÔNG hợp lệ** — cùng chữ ký (tên giống, kiểu tham số giống, chỉ khác tên biến). Tên biến tham số không thuộc chữ ký.
- Khai báo 1 và 4: **KHÔNG hợp lệ** — chữ ký giống nhau (cùng hai tham số `int, int`), chỉ khác kiểu trả về (kiểu trả về không thuộc chữ ký).
- Khai báo 1 và 3: **Hợp lệ** — tham số thứ hai khác kiểu (`int` vs `float`).
- Khai báo 1 và 5: **Hợp lệ** — tham số thứ hai khác kiểu (`int` vs `long`).

**Diagram (bảng tổng hợp tính hợp lệ):**

| Cặp khai báo | Chữ ký khác nhau? | Hợp lệ? |
|---|---|---|
| 1 vs 2 | Không (chỉ khác tên biến) | Không hợp lệ |
| 1 vs 3 | Có (tham số 2: int vs float) | Hợp lệ |
| 1 vs 4 | Không (chỉ khác kiểu trả về) | Không hợp lệ |
| 1 vs 5 | Có (tham số 2: int vs long) | Hợp lệ |

---

## Trang 9 — Nội dung (animation: highlight chủ đề 3)

*(Trang animation — mục "Lập trình tổng quát" được làm nổi bật)*

---

## Trang 10 — Lập trình tổng quát: Khái niệm và phân loại

**Mức độ tổng quát của chương trình:**
- Khả năng hoạt động trong nhiều ngữ cảnh.
- Không cố định vào một trường hợp.
- "Write once, use everywhere."
- Dùng phương pháp tham số hóa:
  - Tham số hóa dữ liệu (truyền tham số thông thường).
  - Tham số hóa kiểu (function template).
  - Tham số hóa xử lý (con trỏ hàm).

**Diagram (phân cấp 3 loại tổng quát hóa):**

```
Lập trình tổng quát
├── Tham số hóa dữ liệu  →  Truyền tham số thông thường
├── Tham số hóa kiểu     →  Function Template
└── Tham số hóa xử lý   →  Con trỏ hàm
```

---

## Trang 11 — Lập trình tổng quát: Tham số hóa dữ liệu

**Tham số hóa dữ liệu:**
- Bài toán: tính tổng hai số nguyên 3 và 5.
- Tổng quát 1: tính tổng hai số nguyên bất kỳ.

**So sánh giải pháp không tổng quát vs tổng quát:**

```cpp
// Giải pháp không tổng quát:
// Không dùng tham số.
int tinhToan()
{
    return 3 + 5;
}
```

```cpp
// Giải pháp tổng quát 1:
// Tham số hóa dữ liệu.
int tinhToan(int x, int y)
{
    return x + y;
}
void main()
{
    tinhToan(3, 5);
    tinhToan(4, 6);
    tinhToan(-2, 7);
}
```

**Diagram:** Hai cột song song so sánh code không tổng quát (trái) và tổng quát (phải).

---

## Trang 12 — Lập trình tổng quát: Tham số hóa kiểu (Function Template)

**Tham số hóa kiểu:**
- Tổng quát 2: tính tổng hai số kiểu bất kỳ.
- Dùng Function Template.

```cpp
// Giải pháp tổng quát 2:
// Tham số hóa kiểu.
template <class T>
T tinhToan(T x, T y)
{
    return x + y;
}

void main()
{
    int x = tinhToan(3, 5);

    double y = tinhToan(4.2, 6.3);

    PhanSo p1, p2;
    PhanSo p3 = tinhToan(p1, p2);
}
```

> Compiler tự động "đúc" (instantiate) hàm cụ thể từ template khi gọi hàm với kiểu dữ liệu cụ thể.

---

## Trang 13 — Lập trình tổng quát: Đặc điểm Function Template

**Đặc điểm của Function Template:**
- Tham số hóa kiểu dữ liệu.
- "Khuôn hàm" tổng quát cho nhiều kiểu dữ liệu.
- "Đúc" thành từng hàm với kiểu cụ thể khi gọi hàm.

**Ghi chú quan trọng:**
- Từ khóa `"class"` có thể thay bằng `"typename"`.
- Phần khai báo và cài đặt hàm đều phải có template.
- Phần cài đặt hàm phải nằm cùng file:
  - Hoặc phần khai báo hàm.
  - Hoặc phần gọi sử dụng hàm.

> **Lý do:** Compiler cần thấy toàn bộ định nghĩa template để instantiate — không thể tách ra file `.cpp` riêng như hàm thông thường.

---

## Trang 14 — Lập trình tổng quát: Tham số hóa xử lý (Con trỏ hàm)

**Tham số hóa xử lý:**
- Tổng quát 3: tính toán bất kỳ giữa hai số nguyên.
- Dùng Con trỏ hàm.

```cpp
// Giải pháp tổng quát 3:
// Tham số hóa xử lý.
typedef int (*PhepTinh)(int, int);
int tinhToan(int x, int y, PhepTinh p)
{
    return p(x, y);
}

int cong(int x, int y) {
    return x + y;
}
int nhan(int x, int y) {
    return x * y;
}
void main()
{
    int x = tinhToan(3, 5, cong);
    int x = tinhToan(4, 6, nhan);
}
```

---

## Trang 15 — Lập trình tổng quát: Cách dùng con trỏ hàm (4 bước)

**Cách sử dụng con trỏ hàm — 4 bước:**

- **B1:** Tạo kiểu hàm, dùng `typedef`.
  ```cpp
  typedef int (*PhepTinh)(int, int);
  ```

- **B2:** Tạo hàm tổng quát có đối số là kiểu hàm đã tạo.
  ```cpp
  int tinh(int x, int y, PhepTinh p) {
      return p(x, y);
  }
  ```

- **B3:** Tạo hàm xử lý cụ thể.
  ```cpp
  int cong(int x, int y) {
      return x + y;
  }
  ```

- **B4:** Gọi hàm tổng quát, truyền hàm xử lý cụ thể vào.
  ```cpp
  tinh(3, 5, cong);
  ```

---

## Trang 16 — Lập trình tổng quát: Đặc điểm con trỏ hàm

**Đặc điểm của con trỏ hàm:**
- Tham số hóa xử lý.
- Hàm làm đối số của hàm khác.
- Hàm có xử lý tổng quát tùy xử lý truyền vào.
- Xử lý cụ thể được quyết định khi gọi hàm.

**Ghi chú quan trọng:**
- Dùng con trỏ hàm trực tiếp, không dùng `typedef`:
  ```cpp
  int tinhToan(int x, int y, int (*p)(int, int));
  ```
- Sử dụng Function Template phải dùng con trỏ hàm trực tiếp (không dùng `typedef`).
- Tổng quát 4: tính toán bất kỳ giữa hai số kiểu bất kỳ.
  *(kết hợp cả template và con trỏ hàm)*

---

## Trang 17 — Tóm tắt (phần 1): Chuẩn & Quy ước + Nạp chồng hàm

**Chuẩn và quy ước lập trình:**
- Áp đặt kỷ luật lên việc lập trình.
- Tạo quy ước để phối hợp hiệu quả.
- Quy ước đặt tên: có nghĩa, ngắn gọn.
- Quy ước viết câu lệnh: rộng rãi, rõ ràng.
- Quy ước viết chú thích: đầy đủ, dễ hiểu.

**Nạp chồng hàm:**
- Nhiều hàm cùng tên, khác tham số.

**Diagram:** Icon clipboard với dấu check đỏ (biểu tượng tóm tắt/checklist).

---

## Trang 18 — Tóm tắt (phần 2): Lập trình tổng quát

**Lập trình tổng quát:**
- Chương trình hoạt động trong nhiều ngữ cảnh.
- Dùng phương pháp tham số hóa:
  - Tham số hóa dữ liệu (tham số thông thường).
  - Tham số hóa kiểu (function template).
  - Tham số hóa xử lý (con trỏ hàm).

**Diagram:** Icon clipboard với dấu check đỏ.

---

## Trang 19 — Bài tập 1.1

**Bài tập 1.1:**

Viết chương trình cho phép thực hiện các thao tác trên kiểu **phân số**:
- Nhập, xuất phân số.
- Rút gọn, nghịch đảo phân số.
- Cộng, nhân, so sánh hai phân số.

*(Bài tập áp dụng quy ước lập trình, nạp chồng hàm)*

---

## Trang 20 — Bài tập 1.2

**Bài tập 1.2:**

Viết chương trình cho phép sắp xếp mảng **phân số** theo thứ tự tăng/giảm/điều kiện bất kỳ.

*(Bài tập áp dụng tham số hóa xử lý — con trỏ hàm)*

---

## Trang 21 — Bài tập 1.3

**Bài tập 1.3:**

Mở rộng bài 1.2, sắp xếp mảng **phân số/số nguyên/kiểu bất kỳ**.

*(Bài tập áp dụng cả tham số hóa kiểu — function template — kết hợp con trỏ hàm: Tổng quát 4)*

---

## Tong hop kien thuc chinh

### 1. Chuẩn và quy ước lập trình (Coding Standards)

| Loại quy ước | Nội dung | Nguyên tắc |
|---|---|---|
| Naming convention | Đặt tên biến, hàm, class | Có nghĩa, ngắn gọn |
| Statement convention | Viết câu lệnh | Rộng rãi, rõ ràng (thụt đầu dòng, xuống dòng) |
| Comment convention | Viết chú thích | Đầy đủ, dễ hiểu |

> Quy ước #0: Không có chuẩn chung — tùy ngôn ngữ, doanh nghiệp, cộng đồng.

### 2. Nạp chồng hàm (Function Overloading)

- **Chữ ký hàm (Function Signature)** = Tên hàm + Danh sách tham số (kiểu)
- Kiểu trả về KHÔNG thuộc chữ ký.
- Nạp chồng hợp lệ khi: cùng tên, khác chữ ký (khác số tham số hoặc khác kiểu tham số).
- Nạp chồng KHÔNG hợp lệ khi: chỉ khác tên biến tham số hoặc chỉ khác kiểu trả về.

### 3. Lập trình tổng quát (Generic Programming)

| Mức tổng quát | Kỹ thuật | Cú pháp |
|---|---|---|
| Tổng quát 1: dữ liệu bất kỳ | Tham số thông thường | `int f(int x, int y)` |
| Tổng quát 2: kiểu bất kỳ | Function Template | `template <class T> T f(T x, T y)` |
| Tổng quát 3: xử lý bất kỳ, dữ liệu cố định | Con trỏ hàm + typedef | `typedef int (*F)(int,int); int f(int x, int y, F p)` |
| Tổng quát 4: kiểu bất kỳ + xử lý bất kỳ | Template + con trỏ hàm trực tiếp | `template <class T> T f(T x, T y, T(*p)(T,T))` |

**4 bước dùng con trỏ hàm:**
1. `typedef` kiểu hàm.
2. Tạo hàm tổng quát nhận con trỏ hàm làm tham số.
3. Viết hàm xử lý cụ thể.
4. Gọi hàm tổng quát, truyền hàm cụ thể vào.

**Lưu ý Function Template:**
- `class` có thể thay bằng `typename`.
- Phần cài đặt phải nằm cùng file với khai báo hoặc nơi gọi.
- Không thể tách ra file `.cpp` riêng.
