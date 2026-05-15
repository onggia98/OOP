# Thư Viện STL và Tính Đóng Gói — OOP Slide 06
> Nguồn: raw/slides/OOP-06-The STL Library and Encapsulation.pptx
> Ngôn ngữ: C++

## Tóm tắt nội dung chính
Slide 06 giới thiệu hệ sinh thái thư viện C++, trọng tâm là thư viện STL (Standard Template Library) với hai lớp được dùng nhiều nhất là `string` và `vector<T>`. Phần hai củng cố lại tính đóng gói thông qua quy tắc hộp đen và nguyên tắc "Tell, Don't Ask" với các ví dụ thực tế.

## Các khái niệm core

### 1. Thư viện C++ phổ biến
| Thư viện | Mô tả |
|----------|-------|
| **Thư viện chuẩn C++** | Bộ công cụ nền tảng, namespace `std`, header không có `.h` |
| **Boost** | Hơn 80 thư viện mở rộng, nhiều tính năng nâng cao |
| **MFC** | Microsoft Foundation Class — lập trình Windows GUI |

### 2. Cấu trúc STL (Standard Template Library)
Ra đời 1994 bởi Alexander Stepanov. Gồm 4 nhóm:
- **Containers**: lưu trữ dữ liệu (`vector`, `list`, `map`, `set`...)
- **Iterators**: duyệt qua container
- **Algorithms**: thuật toán tổng quát (`sort`, `find`, `count`...)
- **Functors**: đối tượng hàm (function objects)

### 3. Lớp `string` (`<string>`)
Giải quyết vấn đề quản lý chuỗi ký tự — thay thế `char*` nguy hiểm.

| Phương thức | Ý nghĩa |
|-------------|---------|
| `string(char*)` | Khởi tạo từ chuỗi C |
| `length()` | Chiều dài chuỗi |
| `operator[]` | Lấy ký tự tại vị trí |
| `==, !=, <, >` | So sánh theo thứ tự từ điển |
| `+, +=` | Nối chuỗi |
| `find(char*)` | Tìm vị trí chuỗi con |
| `substr(pos, len)` | Trích chuỗi con |

### 4. Lớp `vector<T>` (`<vector>`)
Mảng động kiểu T — tự quản lý bộ nhớ.

| Phương thức | Ý nghĩa |
|-------------|---------|
| `vector<T>()` | Khởi tạo mảng rỗng |
| `size()` | Số phần tử hiện có |
| `resize(n)` | Thay đổi kích thước |
| `operator[]` | Truy xuất phần tử |
| `push_back(T)` | Thêm vào cuối |
| `insert(pos, T)` | Chèn vào vị trí |

## Code examples / Syntax quan trọng

### Sử dụng `string`
```cpp
#include <string>
using namespace std;

void main() {
    string s1("software");
    string s2("SoftWare");

    if (s1 == s2)
        cout << "equal." << endl;
    else
        cout << "not equal." << endl;  // In ra đây (case-sensitive)

    string s3 = s1.substr(4, 4);   // Trích "ware"
    cout << s3 << endl;

    string s4 = s1 + s3;           // Nối: "softwareware"
    cout << s4 << endl;
}
```

### Sử dụng `vector<T>`
```cpp
#include <vector>
using namespace std;

void main() {
    // Vector số nguyên
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);

    for (int i = 0; i < v1.size(); i++)
        cout << v1[i] << " ";

    // Vector con trỏ đối tượng
    vector<PhanSo*> v2;
    v2.push_back(new PhanSo(1, 3));
    v2[0]->rutGon();
}
```

### Tính đóng gói — Tell, Don't Ask
```cpp
// Bài toán: tính trọng tâm tam giác
class Diem {
private:
    float m_X, m_Y;
public:
    // ĐÚNG: để lớp TamGiac nhờ Diem tính
    Diem tinhTrungDiem(const Diem &d) const;
    float layX() const { return m_X; }  // Getter chấp nhận được
    float layY() const { return m_Y; }
};

class TamGiac {
private:
    Diem m_A, m_B, m_C;
public:
    // ĐÚNG: TamGiac tự tính trọng tâm — không lộ thuộc tính
    Diem tinhTrongTam() {
        // Tính từ m_A, m_B, m_C nội bộ
    }
};
```

```cpp
// Bài toán: xuất học sinh đậu
class HocSinh {
private:
    char *m_hoTen;
    float m_diemVan, m_diemToan;
public:
    bool laDau() { return tinhDTB() >= 5.0; }  // HocSinh tự biết mình đậu không
    void xuat();
};

class BangDiem {
private:
    vector<HocSinh> m_danhSach;
public:
    void xuatDSDau() {
        for (int i = 0; i < m_danhSach.size(); i++)
            if (m_danhSach[i].laDau())  // Hỏi đối tượng, không lấy điểm về tự so
                m_danhSach[i].xuat();
    }
};
```

## Điểm hay thi / Lưu ý
- **`string` so sánh case-sensitive**: `"software" != "SoftWare"`
- **`vector` vs mảng thường**: vector tự quản lý bộ nhớ, tự resize — không cần `new`/`delete`
- `push_back` thêm vào CUỐI, không có `push_front` trong vector (dùng `list` nếu cần)
- **`vector<PhanSo*>` vs `vector<PhanSo>`**: khi chứa con trỏ, cần tự `delete` từng phần tử khi xong
- STL containers giải quyết "ba vấn đề con trỏ" (rò rỉ, chia sẻ, mất bộ nhớ)
- **Namespace `std`**: dùng `using namespace std;` hoặc viết đầy đủ `std::string`, `std::vector`
- Header của thư viện chuẩn C++ **không có đuôi `.h`**: `<string>`, `<vector>`, `<algorithm>`

## Thuật ngữ
- **STL** (Standard Template Library): thư viện template chuẩn
- **Container**: lớp chứa dữ liệu tổng quát
- **Iterator**: đối tượng duyệt qua container
- **Algorithm**: thuật toán tổng quát hoạt động trên iterator
- **namespace std**: không gian tên chứa toàn bộ thư viện chuẩn C++
- **Tell, Don't Ask**: nhờ đối tượng xử lý, không lấy dữ liệu về tự xử lý
- **Encapsulation** (Tính đóng gói): quy tắc hộp đen — private data, public interface
