# Các thuộc tính public, protected và private trong C++

* **Thực hiện:** Thi Minh Nhựt - **Email:** thiminhnhut@gmail.com

* **Thời gian:** Ngày 29 tháng 09 năm 2018

## Nội dung

* Thuộc tính ``private``:
  
  * Chỉ được gọi và sử dụng trong phạm vi của class (sử dụng nội bộ trong class).

  * Bên ngoài class sẽ không thể truy cập vào thuộc tính ``private``.

* Thuộc tính ``protected``:

  * Giống như thuộc tính ``private``, thuộc tính ``protected`` không cho phép truy cặp từ bên ngoài.

  * Tuy nhiên, thuộc tính ``protected`` cho phép các dẫn xuất của nó truy cập đến các nội dung của nó.

  * Lớp dẫn xuất là lớp được kế thừa từ lớp đó, bổ sung thêm một số dữ liệu và phương thức với các thuộc tính khác.

* Thuộc tính ``public``: cho phép truy cập đến các thuộc tính và phương thức từ bên ngoài của class (trái ngược với thuộc tính ``private`` và ``protected``).

* Tùy vào mục đích sử dụng mà chọn sử dụng các thuộc tính ``private``, ``protected`` và ``public`` cho phù hợp nhằm đảm bảo *tính đóng gói* và *che giấu thông tin*.