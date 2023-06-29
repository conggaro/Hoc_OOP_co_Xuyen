# Tuần 1 (22/05/2023): 
1. Giới thiệu học lập trình C++
2. Học biến
3. Học kiểu dữ liệu
4. Học hàm

# Tuần 2 (29/05/2023):
1. Học kiểu mảng - array
2. Học kiểu véc tơ - vector
3. Học kiểu bản ghi - struct
4. Học kiểu chuỗi - string

# Tuần 3 (05/06/2023):
1. Học biến con trỏ
2. Học đọc/ghi file

# Tuần 4 (12/06/2023):
1. Ôn bài để kiểm tra giữa kỳ
2. Ôn bài đọc/ghi file
3. Ôn bài mảng (mảng 1 chiều, mảng 2 chiều)
4. Ôn biến con trỏ
5. Ôn bài đếm chữ, đếm số, đếm ký tự (kiểu string)
6. Ôn bài kiểu bản ghi (struct)

# Tuần 5 (19/06/2023):
1. Thi giữa kỳ (bài 1 nhập xuất dữ liệu, bài 2 đọc ghi file, bài 3 đọc ghi file)
2. Khai báo lớp (class)
3. Khai báo thuộc tính (properties)
4. Khai báo phương thức (methods)
5. Phương thức tạo không tham số (constructor)
6. Phương thức tạo có tham số (cái này nó là nạp chồng overload của phương thức tạo không tham số)
7. Phương thức hủy (destructor). Lúc khai báo thì có dấu "~"
8. Phương thức gán dt2 cho dt1 (hoặc gọi là phương thức copy)
9. Biến static (là 1 giải pháp dùng để đếm số lượng đối tượng)
10. Hàm bạn bè (friend) --> Có tác dụng truy cập, sử dụng các thuộc tính private của 1 lớp (2 lớp cũng được luôn)
11. Con trỏ this

# Tuần 6 (26/06/2023):
1. Học tính kế thừa.<br>
&emsp;&emsp;&emsp;&emsp;Lớp cơ sở (base class).<br>
&emsp;&emsp;&emsp;&emsp;Lớp dẫn xuất (derived class).<br>
&emsp;&emsp;&emsp;&emsp;Kiểu kế thừa: public, protected, private.<br><br>
&emsp;&emsp;&emsp;&emsp;Trong C++ có:<br>
&emsp;&emsp;&emsp;&emsp;--> Đơn kế thừa.<br>
&emsp;&emsp;&emsp;&emsp;--> Đa kế thừa.<br>
&emsp;&emsp;&emsp;&emsp;--> Kế thừa nhiều tầng.<br><br>
&emsp;&emsp;&emsp;&emsp;Lớp cơ sở ảo (virtual base class)<br>
&emsp;&emsp;&emsp;&emsp;--> Để giải quyết vấn đề kế thừa như hình kim cương (kinh điển).<br><br>
2. Học tính đa hình.<br>
&emsp;&emsp;&emsp;&emsp;Là khả năng cho phép<br>
&emsp;&emsp;&emsp;&emsp;sự thể hiện khác nhau<br>
&emsp;&emsp;&emsp;&emsp;của MỘT PHƯƠNG THỨC<br>
&emsp;&emsp;&emsp;&emsp;ở các lớp kế thừa khác nhau.<br><br>
&emsp;&emsp;&emsp;&emsp;--> Ghi đè (Overriding)<br>
&emsp;&emsp;&emsp;&emsp;--> Nạp chồng (Overloading)<br>
&emsp;&emsp;&emsp;&emsp;--> Kết nối muộn (Late binding)<br><br>
&emsp;&emsp;&emsp;&emsp;Phương thức ảo.<br>
&emsp;&emsp;&emsp;&emsp;--> Được gọi theo cơ chế kết nối muộn (có từ khóa virtual).<br>
&emsp;&emsp;&emsp;&emsp;Ví dụ:<br>
&emsp;&emsp;&emsp;&emsp;public: virtual void Print() {}<br><br>
4. Học tính trừu tượng.<br>
&emsp;&emsp;&emsp;&emsp;Lớp trừu tượng (abstract class).<br>
&emsp;&emsp;&emsp;&emsp;--> Chứa phương thức ảo thuần túy.<br>
&emsp;&emsp;&emsp;&emsp;--> Không thể tạo đối tượng từ lớp trừu tượng.<br><br>
&emsp;&emsp;&emsp;&emsp;Phương thức ảo thuần túy (pure virtual function).<br>
&emsp;&emsp;&emsp;&emsp;Ví dụ:<br>
&emsp;&emsp;&emsp;&emsp;public: virtual void Print() = 0;<br>
