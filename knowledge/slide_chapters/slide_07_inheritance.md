# Kế Thừa (Inheritance) — OOP Slide 07
> Nguồn: raw/slides/OOP-07-Inheritance.pptx
> Ngôn ngữ: C++

## Tóm tắt nội dung chính
Slide 07 trình bày khái niệm kế thừa trong OOP — cách định nghĩa lớp mới dựa trên lớp đã có để tái sử dụng code. Bao gồm cú pháp khai báo kế thừa trong C++, bảng tầm vực trong kế thừa, kỹ thuật định nghĩa lại phương thức, và quan trọng là hai quan hệ cần phân biệt: IS-A (dùng kế thừa) và HAS-A (dùng thành phần).

## Các khái niệm core

### 1. Khái niệm kế thừa
- **Lớp cơ sở (Base class)**: lớp được dùng để định nghĩa lớp mới
- **Lớp kế thừa (Derived class)**: lớp được định nghĩa từ lớp cơ sở
- Lớp kế thừa **thừa hưởng TẤT CẢ** thuộc tính và phương thức của lớp cơ sở
- Giải quyết vấn đề trùng lắp thông tin → tái sử dụng code

### 2. Cú pháp kế thừa trong C++
```
class <Lớp kế thừa> : <Loại kế thừa> <Lớp cơ sở>
```
Loại kế thừa: `public`, `protected`, `private`

### 3. Bảng tầm vực trong kế thừa

| Tầm vực gốc | Kế thừa `public` | Kế thừa `protected` | Kế thừa `private` |
|-------------|-----------------|---------------------|-------------------|
| `public` | `public` | `protected` | `private` |
| `protected` | `protected` | `protected` | `private` |
| `private` | **Không thể truy xuất** | **Không thể truy xuất** | **Không thể truy xuất** |

> Private của lớp cơ sở **không bao giờ** truy xuất được từ lớp kế thừa!

### 4. Định nghĩa lại phương thức (Method Overriding)
- Lớp kế thừa có thể **viết lại** phương thức đã thừa hưởng
- Dùng `TênLớpCơSở::tênPhươngThức()` để gọi phiên bản lớp cơ sở từ trong lớp kế thừa
- Lớp kế thừa ưu tiên phiên bản của mình, bỏ qua phiên bản kế thừa

### 5. Quan hệ IS-A và HAS-A

| Quan hệ | Ý nghĩa | Cài đặt |
|---------|---------|---------|
| **IS-A** | A là trường hợp đặc biệt của B | A kế thừa B |
| **HAS-A** | A bao hàm B (B là bộ phận của A) | B là thuộc tính của A |

**Chỉ dùng kế thừa khi và chỉ khi có quan hệ IS-A!**

## Code examples / Syntax quan trọng

### Khai báo kế thừa cơ bản
```cpp
class GiaoVien {
private:
    char *m_hoTen;
    float m_mucLuong;
    int m_ngayNghi;
public:
    GiaoVien(char *hoTen, float mucLuong, int ngayNghi);
    void giangDay();
    float tinhLuong() {
        return m_mucLuong - m_ngayNghi * 100000;
    }
};

// GVCN IS-A GiaoVien → kế thừa
class GVCN : public GiaoVien {
private:
    char *m_lopCN;   // Thêm thuộc tính mới
public:
    GVCN(char *hoTen, float mucLuong, int ngayNghi, char *lopCN);
    void sinhHoatCN();  // Thêm phương thức mới
};
```

### Sử dụng lớp kế thừa
```cpp
void main() {
    GiaoVien gv1("Minh", 500000, 5);
    gv1.giangDay();
    float luong1 = gv1.tinhLuong();

    GVCN gv2("Hanh", 700000, 3, "10A5");
    gv2.giangDay();      // Thừa hưởng từ GiaoVien
    gv2.sinhHoatCN();    // Phương thức riêng của GVCN
    float luong2 = gv2.tinhLuong(); // Thừa hưởng từ GiaoVien
}
```

### Định nghĩa lại phương thức
```cpp
class GVCN : public GiaoVien {
public:
    // Ghi đè (override) tinhLuong()
    float tinhLuong() {
        // Gọi phiên bản của lớp cơ sở qua ::
        return GiaoVien::tinhLuong() + 1000000;  // Cộng thêm phụ cấp
    }
};
```

### Quan hệ IS-A vs HAS-A
```cpp
// IS-A: ConMeo là ConVat → kế thừa
class ConMeo : public ConVat { };

// HAS-A: ChiecXe có BanhXe → thuộc tính
class ChiecXe {
private:
    BanhXe *m_banhXe;   // BanhXe là thành phần của ChiecXe
};
```

### Bảng tầm vực — ví dụ thực tế
```cpp
class O {
private:   int m_priv;    // Không thể truy xuất từ A
protected: int m_prot;    // A có thể truy xuất
public:    int m_pub;     // A có thể truy xuất
};

class A : public O {
    void method() {
        // m_priv  // Sai — private của O
        m_prot = 1;  // Đúng — protected
        m_pub = 2;   // Đúng — public
    }
};
```

## Điểm hay thi / Lưu ý
- **Kế thừa `public`** là dạng phổ biến nhất trong thực tế — `protected` và `private` ít dùng
- **Private không kế thừa được** (kể cả trong lớp kế thừa) → dùng `protected` nếu cần lớp con truy cập
- **Luật IS-A**: sai lầm phổ biến là kế thừa vì "có nhiều thuộc tính giống nhau" mà không có quan hệ IS-A → nên dùng HAS-A thay thế
- **Hình vuông IS-A Hình chữ nhật**: nghe có vẻ đúng nhưng thực tế có vấn đề về Liskov Substitution Principle — đây là ví dụ kinh điển hay ra đề
- `GiaoVien::tinhLuong()` — cú pháp gọi phương thức lớp cơ sở từ lớp kế thừa
- Lớp kế thừa vẫn **không thể truy xuất** private của lớp cơ sở, kể cả với kế thừa `public`

## Thuật ngữ
- **Inheritance** (Kế thừa): lớp con thừa hưởng từ lớp cha
- **Base class / Parent class** (Lớp cơ sở): lớp được kế thừa
- **Derived class / Child class** (Lớp kế thừa): lớp kế thừa
- **Method Overriding** (Định nghĩa lại): lớp con ghi đè phương thức lớp cha
- **IS-A relationship**: quan hệ "là một loại" → dùng kế thừa
- **HAS-A relationship**: quan hệ "bao hàm" → dùng composition
- **Reusability** (Tái sử dụng): mục đích chính của kế thừa
