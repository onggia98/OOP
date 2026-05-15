# Giáo trình: Phương Pháp Lập Trình Hướng Đối Tượng
> Tác giả: Trần Đan Thư, Đinh Bá Tiến, Nguyễn Tấn Trần Minh Khang  
> NXB Khoa Học và Kỹ Thuật, 2010 — Tổng 375 trang  
> Ngôn ngữ chính: **C++** (so sánh Java, C# xuyên suốt)  
> Nguồn: raw/ebooks/Giáo trình PPLTHDT.pdf (scanned — không có text layer)

---

## Mục Lục (kèm số trang PDF)

| Chương | Tên | Trang bắt đầu |
|--------|-----|---------------|
| — | Lời nói đầu | 4 (PDF trang 4) |
| — | Mục lục | 4–15 |
| **Chương 1** | **LỚP VÀ ĐỐI TƯỢNG** | **PDF trang ~18** |
| **Chương 2** | **KIỂU DỮ LIỆU CƠ SỞ VÀ LỚP DỰNG SẴN** | **PDF trang ~53** |
| **Chương 3** | **THUỘC TÍNH ĐỐI TƯỢNG VÀ PHƯƠNG THỨC** | **PDF trang ~78** |
| **Chương 4** | **TỔNG QUÁT HÓA, ĐẶC BIỆT HÓA VÀ ĐA HÌNH** | **PDF trang ~137** |
| **Chương 5** | **NHỮNG KIỂU DỮ LIỆU TRỪU TƯỢNG** | **PDF trang ~195** |
| **Chương 6** | **LIÊN HỆ GIỮA CÁC LỚP ĐỐI TƯỢNG** | **PDF trang ~214** |
| **Chương 7** | **LẬP TRÌNH VỚI TẬP TIN TRONG C++** | **PDF trang ~232** |
| **Chương 8** | **LỚP THAM SỐ HÓA BỞI KIỂU DỮ LIỆU (Templates)** | **PDF trang ~304** |

---

## Chi tiết từng chương

### Chương 1 — LỚP VÀ ĐỐI TƯỢNG (trang sách: 16–50)
- I. Khái niệm về lớp và đối tượng
  - I.1 Lớp đối tượng: khai báo (tên lớp, thuộc tính, phương thức); cài đặt lớp; viết gộp; khái niệm đối tượng & chu kỳ sống
  - I.2 Sự che chắn, bao bọc dữ liệu và phương thức
  - I.3 Tạo lập, sử dụng và hủy đối tượng (new, delete)
- II. Sơ lược về nhập xuất (cin/cout)
- III. Tổ chức các tập tin mã nguồn (nhiều file, sơ đồ nối kết)
- IV. Ký hiệu UML cho lớp và đối tượng
- V. Sự tương đồng, khác nhau giữa C++, Java, C#
- VI. Thuật ngữ

### Chương 2 — KIỂU DỮ LIỆU CƠ SỞ VÀ LỚP DỰNG SẴN (trang: 51–75)
- I. Các kiểu dữ liệu cơ sở và phép toán (số thực, nguyên, luận lý, ký tự)
- II. Kiểu chuỗi ký tự (8-bit, 16-bit)
- III. Dữ liệu động — vector<T>, mảng động
- IV. Những lớp dựng sẵn khác (STL, lớp không chuẩn)
- V. So sánh kiểu dựng sẵn của C++, Java, C#

### Chương 3 — THUỘC TÍNH ĐỐI TƯỢNG VÀ PHƯƠNG THỨC (trang: 76–134)
- II. Phương thức tạo lập (Constructor): sự cần thiết; đặc điểm; cài đặt; copy constructor; so sánh C++/Java/C#
- III. Phương thức hủy (Destructor): dọn dẹp; đặc điểm; cài đặt
- IV. Operator Overloading: toán tử gán; toán tử khác; quy ước & lưu ý; so sánh C#, Java
- V. Tham số cho phương thức: giá trị; tham chiếu; con trỏ; mặc định; variadic
- VI. Chuyển đổi kiểu dữ liệu (Casting): ngầm định; tường minh; static_cast; dynamic_cast; const_cast; reinterpret_cast
- VII. Thành phần tĩnh (static), thành phần const
- VIII. Đồ án học tập: Singleton, lớp chỉ có phương thức tĩnh

### Chương 4 — TỔNG QUÁT HÓA, ĐẶC BIỆT HÓA VÀ ĐA HÌNH (trang: 135–192)
- I. Tổng quát hóa & đặc biệt hóa: khai báo kế thừa; sự tương thích kiểu; nguyên tắc phương pháp luận
- II. Đa hình (Polymorphism): ví dụ dẫn nhập; lớp trừu tượng & phương thức thuần ảo
- III. Ký hiệu UML: quan hệ kế thừa; phương thức đa hình
- IV. Các vấn đề liên quan: cơ chế truy xuất; hàm friend & lớp friend; virtual destructor
- V. Một số kỹ thuật HĐT cơ bản: xác định tên lớp; cloning; tổng quát hóa thuật toán
- VI. Đối sánh C++/Java/C#

### Chương 5 — NHỮNG KIỂU DỮ LIỆU TRỪU TƯỢNG (trang: 193–211)
- II. Container trừu tượng: Stack; Queue; Priority Queue
- III. Thảo luận và mở rộng
- V. Đồ án học tập: tính giá trị biểu thức; duyệt đồ thị BFS

### Chương 6 — LIÊN HỆ GIỮA CÁC LỚP ĐỐI TƯỢNG (trang: 212–229)
- I. Các loại quan hệ: bao hàm/bộ phận (HAS-A, PART-OF); tổng quát hóa/đặc biệt hóa (IS-A)
- II. Quan hệ bạn (friend), phụ thuộc
- III. Cài đặt: HAS-A; IS-A; friend; phụ thuộc
- IV. Thảo luận: kế thừa private/protected; đa kế thừa (C++, Java, C#)

### Chương 7 — LẬP TRÌNH VỚI TẬP TIN TRONG C++ (trang: 230–301)
- I. Hệ thống nhập xuất chuẩn
- II. Tập tin theo góc nhìn lập trình (văn bản thô, nhị phân)
- III. Giới thiệu lập trình trên tập tin (ifstream, ofstream)
- IV. Đọc dữ liệu từ tập tin; V. Ghi dữ liệu lên tập tin
- VI. Đọc & ghi trên cùng một tập tin; VII. Ví dụ áp dụng
- VIII. Lập trình tập tin văn bản dạng mở rộng (Unicode UTF-16, UTF-8)

### Chương 8 — LỚP THAM SỐ HÓA BỞI KIỂU DỮ LIỆU / Templates (trang: 302–375)
- I. Khái niệm và ý nghĩa: tham số hóa hàm; tham số hóa lớp; vấn đề biên dịch
- II. Xây dựng riêng cho trường hợp đặc biệt; non-type parameter
- III. Kế thừa các lớp tham số hóa
- IV. Ứng dụng Template: STL; Metaprogramming
- V. Đối sánh: Generic C#; Generic Java
- VII. Đồ án học tập: Stack template; Mảng template

---

## Ánh xạ với OOP Knowledge Map

| Chương | Tương ứng Tầng OOP |
|--------|-------------------|
| 1 | Tầng 1 — Class & Object, Encapsulation |
| 2 | Tầng 1 — Kiểu dữ liệu cơ sở |
| 3 | Tầng 1 — Constructor/Destructor; Tầng 2 — Operator Overloading |
| 4 | Tầng 2 — Inheritance; Tầng 3 — Polymorphism, Abstract Class |
| 5 | Tầng 3 — Abstract Data Types |
| 6 | Tầng 4 — IS-A vs HAS-A, Composition vs Inheritance |
| 7 | Tầng 5 — File I/O (ứng dụng OOP) |
| 8 | Tầng 5 — Generics / Templates |

---

## Ghi chú sử dụng
> **Giáo trình là scanned PDF** — không có text layer. Để học từng chương:
> 1. Yêu cầu: "ôn chương [X]" → Cowork sẽ OCR các trang tương ứng
> 2. Mỗi chương ~15-60 trang, sẽ convert từng batch
> 3. Ngôn ngữ C++ là chính, luôn so sánh với Java/C#
