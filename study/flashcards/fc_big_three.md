# Flashcard — Big Three (Rule of Three) + Dynamic Memory
> Chủ đề: Buổi 4 | Tần suất thi: 2/2 đề mới nhất (2025 HK2, 2026 HK1) — xu hướng tăng mạnh

---

## Q1: Rule of Three là gì?
**A:** Nếu class cần định nghĩa 1 trong 3 thứ sau, phải định nghĩa cả 3:
1. **Destructor** — `~MyClass()`
2. **Copy Constructor** — `MyClass(const MyClass&)`
3. **Assignment Operator** — `MyClass& operator=(const MyClass&)`

> Dấu hiệu nhận ra: class có `new`/`delete[]` bên trong → áp dụng Rule of Three.

---

## Q2: Shallow copy vs deep copy — sự khác biệt?
**A:**
```cpp
// SHALLOW COPY (mặc định nếu không viết copy ctor)
// 2 object cùng trỏ vào 1 vùng nhớ → thay đổi 1 → ảnh hưởng cái kia
CMyArray a;  a.Add(5);
CMyArray b = a;  // shallow: b._data và a._data cùng trỏ 1 vùng nhớ
b._data[0] = 99; // → a._data[0] cũng thành 99 (SAI)
delete b;        // → a._data bị trỏ đến vùng nhớ đã free (CRASH)

// DEEP COPY (ta phải tự viết)
// Cấp phát vùng nhớ mới, copy nội dung sang
CMyArray(const CMyArray& other) {
    _size = other._size;
    _data = new int[_size];           // ← vùng nhớ RIÊNG
    for (int i = 0; i < _size; i++)
        _data[i] = other._data[i];   // ← copy từng phần tử
}
```

---

## Q3: Viết Destructor đúng chuẩn
**A:**
```cpp
~CMyArray() {
    delete[] _data;   // giải phóng mảng động
    _data = nullptr;  // tránh dangling pointer (tuỳ chọn nhưng tốt)
}
```
> `delete[]` cho mảng, `delete` cho single object. Nhầm → undefined behavior.

---

## Q4: Viết Copy Constructor đúng chuẩn
**A:**
```cpp
CMyArray(const CMyArray& other) {
    _size     = other._size;
    _capacity = other._capacity;
    _data     = new int[_capacity];         // cấp phát vùng nhớ MỚI
    for (int i = 0; i < _size; i++)
        _data[i] = other._data[i];          // copy từng phần tử
}
```
> Được gọi khi: `CMyArray b = a;` hoặc truyền vào hàm theo giá trị.

---

## Q5: Viết Assignment Operator đúng chuẩn
**A:**
```cpp
CMyArray& operator=(const CMyArray& other) {
    if (this == &other) return *this;   // ← kiểm tra tự gán (QUAN TRỌNG)
    delete[] _data;                      // ← giải phóng bộ nhớ CŨ
    _size     = other._size;
    _capacity = other._capacity;
    _data     = new int[_capacity];
    for (int i = 0; i < _size; i++)
        _data[i] = other._data[i];
    return *this;                        // ← trả về *this để chain: a = b = c
}
```

---

## Q6: Tại sao phải kiểm tra `if (this == &other)`?
**A:**
```cpp
CMyArray a;
a = a;   // tự gán!
// Nếu không kiểm tra:
// delete[] _data;   → vùng nhớ bị xóa
// _data = new int[_capacity];  → nhưng _capacity cũng bị xóa!
// → undefined behavior / crash
```

---

## Q7: Tại sao phải `delete[] _data` trước khi copy trong `operator=`?
**A:** Vì `this` đã tồn tại và có thể đang trỏ đến vùng nhớ cũ.  
Nếu không xóa → memory leak (vùng nhớ cũ không ai trỏ đến nữa, không thể giải phóng).
```cpp
CMyArray a, b;
a.Add(1); a.Add(2);  // a có _data trỏ vùng A
b.Add(10);           // b có _data trỏ vùng B
b = a;
// Nếu không delete[] b._data trước → vùng B bị leak!
```

---

## Q8: Khi nào copy constructor được gọi?
**A:** 3 trường hợp:
```cpp
CMyArray b = a;                  // 1. khởi tạo từ object khác
func(a);                         // 2. truyền vào hàm theo giá trị
CMyArray c = someFunc();         // 3. nhận từ hàm trả về theo giá trị (có thể bị RVO)
```

---

## Q9: Template Big Three hoàn chỉnh cho mọi class có dynamic array
**A:**
```cpp
class MyClass {
private:
    T*  _data;
    int _size;
    int _capacity;

public:
    MyClass() : _data(nullptr), _size(0), _capacity(0) {}

    ~MyClass() {
        delete[] _data;
        _data = nullptr;
    }

    MyClass(const MyClass& o) {
        _size = o._size; _capacity = o._capacity;
        _data = new T[_capacity];
        for (int i = 0; i < _size; i++) _data[i] = o._data[i];
    }

    MyClass& operator=(const MyClass& o) {
        if (this == &o) return *this;
        delete[] _data;
        _size = o._size; _capacity = o._capacity;
        _data = new T[_capacity];
        for (int i = 0; i < _size; i++) _data[i] = o._data[i];
        return *this;
    }
};
```

---

## Q10: CMyString — Big Three với `char*` khác gì `int*`?
**A:**
```cpp
// CMyString dùng char* → cần null-terminate ('\0')

CMyString(const char* str = "") {
    _len  = strlen(str);
    _data = new char[_len + 1];   // +1 cho '\0'
    strcpy(_data, str);           // copy kể cả '\0'
}

CMyString(const CMyString& o) {
    _len  = o._len;
    _data = new char[_len + 1];
    strcpy(_data, o._data);
}

CMyString& operator=(const CMyString& o) {
    if (this == &o) return *this;
    delete[] _data;
    _len  = o._len;
    _data = new char[_len + 1];
    strcpy(_data, o._data);
    return *this;
}
```
> Khác với `int*`: phải `+1` khi cấp phát, dùng `strcpy` thay vòng for, `strlen` để đo độ dài.

---

## Quick Test — trả lời không nhìn

1. "Rule of Three" gồm những gì? Dấu hiệu nhận ra khi nào cần áp dụng?
2. Shallow copy gây ra vấn đề gì?
3. Trong `operator=`, câu lệnh nào phải viết TRƯỚC tiên? Tại sao?
4. Sự khác biệt giữa copy constructor và assignment operator?
5. `delete` và `delete[]` dùng khác nhau thế nào?
6. Tại sao `operator=` phải trả về `MyClass&` (reference)?
