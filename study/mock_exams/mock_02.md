# Mock Exam 02 — CSC10003 OOP
> Dạng: tương tự đề 2025–2026 (mới nhất) | Thời gian: 90 phút | Không xem tài liệu  
> Khó hơn Mock 01 — có Big Three và câu 2 phức tạp hơn

---

**Ngày làm:** ___________  
**Thời gian bắt đầu:** ___________  
**Thời gian kết thúc:** ___________

---

## Câu 1 (5 điểm) — Big Three + Operator Overloading

Cài đặt các lớp cần thiết để thực hiện được hàm `main` sau:

```cpp
int main() {
    CStack st;
    st.Push(10);
    st.Push(20);
    st.Push(30);

    cout << "Size: " << st.Size() << endl;       // → 3
    cout << "Top: "  << st.Top()  << endl;       // → 30

    CStack st2 = st;       // copy constructor
    st2.Pop();
    cout << "st2 top: " << st2.Top() << endl;    // → 20
    cout << "st top: "  << st.Top()  << endl;    // → 30 (không đổi)

    CStack st3;
    st3 = st;              // assignment operator
    st3.Push(99);
    cout << "st3 size: " << st3.Size() << endl;  // → 4
    cout << "st size: "  << st.Size()  << endl;  // → 3 (không đổi)

    return 0;
}
```

---

## Câu 2 (5 điểm) — Inheritance + Polymorphism

Xây dựng hệ thống quản lý **các loại tài khoản ngân hàng**. Ngân hàng có hai loại tài khoản:

- **Tài khoản tiết kiệm** (`TKTietKiem`): có số dư và lãi suất (%/năm).  
  Tiền lãi 1 năm = số dư × lãi suất / 100

- **Tài khoản thanh toán** (`TKThanhToan`): có số dư và phí duy trì hàng tháng.  
  Chi phí 1 năm = phí duy trì × 12

Yêu cầu:
- Nhập vào danh sách các tài khoản (hỗn hợp 2 loại).
- In thông tin từng tài khoản.
- Tìm và in ra **tài khoản có số dư cao nhất**.
- **Bắt buộc sử dụng đa hình.**

**Thông tin chung của tài khoản:** số tài khoản, tên chủ tài khoản, số dư.

**Ví dụ output:**
```
=== Danh sach tai khoan ===
TK001 - Nguyen Van A [Tiet kiem] - So du: 50,000,000 - Lai/nam: 2,500,000
TK002 - Tran Thi B [Thanh toan] - So du: 10,000,000 - Phi/nam: 240,000
TK003 - Le Van C [Tiet kiem] - So du: 100,000,000 - Lai/nam: 5,000,000
Tai khoan so du cao nhat: TK003 - Le Van C (100,000,000)
```

---

*Xem đáp án tại `mock_02_answer.md`*
