# Topic Frequency Map — Phân Tích Đề Thi CSC10003
> Môn: PP Lập Trình Hướng Đối Tượng (C++) — HCMUS ĐTTX  
> Phân tích: 16 đề thi từ 2019–2026 (HK1 & HK2)  
> Cập nhật: 2026-05-15

---

## 🔥 KẾT LUẬN NHANH CHO ÔN THI

| Ưu tiên | Chủ đề | Mức độ xuất hiện |
|---------|--------|-----------------|
| ⚠️ BẮT BUỘC | Inheritance + Polymorphism (đa hình) | **100% đề** (câu 2 mọi năm) |
| ⚠️ BẮT BUỘC | Class Design + Encapsulation | **100% đề** (câu 1 mọi năm) |
| 🔺 TĂNG MẠNH | Operator Overloading | 4/6 đề gần nhất (2021–2026) |
| 🔺 TĂNG MẠNH | Dynamic Memory / Big Three (Rule of 3) | 2/2 đề mới nhất (2025–2026) |
| ➕ CÓ THỂ | Aggregation (HAS-A, Composition) | 2024a |
| ➕ CÓ THỂ | Sorting theo tiêu chí | 2023 |

**Dạng đề KHÔNG thấy trong bộ đề này:** lý thuyết trắc nghiệm, code tracing, UML vẽ tay, Design Patterns tên gọi.

---

## 📋 BẢNG TOÀN BỘ ĐỀ THI

| Năm | Kỳ | Ngày | Câu 1 (5đ) | Câu 2 (5đ) | OOP Pattern |
|-----|----|------|-----------|-----------|-------------|
| 2019 | HK2 | 09/06/2019 | Danh sách HS, tìm TB cao nhất | 3 hệ đào tạo, học bổng khác nhau | Inheritance + Poly |
| 2020 | HK2 | 13/06/2020 | Tam giác (3 đỉnh), tính chu vi | Hóa đơn 2 loại mặt hàng (thường/đặc biệt) | Inheritance + Poly |
| 2020 | HK1 | 29/11/2020 | Danh sách sản phẩm, tìm hết hạn | Cửa hàng 2 loại SP, thuế khác nhau | Inheritance + Poly |
| 2021 | HK1 | 04/12/2021 | Mảng phân số, tìm max | 2 hệ SV, học bổng khác nhau | **Op.Overload** + Inheritance + Poly |
| 2021 | HK2 | 23/11/2021 | Đa giác, tính chu vi | Hóa đơn 2 loại mặt hàng | Inheritance + Poly |
| 2022 | HK2 | 11/06/2022 | Quyển sách, tính độ dày | Lớp học, tính phí đồng phục nam/nữ | Inheritance + Poly |
| 2022 | HK1 | 12/11/2022 | Tam giác, kiểm tra hợp lệ | 2 hệ SV, học bổng | Inheritance + Poly |
| 2023 | HK2 | 10/06/2023 | Đa giác, tính chu vi | Lớp học SV, xuất theo điểm TB | Aggregation + Sort |
| 2024 | HK1 | 19/11/2023 | Tam giác cân | Đơn hàng (khách hàng + chi tiết mặt hàng) | Composition (HAS-A) |
| 2024 | HK2 | 25/05/2024 | **Phân số: toán tử +, >, ==** | Hình học (tròn/chữ nhật), điểm thuộc hình | **Op.Overload** + Inheritance + Poly |
| 2024 | HK2 | 25/05/2024 | (Đề song song — giống 2024b) | (Giống 2024b) | |
| 2025 | HK2 | 08/06/2025 | **CMyArray: Add(), Min(), op[]** (cài đặt theo main) | Monitor/Projector/SmartTV, bật/tắt/hiển thị | **Big Three + Op[]** + Inheritance + Poly |
| 2025 | HK1 | 23/11/2024 | SinhVien + LopHoc, in SV có TB > 8 | Hình cơ bản (tròn/vuông/chữ nhật), diện tích & chu vi lớn nhất | Inheritance + Poly |
| 2026 | HK1 | 30/11/2025 | **CMyString: Append, Find, op+, op[]** (cài đặt theo main) | Phương tiện (Ô tô/Xe máy/Xe tải), tính phí cầu đường | **Big Three + Op.Overload** + Inheritance + Poly |

---

## 📊 TẦN SUẤT TỪNG CHỦ ĐỀ

### Câu 2 — Luôn Luôn: Inheritance + Polymorphism (đa hình bắt buộc)

**Xuất hiện: 13/13 đề (100%)**

Các bài toán điển hình theo năm:

| Bài toán quen | Số lần |
|--------------|--------|
| Quản lý sinh viên nhiều hệ đào tạo (CQ / CNTN / CLC), học bổng khác nhau | **4 lần** (2019, 2021HK1, 2022HK1, xem thêm) |
| Hóa đơn / đặt hàng với nhiều loại mặt hàng, cách tính giá khác nhau | **3 lần** (2020HK2, 2021HK2, 2020HK1) |
| Hình học (tròn, chữ nhật, vuông, đa giác) với diện tích/chu vi/kiểm tra điểm thuộc | **3 lần** (2024HK2, 2025HK1, 2025HK2) |
| Thiết bị điện tử, phương tiện giao thông với hành vi khác nhau | **2 lần** (2025HK2, 2026HK1) |

**Yêu cầu kỹ năng câu 2:**
- Khai báo base class (abstract hoặc concrete)
- 2–3 lớp con kế thừa
- Override phương thức tính toán (tính học bổng, tính tiền, tính diện tích...)
- Dùng con trỏ base class để gọi virtual function → runtime polymorphism
- Thường cần 1 class container (LopHoc, DanhSach, CuaHang...) chứa mảng/vector base pointer

---

### Câu 1 — Class Design (cơ bản → phức tạp dần)

| Giai đoạn | Năm | Dạng câu 1 |
|-----------|-----|-----------|
| **Giai đoạn 1** (2019–2022) | 2019–2022 | Nhập danh sách → tìm kiếm/thống kê đơn giản. Class design cơ bản |
| **Giai đoạn 2** (2023–2024) | 2023–2024 | Aggregation/Composition, đa giác nhiều đỉnh, đơn hàng chi tiết |
| **Giai đoạn 3** (2025–2026) | 2025–2026 | **Cài đặt lớp theo main cho sẵn** — yêu cầu Big Three + Operator Overloading |

⚠️ **Xu hướng 2025–2026:** Câu 1 không còn dễ nữa. Đề cho sẵn hàm main, yêu cầu thiết kế class đúng interface (constructor, destructor, copy constructor, operator overloading). Đây là dạng **khó nhất** trong bộ đề.

---

### Operator Overloading — Tăng Đều Qua Năm

**Xuất hiện: 2021HK1, 2024HK2, 2025HK2, 2026HK1**

| Năm | Toán tử yêu cầu | Context |
|-----|----------------|---------|
| 2021 HK1 | `>` (so sánh phân số) | Tìm phân số lớn nhất trong mảng |
| 2024 HK2 | `+`, `>`, `==` (phân số vs 0) | Tính TB cộng các phân số dương |
| 2025 HK2 | `[]` (truy cập mảng) | CMyArray quản lý mảng động |
| 2026 HK1 | `+`, `[]`, (copy ctor, dtor) | CMyString quản lý chuỗi động |

---

### Big Three (Constructor/Copy Constructor/Destructor) — Xu Hướng Mới

**Xuất hiện rõ ràng: 2025HK2, 2026HK1**

Cả hai đề đều yêu cầu xây dựng lớp quản lý **bộ nhớ động**:
- `CMyArray` (2025): mảng int động, Add(), Min(), op[]
- `CMyString` (2026): chuỗi char* động, Append(), Find(), op+, op[]

Rule of Three **bắt buộc** khi có: destructor xóa `delete[]`, copy constructor cần deep copy, assignment operator cần deep copy.

---

## 🎯 DẠNG BÀI THI PHỔ BIẾN NHẤT (Luyện ưu tiên)

### Dạng 1 — Inheritance + Polymorphism (câu 2 chắc chắn)

**Template bài toán chuẩn:**
```
Cho bài toán quản lý [đối tượng] có [N loại khác nhau].
Mỗi loại có cách tính [giá trị X] riêng.
Viết chương trình [nhập dữ liệu] và tính [tổng/trung bình/tìm kiếm].
Bắt buộc sử dụng đa hình.
```

**Kỹ năng cần có:**
- Khai báo virtual function trong base class
- Override đúng chữ ký
- Dùng `vector<BaseClass*>` hoặc mảng con trỏ
- Gọi virtual → runtime dispatch đúng

### Dạng 2 — Cài đặt lớp theo main cho sẵn (câu 1 xu hướng mới)

**Template bài toán:**
```cpp
// Main cho sẵn:
int main() {
    MyClass obj;
    obj.Method1(param);
    obj.Method2();
    MyClass obj2 = obj;   // copy constructor
    MyClass obj3 = obj1 + obj2;  // operator+
    cout << obj[i];       // operator[]
}
// Yêu cầu: Cài đặt MyClass để main chạy được
```

**Kỹ năng cần có:**
- Đọc main → xác định các phương thức cần có
- Constructor (nhiều dạng), destructor, copy constructor
- Operator overloading đúng chữ ký
- Quản lý bộ nhớ động (new/delete)

### Dạng 3 — Operator Overloading cho kiểu dữ liệu số học

Hay gặp: Lớp **Phân số (Fraction)** với +, -, *, /, >, <, ==

---

## 📐 CẤU TRÚC ĐỀ THI

| Thuộc tính | Giá trị |
|-----------|---------|
| Số câu | **2 câu** (không đổi từ 2019–2026) |
| Điểm từng câu | **5 điểm + 5 điểm = 10 điểm** |
| Thời gian | **90 phút** |
| Tài liệu | **Không được dùng** (từ 2023 trở đi, một số đề trước có thể dùng) |
| Ngôn ngữ | **C++** |
| Dạng câu hỏi | **100% viết code** — không có lý thuyết, trắc nghiệm, code tracing |

---

## 🗺️ BỘ ĐỀ LUYỆN ƯU TIÊN

Dựa vào tần suất, nên luyện theo thứ tự:

1. **Inheritance + Polymorphism** — Bài học bổng SV (2019, 2021HK1, 2022HK1)
2. **Inheritance + Polymorphism** — Bài hình học (2024HK2, 2025HK1)
3. **Operator Overloading** — Bài phân số (2021HK1, 2024HK2)
4. **Big Three + Dynamic Array** — Bài CMyArray (2025HK2)
5. **Big Three + Dynamic String** — Bài CMyString (2026HK1) ← ĐỀ MỚI NHẤT
6. **Aggregation/Composition** — Bài đơn hàng (2024HK1)

---

## ⚡ ĐIỂM DỄ MẤT ĐIỂM TRONG THI

| Lỗi | Hậu quả |
|-----|---------|
| Quên `virtual` ở base class | Không có dynamic dispatch → câu 2 sai hoàn toàn |
| Quên `virtual destructor` khi dùng con trỏ base | Memory leak, undefined behavior |
| Copy constructor không deep copy | CMyString/CMyArray bị shallow copy |
| Quên `delete[]` trong destructor | Memory leak |
| Operator+ không trả về object mới | Logic sai |
| Dùng `if/else` thay polymorphism | Không đạt yêu cầu "bắt buộc dùng đa hình" |
