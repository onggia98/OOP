# Bài Tập — Ngày 1: Class Design + Encapsulation
> Làm theo thứ tự: Dễ → Trung bình → Nâng cao  
> Mỗi bài: đọc đề → suy nghĩ → viết code → tự chấm

---

## Bài 1 — Dễ (10 phút)

**Viết class `HinhChuNhat`** với:
- Thuộc tính: chiều dài (`_dai`), chiều rộng (`_rong`) kiểu `double`
- Constructor nhận 2 tham số
- Method: `tinhDienTich()`, `tinhChuVi()`, `xuat()`

**Kết quả mong đợi:**
```
HinhChuNhat(5.0, 3.0)
Dien tich: 15
Chu vi: 16
```

<details>
<summary>Đáp án</summary>

```cpp
class HinhChuNhat {
private:
    double _dai, _rong;
public:
    HinhChuNhat(double dai, double rong) : _dai(dai), _rong(rong) {}
    double tinhDienTich() const { return _dai * _rong; }
    double tinhChuVi() const { return 2 * (_dai + _rong); }
    void xuat() const {
        cout << "Dien tich: " << tinhDienTich() << "\n"
             << "Chu vi: "   << tinhChuVi()    << "\n";
    }
};
```
</details>

---

## Bài 2 — Trung bình (20 phút)

**Viết class `SinhVien` và `LopHoc`:**

`SinhVien`:
- Thuộc tính: `_maSV` (string), `_hoTen` (string), `_diemTB` (float)
- Constructor đủ tham số + default
- Getter cho cả 3 thuộc tính
- `void nhap()`, `void xuat() const`

`LopHoc`:
- Thuộc tính: `_tenLop` (string), `_dsv` (`vector<SinhVien>`)
- `void them(SinhVien sv)`
- `void xuatTatCa() const`
- `SinhVien timMax() const` — tìm SV có điểm TB cao nhất
- `void inSVDuongTiem(float nguong) const` — in SV có điểm TB ≥ ngưỡng

**Test:**
```cpp
LopHoc lop("20CLC01");
lop.them(SinhVien("SV001", "Nguyen Van A", 8.5));
lop.them(SinhVien("SV002", "Tran Thi B", 9.2));
lop.them(SinhVien("SV003", "Le Van C", 7.8));
lop.xuatTatCa();
cout << "Diem cao nhat: "; lop.timMax().xuat();
lop.inSVDuongTiem(8.0);  // in A và B
```

<details>
<summary>Đáp án</summary>

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SinhVien {
private:
    string _maSV, _hoTen;
    float  _diemTB;
public:
    SinhVien() : _maSV(""), _hoTen(""), _diemTB(0) {}
    SinhVien(string ma, string ht, float dtb)
        : _maSV(ma), _hoTen(ht), _diemTB(dtb) {}
    string getMaSV() const { return _maSV; }
    string getHoTen() const { return _hoTen; }
    float getDiemTB() const { return _diemTB; }
    void nhap() { cin >> _maSV >> _hoTen >> _diemTB; }
    void xuat() const {
        cout << _maSV << " | " << _hoTen << " | " << _diemTB << "\n";
    }
};

class LopHoc {
private:
    string _tenLop;
    vector<SinhVien> _dsv;
public:
    LopHoc(string tenLop) : _tenLop(tenLop) {}
    void them(SinhVien sv) { _dsv.push_back(sv); }
    void xuatTatCa() const {
        cout << "Lop: " << _tenLop << "\n";
        for (const auto& sv : _dsv) sv.xuat();
    }
    SinhVien timMax() const {
        SinhVien max = _dsv[0];
        for (const auto& sv : _dsv)
            if (sv.getDiemTB() > max.getDiemTB()) max = sv;
        return max;
    }
    void inSVDuongTiem(float nguong) const {
        cout << "SV co diem TB >= " << nguong << ":\n";
        for (const auto& sv : _dsv)
            if (sv.getDiemTB() >= nguong) sv.xuat();
    }
};
```
</details>

---

## Bài 3 — Nâng cao (30 phút)

**Làm câu 1 đề 2019 HK2 thực tế:**

Viết chương trình cho phép nhập vào danh sách học sinh (mã HS, tên, địa chỉ, điểm toán, điểm văn), tìm học sinh có điểm trung bình cao nhất.

Yêu cầu:
- Điểm TB = (điểm toán + điểm văn) / 2
- Class `HocSinh` với đủ thuộc tính
- Class `DanhSach` chứa `vector<HocSinh>`
- Nhập n học sinh từ bàn phím
- In ra học sinh có điểm TB cao nhất

<details>
<summary>Gợi ý cấu trúc (chưa có code đầy đủ)</summary>

```cpp
class HocSinh {
    string _ma, _ten, _diaChi;
    float  _diemToan, _diemVan;
public:
    HocSinh(string ma, string ten, string dc, float toan, float van);
    float getDiemTB() const { return (_diemToan + _diemVan) / 2.0f; }
    void nhap();
    void xuat() const;
};

class DanhSach {
    vector<HocSinh> _ds;
public:
    void them(HocSinh hs);
    HocSinh timMax() const;
    void xuat() const;
};
```
</details>

---

## Checklist sau khi làm xong

- [ ] Bài 1: class đơn giản với constructor + method — làm trong < 10 phút
- [ ] Bài 2: 2 class có quan hệ Composition — làm trong < 25 phút
- [ ] Bài 3: đề thật — làm được hết không cần gợi ý

**Điểm yếu phát hiện hôm nay:** _(ghi vào `notes/weak_points.md`)_
