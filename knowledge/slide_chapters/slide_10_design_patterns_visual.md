# Slide 10 — Mẫu Thiết Kế Hướng Đối Tượng (Design Patterns)
**Giảng viên:** Nguyễn Minh Huy
**Môn:** Phương pháp lập trình hướng đối tượng

---

## Trang 1 — Trang bìa

**Tiêu đề:** Mẫu thiết kế hướng đối tượng
**GV:** Nguyễn Minh Huy

---

## Trang 2 — Nội dung

Slide mục lục (animation chưa highlight):
- Giới thiệu mẫu thiết kế.
- Một số mẫu thông dụng.

*(Trang 3 là animation lặp của trang 2 với "Giới thiệu mẫu thiết kế" được highlight — bỏ qua.)*

---

## Trang 4 — Giới thiệu mẫu thiết kế: Thế nào là OOP?

**Thế nào là chương trình hướng đối tượng?**
- Có khai báo lớp và sử dụng đối tượng? → Chưa đủ!!
- Cần tuân thủ **ba tính chất hướng đối tượng**:
  - Tính đóng gói (encapsulation)
    - Quy tắc hộp đen.
  - Tính kế thừa (inheritance)
    - Tái sử dụng.
  - Tính đa hình.
    - Hàm ảo + liên kết động.

**📊 Diagram:** Hình minh họa nhân vật hoạt hình đang suy nghĩ (dấu hỏi), biểu trưng cho câu hỏi "OOP thực sự là gì?".

---

## Trang 5 — Giới thiệu mẫu thiết kế: Mục đích OOP

**Mục đích của hướng đối tượng?**
- Giảm gắn kết mã nguồn (spaghetti code).
- Giảm chi phí xây mới.
- Giảm phụ thuộc vào cài đặt cụ thể.
  - Ứng phó thay đổi, dễ bảo trì, nâng cấp.

**📊 Diagram:** Hình ảnh đĩa mì spaghetti — ẩn dụ cho "spaghetti code" (mã nguồn rối rắm, khó bảo trì).

---

## Trang 6 — Giới thiệu mẫu thiết kế: Khái niệm Design Pattern

**Khái niệm mẫu thiết kế:**
- Các tính chất hướng đối tượng mơ hồ, khó hiểu.
  - Cần có những bài giải mẫu.
- **Mẫu thiết kế Gang of Four:**
  - Ra đời tại OOPSLA 1994.
  - 23 bài giải mẫu cho những vấn đề thiết kế thường gặp.

**📊 Diagram:** Hình bìa cuốn sách "Design Patterns: Elements of Reusable Object-Oriented Software" (Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides) cùng ảnh chụp nhóm tác giả Gang of Four.

---

## Trang 7 — Nội dung (chuyển phần)

Slide mục lục chuyển tiếp:
- Giới thiệu mẫu thiết kế.
- **Một số mẫu thông dụng.** ← đang học

*(Animation highlight mục 2 — nội dung giống trang 2, chỉ ghi một lần.)*

---

## Trang 8 — Vấn đề 1: Singleton — Bài toán NhanVienPhucVu

**Vấn đề 1:**
Một nhà hàng nhỏ thuê duy nhất **MỘT** nhân viên phục vụ bàn. Tại một thời điểm, nhân viên chỉ có thể phục vụ tối đa 5 bàn. Nhân viên được tiền thưởng 5% trên mỗi hóa đơn tính tiền.

Hãy xây dựng lớp **NhanVienPhucVu** đảm bảo điều kiện phục vụ và tính số tiền thưởng mà nhân viên nhận được đến thời điểm hiện tại.

**💻 Code:**
```cpp
class NhanVienPhucVu
{
private:
    int soban;          // Số bàn đang phục vụ.
    float tongTien;     // Tổng số tiền tính được.
public:
    void donKhach();
    void tinhTienKhach(float soTien);
    float tinhTienThuong();
};
```

---

## Trang 9 — Mẫu Singleton: Giới thiệu và UML

**Mẫu Singleton:**
- Giúp giới hạn số lượng đối tượng được tạo.
  - Đối tượng dùng chung.
  - Connection Pool.
  - Application Object.

**📊 Diagram:** UML Class Diagram của Singleton:

```
+---------------------------+
|         Singleton         |
+---------------------------+
| - singleton : Singleton   |  ← thuộc tính static private, kiểu chính lớp đó
+---------------------------+
| - Singleton()             |  ← constructor private (ngăn tạo từ bên ngoài)
| + getInstance() : Singleton| ← phương thức static public trả về thể hiện duy nhất
+---------------------------+
```

- Dấu gạch dưới (underline) trên `singleton` và `getInstance()` biểu thị thành viên **static**.
- Constructor `Singleton()` là **private** (dấu `-`) — không ai có thể `new Singleton()` từ bên ngoài.
- `getInstance()` là **public** (dấu `+`) — điểm truy cập toàn cục duy nhất.

---

## Trang 10 — Vấn đề 2: Composite — Bài toán mạch điện

**Vấn đề 2:**
Có 2 loại mạch điện:
- Cuộn dây: mạch đơn, có tiết diện S và chiều dài L.
  - R = 0.5 * L / S
- Mạch nối tiếp: mạch phức, có mạch con mắc nối tiếp bên trong.
  - R = R₁ + R₂ + … + R_N

Xây dựng chương trình tính điện trở của một mạch điện.

**💻 Code:**
```cpp
class CuonDay
{
private:
    float m_tietDien;
    float m_chieuDai;
public:
    CuonDay(float S, float L);
    float tinhDienTro();
};

class MachNoiTiep
{
private:
    ???
public:
    float tinhDienTro();
    ???
};
```

*(Dấu `???` biểu thị phần cần thiết kế — đây là bài toán dẫn vào mẫu Composite.)*

---

## Trang 11 — Mẫu Composite: UML Class Diagram

**📊 Diagram:** UML Class Diagram đầy đủ của mẫu Composite:

```
         uses
Client ---------> +------------------+  * - children
                  |    Component     |<--------------+
                  +------------------+               |
                  | + Operation1()   |               |
                  | + Operation2()   |               |
                  +------------------+               |
                        /\    /\                     |
                       /    \/   \                   |
          (kế thừa)   /            \ (kế thừa)       |
                     /              \                |
        +-----------+        +------------------+   |
        |   Leaf    |        |    Composite     |---+ (aggregation/composition)
        +-----------+        +------------------+
        |+Operation1()|      | + Operation1()   |
        |+Operation2()|      | + Operation2()   |
        +-----------+        | + addComponent() |
                             | + removeComponent()|
                             | + getComponent() |
                             | + getComponentCount()|
                             +------------------+
```

**Giải thích các quan hệ:**
- `Client` → `Component`: quan hệ **uses** (phụ thuộc, mũi tên đứt nét).
- `Leaf` → `Component`: kế thừa (mũi tên tam giác rỗng, chỉ vào cha).
- `Composite` → `Component`: kế thừa (mũi tên tam giác rỗng).
- `Composite` ◇→ `Component` (nhãn `* - children`): **aggregation** — Composite chứa danh sách các Component con (nhiều — `*`), đây chính là mối quan hệ đệ quy cho phép lồng ghép cây.
- `Leaf` là lá (không có con), `Composite` là nút nhánh (có con là danh sách Component).

**Ý nghĩa pattern:**
- `Component`: interface/lớp trừu tượng chung cho cả Leaf và Composite.
- `Leaf`: phần tử không thể phân chia thêm.
- `Composite`: phần tử phức hợp, chứa danh sách `children : Component[]`, gọi đệ quy Operation xuống các con.

---

## Trang 12 — Vấn đề 3: Adapter — Bài toán huấn luyện thú nuôi

**Vấn đề 3:**
Xét chương trình huấn luyện thú nuôi:

**💻 Code:**
```cpp
class Pet {
public:
    virtual void eat() = 0;
    virtual void talk() = 0;
};

class Cat : public Pet {
public:
    void eat();
    void talk();
};

class Dog : public Pet {
public:
    void eat();
    void talk();
};

void trainPet( Pet *p )
{
    p->eat();
    p->talk();
    p->eat();
    p->talk();
}
```

---

## Trang 13 — Vấn đề 3 (tiếp theo): Adapter — WildAnimal

**Vấn đề 3 (tiếp theo):**
Có thêm hệ thống thú hoang dã với interface riêng:

**💻 Code:**
```cpp
class WildAnimal {
public:
    virtual void hunt() = 0;
    virtual void eatMeat() = 0;
    virtual void shout() = 0;
};

class Tiger : public WildAnimal {
public:
    void hunt();
    void eatMeat();
    void shout();
};

class Wolf : public WildAnimal {
public:
    void hunt();
    void eatMeat();
    void shout();
};

void main()
{
    Tiger  t = new Tiger();
    Wolf   w = new Wolf();

    // làm sao huấn luyện??
    // trainPet( t );   // KHÔNG hợp lệ — Tiger không phải Pet
    // trainPet( w );   // KHÔNG hợp lệ — Wolf không phải Pet
}
```

**Yêu cầu:** Hãy tìm cách mở rộng chương trình để có thể huấn luyện được cả cọp và sói.
**Ràng buộc:** chỉ tái sử dụng, **không chỉnh sửa chương trình hiện có**.

→ Đây là bài toán điển hình của **Mẫu Adapter**: cần "chuyển đổi" WildAnimal sang interface Pet mà hàm `trainPet` mong đợi.

---

## Trang 14 — Mẫu Adapter: Giới thiệu và UML

**Mẫu Adapter:**
- Tái sử dụng đối tượng sẵn có vào ngữ cảnh khác.
  - Sử dụng lại thư viện có sẵn.

**📊 Diagram 1 — Minh họa trực quan (puzzle analogy):**
```
[Your Existing System] ──> [Vendor Class]       ← không khớp interface
[Your Existing System] ──> [Adapter] ──> [Vendor Class]  ← dùng Adapter làm cầu nối
```

**📊 Diagram 2 — UML Class Adapter (dùng kế thừa):**
```
Client ──> Target (interface)        Adaptee
            + Request()              + SpecificRequest()
                /\
                |  (implementation / kế thừa)
           Adapter
           + Request() o-----------> SpecificRequest()
                       (delegation)
```
- `Adapter` kế thừa `Target` (cung cấp đúng interface mà Client mong muốn).
- `Adapter` cũng kế thừa hoặc giữ tham chiếu đến `Adaptee` (gọi lại `SpecificRequest()`).
- `Request()` trong Adapter gọi đến `SpecificRequest()` của Adaptee.

**📊 Diagram 3 — UML Object Adapter (dùng composition):**
```
Client ──> Target (interface)         ──> Adaptee
            + Request()                   + SpecificRequest()
                /\
                |
           Adapter ──────────────────────(adaptee)──>
           + Request() o-----------> adaptee->SpecificRequest()
```
- Thay vì kế thừa Adaptee, Object Adapter **chứa** một con trỏ/tham chiếu `adaptee` đến Adaptee.
- `Request()` trong Adapter gọi `adaptee->SpecificRequest()`.
- Linh hoạt hơn Class Adapter (có thể adapter nhiều Adaptee khác nhau lúc runtime).

**Hai biến thể:**
| Loại | Cơ chế | Ưu điểm |
|------|--------|---------|
| Class Adapter | Đa kế thừa (Target + Adaptee) | Đơn giản, override được |
| Object Adapter | Composition (chứa con trỏ Adaptee) | Linh hoạt hơn, không cần đa kế thừa |

---

## Trang 15 — Tóm tắt

**Tóm tắt toàn chương:**

- **Chương trình hướng đối tượng:**
  - Tuân thủ ba tính chất hướng đối tượng.
  - Mục tiêu: ứng phó thay đổi, dễ bảo trì, nâng cấp.

- **Mẫu thiết kế:**
  - Bài giải mẫu cho vấn đề thiết kế thường gặp.
  - 23 mẫu của Gang of Four.

- **Mẫu thông dụng (3 mẫu được học):**
  - **Singleton** — giới hạn số lượng thể hiện.
  - **Composite** — cấu trúc cây đệ quy (leaf / composite).
  - **Adapter** — chuyển đổi interface để tái sử dụng.

---

## Trang 16 — Bài tập 10.1: Cỗ máy (Composite)

**Bài tập 10.1:**

Một cỗ máy được cấu tạo từ các chi tiết máy. Mỗi chi tiết máy đều được đánh mã số để phân biệt với nhau (ví dụ CT001).

Các chi tiết máy được phân làm 2 loại:
- **Chi tiết đơn:** không thể phân chia, có trọng lượng và giá thành.
- **Chi tiết phức:** cấu tạo từ những chi tiết con (đơn hoặc phức).
  - Trọng lượng = trọng lượng các chi tiết con + 10% phụ kiện kết nối.
  - Giá thành = giá thành các chi tiết con + 20% công lắp ráp.

Viết chương trình:
- Nhập vào các chi tiết máy cấu thành nên cỗ máy.
- Tính trọng lượng cỗ máy.
- Tính giá thành cỗ máy.

*(Áp dụng mẫu Composite: ChiTietDon = Leaf, ChiTietPhuc = Composite, ChiTiet = Component.)*

---

## Trang 17 — Bài tập 10.2: Hệ thống tập tin (Composite)

**Bài tập 10.2:**

Đơn vị lưu trữ dữ liệu trên máy tính là tập tin và thư mục.
- Tập tin có thông tin về tên và kích thước.
- Thư mục chỉ có tên nhưng có thể chứa tập tin và thư mục con.

Viết chương trình cho phép:
- Tạo ra một cây thư mục tập tin.
- Đếm số tập tin và thư mục có trong một thư mục nào đó.
- Tính kích thước một thư mục.

*(Áp dụng mẫu Composite: TapTin = Leaf, ThuMuc = Composite, DonViLuuTru = Component.)*

---

## Trang 18 — Bài tập 10.3: Nhân viên công ty (Đa hình)

**Bài tập 10.3:**

Một công ty sản xuất có 2 loại nhân viên:
- Nhân viên sản xuất: lương = số sản phẩm x 10000.
- Nhân viên văn phòng: lương = mức lương – ngày nghỉ x 10000.

Thông tin chung của nhân viên công ty gồm:
- Họ tên.
- Năm vào làm.

Ngoài lương được tính như trên, mỗi nhân viên còn được phụ cấp một khoảng tiền là 500000. Và khoảng tiền này cứ tăng thêm 50000 cho mỗi năm công tác ở công ty.

Viết chương trình:
- Nhập vào danh sách nhân viên công ty.
- Tính tổng số tiền công ty phải trả cho nhân viên mỗi tháng.

*(Áp dụng kế thừa và đa hình: NhanVien là lớp cha trừu tượng, NhanVienSanXuat và NhanVienVanPhong kế thừa.)*

---

## Trang 19 — Bài tập 10.4: Khách sạn (Đa hình + kế thừa)

**Bài tập 10.4:**

Một khách sạn 5 sao có 3 loại phòng:
- Phòng loại A, đơn giá 300 USD / ngày.
- Phòng loại B, đơn giá 200 USD / ngày.
- Phòng loại C, đơn giá 100 USD / ngày.

Tiền thuê phòng = đơn giá * số ngày thuê.

Khách ở phòng loại A được sử dụng một số dịch vụ của khách sạn. Tiền sử dụng dịch vụ được cộng vào tiền thuê phòng của khách.

Đặc biệt khách sạn có chính sách giảm giá 10% từ ngày thứ 10 trở đi cho những khách thuê phòng loại A và B.

Viết chương trình:
- Nhập vào thông tin thuê phòng.
- Tính tổng tiền thuê phòng.

*(Áp dụng kế thừa và đa hình: Phong là lớp cha, PhongA/B/C kế thừa, override phương thức tính tiền.)*

---

## Trang 20 — Bài tập 10.5: Bất động sản (Đa hình)

**Bài tập 10.5:**

Một công ty kinh doanh bất động sản sở hữu N miếng đất. Mỗi miếng đất có những thông tin sau:
- Mã số (ví dụ: MD001).
- Đơn giá một m2.

Ngoài ra, mỗi miếng đất tùy theo hình dạng còn có những thông tin riêng. Hiện có 2 loại hình dạng:
- Hình chữ nhật: diện tích = dài x rộng.
- Hình thang: diện tích = (đáy lớn + đáy nhỏ) * chiều cao / 2.

Miếng đất hình thang được công ty giảm giá 5%.

Viết chương trình:
- Nhập danh sách những miếng đất của công ty.
- Tính tổng diện tích các miếng đất.
- Tính tổng giá tiền của các miếng đất.

*(Áp dụng kế thừa và đa hình: MiengDat là lớp cha trừu tượng, MiengDatChuNhat và MiengDatHinhThang kế thừa, override phương thức tính diện tích và giá tiền.)*

---

## Tóm lược 3 Design Patterns trong slide này

### 1. Singleton
- **Mục đích:** Đảm bảo chỉ có **một thể hiện duy nhất** của lớp tồn tại trong toàn bộ chương trình.
- **Cơ chế:** Constructor private, thuộc tính static `singleton`, phương thức static `getInstance()`.
- **Ứng dụng:** Đối tượng dùng chung, Connection Pool, Application Object.

### 2. Composite
- **Mục đích:** Xây dựng **cấu trúc cây** cho phép Client xử lý đồng nhất cả đối tượng đơn lẻ (Leaf) và đối tượng phức hợp (Composite).
- **Cơ chế:**
  - `Component` (interface): khai báo các operation chung.
  - `Leaf` (lá): kế thừa Component, không có con.
  - `Composite` (nhánh): kế thừa Component, chứa danh sách `children : Component[]`, gọi đệ quy operation xuống các con.
- **Quan hệ UML:** Composite aggregates Component (nhiều con), cả Leaf và Composite đều kế thừa Component.
- **Ứng dụng:** Mạch điện (CuonDay / MachNoiTiep), hệ thống tập tin (File / Folder), cỗ máy (ChiTietDon / ChiTietPhuc).

### 3. Adapter
- **Mục đích:** Chuyển đổi interface của một lớp sang interface khác mà client mong muốn — cho phép **tái sử dụng** các lớp có interface không tương thích.
- **Hai biến thể:**
  - **Class Adapter:** Adapter kế thừa cả Target và Adaptee (đa kế thừa).
  - **Object Adapter:** Adapter kế thừa Target, **chứa** một instance của Adaptee (composition), gọi `adaptee->SpecificRequest()` trong `Request()`.
- **Ứng dụng:** Huấn luyện WildAnimal qua interface Pet, tái sử dụng thư viện có sẵn.
