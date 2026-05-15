# Vòng Đời Đối Tượng Trong Kế Thừa — OOP Slide 08
> Nguồn: raw/slides/OOP-08-Object Life Cycle in Inheritance.pptx
> Ngôn ngữ: C++

## Tóm tắt nội dung chính
Slide 08 trình bày chi tiết thứ tự khởi tạo và hủy đối tượng trong mối quan hệ kế thừa. Constructor của lớp cơ sở luôn chạy trước; destructor theo thứ tự ngược lại. Phần hai mở rộng "Luật Ba Ông Lớn" cho trường hợp kế thừa — khi lớp kế thừa có con trỏ động, "ông lớn" của lớp kế thừa phải kích hoạt "ông lớn" tương ứng của lớp cơ sở.

## Các khái niệm core

### 1. Thứ tự khởi tạo trong kế thừa
- Xây từ **móng đến mái** — tạo phần lõi (lớp cơ sở) trước, phần vỏ (lớp kế thừa) sau
- **Constructor lớp cơ sở → Constructor lớp kế thừa**
- Lớp kế thừa có thể **chỉ định** constructor lớp cơ sở nào được gọi
- Nếu không chỉ định → constructor **mặc định** của lớp cơ sở được gọi

### 2. Thứ tự hủy trong kế thừa
- Ngược với thứ tự tạo — hủy từ **vỏ vào lõi**
- **Destructor lớp kế thừa → Destructor lớp cơ sở**
- Lớp kế thừa **không cần** chỉ định destructor lớp cơ sở (tự động)

### 3. Luật Ba Ông Lớn trong kế thừa
Khi lớp kế thừa **có thêm** thuộc tính con trỏ động:
- Trang bị Ba Ông Lớn cho **lớp kế thừa**
- "Ông lớn" của lớp kế thừa **kích hoạt** "ông lớn" tương ứng của lớp cơ sở
- Destructor: tự động gọi destructor lớp cơ sở sau
- Copy constructor: gọi tường minh bằng `TênLớpCơSở(b)` trong member initializer list
- Operator=: gọi tường minh bằng `TênLớpCơSở::operator=(b)`

## Code examples / Syntax quan trọng

### Thứ tự constructor — cú pháp chỉ định
```cpp
class GiaoVien {
public:
    GiaoVien();
    GiaoVien(char *hoTen, float mucLuong, int ngayNghi);
};

class GVCN : public GiaoVien {
private:
    char *m_lopCN;
public:
    // Chỉ định constructor lớp cơ sở qua member initializer list
    GVCN(char *lopCN) : GiaoVien("Minh", 500000, 0) {
        m_lopCN = new char[strlen(lopCN) + 1];
        strcpy(m_lopCN, lopCN);
    }

    // Constructor đầy đủ
    GVCN(char *hoTen, float mucLuong, int ngayNghi, char *lopCN)
        : GiaoVien(hoTen, mucLuong, ngayNghi) {   // Gọi constructor cơ sở
        m_lopCN = new char[strlen(lopCN) + 1];
        strcpy(m_lopCN, lopCN);
    }

    // Constructor mặc định: GiaoVien() được gọi trước tự động
    GVCN() {}
};
```

### Thứ tự destructor
```cpp
GiaoVien::~GiaoVien() {
    delete[] m_hoTen;  // Hủy phần lõi
}

GVCN::~GVCN() {
    delete[] m_lopCN;  // Hủy phần vỏ TRƯỚC
    // Sau khi hàm này kết thúc, ~GiaoVien() tự động gọi
}
```

### Ba Ông Lớn trong kế thừa — ví dụ đầy đủ
```cpp
class A {
public:
    A(const A &a);
    A& operator=(const A &a);
    virtual ~A();
};

class B : public A {
private:
    int *m_data;  // Con trỏ → cần Ba Ông Lớn
public:
    // Copy constructor — kích hoạt copy constructor của A
    B(const B &b) : A(b) {
        // Cài đặt deep copy phần riêng của B
        m_data = new int(*b.m_data);
    }

    // Operator= — kích hoạt operator= của A
    B& operator=(const B &b) {
        if (this == &b) return *this;
        A::operator=(b);        // Gọi operator= của lớp cơ sở
        delete m_data;
        m_data = new int(*b.m_data);
        return *this;
    }

    // Destructor — ~A() tự động gọi sau
    ~B() {
        delete m_data;
    }
};
```

### Ví dụ xác định thứ tự khởi tạo (bài tập)
```cpp
class A { public: A(int iX) {} };
class B : public A {
public:
    B() {}
    B(int iX, int iY) : A(iX) {}
};
class C : public B {
public:
    C() {}
    C(int iZ) {}
    C(int iX, int iY, int iZ) : B(iX, iY) {}
};

// a) C obj(1,2,3) → A(1) → B(1,2) → C(1,2,3)
// b) C obj(4)     → A() [mặc định] → B() [mặc định] → C(4)
// c) C obj        → A() [mặc định] → B() [mặc định] → C() [mặc định]
```

## Điểm hay thi / Lưu ý
- **Thứ tự constructor**: lớp cơ sở → lớp kế thừa (từ gốc đến ngọn trong cây kế thừa)
- **Thứ tự destructor**: ngược lại — lớp kế thừa → lớp cơ sở
- Cú pháp gọi constructor lớp cơ sở: **member initializer list** (sau dấu `:`) — không gọi trong thân constructor
- Nếu không chỉ định → constructor **mặc định** (không tham số) của lớp cơ sở bắt buộc phải tồn tại
- **Hay ra bài**: cho cây kế thừa 3 lớp A→B→C, xác định thứ tự gọi constructor/destructor với từng cách khởi tạo
- Trong `operator=` của lớp kế thừa: gọi `BaseClass::operator=(b)` để xử lý phần thuộc tính của lớp cơ sở
- **Destructor ảo** (virtual destructor): sẽ học ở slide 09 — cần thiết khi dùng con trỏ lớp cơ sở

## Thuật ngữ
- **Member initializer list**: danh sách khởi tạo thành phần (sau `:` trong constructor)
- **Construction order**: thứ tự xây dựng — từ lõi đến vỏ (cơ sở → kế thừa)
- **Destruction order**: thứ tự hủy — từ vỏ đến lõi (kế thừa → cơ sở)
- **Big Three in inheritance**: Ba Ông Lớn áp dụng trong cây kế thừa
- **Chaining constructors**: chuỗi gọi constructor qua các cấp kế thừa
