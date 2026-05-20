# Session Log
<!-- Ghi lại những gì đã học mỗi buổi -->

---

## 2026-05-19 — Buổi Setup + Chuẩn bị tài liệu (Cowork)

### Đã hoàn thành
- **Bootstrap dự án:** Tạo toàn bộ cấu trúc thư mục (raw/, knowledge/, study/, notes/)
- **Extract slides:** 10 slide OOP (slide_01 → slide_10) — cả text lẫn visual (228 ảnh đọc bằng vision)
- **OCR đề thi:** 16 đề 2019–2026 → `knowledge/de_thi_analysis/de_thi_transcript.md`
- **Phân tích đề thi:** `topic_frequency_map.md` — câu 2 luôn Inheritance + Polymorphism; câu 1 từ 2025 dạng mới: Big Three + Operator Overloading theo main cho sẵn
- **Review source code:** 4 bộ trong `raw/source_code/`, tìm + sửa **11 lỗi** vào file gốc, ghi báo cáo `notes/code_review.md`
- **Kế hoạch ôn tập:** `study/plan.md` — 5 buổi với tài liệu, code mẫu, bài tập, checklist
- **Push GitHub:** `https://github.com/onggia98/OOP.git`

### Lỗi nổi bật đã sửa trong source code (học từ đây)
| Lỗi | File | Bài học |
|-----|------|---------|
| Thiếu copy ctor + op= | DynamicArray.cpp | Rule of Three — bắt buộc khi có delete[] |
| Thiếu virtual destructor | Shape, IEmployee, final2022 | Luôn thêm khi dùng base pointer |
| Stack::pop/top không return khi rỗng | final2022.cpp | Undefined behavior → throw exception |
| `num / den` thay vì `num % den` | FractionDisplay.cpp | Bug logic phân số hỗn số |
| main() không dùng base pointer | HinhHoc/main.cpp | Không có polymorphism nếu tạo object theo giá trị |

### Chưa làm — ưu tiên buổi tới
- [ ] Bắt đầu Buổi 1 (Class Design) theo `study/plan.md`
- [ ] Flashcard Operator Overloading + Big Three
- [ ] Đáp án mẫu đề 2025 HK2 (CMyArray) + 2026 HK1 (CMyString)
- [ ] 1–2 mock exam theo pattern đề thi
