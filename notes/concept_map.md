# Concept Map — OOP C++ (CSC10003)
> Sơ đồ liên kết các khái niệm. Đọc từ trên xuống = từ nền tảng đến nâng cao.
> Cập nhật: 2026-05-20

---

## Bản đồ tổng quan

```
┌─────────────────────────────────────────────────────────────┐
│                    CLASS & OBJECT                           │
│  blueprint → instance | private/protected/public           │
└──────────────────┬──────────────────────────────────────────┘
                   │ tạo nền tảng cho
          ┌────────┴────────┐
          ▼                 ▼
┌──────────────────┐  ┌──────────────────┐
│  CONSTRUCTOR /   │  │  ENCAPSULATION   │
│  DESTRUCTOR      │  │  getter / setter │
│  default/param   │  │  data hiding     │
│  initializer list│  │  validation      │
└────────┬─────────┘  └────────┬─────────┘
         │                     │
         └──────────┬──────────┘
                    ▼
┌─────────────────────────────────────────────────────────────┐
│                  OPERATOR OVERLOADING                       │
│  member: +, -, >, ==, [], ++, =, +=                        │
│  friend: <<, >>                                             │
│  Rule: const&, const method, return type                   │
└──────────────────┬──────────────────────────────────────────┘
                   │ nền tảng kỹ thuật cho
          ┌────────┴────────┐
          ▼                 ▼
┌──────────────────┐  ┌──────────────────┐
│   BIG THREE      │  │   INHERITANCE    │
│   (Rule of 3)    │  │   IS-A vs HAS-A  │
│  = dtor          │  │   public kế thừa │
│  = copy ctor     │  │   protected attr │
│  = op= (assign)  │  │   constructor    │
│  WHY: dynamic    │  │   chaining       │
│  memory!         │  │                  │
└────────┬─────────┘  └────────┬─────────┘
         │                     │ cho phép
         │                     ▼
         │          ┌──────────────────────┐
         │          │    POLYMORPHISM      │
         │          │  virtual function    │
         │          │  pure virtual (=0)   │
         │          │  abstract class      │
         │          │  virtual destructor  │
         │          │  vector<Base*>       │
         │          │  override keyword    │
         └──────────┼──────────────────────┘
                    │
                    ▼
┌─────────────────────────────────────────────────────────────┐
│                   DESIGN PRINCIPLES                         │
│  Composition (HAS-A) vs Inheritance (IS-A)                 │
│  SOLID: SRP, OCP, LSP, ISP, DIP                            │
└─────────────────────────────────────────────────────────────┘
```

---

## Liên kết quan trọng

### Big Three ↔ Operator Overloading
```
Class có new/delete → phải có Big Three
Big Three bao gồm: dtor, copy ctor, op= (đều là dạng operator/special method)
op= phải kiểm tra self-assignment: if (this == &o) return *this;
```

### Virtual ↔ Destructor
```
Có base pointer (Base* p = new Derived())
    → BẮT BUỘC virtual destructor trong Base
    → Không có → delete p chỉ gọi ~Base() → memory leak

QUY TẮC VÀNG: có virtual function → phải có virtual destructor
```

### Operator[] ↔ const
```
int& operator[](int i)        // non-const: gán a[i] = 5
int  operator[](int i) const  // const: đọc trên const object
→ Viết CẢ HAI phiên bản
```

---

## Bảng "nếu... thì phải..."

| Tình huống | Bắt buộc thêm |
|-----------|---------------|
| Class có `delete[]` trong dtor | Copy ctor (deep copy) + op= (deep copy) |
| Class dùng với base pointer | `virtual ~Base() {}` |
| Method cần override ở lớp con | `virtual` ở base, `override` ở derived |
| Method không sửa object | `const` ở cuối |
| `operator<<` hoặc `>>` | `friend` function |
| Postfix `++` | Tham số `(int)` giả, trả về copy |
| Abstract class | Ít nhất 1 pure virtual: `= 0` |

---

## Dấu hiệu nhận đề thi

### Câu 1 dạng Class Design (2019–2022)
```
"Viết chương trình nhập vào danh sách X, tìm/tính/in Y"
→ class X + container + method tìm/tính/in
```

### Câu 1 dạng Operator Overloading (2021–2024)
```
"Bắt buộc cài đặt các toán tử... viết được theo kiểu a + b"
→ operator+, >, ==, <<; tuỳ đề: +=, [], ++
```

### Câu 1 dạng Big Three (2025–2026, xu hướng hiện tại)
```
"Cài đặt các lớp cần thiết để thực hiện được hàm main sau..."
→ Phân tích main → xác định methods
→ Nếu main dùng copy/assign → Big Three bắt buộc
```

### Câu 2 luôn luôn (100%)
```
"Bắt buộc sử dụng đa hình"
→ Abstract base class (pure virtual)
→ 2–3 lớp con override
→ vector<Base*> + virtual dispatch
→ virtual ~Base() + delete trong ~Container()
```

---

## Runtime vs Compile-time

```
COMPILE TIME:
├── Method Overloading (cùng tên, khác tham số)
├── Operator Overloading
└── Template

RUNTIME:
└── Virtual + Override → dynamic dispatch
    SinhVien* p = new SVChinhQuy();
    p->tinhHocBong();  ← gọi đúng SVChinhQuy::tinhHocBong()
```

---

## Keywords C++ quan trọng

```cpp
virtual   // method có thể override → runtime dispatch
override  // xác nhận override, compiler kiểm tra signature
= 0       // pure virtual → class trở thành abstract
protected // accessible trong lớp con, ẩn với bên ngoài
friend    // cho phép function ngoài truy cập private members
delete[]  // giải phóng mảng động (khác delete cho single object)
```
