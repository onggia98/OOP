# Đề Cương Chi Tiết — OOP Slide 00
> Nguồn: raw/slides/Decuong-OOP.docx
> Ngôn ngữ: C++

## Tóm tắt nội dung chính
Đề cương môn Phương pháp Lập trình Hướng đối tượng tại HCMUS (4 tín chỉ). Môn học cung cấp các khái niệm cơ bản về OOP, cách tư duy và kỹ năng lập trình theo hướng đối tượng bằng C++. Sinh viên được rèn luyện kế thừa, đa hình, áp dụng design pattern, và xây dựng các lớp mô hình hóa thực thể thế giới thực.

## Các khái niệm core

### Cấu trúc 12 chương
| Chương | Nội dung chính |
|--------|---------------|
| 1 | Lập trình cấu trúc vs OOP, con trỏ hàm, function template |
| 2 | Lớp và đối tượng, UML, so sánh C++/Java/C# |
| 3 | Kiểu dữ liệu cơ sở, string, vector<T>, dữ liệu động |
| 4 | Constructor, destructor, operator overloading, static members |
| 5 | Tổng quát hóa, đặc biệt hóa, đa hình, virtual methods |
| 6 | Lớp trừu tượng, pure virtual, interface trong C++ |
| 7 | Abstract Data Types: stack, queue, priority queue |
| 8 | Quan hệ giữa lớp: composition (has-a), inheritance (is-a) |
| 9 | File I/O, iostream hierarchy, persistent objects |
| 10 | Class template, function template, kế thừa template |
| 11 | STL containers: vector, list, stack, queue; iterators, algorithms |
| 12 | Exception handling: try-catch-throw, assert |

### Điều kiện tiên quyết
- Tin học cơ sở
- Nhập môn lập trình

### Thang điểm
- Bài tập thực hành viết chương trình
- Đồ án môn học / thi thực hành giữa kỳ + cuối kỳ
- Thuyết trình / giải bài trên lớp
- **Thi lý thuyết cuối kỳ**

## Code examples / Syntax quan trọng

### Function Template (Chương 1)
```cpp
template <class T>
T tinhToan(T x, T y) {
    return x + y;
}
```

### Con trỏ hàm (Chương 1)
```cpp
typedef int (*PhepTinh)(int, int);
int tinhToan(int x, int y, PhepTinh p) {
    return p(x, y);
}
```

### Class template (Chương 10)
```cpp
template <class T>
class Mang {
    T* m_duLieu;
    int m_kichThuoc;
public:
    T& layPhanTu(int i);
};
```

## Điểm hay thi / Lưu ý
- **So sánh C++/Java/C#** xuất hiện ở hầu hết các chương — hay ra câu hỏi lý thuyết
- **Singleton, Composite, Template Method, Strategy, Adapter, Prototype** là các design pattern được nhắc trong đề cương
- Chương 5–6 (đa hình, interface, virtual) thường là trọng tâm bài thi
- **Luật ba ông lớn** (destructor, copy constructor, operator=) áp dụng khi lớp có con trỏ
- Exception handling: lưu ý thứ tự catch khi có kế thừa exception
- **Template vs. đa hình**: hai cách khác nhau để tổng quát hóa code

## Thuật ngữ
- **Encapsulation** (Tính đóng gói): ẩn dữ liệu, chỉ lộ phương thức public
- **Inheritance** (Tính kế thừa): lớp con thừa hưởng từ lớp cha
- **Polymorphism** (Tính đa hình): cùng interface, hành vi khác nhau tùy đối tượng
- **Abstract class** (Lớp trừu tượng): lớp chứa ít nhất một pure virtual function
- **Interface**: tập hợp phương thức public — giao thức giao tiếp
- **Template**: tham số hóa kiểu dữ liệu
- **Design Pattern**: bài giải mẫu cho vấn đề thiết kế thường gặp
