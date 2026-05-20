# Sử dụng Forward Declaration trong C++

* **Thực hiện:** Thi Minh Nhựt - **Email:** thiminhnhut@gmail.com

* **Thời gian:** Ngày 20 tháng 11 năm 2018

## Nguồn tham khảo

1. [Sử dụng Forward Declaration trong C++](https://www.cppdeveloper.com/best-practices/su-dung-forward-declaration-trong-c/?fbclid=IwAR0BUZo_oYicQ9H0xEPytoc2p046lF75CJwaoBgX3kvkPlfNaMRhOmqqpCk)

## Nội dung

* **Ví dụ:**

    * Ta có 2 class `ClassA` (gồm 2 file `ClassA.h` và `ClassA.cpp`) và `ClassB` (gồm 2 file `ClassB.h` và `ClassB.cpp`).

    * Trong `ClassB` có sử dụng `ClassA`.

        * Với cách làm thông thường: trong `ClassB.h` chúng ta `#include "ClassA.h"` và trong `ClassB.cpp` chúng ta `#include "ClassB.h"`.

        * Vì `ClassB.h` đã `#include "ClassA.h"` và `ClassB.cpp` cũng có `#include "ClassA.h"` thông qua `#include "ClassB.h"` (do `ClassB.cpp` có `#include "ClassB.h"`).

        * File `ClassB.cpp` lúc nào cũng cần `#include "ClassA.h"` nhưng không phải lúc nào `ClassB.h` cũng cần `#include "ClassA.h"`.

        * Việc `#include` thừa, nếu không cần thiết thì làm tốn thời gian biên dịch chương trình.

    * Nếu `ClassB.h` chỉ tham chiếu đến `ClassA` thông qua con trỏ hoặc biến tham chiếu (mà không gọi đến các phương thức gồm cả `contructor` hoặc bất kỳ thuộc tính nào của `ClassA`) thì chúng ta sử dụng chức năng `Forward Declaration` thay vì `#include "ClassA.h"`

    * Sử dụng chức năng `Forward Declaration` cho ví dụ:

        * Trong `ClassB.h` thêm dòng `class ClassA;` (đặt ngoài `class ClassB`).

        * Trong `ClassB.cpp` thì cả `#include "ClassA.h"` và `#include "ClassB.h"`
