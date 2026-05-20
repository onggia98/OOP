# Constructor - Destructor và Copy Constructor

* **Thực hiện:** Thi Minh Nhựt - **Email:** thiminhnhut@gmail.com

* **Thời gian:** Ngày 30 tháng 09 năm 2018

## Nội dung

### Định nghĩa

* ``Static`` là dữ liệu của một ``class`` không phải là dữ liệu của đối tượng, biến ``static`` tồn tại như một biến toàn cục.

* Biến ``Static`` được khởi tạo trước khi đối tượng của một ``class`` được tạo ra và nó chỉ tồn tại duy nhất.

* ``Static`` có thể là ``private``, ``protected`` và ``public`` dành cho biến khai báo biến và khai báo hàm.

* Với ``class``, ``static`` dùng để khai báo ``data member`` dùng dung cho mọi thể hiện của ``class``.

  * Một bản duy nhất tồn tại trong suốt quá trình chạy chương trình.

  * Dùng chung cho tất cả các thể hiện của ``class``.

  * Bất kể ``class`` có bao nhiêu thể hiện của nó.

### Cách gọi biến static

* Cú pháp: ``Class_Name::Static_Variable``