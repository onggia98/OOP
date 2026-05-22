# Đề Thi Thử 03 — Dạng 2026 (Khó Nhất)
> Thời gian: **90 phút** — Không được dùng tài liệu
> Dạng: Câu 1 = Dynamic class theo main cho sẵn (Big Three + Operator). Câu 2 = Abstract class + Polymorphism đầy đủ.
> Độ khó: ⭐⭐⭐⭐⭐

---

## CÂU 1 (5 điểm) — Lớp CMyMatrix

Cài đặt lớp `CMyMatrix` quản lý ma trận số nguyên (mảng 2 chiều động) để hàm `main` sau chạy đúng:

```cpp
int main() {
    // Tạo ma trận 2x3, nhập giá trị
    CMyMatrix m1(2, 3);
    m1.Set(0, 0, 1); m1.Set(0, 1, 2); m1.Set(0, 2, 3);
    m1.Set(1, 0, 4); m1.Set(1, 1, 5); m1.Set(1, 2, 6);

    cout << "m1:\n";
    m1.Print();
    // In ra:
    // 1 2 3
    // 4 5 6

    cout << "Sum = " << m1.Sum() << "\n";   // → 21
    cout << "Max = " << m1.Max() << "\n";   // → 6

    // Test deep copy — copy constructor
    CMyMatrix m2 = m1;
    m2.Set(0, 0, 99);
    cout << "m1[0][0] = " << m1.Get(0, 0) << "\n";  // → 1 (không đổi)
    cout << "m2[0][0] = " << m2.Get(0, 0) << "\n";  // → 99

    // Test deep copy — assignment operator
    CMyMatrix m3(1, 1);
    m3 = m1;
    m3.Set(1, 1, 100);
    cout << "m1[1][1] = " << m1.Get(1, 1) << "\n";  // → 5 (không đổi)

    // Test operator+
    CMyMatrix m4 = m1 + m2;
    cout << "m4[0][0] = " << m4.Get(0, 0) << "\n";  // → 1+99 = 100
    cout << "m4[0][1] = " << m4.Get(0, 1) << "\n";  // → 2+2 = 4

    return 0;
}
```

**Yêu cầu:**
- `CMyMatrix(int rows, int cols)` — constructor, cấp phát mảng 2D động, khởi tạo 0
- `~CMyMatrix()` — giải phóng bộ nhớ đúng cách
- Copy constructor — deep copy
- `operator=` — deep copy, có self-assignment guard
- `void Set(int r, int c, int val)` — đặt giá trị tại ô (r, c)
- `int Get(int r, int c) const` — lấy giá trị
- `void Print() const` — in ma trận, mỗi hàng một dòng
- `int Sum() const` — tổng tất cả phần tử
- `int Max() const` — giá trị lớn nhất
- `CMyMatrix operator+(const CMyMatrix& o) const` — cộng hai ma trận cùng kích thước

> **Gợi ý:** Dùng `int**` hoặc `int*` 1D giả lập 2D (`data[r * _cols + c]`). Cấp phát/giải phóng mảng 2D cần lặp qua từng hàng.

---

## CÂU 2 (5 điểm) — Hệ Thống Quản Lý Tài Khoản Ngân Hàng

Xây dựng hệ thống quản lý 3 loại tài khoản ngân hàng: **Tiết kiệm**, **Thanh toán**, **Đầu tư**. Bắt buộc sử dụng đa hình.

**Quy tắc tính lãi hàng tháng:**
- `TKTietKiem`: lãi = `soDu × laiSuat / 100 / 12` (laiSuat là % năm)
- `TKThanhToan`: lãi = `soDu × 0.001` (0.1% cố định/tháng), nếu `soDu < 50000` → lãi = 0
- `TKDauTu`: lãi = `soDu × laiSuat / 100 / 12`, nhưng nếu `soDu < 1000000` → lãi nhân thêm hệ số rủi ro 0.8

**Yêu cầu cài đặt:**
- Abstract base class `TaiKhoan` với:
  - `_soTK` (string), `_chuTK` (string), `_soDu` (double)
  - `virtual double tinhLai() const = 0`
  - `virtual string loaiTK() const = 0`
  - `virtual ~TaiKhoan() {}`
  - `void xuat() const` — in đủ thông tin (số TK, chủ, số dư, loại, lãi)
- 3 lớp con kế thừa: `TKTietKiem`, `TKThanhToan`, `TKDauTu`
- Class `NganHang` chứa `vector<TaiKhoan*>`:
  - `void them(TaiKhoan* tk)`
  - `void xuatTatCa() const`
  - `double tongLaiThang() const` — tổng lãi tháng toàn bộ tài khoản
  - `TaiKhoan* timMaxLai() const` — tìm TK có lãi tháng cao nhất
  - `void inTKLaiCao(double nguong) const` — in các TK có lãi > ngưỡng

**Test mẫu:**
```cpp
int main() {
    NganHang nh;
    nh.them(new TKTietKiem("TK001", "Nguyen Van A", 10000000, 6.5));   // lai: 10M×6.5/100/12
    nh.them(new TKThanhToan("TK002", "Tran Thi B", 30000));            // lai: 0 (< 50000)
    nh.them(new TKThanhToan("TK003", "Le Van C", 500000));             // lai: 500000×0.001
    nh.them(new TKDauTu("TK004", "Pham Thi D", 5000000, 8.0));        // lai: 5M×8/100/12

    nh.xuatTatCa();
    cout << "Tong lai thang: " << nh.tongLaiThang() << "\n";
    nh.timMaxLai()->xuat();
    nh.inTKLaiCao(1000);

    return 0;
}
```

---

## Checklist Sau Khi Làm

**Câu 1 — CMyMatrix:**
- [ ] Cấp phát đúng: `new int*[_rows]` + mỗi hàng `new int[_cols]`
- [ ] Destructor: for loop `delete[] _data[i]` rồi `delete[] _data`
- [ ] Copy constructor deep copy đúng
- [ ] `operator=` có self-assignment guard + delete cũ
- [ ] `operator+` trả về object mới (không sửa `this`)

**Câu 2 — NganHang:**
- [ ] `virtual ~TaiKhoan() {}` có trong base class
- [ ] 3 lớp con override `tinhLai()` và `loaiTK()`
- [ ] `vector<TaiKhoan*>` trong NganHang
- [ ] `~NganHang()` delete từng con trỏ
- [ ] `timMaxLai()` dùng virtual dispatch đúng

> Xem đáp án tại `study/mock_exams/mock_03_answer.md`
