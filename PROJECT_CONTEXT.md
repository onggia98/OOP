# PROJECT CONTEXT — OOP (Lập Trình Hướng Đối Tượng)
> File này chứa toàn bộ context đã được thiết lập qua các buổi làm việc với Claude.
> Cowork đọc file này trước mỗi session để không cần train lại từ đầu.
> Cập nhật lần cuối: 2026-05-15

---

## 1. MỤC TIÊU DỰ ÁN

- Môn học: **Object-Oriented Programming (OOP)**
- Phương pháp: hiểu design intent > thuộc syntax
- Output cuối: nắm vững 4 tầng kiến thức OOP, làm tốt mọi dạng đề thi

---

## 2. TÀI LIỆU CÓ SẴN

| Loại | Vị trí | Trạng thái |
|---|---|---|
| Ebook (PDF có text) | `raw/ebooks/` | Chưa tách chương |
| Slide môn học | `raw/slides/` | Chưa tách chương |
| Đề thi cũ (PDF) | `raw/de_thi_cu/` | Chưa phân tích |
| Source code bài tập | `raw/source_code/` | Chưa review |
| Script tách PDF→MD | `pdf_to_chapters.py` | Sẵn sàng dùng |

---

## 3. CẤU TRÚC THƯ MỤC

```
~/Documents/OOP/
├── SYSTEM_PROMPT.md
├── about.md
├── PROJECT_CONTEXT.md          ← file này
├── pdf_to_chapters.py
│
├── raw/
│   ├── ebooks/
│   ├── slides/
│   ├── de_thi_cu/
│   └── source_code/            ← bài tập, project mẫu
│
├── knowledge/
│   ├── ebook_chapters/         ← output từ script (ebook)
│   ├── slide_chapters/         ← output từ script (slide)
│   └── de_thi_analysis/        ← phân tích đề thi cũ
│       └── topic_frequency_map.md
│
├── study/
│   ├── flashcards/
│   ├── exercises/              ← bài tập code + thiết kế class
│   └── mock_exams/
│
└── notes/
    ├── weak_points.md
    ├── concept_map.md
    └── session_log.md
```

---

## 4. TEACHING SYSTEM PROMPT

Claude đóng vai: **elite OOP professor + exam coach**

Mục tiêu cốt lõi:
1. Hiểu OOP principles sâu — không học vẹt syntax
2. Kết nối lý thuyết ↔ code thực tế
3. Phát hiện OOP violations và bad design
4. Xây dựng software design thinking
5. Chuẩn bị thi hiệu quả mọi dạng câu hỏi

Learning flow cho mỗi chủ đề (9 bước):
1. Big picture — vị trí trong OOP knowledge map
2. Intuition — tại sao concept này tồn tại
3. Real-world analogy — ví dụ không dùng code
4. Technical foundation — định nghĩa, syntax, rules
5. Code example — ngắn, sạch, có comment
6. Connect — liên kết với concepts đã học
7. Common mistakes — lỗi sinh viên hay mắc
8. Exam angle — dạng câu hỏi thường gặp
9. Active recall questions — 3–5 câu kiểm tra ngay

Phong cách dạy:
- Luôn giải thích "tại sao" trước "làm như thế nào"
- So sánh good OOP vs bad OOP bằng code song song
- Dùng UML text diagram khi cần minh họa class relationships
- Ngôn ngữ: tiếng Việt, code và thuật ngữ kỹ thuật giữ tiếng Anh

---

## 5. OOP KNOWLEDGE MAP

### Dependency tree

```
[Tầng 1 — Foundation]
Class & Object → Constructor → Encapsulation
        ↓
[Tầng 2 — Inheritance]
Inheritance → Overriding → Abstract Class → Interface
        ↓
[Tầng 3 — Polymorphism]
Overloading → Dynamic Binding → Upcasting/Downcasting
        ↓
[Tầng 4 — Design]
SOLID → Composition vs Inheritance → Design Patterns → UML
        ↓
[Tầng 5 — Advanced]
Generics → Exception Handling → DI → Real-world Design
```

### Checklist tiến độ
<!-- Cập nhật: đánh dấu [x] khi hoàn thành -->

**Tầng 1 — Foundation**
- [ ] Class & Object
- [ ] Constructor & Destructor
- [ ] Encapsulation + Access Modifiers

**Tầng 2 — Inheritance**
- [ ] Inheritance (đơn / đa kế thừa)
- [ ] Method Overriding
- [ ] Abstract Class
- [ ] Interface

**Tầng 3 — Polymorphism** ⚠️ hay thi
- [ ] Method Overloading (compile-time)
- [ ] Dynamic Binding (runtime)
- [ ] Upcasting / Downcasting / instanceof

**Tầng 4 — Design** ⚠️ hay thi
- [ ] SOLID Principles
- [ ] Composition vs Inheritance
- [ ] Creational Patterns: Singleton, Factory, Builder
- [ ] Structural Patterns: Adapter, Decorator, Facade
- [ ] Behavioral Patterns: Observer, Strategy, Template Method
- [ ] UML Class Diagram

**Tầng 5 — Advanced**
- [ ] Exception Handling trong OOP
- [ ] Generic Classes
- [ ] Dependency Injection
- [ ] Real-world class design

---

## 6. FOCUS AREAS — HAY NHẦM NHẤT

| Cặp concept | Điểm hay nhầm |
|---|---|
| Overloading vs Overriding | Cùng tên, cơ chế hoàn toàn khác |
| Abstract class vs Interface | Khi nào dùng cái nào |
| IS-A vs HAS-A | Khi nào dùng inheritance vs composition |
| Static vs Instance | Context của method/attribute |
| Constructor chaining | Thứ tự gọi this() vs super() |
| Dynamic binding | JVM resolve method call lúc runtime |
| LSP (SOLID) | Nguyên lý khó nhất trong SOLID |

---

## 7. WORKFLOW COWORK

### Xử lý tài liệu đầu vào
```bash
# Tách ebook thành chapters
python pdf_to_chapters.py raw/ebooks/<file>.pdf --out knowledge/ebook_chapters/ --lang vi

# Tách slide thành chapters
python pdf_to_chapters.py raw/slides/<file>.pdf --out knowledge/slide_chapters/ --lang vi
```

### Tasks Cowork theo giai đoạn

**Giai đoạn 1 — Phân tích đề thi cũ (làm trước)**
```
Đọc tất cả file trong raw/de_thi_cu/.
Phân tích từng đề: dạng câu hỏi (lý thuyết / code tracing /
viết code / UML), chủ đề, mức độ khó.
Tổng hợp vào knowledge/de_thi_analysis/topic_frequency_map.md:
- OOP topic nào xuất hiện nhiều nhất
- Dạng câu hỏi nào chiếm tỉ lệ cao
- Tỉ lệ lý thuyết vs thực hành vs design
```

**Giai đoạn 2 — Review source code (nếu có)**
```
Đọc SYSTEM_PROMPT.md, PROJECT_CONTEXT.md, about.md.
Đọc toàn bộ file trong raw/source_code/.
Phân tích: class structure, OOP principles được áp dụng,
OOP violations, cơ hội refactor.
Lưu báo cáo vào notes/code_review.md.
```

**Giai đoạn 3 — Học từng tầng**
```
Đọc SYSTEM_PROMPT.md, PROJECT_CONTEXT.md, about.md.
Đọc knowledge/ebook_chapters/chuong_0X_<tên>.md
và knowledge/slide_chapters/slide_0X_<tên>.md.
Dạy tôi chủ đề [X] theo learning_flow 9 bước trong SYSTEM_PROMPT.
Lưu flashcard vào study/flashcards/fc_<tên>.md.
Lưu bài tập vào study/exercises/ex_<tên>.md.
```

**Giai đoạn 4 — Luyện đề**
```
Đọc knowledge/de_thi_analysis/topic_frequency_map.md.
Tạo đề thi mock theo đúng pattern đề thi cũ.
Lưu đề vào study/mock_exams/mock_0X.md.
Lưu đáp án + giải thích vào study/mock_exams/mock_0X_answer.md.
```

---

## 8. ĐIỂM YẾU / HAY NHẦM
<!-- Cập nhật dần trong quá trình học -->
_Chưa có dữ liệu — sẽ cập nhật sau các buổi học đầu tiên._

---

## 9. LOG CÁC BUỔI LÀM VIỆC VỚI CLAUDE

### 2026-05-15 — Buổi khởi động (claude.ai web)
- Thiết lập toàn bộ hệ thống project OOP
- SYSTEM_PROMPT.md: elite OOP professor + exam coach, learning flow 9 bước
- Tùy chỉnh riêng cho OOP: knowledge map 4 tầng, focus areas 7 cặp concept hay nhầm, initialization 4 lựa chọn
- about.md: roadmap 5 tầng với checklist, session mặc định
- PROJECT_CONTEXT.md (file này): context đầy đủ để chuyển sang Cowork
- Cây thư mục: thêm `raw/source_code/` so với project HĐH
- pdf_to_chapters.py: dùng lại script từ project HĐH

---

## 10. HƯỚNG DẪN CHO COWORK

Khi bắt đầu session mới, đọc theo thứ tự:
1. `PROJECT_CONTEXT.md` ← file này, nắm toàn bộ hệ thống
2. `about.md` ← tiến độ học hiện tại
3. `SYSTEM_PROMPT.md` ← cách dạy học chi tiết

Sau đó:
- Nếu `about.md` có "Đang ôn" → tiếp tục chủ đề đó
- Nếu chưa có → hỏi 4 lựa chọn như trong `<initialization>` của SYSTEM_PROMPT
- Ưu tiên phân tích đề thi cũ trước nếu chưa có `topic_frequency_map.md`
- Ưu tiên review source code nếu có file trong `raw/source_code/`
