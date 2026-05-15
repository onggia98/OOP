# 📚 OOP Study Project — CSC10003

> Tài liệu ôn tập môn **Phương Pháp Lập Trình Hướng Đối Tượng**  
> Trường Đại học Khoa học Tự nhiên, ĐHQG-HCM · Hệ ĐTTX · Mã HP: CSC10003  
> Ngôn ngữ: **C++** (so sánh Java, C# xuyên suốt)

---

## 📁 Cấu trúc thư mục

```
├── raw/
│   ├── ebooks/          # Giáo trình gốc (PDF)
│   ├── slides/          # Slide bài giảng (PPTX, DOCX)
│   └── de_thi_cu/       # Đề thi cũ 2019–2026 (ảnh/PDF)
│
├── knowledge/
│   ├── ebook_chapters/  # Index & nội dung giáo trình theo chương
│   ├── slide_chapters/  # Nội dung slides đã extract & tổng hợp
│   └── de_thi_analysis/ # Phân tích đề thi + transcript toàn bộ đề
│
├── study/
│   ├── flashcards/      # Flashcard Q/A theo chủ đề
│   ├── exercises/       # Bài tập code
│   └── mock_exams/      # Đề thi thử + đáp án
│
└── notes/
    ├── weak_points.md   # Điểm hay nhầm
    ├── concept_map.md   # Sơ đồ liên kết khái niệm
    └── session_log.md   # Nhật ký học
```

---

## 🗺️ Roadmap OOP (5 tầng)

```
[Tầng 1 — Foundation]
Class & Object → Constructor/Destructor → Encapsulation
        ↓
[Tầng 2 — Inheritance]
Inheritance → Method Overriding → Abstract Class → Interface
        ↓
[Tầng 3 — Polymorphism]  ⚠️ hay thi
Overloading → Dynamic Binding → Upcasting/Downcasting
        ↓
[Tầng 4 — Design]  ⚠️ hay thi
SOLID → Composition vs Inheritance → Design Patterns → UML
        ↓
[Tầng 5 — Advanced]
Generics/Templates → Exception Handling → DI → Real-world Design
```

---

## 🔥 Tổng kết phân tích đề thi (2019–2026)

Dựa trên **16 đề thi** từ HK1/HK2 các năm 2019–2026:

| Thuộc tính | Giá trị |
|-----------|---------|
| Số câu | 2 câu |
| Điểm | 5đ + 5đ = 10đ |
| Thời gian | 90 phút |
| Tài liệu | Không được dùng |
| Dạng | 100% viết code C++ |

**Câu 2 — luôn luôn:** Inheritance + Polymorphism (bắt buộc dùng đa hình)

**Xu hướng 2025–2026:** Câu 1 chuyển sang dạng *"cài đặt lớp để hàm `main` cho sẵn chạy được"* — yêu cầu Big Three + Operator Overloading.

> Chi tiết: [`knowledge/de_thi_analysis/topic_frequency_map.md`](knowledge/de_thi_analysis/topic_frequency_map.md)

---

## 📖 Tài liệu học

| Loại | Tên | Ghi chú |
|------|-----|---------|
| Giáo trình | Phương Pháp Lập Trình Hướng Đối Tượng | Trần Đan Thư, NXB KHKT 2010, 375 trang |
| Slides | OOP-01 → OOP-10 | 10 chủ đề từ Overview đến Design Patterns |
| Đề cương | Decuong-OOP.docx | Đề cương chi tiết môn học |
| Đề thi cũ | 2019 → 2026 | 16 đề, đầy đủ transcript |

---

## ⚡ Chủ đề cần luyện (theo ưu tiên)

1. **Inheritance + Polymorphism** — xuất hiện 100% đề thi
2. **Operator Overloading** — tăng mạnh từ 2021
3. **Big Three (Constructor / Copy Constructor / Destructor)** — bắt buộc từ 2025
4. **Class Design + Encapsulation** — nền tảng mọi bài
5. **Aggregation / Composition (HAS-A)** — câu hỏi phức tạp hơn

---

## 🧰 Slides đã tổng hợp

| File | Chủ đề |
|------|--------|
| `slide_01_course_overview.md` | Chuẩn lập trình, Overloading, Template |
| `slide_02_intro_oop.md` | Lớp, đối tượng, tầm vực |
| `slide_03_object_life_cycle.md` | Constructor, Destructor, Static |
| `slide_04_operators.md` | Operator Overloading, Friend function |
| `slide_05_big_three.md` | Rule of Three, Encapsulation |
| `slide_06_stl_encapsulation.md` | STL: string, vector, Tell Don't Ask |
| `slide_07_inheritance.md` | Kế thừa, IS-A vs HAS-A |
| `slide_08_lifecycle_inheritance.md` | Constructor/Destructor trong kế thừa |
| `slide_09_interface_polymorphism.md` | Virtual, pure virtual, abstract class |
| `slide_10_design_patterns.md` | Singleton, Composite, Adapter |
