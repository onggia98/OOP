# Bài Tập — Ngày 4: Big Three + Dynamic Memory
> Dạng khó nhất, mới nhất. Xuất hiện đề 2025 và 2026.

---

## Bài 1 — Hiểu vấn đề shallow copy (10 phút — KHÔNG code)

Đọc đoạn code sau và trả lời:

```cpp
class Bad {
public:
    int* _data;
    int  _size;
    Bad(int size) : _size(size) {
        _data = new int[size];
        for (int i = 0; i < size; i++) _data[i] = i;
    }
    ~Bad() { delete[] _data; }
    // KHÔNG có copy constructor và operator=
};

int main() {
    Bad a(3);      // a._data → [0, 1, 2]
    Bad b = a;     // ??? (A)
    b._data[0] = 99;
    cout << a._data[0];  // ??? (B)
    // khi main() kết thúc → ??? (C)
}
```

**Câu hỏi:**
1. (A): `Bad b = a` gọi cái gì? `b._data` trỏ đến đâu?
2. (B): Output là gì? Tại sao?
3. (C): Điều gì xảy ra khi hủy `a` và `b`?

<details>
<summary>Đáp án</summary>

1. Gọi **default copy constructor** → shallow copy → `b._data` trỏ **cùng vùng nhớ** với `a._data`
2. Output: **99** — vì a và b cùng trỏ 1 vùng nhớ, sửa `b` → `a` cũng thay đổi
3. **Double free crash!** — `~Bad()` của `b` xóa vùng nhớ, rồi `~Bad()` của `a` cố xóa vùng nhớ đã xóa → undefined behavior
</details>

---

## Bài 2 — Viết đúng Big Three cho class trên (20 phút)

Sửa class `Bad` thành class `Good` với Big Three đầy đủ và đúng.

<details>
<summary>Đáp án</summary>

```cpp
class Good {
public:
    int* _data;
    int  _size;

    Good(int size) : _size(size) {
        _data = new int[size];
        for (int i = 0; i < size; i++) _data[i] = i;
    }

    ~Good() {
        delete[] _data;
        _data = nullptr;
    }

    Good(const Good& o) {
        _size = o._size;
        _data = new int[_size];
        for (int i = 0; i < _size; i++) _data[i] = o._data[i];
    }

    Good& operator=(const Good& o) {
        if (this == &o) return *this;
        delete[] _data;
        _size = o._size;
        _data = new int[_size];
        for (int i = 0; i < _size; i++) _data[i] = o._data[i];
        return *this;
    }
};
```
</details>

---

## Bài 3 — Đề thật 2025 HK2: CMyArray (45 phút)

Cài đặt class `CMyArray` để chạy đúng main sau:

```cpp
int main() {
    CMyArray arr;
    arr.Add(5); arr.Add(4); arr.Add(9); arr.Add(6);
    int minIndex = arr.Min();
    if (minIndex != -1) {
        cout << arr[minIndex] << endl;   // → 4
    }

    // Test deep copy:
    CMyArray arr2 = arr;
    arr2.Add(1);
    cout << arr.Size() << endl;   // → 4 (không đổi)
    cout << arr2.Size() << endl;  // → 5

    CMyArray arr3;
    arr3 = arr;
    arr3.Add(100);
    cout << arr[0] << endl;   // → 5 (không đổi)
    return 0;
}
```

> Xem đáp án đầy đủ tại `study/mock_exams/ans_2025HK2.md`

---

## Bài 4 — Đề thật 2026 HK1: CMyString (45 phút)

Cài đặt class `CMyString` để chạy đúng main:

```cpp
int main() {
    CMyString s1("ABC.");
    s1.Append("DEE.");
    int foundIndex = s1.Find("DE");    // → 4
    if (foundIndex != -1) {
        cout << foundIndex << "\n";          // → 4
        cout << s1[foundIndex] << "\n";      // → 'D'
    }
    CMyString s2("C++");
    CMyString s3 = s1 + s2;
    // s3 = "ABC.DEE.C++"
    return 0;
}
```

> Xem đáp án đầy đủ tại `study/mock_exams/ans_2026HK1.md`

---

## Bài 5 — Tự kiểm tra (không nhìn mẫu)

Viết từ đầu template Big Three cho một class `IntList` có:
- `Add(int val)` — thêm phần tử
- `Get(int i) const` — lấy phần tử
- `Size() const`
- Big Three đầy đủ

Điều kiện pass: copy `IntList b = a;` rồi `b.Add(99)` → `a.Size()` không thay đổi.

---

## Checklist

- [ ] Bài 1: trả lời đúng 3 câu hỏi về shallow copy
- [ ] Bài 2: viết đúng Big Three — không nhìn template
- [ ] Bài 3: CMyArray hoàn chỉnh, test deep copy pass
- [ ] Bài 4: CMyString hoàn chỉnh, Find + Append + operator+ đúng
- [ ] Bài 5: tự viết từ đầu trong < 20 phút

**3 điểm hay quên:**
1. `if (this == &o) return *this;` trong `operator=`
2. `delete[] _data;` trước khi copy trong `operator=`
3. `+1` khi cấp phát `char*` (cho `'\0'`)
