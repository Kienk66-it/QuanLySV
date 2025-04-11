# 📘 Bài tập: Quản lý sinh viên – Nhập môn lập trình

## 👨‍🎓 Giới thiệu

`QuanLySV.cpp` là một chương trình C++ đơn giản mô phỏng hệ thống quản lý sinh viên cơ bản.  
Bài tập được thực hiện trong khuôn khổ môn học **Nhập môn lập trình** tại trường đại học.  
Chương trình cho phép **thêm, sửa, xóa, tìm kiếm và hiển thị thông tin sinh viên**, lưu trữ trong file `quanLySV.txt`.

---

## 🧩 Tính năng chính

- ✅ **Thêm sinh viên**:  
  Kiểm tra mã sinh viên trùng, định dạng ngày sinh và điểm GPA hợp lệ.

- 📄 **Hiển thị danh sách**:  
  Đọc dữ liệu từ file và in toàn bộ danh sách sinh viên.

- 🔍 **Tìm kiếm sinh viên**:  
  Hỗ trợ tìm kiếm theo mã sinh viên hoặc theo tên.

- ✏️ **Cập nhật thông tin**:  
  Cho phép sửa tên, ngày sinh, GPA và lớp học của sinh viên theo mã.

- ❌ **Xoá sinh viên**:  
  Có xác nhận trước khi xóa thông tin.

- 💾 **Lưu trữ dữ liệu**:  
  Dữ liệu được ghi và đọc từ file `quanLySV.txt`. File sẽ được cập nhật sau mỗi thao tác.

---

## 📁 Cấu trúc tệp

```
QuanLySV/
├── QuanLySV.cpp         # Mã nguồn chương trình
└── quanLySV.txt         # File lưu trữ thông tin sinh viên (được tạo sau khi chạy)
```

---

## 🚀 Cách chạy chương trình

### 🔧 Biên dịch chương trình:

```bash
g++ -o QuanLySV QuanLySV.cpp
```

### ▶️ Chạy chương trình:

- Trên Linux/macOS:
```bash
./QuanLySV
```

- Trên Windows (hoặc click đúp nếu dùng Code::Blocks, Dev-C++, v.v):
```bash
QuanLySV.exe
```

---

## 💡 Ghi chú

- Mã sinh viên phải đúng **8 ký tự** và **không trùng lặp**.
- Ngày sinh yêu cầu đúng định dạng: `DD/MM/YYYY`.
- GPA hợp lệ trong khoảng: **0.00 → 4.00**.
- Dữ liệu trong file `quanLySV.txt` sẽ được **cập nhật và sắp xếp** mỗi khi thêm, sửa hoặc xóa.

---

## 📚 Mục đích bài tập

Bài tập giúp luyện tập các kỹ năng lập trình cơ bản:

- Làm việc với **`struct`** và **`vector`**
- Xử lý **chuỗi**, **tương tác nhập/xuất** từ bàn phím
- Lưu trữ và đọc dữ liệu bằng **file**
- Sử dụng **vòng lặp**, **câu điều kiện**, **hàm**, và kỹ thuật sắp xếp

---

## ✍️ Tác giả

- **Họ tên**: Lê Trung Kiên
- **Môn học**: Nhập môn lập trình
- **Trường**: Đại học công nghệ

---

## 📎 Ghi chú thêm

> Đây là bài tập phục vụ mục đích học tập. Không sử dụng cho mục đích thương mại.

---
