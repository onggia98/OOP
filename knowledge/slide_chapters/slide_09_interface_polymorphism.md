# Interface và Đa Hình (Polymorphism) — OOP Slide 09
> Nguồn: raw/slides/OOP-09-Interface and Polymorphism.pptx
> Ngôn ngữ: C++

## Tóm tắt nội dung chính
Slide 09 là một trong những slide quan trọng nhất của môn học. Trình bày khái niệm interface, cơ chế liên kết tĩnh vs. liên kết động, hàm ảo (virtual function), hàm thuần ảo (pure virtual function), và lớp trừu tượng (abstract class). Kết thúc với quy tắc bắt buộc: destructor phải là virtual khi dùng con trỏ đa hình.

## Các khái niệm core

### 1. Interface
- Phần **public** của lớp — giao thức giao tiếp với bên ngoài
- `Lớp = Interface + Khai báo private + Cài đặt`
- Lớp kế thừa **thừa hưởng interface** của lớp cơ sở → có thể được dùng thay thế nhau

### 2. Tính đa hình trong kế thừa
- Hàm nhận `Animal*` có thể nhận `Cat*`, `Dog*` (lớp kế thừa của Animal)
- Con trỏ kiểu lớp cơ sở có thể trỏ đến đối tượng lớp kế thừa

### 3. Liên kết tĩnh vs. Liên kết động

| Loại | Gắn lúc nào | Từ khóa | Gọi qua |
|------|------------|---------|---------|
| **Liên kết tĩnh** | Lúc dịch (compile time) | (mặc định) | Bất kỳ |
| **Liên kết động** | Lúc chạy (runtime) | `virtual` | Con trỏ/tham chiếu |

**Vấn đề liên kết tĩnh**: khi gọi phương thức qua con trỏ lớp cơ sở → luôn gọi phiên bản lớp cơ sở, bỏ qua override của lớp kế thừa.

### 4. Hàm ảo (Virtual Function)
- Khai báo: `virtual <Chữ ký hàm>;`
- Lời gọi **chỉ gắn với interface**, phần cài đặt xác định lúc chạy tùy đối tượng thực
- **Chỉ dùng được qua con trỏ hoặc tham chiếu** — không hoạt động qua giá trị

### 5. Hàm thuần ảo (Pure Virtual Function)
- Khai báo: `virtual <Chữ ký hàm> = 0;`
- **Chỉ có khai báo, không có cài đặt**
- Lớp chứa ít nhất 1 pure virtual → **lớp trừu tượng (abstract class)**
- **Không thể tạo đối tượng** từ lớp trừu tượng
- Lớp kế thừa **phải override** tất cả pure virtual mới trở thành lớp cụ thể (concrete class)

### 6. Destructor ảo (Virtual Destructor)
- **Bắt buộc** khi dùng con trỏ lớp cơ sở trỏ đến lớp kế thừa
- Không có virtual destructor → khi `delete p` (p là con trỏ lớp cơ sở), chỉ gọi destructor lớp cơ sở → rò rỉ bộ nhớ của lớp kế thừa

## Code examples / Syntax quan trọng

### Vấn đề liên kết tĩnh
```cpp
class Animal {
public:
    void talk() { cout << "Don't talk"; }
};
class Cat : public Animal {
public:
    void talk() { cout << "Meo meo"; }
};

void xuLy(Animal *p) {
    p->talk();  // Liên kết tĩnh → luôn gọi Animal::talk()!
}

void main() {
    Cat c;
    xuLy(&c);   // In "Don't talk" — SAI!
    
    Animal *p = &c;
    p->talk();  // In "Don't talk" — SAI!
}
```

### Giải pháp: hàm ảo
```cpp
class Animal {
public:
    virtual void talk() { cout << "Don't talk"; }  // Thêm virtual
};
class Cat : public Animal {
public:
    void talk() { cout << "Meo meo"; }
};
class Dog : public Animal {
public:
    void talk() { cout << "Gau gau"; }
};

void xuLy(Animal *p) {
    p->talk();  // Liên kết động → gọi đúng phiên bản!
}

void main() {
    Cat c; Dog d;
    xuLy(&c);   // In "Meo meo" ✓
    xuLy(&d);   // In "Gau gau" ✓
}
```

### Lớp trừu tượng — hàm thuần ảo
```cpp
class Animal {
public:
    virtual void talk() = 0;  // Pure virtual — lớp trừu tượng
};
class Cat : public Animal {
public:
    void talk() { cout << "Meo meo"; }  // Phải override
};

void main() {
    Animal *p;
    p = new Animal; // LỖI — lớp trừu tượng, không tạo được đối tượng
    p = new Cat;    // Đúng — Cat là concrete class
    p->talk();      // "Meo meo"
}
```

### Destructor ảo
```cpp
class GiaoVien {
private:
    char *m_hoTen;
public:
    virtual ~GiaoVien() {   // Phải là virtual!
        delete[] m_hoTen;
    }
};
class GVCN : public GiaoVien {
private:
    char *m_lopCN;
public:
    ~GVCN() { delete[] m_lopCN; }
};

void main() {
    GiaoVien *p = new GVCN;
    delete p;
    // Với virtual destructor: ~GVCN() → ~GiaoVien() ✓
    // Không có virtual: chỉ ~GiaoVien() → m_lopCN rò rỉ ✗
}
```

### Bài tập kinh điển — xác định output
```cpp
class A {
public:
    virtual void f1() { cout << "Good morning.\n"; f2(); }
    virtual void f2() { cout << "Good afternoon.\n"; }
};
class B : public A {
public:
    void f1() { cout << "Good evening.\n"; f2(); }
    void f2() { cout << "Good night.\n"; }
};

void main() {
    A *p = new B;
    p->f1();
}
// f1() virtual → gọi B::f1() → "Good evening." → f2()
// f2() virtual → liên kết động, p thực sự là B → B::f2() → "Good night."
// Output: "Good evening.\nGood night.\n"
```

### Lợi ích của đa hình — code tổng quát
```cpp
// ĐÚNG — một hàm cho tất cả loại
void giveATalk(Animal *p) {
    p->talk();   // Gọi đúng loại tùy đối tượng truyền vào
}

// SAI — phải sửa code mỗi khi thêm loại mới
void giveATalk(int type) {
    if (type == 0) { Cat c; c.talk(); }
    else if (type == 1) { Dog d; d.talk(); }
}
```

## Điểm hay thi / Lưu ý
- **Liên kết động chỉ hoạt động qua CON TRỎ hoặc THAM CHIẾU** — không qua giá trị!
  - `xuLy(Animal p)` → liên kết tĩnh (object slicing)
  - `xuLy(Animal *p)` hoặc `xuLy(Animal &p)` → liên kết động
- **Hàm ảo trong lớp cơ sở → lớp kế thừa override không cần viết lại `virtual`** (nhưng nên viết để rõ ràng)
- **Destructor PHẢI virtual** khi lớp có lớp kế thừa dùng qua con trỏ — quy tắc Dr. Guru
- **Lớp trừu tượng không tạo được đối tượng** nhưng vẫn có thể có **con trỏ** kiểu đó
- `= 0` ở pure virtual — đây là cú pháp C++ giả lập interface (không có keyword `interface` như Java)
- **Bài tập hay ra**: xác định output khi có virtual/không virtual ở các hàm f1, f2

## Thuật ngữ
- **Interface**: tập hợp phương thức public — giao thức giao tiếp
- **Virtual function** (Hàm ảo): liên kết động — gắn cài đặt lúc runtime
- **Pure virtual function** (Hàm thuần ảo): `= 0` — bắt buộc override ở lớp kế thừa
- **Abstract class** (Lớp trừu tượng): có ít nhất 1 pure virtual — không tạo được đối tượng
- **Concrete class** (Lớp cụ thể): override hết pure virtual — tạo được đối tượng
- **Static binding** (Liên kết tĩnh): gắn cài đặt lúc compile
- **Dynamic binding** (Liên kết động): gắn cài đặt lúc runtime
- **Virtual destructor**: destructor ảo — đảm bảo hủy đúng lớp kế thừa
- **Object slicing**: mất phần kế thừa khi truyền đối tượng theo giá trị
- **vtable**: bảng con trỏ hàm ảo — cơ chế C++ thực hiện liên kết động
