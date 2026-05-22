# Mock Exam 01 — CSC10003 OOP
> Dạng: tương tự đề 2024 HK2 | Thời gian: 90 phút | Không xem tài liệu  
> Điều kiện thi thật: viết tay hoặc gõ code không chạy thử

---

**Ngày làm:** ___________  
**Thời gian bắt đầu:** ___________  
**Thời gian kết thúc:** ___________

---

## Câu 1 (5 điểm) — Operator Overloading + Class Design

Viết chương trình cho phép nhập vào một mảng các **số phức** và tính **tổng** của tất cả các số phức đó.

Yêu cầu:
- Biểu diễn số phức bằng class `SoPhuc` với phần thực (`_re`) và phần ảo (`_im`).
- **Bắt buộc cài đặt các toán tử cần thiết** khi thực hiện phép cộng hai số phức và khi in ra màn hình.
- Cụ thể: để cộng 2 số phức `a` và `b`, phải viết được theo kiểu `a + b`.
- In kết quả dạng: `3 + 4i` hoặc `3 - 4i` (xử lý dấu của phần ảo).

**Ví dụ:**
```
Nhap so phan tu: 3
Nhap so phuc 1: 1 2     → 1 + 2i
Nhap so phuc 2: 3 -1    → 3 - 1i
Nhap so phuc 3: -2 4    → -2 + 4i
Tong: 2 + 5i
```

---

## Câu 2 (5 điểm) — Inheritance + Polymorphism

Xây dựng hệ thống quản lý **nhân viên** trong một công ty. Công ty có hai loại nhân viên:

- **Nhân viên chính thức** (`NhanVienChinhThuc`): có lương cơ bản và phụ cấp.  
  Lương thực nhận = lương cơ bản + phụ cấp.

- **Nhân viên hợp đồng** (`NhanVienHopDong`): có lương ngày và số ngày đã làm trong tháng.  
  Lương thực nhận = lương ngày × số ngày làm.

Yêu cầu:
- Nhập vào danh sách nhân viên (hỗn hợp 2 loại).
- Tính và in ra lương của từng nhân viên.
- Tính **tổng quỹ lương** của toàn công ty.
- **Bắt buộc sử dụng đa hình.**

**Ví dụ output:**
```
=== Danh sach nhan vien ===
Nguyen Van A (Chinh thuc) - Luong: 8,500,000
Tran Thi B (Hop dong) - Luong: 4,200,000
Le Van C (Chinh thuc) - Luong: 12,000,000
Tong quy luong: 24,700,000
```

---

*Lật trang để xem đáp án — hoặc xem file `mock_01_answer.md`*
