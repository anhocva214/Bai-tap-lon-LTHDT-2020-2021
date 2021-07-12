# Bài báo cáo bài tập lớn
## Môn lập trình hướng đối tượng

| Họ và tên  | MSSV     |  Giảng viên           |
| :---       | :----:   |  :---:                |
| HỒ AN      | 19110251 |THS. NGUYỄN NGỌC LONG  |

### Đề tài:
>Xây dựng lớp biểu diễn khái niệm Stack. Sử dụng Stack kể trên, viết một ứng dụng cho phép giải quyết bài tính giá trị một biểu thức trung tố (không dùng đệ qui). Biểu thức trung tố có thể bao gồm cả phép gọi hàm các hàm thông dụng như sqrt, exp, log, sin, cos…


### Giai đoạn:
    1. Khời tạo khái niệm Stack
    2. Xây dựng chương trình tính toán biểu thức trung tố

### Nội dung:
1. Khời tạo khái niệm Stack:
    - `Init`: khởi tạo Stack rỗng
    - `IsEmpty` : kiểm tra Stack rỗng
    - `IsFull`: kiểm tra Stack đầy
    - `Push`: thêm phần tử vào Stack
    - `Pop`: lấy và loại bỏ phần tử khỏi Stack

2. Xây dựng chương trình tính toán biểu thức trung tố
    - Viết hàm `ScanInput` để duyệt và xử lý tất cả các ký tự trên input đầu vào theo các hàm sau đây:
    - Hàm `Prioritize` đẻ kiểm tra mức độ ưu tiên của *toán tử*
    - Hàm `Classify` để phẩn loại *toán tử* và *số hạng*
    - Hàm `CalValue` để tính toán giá trị của phép toán
    - Hàm `Calculator` để bắt đàu thực hiện thuật toán

3. Demo thuật toán:

    Cho M = 5 * 3 – (3 + 5)
    ```
    1.  Khởi tạo Sh = {} và St = {}
    2.  M1 = "5"       -> Đưa vào Sh.        Sh={ 5 }       St={}
    3.  M2 = "*"       -> Đưa vào St.        Sh={ 5 }       St={ * }
    4.  M3 = "3"       -> Đưa vào Sh.        Sh={ 5 3 }     St={ * }
    5.  M4 = "-"       -> Tính 5 * 3 = 15    Sh={ 15 }      St={ - }
    6.		   -> Đưa vào Sh.
    7.  M5 = "("       -> Đưa vào St.        Sh={ 15 }      St={ - ( }
    8.  M6 = "3"       -> Đưa vào Sh.	 Sh={ 15 3 }    St={ - ( }
    9.  M7 = "+"       -> Đưa vào St.        Sh={ 15 3 }    St={ - ( + }
    10. M8 = "5"       -> Đưa vào Sh.        Sh={ 15 3 5 }  St={ - ( + }
    11. M9 = "("       -> Tính 3 + 5 = 8     Sh={ 15 8 }    St={ - }
    12.		   -> Đưa vào Sh.
    13. Top(St) = "-"  -> Tính 15-8=7        Sh={ 7 }       St={}
    14.		   -> Đưa vào Sh.
    15. Dừng.
    ```
4. Kiểm thử chương trình:

    ![Kết quả thực nghiệm](https://octodex.github.com/images/yaktocat.png)

    - Video : *https://drive.google.com/file/d/11vMXub2Rm37xmwtto7-aQbnbDLPfyX9G/view?usp=sharing*

5. Source code:
    > https://github.com/anhocva214/Bai-tap-lon-LTHDT-2020-2021
