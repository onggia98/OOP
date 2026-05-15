# Mẫu Thiết Kế Hướng Đối Tượng (Design Patterns) — OOP Slide 10
> Nguồn: raw/slides/OOP-10-Design Patterns.pptx
> Ngôn ngữ: C++

## Tóm tắt nội dung chính
Slide 10 tổng hợp và ứng dụng ba tính chất OOP (đóng gói, kế thừa, đa hình) thông qua các mẫu thiết kế (Design Patterns). Giới thiệu khái niệm Design Pattern và bộ 23 mẫu Gang of Four (GoF). Trình bày chi tiết ba mẫu thông dụng: **Singleton** (giới hạn số đối tượng), **Composite** (tổ chức cấu trúc phức hợp), và **Adapter** (tái sử dụng đối tượng không tương thích).

## Các khái niệm core

### 1. Ba tính chất OOP — mục đích thực sự
| Tính chất | Cơ chế | Mục tiêu |
|-----------|--------|----------|
| **Đóng gói** | Quy tắc hộp đen | Giảm phụ thuộc vào cài đặt cụ thể |
| **Kế thừa** | IS-A, reuse | Giảm chi phí xây mới |
| **Đa hình** | Virtual + liên kết động | Giảm gắn kết mã nguồn |

**Mục đích chung**: ứng phó thay đổi, dễ bảo trì, nâng cấp.

### 2. Design Pattern là gì?
- **Bài giải mẫu** cho những vấn đề thiết kế thường gặp trong OOP
- **Gang of Four (GoF)** — 1994 (OOPSLA): 23 mẫu thiết kế
- Chia làm 3 nhóm: Creational, Structural, Behavioral

### 3. Mẫu Singleton
**Vấn đề**: giới hạn số lượng đối tượng được tạo ra (ví dụ: chỉ 1 nhân viên phục vụ).
**Giải pháp**:
- Constructor `private` → bên ngoài không tạo trực tiếp được
- Static method `getInstance()` kiểm soát việc tạo đối tượng
- Lưu instance duy nhất trong static attribute

### 4. Mẫu Composite
**Vấn đề**: tổ chức đối tượng có cấu trúc cây (đơn/phức hợp cùng interface).
**Ví dụ**: mạch điện (cuộn dây đơn + mạch nối tiếp), thư mục (file + folder), chi tiết máy.
**Giải pháp**:
- Lớp cơ sở trừu tượng định nghĩa interface chung
- Lớp đơn (Leaf): cài đặt trực tiếp
- Lớp phức (Composite): chứa danh sách các lớp cơ sở, ủy quyền xử lý

### 5. Mẫu Adapter
**Vấn đề**: tái sử dụng đối tượng/lớp sẵn có vào ngữ cảnh khác (interface không khớp).
**Ví dụ**: tái sử dụng lớp `WildAnimal` (có `hunt()`, `shout()`) vào hàm `trainPet(Pet*)`.
**Giải pháp**: tạo lớp Adapter kế thừa interface mong muốn, bao bọc đối tượng cũ.

## Code examples / Syntax quan trọng

### Mẫu Singleton
```cpp
class NhanVienPhucVu {
private:
    int m_soBan;
    float m_tongTien;
    static NhanVienPhucVu *m_instance;  // Instance duy nhất

    NhanVienPhucVu() : m_soBan(0), m_tongTien(0) {}  // Constructor private

public:
    static NhanVienPhucVu* getInstance() {
        if (m_instance == nullptr)
            m_instance = new NhanVienPhucVu();
        return m_instance;
    }

    void donKhach() {
        if (m_soBan < 5) m_soBan++;
    }
    void tinhTienKhach(float soTien) {
        m_tongTien += soTien;
        m_soBan--;
    }
    float tinhTienThuong() { return m_tongTien * 0.05f; }
};

// Khởi tạo static ngoài lớp
NhanVienPhucVu* NhanVienPhucVu::m_instance = nullptr;

// Sử dụng — không dùng new trực tiếp
NhanVienPhucVu *nv = NhanVienPhucVu::getInstance();
nv->donKhach();
```

### Mẫu Composite — bài toán mạch điện
```cpp
// Lớp cơ sở trừu tượng — interface chung
class MachDien {
public:
    virtual float tinhDienTro() = 0;  // Pure virtual
};

// Leaf — mạch đơn
class CuonDay : public MachDien {
private:
    float m_tietDien;
    float m_chieuDai;
public:
    CuonDay(float S, float L) : m_tietDien(S), m_chieuDai(L) {}
    float tinhDienTro() {
        return 0.5 * m_chieuDai / m_tietDien;
    }
};

// Composite — mạch phức hợp
class MachNoiTiep : public MachDien {
private:
    vector<MachDien*> m_machCon;  // Chứa danh sách mạch con
public:
    void them(MachDien *m) { m_machCon.push_back(m); }
    float tinhDienTro() {
        float tong = 0;
        for (int i = 0; i < m_machCon.size(); i++)
            tong += m_machCon[i]->tinhDienTro();  // Đa hình!
        return tong;
    }
};

// Sử dụng
MachNoiTiep mach;
mach.them(new CuonDay(2, 10));
mach.them(new CuonDay(3, 15));
// mach có thể chứa cả MachNoiTiep khác → đệ quy
```

### Mẫu Adapter — giải quyết không tương thích interface
```cpp
class Pet {
public:
    virtual void eat() = 0;
    virtual void talk() = 0;
};

class WildAnimal {
public:
    virtual void hunt() = 0;
    virtual void eatMeat() = 0;
    virtual void shout() = 0;
};

class Tiger : public WildAnimal { /* ... */ };

// Adapter: bọc Tiger vào interface Pet
class TigerAdapter : public Pet {
private:
    WildAnimal *m_wildAnimal;  // Bao bọc đối tượng không tương thích
public:
    TigerAdapter(WildAnimal *wa) : m_wildAnimal(wa) {}
    void eat() { m_wildAnimal->eatMeat(); }  // Ánh xạ eat → eatMeat
    void talk() { m_wildAnimal->shout(); }   // Ánh xạ talk → shout
};

void trainPet(Pet *p) {
    p->eat();
    p->talk();
}

void main() {
    Tiger t;
    TigerAdapter adapter(&t);
    trainPet(&adapter);  // Huấn luyện cọp qua adapter!
}
```

### Bài toán Video Rental — áp dụng tổng hợp
```cpp
// Lớp trừu tượng phim
class Movie {
public:
    virtual float tinhPhi(int ngay) = 0;
    virtual int tinhDiemThuong(int ngay) { return 0; } // Mặc định không có điểm
};

class PhimThuong : public Movie {
public:
    float tinhPhi(int ngay) {
        float phi = 2.0;
        if (ngay > 2) phi += (ngay - 2) * 1.5;
        return phi;
    }
};

class PhimTreEm : public Movie {
public:
    float tinhPhi(int ngay) {
        float phi = 1.5;
        if (ngay > 3) phi += (ngay - 3) * 1.5;
        return phi;
    }
};

class PhimMoi : public Movie {
public:
    float tinhPhi(int ngay) { return 3.0 * ngay; }
    int tinhDiemThuong(int ngay) { return ngay; }  // Override — có điểm thưởng
};
```

## Điểm hay thi / Lưu ý
- **Singleton**: constructor `private` là điểm mấu chốt — ngăn tạo đối tượng tự do
- **Composite**: lớp phức và lớp đơn cùng một interface → có thể xử lý đồng nhất qua đa hình
- **Adapter**: không thay đổi code lớp cũ — chỉ thêm lớp bọc → nguyên tắc Open/Closed
- **Video Rental** là bài toán hay ra thi — kiểm tra hiểu biết về kế thừa + virtual + đa hình
- Ba tính chất OOP phải **đồng thời** thỏa mãn — chỉ dùng class mà không đóng gói, kế thừa, đa hình đúng cách thì chưa phải OOP thực sự
- **Khi nào dùng Composite?** Khi cấu trúc có dạng cây — phần đơn và phần phức có cùng interface

## Thuật ngữ
- **Design Pattern** (Mẫu thiết kế): bài giải mẫu cho vấn đề OOP thường gặp
- **Gang of Four (GoF)**: nhóm 4 tác giả — Gamma, Helm, Johnson, Vlissides — tác giả sách 23 mẫu
- **Singleton**: mẫu đảm bảo chỉ một đối tượng được tạo
- **Composite**: mẫu tổ chức cấu trúc cây — Leaf và Composite cùng interface
- **Adapter**: mẫu chuyển đổi interface — tái sử dụng code không tương thích
- **Creational patterns**: nhóm mẫu tạo đối tượng (Singleton thuộc nhóm này)
- **Structural patterns**: nhóm mẫu cấu trúc (Composite, Adapter thuộc nhóm này)
- **Open/Closed Principle**: mở để mở rộng, đóng để sửa đổi
