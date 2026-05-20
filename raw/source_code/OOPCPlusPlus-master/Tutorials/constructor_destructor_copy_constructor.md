# Constructor - Destructor và Copy Constructor

* **Thực hiện:** Thi Minh Nhựt - **Email:** thiminhnhut@gmail.com

* **Thời gian:** Ngày 29 tháng 09 năm 2018

## Nội dung

* Phương thức ``constructor``:

  * Dùng để khởi tạo lớp, có tên trùng với tên class. Ví dụ: ``class Circle`` thì constructor là ``Circle()`` hoặc ``Circle(float radius)``.

  * Phương thức được gọi khi chúng ta khởi tạo đối tượng.

  * Phương thức ``constructor`` có thể có đối số hoặc không có đối số.

  * Một class có thể có nhiều phương thức ``constructor``.

  * Phương thức ``constructor`` phải nằm ở thuộc tính ``public``.

* Phương thức ``destructor``:

  * Là phương thức hủy bỏ đối tượng, mang toán tử ``~`` trước tên phương thức. Ví dụ: ``class Circle`` thì destructor là ``~Circle()`` hoặc ``~Circle(float radius)``.

  * Được gọi trước khi đối tượng được hủy bỏ.

  * Một class chỉ có một phương thức ``destructor``.

  * Phương thức ``destructor`` phải nằm ở thuộc tính ``public``.

  * Phương thức ``destructor`` được dùng để dọn dẹp một số thứ cần thiết trước khi đối tượng được hủy bỏ (con trỏ, cấp phát bộ nhớ động).

* Phương thức ``Copy constructor``:

  * ``Copy constructor`` dùng để tạo ra một bản sau của một đối tượng đã có trước đó.

  * ``Copy constructor`` chỉ sao chép nội dung chứ không sao chép địa chỉ của đối tượng.

  * Khi nào dữ liệu của class có cấp phát động thì cài đặt ``copy constructor``.

  * Cú pháp khai báo ``Copy constructor``:

        Class_Name(const Class_Name& Variable_Name) {
            /*
                Cấp phát bộ nhớ động cho kiểu dữ liệu con trỏ.

                Gán dữ liệu của Variable_Name cho đối tượng hiện tai.
            */
        }