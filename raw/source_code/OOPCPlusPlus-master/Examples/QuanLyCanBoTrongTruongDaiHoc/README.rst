Đề bài - Quản lý cán bộ trong trường đại học
############################################

.. sectnum::

.. contents:: Nội dung

Nội dung thực hiện
******************

Đề bài
======

Giả sử một trường Đại học cần quản lý thông tin cán bộ (gồm giảng viên và nhân viên hành chính) trong trường.

* Với giảng viên cần quản lý thông tin: Họ tên, khoa, trình độ (cử nhân, thạc sĩ, tiến sĩ), phụ cấp, số tiết dạy, hệ số lương.

* Với nhân viên hành chính cần quản lý thông tin: Họ tên, phòng ban, số ngày công, hệ số lương, phụ cấp, chức vụ (trưởng phòng, phó phòng, nhân viên).

Phụ cấp của cán bộ được tính theo bảng sau:

+-------------------+-----------+----------------------+-----------+ 
| Học vị giảng viên | Phụ cấp   | Chức vụ nhân viên    | Phụ cấp   |
+===================+===========+======================+===========+
| Cử nhân           | 300       | Trưởng phòng         | 2000      |
+-------------------+-----------+----------------------+-----------+
| Thạc sĩ           | 500       | Phó phòng            | 1000      |
+-------------------+-----------+----------------------+-----------+
| Tiến sĩ           | 1000      | Nhân viên            | 500       |
+-------------------+-----------+----------------------+-----------+

* Lương giảng viên được tính như sau: ``Hệ số lương * 730 + Phụ cấp + Số tiết dạy * 45``.

* Lương của nhân viên được tính như sau: ``Hệ số lương * 730 + Phụ cấp + Số ngày công * 200``.

Hãy viết chương trình bằng C++ cho phép thực hiện các chức năng sau:

1. Nhập vào danh sách cán bộ trong trường.

2. In ra danh sách cán bộ.

3. In danh sách cán bộ ra file ``Danhsach.txt``

4. Tính tổng lương phải trả cho các cán bộ trong trường.

5. Hãy cho biết giảng viên nào nhận lương thấp nhất và giảng viên nào nhận lương cao nhất, xuất thông tin giảng viên đó ra ``LuongCanBo.txt``.

Yêu cầu sử dụng tính kế thừa và đa hình. Lập trình các chức năng theo yêu cầu trên.

Bài làm
=======

* Xây dựng lớp cơ sở ``CanBo`` và các lớp ``GiangVien``, ``NhanVienHanhChinh`` kế thừa từ lớp cơ sở ``CanBo``.

* Xây dựng lớp ``QuanLyCanBo`` để thực hiện các yêu cầu.

* Source code: `QuanLyCanBoTrongTruongDaiHoc <https://github.com/thiminhnhut/OOPCPlusPlus/tree/master/Examples/QuanLyCanBoTrongTruongDaiHoc/source>`_

