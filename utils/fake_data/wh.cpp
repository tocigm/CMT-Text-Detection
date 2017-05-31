#include <cairo/cairo.h>
#include <string>
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <random>

#include <vector>

#include <iostream>
#include <fstream>
#include <string>
#include <fstream>


using namespace cv;
using namespace std;
using std::vector;

string BASE = "/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/";
string  texts[] = {"Thời","khắc","này","Mệnh","Vận","chi","thành","bốn","phía","toà","cổ","mấy","người","đều","ngẩng","đầu","lên","hướng","về","vị","trí","nhìn","lại","trên","hư","không","như","tranh","thuỷ","mặc","trong","mộng","ảo","trì","giống","dần","ánh","vào","đoàn","mi","mắt","mông","lung","phục","thậm","chí","có","chút","tin","mình","con","chứng","kiến","đây","căn","bản","một","chân","thực","càng","là","ảnh","kỳ","cảnh","tuần","viên","Quả","nhiên","đại","thế","tự","huyễn","nhưng","thể","soạn","nhạc","rất","nhiều","lòng","khá","chấn","động","mở","ra","cũng","phải","chỉ","cửa","mà","bỗng","dưng","hiện","liền","dường","giờ","cho","rằng","bao","phủ","ở","mảnh","tận","sương","mù","bên","ngày","thường","xem","phương","cái","gì","thấy","tiên","tri","đem","tản","đi","thì","tựa","rõ","ràng","Đó","chuyện","xảy","ta","làm","sao","được","thật","pháo","đài","đang","chầm","chậm","phảng","phất","bình","địa","dựng","vẻ","mặt","phốc","đông","nhảy","từng","cao","lầu","từ","đất","bay","ngắn","nháy","hình","khiến","quần","suy","đoán","đạo","lý","tới","thượng","bắt","nên","sẽ","tình","huống","hồ","còn","yêu","thú","phát","sinh","thán","bọn","họ","đồ","vật","tồn","tại","với","ngừng","lóe","thân","ngự","bước","trực","tiếp","đến","lập","tức","biến","mất","tăm","hơi","nhanh","tác","cơ","duyên","lớn","đã","chờ","đợi","nữa","ít","bóng","khi","chạm","kia","gian","ngoại","giới","nơi","nào","nghi","ngờ","chính","thay","đổi","khổng","phong","muốn","nghịch","thiên","cải","cuồn","cuộn","âm","thanh","truyền","tiếng","reo","hò","mang","theo","so","sục","sôi","dũng","cảm","tâm","Lúc","hành","cung","Lâm","lẩm","bẩm","nói","nhỏ","cạnh","hắn","áo","trắng","tuyết","lời","yên","tĩnh","đứng","run","lôi","kéo","hai","thẳng","khác","đỉnh","tương","ngóng","Hại","Trùng","Ngụy","Đế","quay","hô","Song","Hoàng","Chèn","Ép","Nhược","Tà","Tuế","Nguyệt","Kiếm","xác","tàn","nhẫn","hoang","bí","cùng","tốc","độ","đồng","bùng","nổ","Tôn","Vũ","cửu","trọng","nhân","ngăn","hạ","thi","trụy","lạc","huyết","dịch","phiêu","tán","rơi","rụng","vu","Long","Thần","Bảo","cường","giả","vẫn","đủ","phá","sát","lục","ma","quyền","đánh","trúng","rung","chuyển","quán","xuyên","phiến","loạt","bạo","liệt","bị","oanh","tan","mây","khói","toàn","bộ","vô","lực","xuống","gào","thét","hiếm","mỏng","hơn","cuồng","dã","khí","yếu","đích","dám","trước","vờn","quanh","chung","gắt","gao","chằm","vòng","chiến","đấu","cực","mãnh","để","bất","luận","kẻ","tham","dự","ngược","hổ","ngàn","năm","nội","dù","lấy","đảo","qua","đám","ngươi","lộ","lạnh","lùng","phạt","của","những","cách","chúng","lần","Tề","gia","thống","khoái","giết","chóc","tràng","a","Tốt","gật","đạp","mạnh","chớp","xuất","Na","thức","tia","dạng","hàng","thứ","nếu","phóng","ngoài","vênh","hất","hàm","sai","ớt","kích","Rống","cánh","tay","nứt","tràn","ngập","lượng","giác","vung","trời","rẩy","ầm","toái","nọ","bối","thủng","chết","Tứ","sáu","bát","tất","cả","đúng","sợ","hãi","chủ","cấp","bậc","lay","tuyệt","đối","Xích","Nhai","niệm","vừa","công","vỡ","thuật","ngủi","phẫn","nộ","trảm","chỉnh","khiếu","hãn","Nghĩ","cứng","rắn","bổ","chém","rách","máu","tươi","Tắm","rửa","quang","pháp","trừ","hạn","sắc","bén","đáng","ý","rồi","cận","kề","chư","gan","mật","tái","nhợt","thâm","nhập","mồ","hôi","đơn","giản","chưởng","huy","tòa","sơn","vòm","rũ","áp","hội","tụ","nổi","giận","giữa","trăm","trượng","chặt","đứt","khứ","sụp","thảm","thiết","thái","tử","gầm","dữ","giảm","bớt","sống","chánh","tai","họa","chưa","tục","chỗ","may","mắn","thoát","khỏi","lũy","hủy","diệt","chuyến","nhượng","xoá","tên","Xa","dẫn","sau","mười","đệ","triển","khai","Nhị","cầm","giữ","tế","phút","mượn","nhờ","uy","hóa","dẹp","tợn","quét","thổi","phù","nhẹ","vang","ấn","ký","nát","vậy","thừa","nhận","sự","Mộc","Trần","Hầu","cục","dưới","thông","lẽ","biết","quyết","định","cỡ","sỉ","nhục","y","nguyên","dài","tung","phùng","bừa","bãi","kinh","khủng","hắc","ám","ngạo","nghễ","hết","thảy","khó","coi","hoàn","bức","tường","đổ","khắp","thuộc","gặp","Dừng","miệng","phun","chữ","di","xưa","Tư","hôm","nay","ư","nhàn","nhạt","nhất","bài","Vấn","sư","chuẩn","đầy","ah","đôi","mỉm","cười","màn","chặn","bách","tiểu","truy","liên","minh","tiến","diện","tuy","tùy","thôi","Việc","quan","hệ","chế","FTqaoo","U","ai","thủ","Các","kế","cúi","kiện","râu","ria","khóe","cần","phụ","trách","Nghe","lưu","đày","nhằm","chạy","nắng","Advertisement","nghị","kiêng","kỵ","ngay","huynh","hỗ","trợ","tru","giao","thoáng","khẽ","xông","xanh","thích","tăng","mực","súc","rốt","cuộc","tóe","nại","quá","bố","đập","sít","đấy","Tạch","tắc","lan","trầm","loại","xé","lui","đường","khách","mới","rú","nham","thạch","trùm","lồ","đụng","tầng","sáng","phận","quý","vong","niên","hảo","hữu","vầy","vân","đạm","khinh","hồi","ngạc","trở","bạn","Đương","do","danh","Cứu","điên","thổ","trụ","giãy","dụa","dụng","sẵn","gây","nghiệt","giọng","nắm","khúc","gãy","kêu","bóp","thê","đuôi","tưởng","tượng","mọi","tạo","máy","móc","","quái","đặc","Siêu","Nhà","Tặng","đậu","nhớ","mẽ","bỉ","hoả","ghé","tìm","hồn","phách","vì","Lão","hỏa","mày","xám","xịt","tóc","thiêu","dáng","trận","hỗn","đản","chẳng","mỗi","phú","loa","ngại","cờ","điểm","phen","phi","kiêu","luôn","lẫm","tính","tủng","nở","nụ","khóc","bồi","khốn","gãi","nghiến","răng","lợi","dấp","cừu","hận","Ngạch","hung","lệ","triệt","héo","biển","thị","thận","lâu","hỏi","túy","huyền","viễn","Tiêu","tránh","dị","thải","biệt","hay","hiểu","đoạt","khả","năng","quỷ","lường","câu","kết","võ","tu","tiền","vặn","sức","thỉnh","giáo","cặp","đột","dựa","cau","lắc","đọng","sĩ","mảy","khoác","biểu","dĩ","phức","tạp","vượt","phạm","trù","Viêm","ly","ngâm","chốc","lát","tiện","dò","ngậm","phái","lứa","Khung","Khuyết","hiển","giá","trị","diệu","lai","đâu","Hả","mơ","vực","cuốn","đờ","thầm","quen","quy","xúc","ngầm","củ","đặt","can","thiệp","gió","lấp","loé","ẩn","hứng","tỏ","nghĩa","Phí","Suýt","đời","đồn","căm","ghét","hậu","cợt","Vĩ","ném","Té","sang","xung","Tội","thấp","lĩnh","ngộ","thương","chắp","lưng","khô","cạn","tiếc","cứ","bạch","ngọc","trung","vững","vạn","chiếc","thuyền","bầu","hề","Tô","Kiếp","tọa","tuyển","chuyên","môn","Đào","khớp","phiền","muộn","sớm","lăm","Tài","mỹ","vợ","Đêm","khuya","báo","duỗi","lười","ống","vén","chăn","daX","eBT","giường","ngủ","Ông","ban","cô","em","xinh","đẹp","ngồi","vi","viết","khan","mã","trình","Vượn","dắt","nữ","độc","chó","vui","buồn","thất","nhắc","tỉnh","liếc","châu","lông","diễm","môi","tấm","nõn","gương","non","sắp","xếp","nước","Giang","Nam","thả","thiếu","nhịn","khuôn","nhắn","trứng","nhức","phân","nửa","bệnh","viện","tám","phần","tá","móng","vuốt","xổm","hào","giàu","trai","than","thở","rãi","nhắm","Nha","mềm","mại","giật","tỉ","mỉ","gái","đàn","bà","màu","vải","đóng","hẹp","thắt","cư","trang","toát","Xin","mừng","ảm","Thụ","nặng","vội","vàng","trương","kính","đằng","đan","dệt","sàn","bàn","trà","rượu","bằng","đá","nghiên","rào","linh","sổ","hiệu","sơ","nhiệt","cẩu","nô","ưng","đua","phố","hấn","trêu","đùa","đàng","hạnh","phúc","khổ","thụy","hà","cưỡi","sảng","tịch","nương","mị","Khục","chìm","tuổi","Nghiễm","Dương","Phấn","Tướng","Quân","Toản","nhi","thiếp","trưởng","cưng","chìu","hèn","nhát","há","dùng","xưng","hùng","ngang","dọc","trường","cha","quên","dễ","Mạc","Phu","Hoài","Bích","hoa","tỳ","nhãn","anh","tệ","giày","vò","tối","ao","sen","cước","rót","bụng","vét","sốt","tập","đau","mụ","số","xuân","Đổng","Trác","lửa","đốt","Hán","Hiến","Hiệp","An","rả","nấy","mẹ","Thiệu","dụ","cớ","chiếm","Hàn","tuyên","Kiều","Tòng","tổn","Thấu","to","thủy","cân","trải","sứ","điều","giải","giảng","hòa","dốc","Ngu","dân","căng","chấp","ghi","lỗi","thiện","thù","lánh","mưu","giai","địch","cuối","binh","bại","ZI","sạch","gồm","Bảy","xong","ác","bắp","đùi","cắt","đớn","chơi","bây","lựa","chọn","hoặc","ăn","uống","miễn","giụa","tro","nhút","đói","phòng","cũ","sửng","sờ","lịch","sử","bỏ","buộc","đinh","học","khoa","thuốc","súng","kíp","lỗ","xui","xẻo","lật","quật","đừng","dâng","thuận","ngoan","la","Lương","Hoành","lùn","thua","thiệt","cương","mùi","huyên","thuyên","cố","đen","tạm","xấu","đọc","vài","côn","cắc","ké","nhau","lảo","chịu","thỏ","bệch","hồng","hộc","dứt","bếp","trộm","gảy","cầu","Ô","giỏ","trúc","đĩa","miếng","thịt","thử","dầu","nhàng","vỗ","nhè","chụp","bả","vai","chín","tráng","bổn","Ngũ","ngon","giấc","Ha","càn","rỡ","kể","kí","ưu","nhã","đưa","khu","mũi","đống","cứt","bắn","thác","Chu","lặng","trợn","tròn","O","đắc","chiêu","hăng","ạ","phế","nằm","chứ","oắt","khiêu","khích","truồng","đấm","phản","chống","ngạnh","đo","ong","ve","xử","chớ","cản","sầm","nghiêm","ngặt","nhẫm","quát","vốn","Quận","tộc","sách","thưởng","gả","lạy","Lô","thầy","lễ","kém","tít","tắp","lấn","đoạn","tồi","sói","chen","lẩy","bẩy","trắc","ba","ngẫm","hưng","lỡ","bề","Hít","sâu","cốt","Xá","thúc","giục","ngưng","nồng","nặc","gấp","luyện","trông","thèm","kì","dời","dậy","lượt","nghìn","lam","hấp","thu","trái","tim","Tinh","xoáy","chóng","chảy","thuần","cọ","tấc","tả","say","sưa","ghiền","mạng","Nhưỡng","no","nhiêu","giỡn","ĩ","ôm","ngực","hiếp","Thư","giơ","khuấy","bởi","gần","cơn","đãng","kịch","sánh","nệ","khối","phổ","mô","khán","nhàm","chán","lầm","bia","náo","nghề","kháng","Quốc","nó","Xà","phiên","rộng","hẳn","sửa","chữa","cẩn","khăn","chú","diễn","sở","đội","phối","Cẩm","Vệ","hộ","ấy","khen","ngợi","ngã","trạng","chứa","dược","thảo","ổn","tấn","dằng","dặc","ngữ","giỏi","thôn","phệ","thọ","dung","hợp","óc","cỗ","Rồng","chồm","núi","tiết","rừng","cây","tóm","thoạt","Im","Vương","Ân","tựu","đuổi","xoay","hài","khiêm","tốn","hệt","hãy","tha","đạt","áy","náy","đề","cập","nịnh","nọt","kịp","cỏ","khống","trôi","dập","tắt","cột","chui","văn","mờ","đậm","hắt","sóng","san","tích","tảo","bạc","khoảng","tánh","nuốt","khái","gọi","suông","thí","nhiểu","tầm","chênh","lệch","toán","nguy","hiểm","vãng","mong","bút","trướng","kỹ","băng","lãnh","rời","tạ","FsgDuhdp","phập","phồng","bực","oán","hỏng","bét","đỡ","đa","nghỉ","ngơi","Kim","phó","mức","thịnh","”Vâng","phép","lo","lắng","dằn","khiếp","quyển","hoãn","thuấn","điện","nhíu","chặc","nghệ","hạch","lãm","rèn","mời","não","chăng","trả","bào","chau","tống","Đỗ","Nguyễn","Thuỳ","Hương","Lân","Thắm","Mai","Lê","Bùi","Hải","Khôi","Phan","Hường","Doãn","Tùng","Ngô","Trâm","Đức","Uyên","Việt","Nga","Thùy","Chang","Cúc","Trinh","Khuê","Khánh","Nông","Đình","Tiệp","Nhung","Hiền","Đặng","Quỳnh","Khanh","Triệu","Lộc","Tố","Phượng","Thoa","Lò","Thúy","Trịnh","Tuấn","Xuyến","Ngọ","Chinh","Duy","Gấm","Hằng","Hanh","Huế","Lành","Loan","Ngân","Ngọt","Cấn","Quyên","Tuyến","Khuất","Thơm","Vụ","Yến","Diệp","Nhật","Tân","Thao","Nhâm","Mến","Ngà","Hứa","Tuân","Ninh","Tú","Vinh","Mậu","Thuý","Út","Thắng","Dậu","(Sinh)","Hợi","Huệ","Bửu","Nhiễu","Điệp","Huỳnh","Hiếu","Khương","H","Mrin","Mlô","My","Phường","Tuyền","Ny","Huề","Lài","Ty","Phước","Ng.","Đăng","Bá","Ái","Vy","Hiên","Hoan","Kiên","Vĩnh","Tây","Cù","Nhạn","Soan","Quế","Len","Liễu","Tín","Hoanh","Ni","Thới","Quách","Triết","Cang","Diển","Lạng","Trâbf","Trung'","Vủ","Bé","Ung","H'","Mương","Ađrơng","Hoản","Kha","Lăng","Mân","Nhựt","Rin","Ích","Đàm","Trữ","Triều","Lựu","Luân","Thám","Quí","Trân","Dạ","Sỹ","Oánh","Du","Liêm","Thuyết","Hân","Thoản","Brôl","Điễu","Đô","Zơrâm","Hoà","Khải","Lanh","Tào","Mãi","Mải","Mẫn","Uyển","Phụng","Thêm","Thêu","Thơ","Yaly","Tràm","Dinh","Điền","Sin","Thoại","Mão","Quới","Sum","Tho","Lư","Báu","Chơn","Cừ","Quản","Dư","Chương","Hoạt","Điềm","Ốc","Nhữ","Huê","Chiên","Luyến","Quảng","Thìn","Tịnh","Tuệ","Khang","Thiều","Toại","Xương","Bật","Toan","Giáp","Huân","Huấn","Diên","Đáp","Cam","Triện","Chất","Lã","Ngôn","Tiễn","Biên","Mục","Xưởng","Đoan","Khiển","Roan","Tỵ","Bão","Dào","Vần","Sửu","Canh","Trào","Kiệt","Phến","Đính","Sanh","Khâm","Liêu","Miền","Phung","Bái","Chức","Điển","Diêm","Thứu","Cậy","Duyện","Liết","Kham","Thảng","Châm","Khuyên","Bắc","Lệnh","Chiều","Điến","PhanVăn","Khiên","Thịện","T.","Thạc","Hoát","Nhài","Thoan","Vịnh","Vọng","Ng","Cát","Tuynh","Thục","Lồng","Sếnh","Quãng","Đố","Vượng","Đát","Doanh","Thép","Chử","Dỉnh","Âu","Ấu","Bàng","Bành","Bế","Bì","Biện","Bồ","Ca","Giàng","Chiêm","Cự","Đôn","Đới","Đái","Hy","Khâu","Khưu","Quàng","Lều","Lữ","Lỳ","Mạch","Mâu","Uông","Nhậm","Nhiệm","Thào","Thập","Tông","Trưng","Vừ","Bua","Bun","Cà","Chẩu","Đèo","Điêu","Khằm","Leo","Lỡo","Lềm","Lự","Mè","Ngần","Nho","Nhọt","Panh","Pha","Phia","Tày","Tao","Sa","Zàng","Lù","Phán","Vù","Kía","Ðàm","Ðinh","Chảo","Hù","Adat","Buôr","Bondưng","Bontô","buolto","Bullya","Chil","Chilyú","Mup","Ðayout","Ðayk","Ðazur","Ðakriêng","Ðé","Ðoắt","Ðưngur","Kơ","Kdun","Klong","Kon","Sar","Kơpa","Kơsă","Kơsar","Kơsor","Kơsơ","Krazanh","K’tol","Biêng","Lémou","Liêng","Hót","Zarang","Lơmu","Bon","Mbon","Păng","Próc","Rglê","Rờ","Rơ","Ôn","Sarem","Srê","Chuếch","Dốt","Mu","Rắt","cuốc","Drâm","Nđnok","bò","Prông","sóc","Vọt","khỉ","Cáo","Chéng","Min","Sềnh","Sú","Ðàng","Ðạo","Ðạt","Ðổng","Fatimah","Mahomach","Miêu","Ðại","Mách","B’nahria","Crugiang","Dnơng","Ðơ","Lơng","Ya","K’bao","B’nuh","M’hỏi","Ðối","Ðường","Mãn","Mùng","Da","Adrâng","adrơng","Ayun","Tul","H’wing","Arul","Atul","Buôn","Yah","Yă","Krông","Duốt","Eban","Rah","Emô","Enuol","Ênuôn","Êman","Êmê","H’dơk","H’druê","Hmok","Hwing","Jdrơng","Kbul","Kêbour","Knul[][]","Kpă","Kpơr","Ksor","Ktla","Ktub","Ktul","Mjâo","Ðuôn","Ðu","Hut","Ksêi","Niê","Blô","Ðáp","Rip","Gok","Kđăm","Hrak","Mhiêng","Mkriêk","Mla","Siêng","Sơr","Suk","Tray","Hieu","Kpa","Nây","Pui","Rahlan","Ramah","Rchom","Rơô","Siu","Vùi","Bluông","Bruôt","Căp","Ê","loài","chim","Khoông","Kriêng","Xó","vùng","đỏ","Bờ","Phà","Sần","Lang","Nà","Và","Cáp","Chúc","Dao","Diệc","Ðái","Ðan","Ðơn","Ðào","Ðặng","Ðậu","Ðịch","Ðiền","Ðiêu","Ðoàn","Ðỗ","Ðông","Ðồng","Hạng","Hinh","Hoắc","Kỉ","Khoan","Khứa","Lao","Lu","Mao","Ngươn","Nghê","Nhan","Phàn","Si","Tần","Thang","Thẩm","Vưu","Bạt","Bê","Bi","Bôi","Bông","Bu","Cai","Chan","Chàng","Cốc","Tằng","Cống","Dì","Diêu","Ða","Ðác","Ðắc","Ðằng","Ðấu","Ðẩu","Ðèo","Ðiêm","Ðiệp","Ðiều","Ðiểu","Ðiệu","Ðình","Ðịnh","Ðoái","Ðồ","Ðôn","Ðống","Ðức","Giáng","Giệp","Gioãn","Giốc","Hang","Hạp","Hâm","Hê","Hi","Hui","Kan","Kem","Kheo","Kiệu","Kỷ","Liu","Man","Mẫu","Miên","Nan","Ngư","Ngưu","Nhiếp","Nung","Nùng","On","Phẩm","Phô","Quấc","Quất","Quyến","Roãn","Sái","Sam","Sâm","Sẩm","Sưu","Tang","Teo","Thềm","Ti","Tiệt","Ủ","Uất","Ứng","Ửng","Vầu","Vỏng","Vỹ","Yết","Chanh","Chao","Khum","Néang","Neong","Nuth","Panth","Pem","Tưng","Uônth","Xath","Xum","Chưndre","Vê","Goi","Hrlip","Ho","Hual","Ir","Glaa","Kưmbur","Khư","Tlốc","Klảng","Moong","Tlê","Lít","Praga","Rét","Ric","Rivi","Rvai","Deer","Tlăp","Veng","Xênh","Tgoóc","Xloóc","Tiác","Thrăng","Tmoong","Hol","Tong","Tvạ","Ngăm","Rông","Blai","Vơor","Xoong","Ky","Pờ","Thàng","Cáng","Chông","Dìu","Duyền","Làng","Lặc","Liềng","Mèo","Pâu","Sình","Thồ","Hản","Mùa","Pa","Sùng","Tẩn","Thèn","Sưr","Bing","Byang","Ðăm","Ðớp","Sor","Tol","Ðak","Cat","Chắt","Ðrang","Ja","Kliêng","Hot","Ding","Lưk","Mbuôn","Mdrang","Mok","Nđu","Nong","N’tơr","Pang","Pé","Sur","Ting","Mbre","Phok","Phôk","Rche","Rchil","Riam","Ryam","Rlăk","Sruk","Tơr","Mol","Triek","Triếc","Uê","Dak","Vmăk","Khăm","Ðờ","Ðo","Làn","Me","Lìu","Bô","Táy","Tảy","Vàn","Củng","Chồ","Lèng","Ka","Bởng","Chăm","Rảm","Ru","Rựa","Sô","Pề","Sí","Nhơ","Mướn","Rau","Bo","Catơ","Katơr","Mau","Copuró","Chamalé","Chip","Jarao","Patau","Axá","Pateh","Pinăng","Pupor","Driêng","Krong","Éban","Hdok","Kdam","Hrah","Pồ","Avét","Hăr","Xay","Xền","Viềng","Cháng","Mào","Lèo","Lịm","Phìa","Toòng","Co","Cút","Xeo","NGO","NGUYEN","TRAN","PHAM","DIN","DUONG","DOAN","LUONG","LE","BUI","DONG","VO","DANG","VUONG","LAURENT","TRUONG","LUU","NAKANO","VAN","BACH","KIEU","QUACH","THIEU","DAM","CHE","THACH","KHUAT","DONALD","MR","NGYUEN","DAN","NGHIEM","LEU","HAN","MARTIN","THAI","NGUEN","CU","TRIEU","KHUC","HUA","KHONG","HONG","SOREN","HIDENORI","WATANABE","SUNG","MIKHAIL","NGYEN","PATRICK","HIROSHI","AU","TETSUO","KANG","PHILIPPE","PHUA","JOUNG","THE","CHOI","DANNG","UONG","MAHARDJO","DAU","NGUYET","ENZO","YU","TRNH","HIRAI","TON","NGUIYEN","JOHN","TRINHVAN","DAON","ZHAO","PHUONG","KHAU","NGUYN","LEUNG","WE","TUONG","USHIRABIRA","HAU","DELEVAUX","CONG","LUC","BANG","SUZUKI","DANIEL","PARK","CHUN","HSU","ZHOU","LING","MANEESH","SYED","NGUEYN","JULIEN","XARINXONA","QUE","VUONGXUAN","PO","NGUYENT","HUONG","NANG","XUAN","VIET","PHUOC","TUAN","DUC","NGOC","QUOC","HUU","TIEN","DAC","KHAC","CHUONG","HU","BUGEAU","TAE","DIEN","KENJI","MANH","WEE","KHUONG","HOAI","LOC","HAO","QUYNH","SY","QUANGHUNG","NHU","PHAT","DAI","THUY","HIEN","CHIEN","GEOFFREY","SON",
"TANH","NGHIA","PHUC","QUYET","YE","WINTHER","TUANH","THIEN","KIEM","TAT","LOI","KIEN","SACH","TAM","CUONG","THAC","TUU","NHAT","THUAN","SUN","ROED","AOSHIMA","KENZO","BAEK","IUREVICH","THUONG","TUYEN","JEAN","MASUDA","BICH","YASUDA","GUEON","ROGER","HOP","SEOK","NAK","GEUM","SEUNG","LILA","WEN","HIEP","BIEN","FILONI","BAT","NENG","TSUKASA","THAT","HUYEN","DAVID","GIO","JAE","MING","MYUNG","DANG","DIEU","CHOUL","BONG","TICH","VA","HIDEAKI","ALEXIS","DAT","THONG","HIRONORI","PETER","THIET","KYUNG","THUC","KYOUNG","XI","KUO","RAMCHANDRA","ABRAR","HAIJIN","TUYET","HUE","TRA","BENISTY","THY","NU","NGAN","DIEM","TRUC","BAC","LIEN","T","YEN","THINH","BUOC","HUAN","TUNH","SU","CHAM","VIEN","QUYEN","KHOI","SOO","KE","LICH","LUAT","KIAT","C","DIEP","BUU","CHUYEN","TIEP","DE","CHAT","LUAN","CHAC","UT","DUE","BERGER","TRUYEN","SAC","HEC","LIEM","HACH","SEOB","CHIEU","XIEN","KHIEM","BULOW","BEN","HOAT","XO","NGHIEP","CHIN","MEN","KHIET","HE","KHUE","GIAM","THEM","PHANG","LAP","DAICMT","MINH.","NIEM","TUE","TOI","CUU","PEDERSEN","NGOI","SIMONOV","KHOAI","TUC","THUYEN","SUONG","NHUONG","BERENGIER","GIAP","HOC","STEINER","GI","BOI","KI","IL","GWAN","LIP","THOI","PHIEN","DUOC","IK","GANG","THUAT","SANTOSO","TSE","NOI","BIEU","MUOI","LIEU","THIEP","BINH.","DUYET","DICH","HOE","VUA","DAL","HOI","BROWN","CHUC","KET","DOI","EUI","PHAP","TRAO","CHUAN","MUI","JIN","TIAN","WANG","YUL","BAI","DOAN","BOT","12211042","BANH","CAC","CHING","TOA","SIK","DON","RANG","STEIN","SOUK","UYEN","TUOI","LUYEN","TUNGUYEN","MUON","DUYEN","TOAI","NHIEM","PIL","BAE","JIANG","DANE","BUKHARI","XUYEN","GIONG","TRNAG","CUC","TRAM","THOM","DIU","TIEU","THUOC","LIM","GUONG","THUYET","GAM","MO","NOAN","HANGH","THIN","SUOT","RONIE","QUYN","NIELSEN","KONG","KEVINS","N","MIEN","XIEM","KHUYEN","Thánh","Buồm","Tổ","Gai","Trống","Bưởi","Sài","Đúc","Miếu","Giám","Láng","Chợ","Dừa","Bột","Mác","Dền","Giã","Lũ","Nộn","Khê","Nỗ","Dục","Võng","Tàm","Mầu","Trâu","Quỳ","1","2","Mỗ","Mễ","Oai","áng","Nhuế","Đà","Mê","Trãi","Mộ","Trại","Chiểu","Hát","Trạch","Tháp","Trạm","Liệp","Cộng","Ngải","Nậu","Kiệm","Xã","Ước","Dực","Túc","Lãng","Lộng","Xuy","Đốc","Bảng","Lũng","Cú","Má","Lé","Táo","Thài","Phìn","Sủng","Lủng","Sính","Thầu","Hố","Quáng","Chải","Vạc","Pải","Xín","Pả","Máng","Cán","Pù","Tát","Nậm","Niêm","Mố","Duệ","Ngam","Già","Tỷ","Bạ","Ván","Phiêng","Luông","Pố","Túng","Sán","Nàng","Ngài","Xả","Luốc","Ngàm","Nhùng","Choóng","Péo","Khòa","Pài","Nàn","Xỉn","Díu","Mần","Phàng","Ngán","Pà","Sủ","Rế","Nhìu","Ngò","Nấm","Dẩn","Chì","Sản","Điếm","Rịa","Sông","Duyệt","Pác","Miều","Bôn","Pàng","Nặm","Sác","Tổng","Cọt","Dính","Ngạn","Căo","Hoè","Đoài","Khôn","ẩu","Trừng","Tụng","Bộc","Rã","Trĩ","Phặc","Đán","Nê","Sảo","Nhuận","Lạp","Đĩnh","Hỷ","ỷ","Lưỡng","Lôn","ấm","Lào","Lếu","Pom","Phời","Xát","Mú","Chạc","Tý","Mỳ","Vược","Sàng","Sáo","Mường","Xèo","Hum","Cheo","Pung","Sành","Dìn","Khấu","Nhin","Pan","Mế","Mản","Thẩn","Sui","Cấu","Sín","Lử","Phình","Hối","Mòn","Đét","N.T","Loỏng","Phiệt","Cọn","Khoang","Sả","Suối","Pán","Mả","Rạng","Chầy","Chiềng","Ken","Xây","Noong","Him","Nưa","Leng","Sìn","Pá","Nhé","Kè","Toong","Huổi","Lếch","Chà","Sá","Hừa","Mí","Ham","Nèn","Mươn","Tủa","Chùa","Só","Đun","Báng","Mùn","Pú","Quài","Thín","Tỏa","Sáy","Tở","Tênh","Phông","Tấu","Pồn","Phăng","Luống","Hẹt","Mứn","Lót","Núa","Hẹ","Muông","Lói","Phì","Nhừ","Pu","Keo","Lôm","Giói","Tìa","Dình","Háng","Lìa","ảng","Ngối","Cáy","ẳng","Búng","Lạn","Hỳ","Bủng","Chua","Phài","Hon","Khun","Tè","Lũm","Bum","Khao","Khóa","Lin","Quai","Dề","Ngảo","Hẻo","Mạ","Cuổi","Hăn","Lản","Nhì","Sì","Lờ","Vây","Lìn","Pho","Xe","Súi","Mít","Mung","Khoen","Sỏ","Pắc","Pì","Nhùn","Đao","Lề","Xôm","Cơi","Khay","Giôn","Ơn","Sại","ét","Phỏng","Lái","É","Khiêng","Bám","Bôm","Thôm","Bó","Púng","Pấc","Phặng","Muội","Nọi","Phổng","Păm","Muôn","Pi","Bú","Chùm","Xím","Xùa","Chếu","Pe","Tọ","Bau","Sập","NT","Khừa","Lóng","Sặp","Vạt","Pằn","Viêng","Lán","Hặc","Lựm","Khoài","Cò","Nòi","Cằm","Pẩu","En","Đứa","Nghịu","Mằn","Khoong","Bánh","Sốp","Cộp","Dồm","Khủa","Múa","Thia","Thíp","Cuông","Ngòi","Phác","Mỏ","Hẩu","Phạ","Dế","Khắt","Lau","Mát","Nánh","Đắt","Tuổng","Pheo","Chum","Ruộng","abc","Răm","Đú","Nật","Chiệng","Sào","Báy","Mỵ","Nuông","Dăm","Thung","Nai","Khến","Ngổ","Sạn","Cun","Piềng","Vế","Khe","Phòn","Xăm","Khòe","Hịch","Pin","Đồi","Hẻm","Cảng","Nghiệp","Bồng","Trìu","Chè","Đu","Nghinh","úc","Lòa","Đạn","Trấn","Mịch","Bục","Bác","Bính","Khẩu","Giếng","Đáy","Cháy","Húc","Rui","Đầm","Chẽ","Đạc","Vừng","Trới","Mạo","Dĩnh","Gồ","Hưu","Phồn","Sỏi","Kép","Vôi","Khám","Chũ","Cấm","Hựu","Am","Neo","Gián","Nếnh","Dữu","Hạc","Bến","Gót","Bổng","Xạ","Chuế","Luật","Côi","Yển","Nạp","Mạn","Thản","Bán","Dưỡng","Kệ","Khóan","Nhuệ","Nhạo","Liễn","Trục","Phật","Chẩn","Thứa","Kênh","Phả","Thăng","Sặt","Miện","Chuối","Bội","Chai","Tơ","Tre","Lạch","Đẩu","Kiền","Khởi","Huyện","Bần","ủng","Sậy","Khóai","ấp","á","Đọi","úy","Gôi","Quỹ","Cồn","Diệm","Trạo","Hoằng","Hoạch","Tén","Tằn","Cành","Mìn","Qúy","Mọt","Lẹ","Khuyến","Trành","Triêu","Bàu","Nọc","Nhoóng","Xén","Keng","Đoọc","Mạy","Huồi","Lống","Cắn","Cạ","Típ","ải","Nhôn","Khuông","Hữư","D?ơng","Xiêng","Giát","Nài","Nghèn","Nẫm","Hàu","4","5","3","Dơi","Xing","Xy","Klang","Mò","ó","Nghì","Vao","Rụt","Bung","Triệư","Th?ợng","Cựu","Biều","Sịa","Lưới","Roằng","Đớt","I","II","Nhơn","Thạnh","Ch'ơm","Ga","Ri","Xan","Tr'Hy","Tiêng","Bha","P'rao","Kôn","Jơ","Ngây","Rooi","Za","Cooi","Dăng","Laêê","Chơ","Zuôich","Pơơ","Dêê","Tôi","Vàl","Bhinh","Dy","Pre","Pring","Kót","Nú","Dơn","Dõng","ổ","Lế","Ghềnh","Ráng","Đăk","Bok","8","9","7","6","Mỡ","Lúi","Eachà","Riêng","Ea","EaBar","EaBia","EaTrol","Ealy","Sim","Cụm","Nới","Ná","Né","Rí","Mán","Măng","Ngâu","Kho","Kiết","Xu","Kai","Đắk","Kroong","Ngọk","Blà","Ia","Hreng","Wa","Glei","Plô","Nhoong","Pék","Choong","Xốp","Hoong","Plei","Ang","Xú","Loong","Lem","Pô","Kô","Ring","Buk","Ngok","Tem","Rve","Kôi","Ruồng","Pne","Re","PXi","HRing","Ui","Mar","Réo","Kơi","Hơ","Đal","Rai","Dom","Tơi","Xiêr","Lây","Tê","Xăng","Xuôi","Kring","HDrông","RBol","Băh","RTô","KBang","Roong","Pai","Lơ","Ku","Đak","SMar","Kông","Khơng","Pla","HLơ","Đoa","Sơmei","Yang","K'","Glar","Dơk","HNol","Pết","Khươl","Kreng","Ver","Jôr","Yok","Hrung","Bă","KRai","Grăng","Dêr","Chia","Pếch","Kơn","Dơng","Ley","Djrăng","Thụp","Đê","Ar","Chiêng","Chro","Krêy","SRó","Ning","Pling","Pơ","Krêl","Kla","Pnôn","Kly","Drăng","Tôr","Boòng","Púch","Pia","Piơr","Sê","Tiêm","Pơng","Bar","Măih","Ngoong","Glai","AL","HTok","HLốp","Blang","Dun","Pal","Ko","Tó","KDăm","Rơn","Broăi","Trok","RSai","RSươm","Gu","Mláh","HDreh","RMok","Uar","Rcăm","Ake","Sol","Piar","Peng","Chrôh","Pơnan","Hiao","Yeng","Hrú","Rong","Dreng","Hla","BLứ","Êbur","Kao","Drông","Siên","Eă","H'leo","Ral","Wy","Mốt","Khal","Dliê","Tir","Súp","Lốp","JLơi","Rốk","RVê","M'Lan","Huar","Wer","Cuôr","Knia","Nuôl","Pốk","Kuêh","Tar","M'nông","H'đinh","KPam","M'DRóh","M'gar","D'Rơng","M'nang","Suê","KBô","Drang","Ngai","ĐLiê","Tóh","Puk","Dah","Klông","Kar","Knốp","Tih","Đar","Kmút","ELang","Jang","M'Đrắk","Prao","H'MLay","Jing","M'Doal","M'ta","K","Róa","Kmar","KTy","Reh","Trul","Drăm","Búk","Phê","Knuêc","Yông","Kuăng","Hiu","Yiêng","Trấp","Dray","Sáp","Drênh","Dur","KMăl","Ktur","Krang","Tría","Phơi","Nuê","R'Bin","Wi","BHốk","Đray","Bhăng","R'Moan","Nia","R'Măng","Plao","Som","T'Ling","Wil","Mil","R'La","Gằn","N'Drót","Sắk","Mâm","Sôr","Choah","Drô","Nâm","N'Đir","Môl","N'Drung","N'Jang","R'Tíh","12","10","11","B'lao","Bri","Đạ","M'","Srônh","Rsal","Rô","Chais","Nhim","Đưng","KNớ","Đờn","Hòai","D'Ran","Ròn","Pró","N'Thol","Hine","Gung","Ré","B'","Lá","Ngãi","M'ri","Guôi","Ploa","Tẻh","Bù","Mập","Ơ","Riềng","Nơ","Bom","Dây","Củi","Truông","Đước","Gò","Trảng","Thố","Gòn","Lua","Gáo","Trầu","61","25","Ray","Thiền","Rạch","Rao","Bưng","Nhứt","Xoài","Nghé","B","15","13","17","16","14","27","26","24","21","22","19","28","Thiêm","18","Kiểng","Cội","Hóc","Bè","Kiển","Lức","Quê","Giuộc","Gạo","Quơn","Vàm","Qưới","Lách","Thiềng","Cày","Giồng","Trôm","Qui","Nhum","Vũng","Vồn","Lược","Thảnh","Rài","Tàu","Voi","Đảnh","Eo","Hòn","Lình","Quao","Gành","Khế","Nóc","Thốt","Nốt","III","IV","V","VII","Gòi","Mái","Dầm","Phích","Chèo","Gốc","Giấy","Kạn","Bể","Rì","Bỉm","Thước","Hới","Ranh","Chàm","Tum","Plông","Rẫy","Pleiku","Păh","Grai","Pưh","Thuột","Ana","Lắk","Kuin","Glong","Jút","R'Lấp","Lạt","Đam","Huoai","Đốp","Hớn","Vấp","Lậy","Thít","Đéc","Trăng","1900","1901","1902","1903","1904","1905","1906","1907","1908","1909","1910","1911","1912","1913","1914","1915","1916","1917","1918","1919","1920","1921","1922","1923","1924","1925","1926","1927","1928","1929","1930","1931","1932","1933","1934","1935","1936","1937","1938","1939","1940","1941","1942","1943","1944","1945","1946","1947","1948","1949","1950","1951","1952","1953","1954","1955","1956","1957","1958","1959","1960","1961","1962","1963","1964","1965","1966","1967","1968","1969","1970","1971","1972","1973","1974","1975","1976","1977","1978","1979","1980","1981","1982","1983","1984","1985","1986","1987","1988","1989","1990","1991","1992","1993","1994","1995","1996","1997","1998","1999","2000","2001","2002","2003","2004","2005","2006","2007","2008","2009","2010","2011","2012","2013","2014","2015","2016","2017","2018","2019","2020","Nẵng","tuýp","nóng","gũi","bướng","bỉnh","vách","CHAP","hút","thoải","góc","lướt","ngón","phím","thoăn","thoắt","Sonata","facile","Mozart","trọn","vẹn","socola","đc","cg","lạ","Mệt","mỏi","ơi","đâyy","uể","oải","nấu","cơm","j","đũa","thôii","Vângg","pull","gấu","tò","Chợt","chuông","hé","bữa","Ngước","m","rưỡi","Ây","ngẩn","Gentle","Christian","Girls","Are","Looking","For","Soulmates","com","Cleaner","Made","Millions","In","Few","Days","Read","More","Level","Up","Your","Viking","Top","RPG","Takes","Gaming","Next","plarium","nét","chào","dạo","cộc","lốc","sofa","tí","trc","trò","kèm","bâyh","dạy","nhg","giúp","Vâng","Chả","nỡ","dở","lắm","à","lớp","tuỳ","buổi","Ừm","piano","dịu","dàng","đảm","Thuý","20","23","29","30","31","Nhóm","đón","án","Nguồn","http","ebook","ay","ach","uya","ua","ưa","cụ","lưỡi","rạ","gặt","lúa","hái","tng","mét","vuông","đg","Sấn","tr","mỉa","sực","Ampere","dua","đgt","hùa","ĐgThMai","Nh","phiện","bậy","cướp","id","Ùa","ạt","trẻ","vườn","kng","nhỉ","dt","Truyện","nũ","lừa","Chị","đphg","xướng","HgĐThuý","ngột","Câm","trt","bận","quạ","ráo","mưa","gỗ","dòng","go","cửi","thóp","đẻ","cháu","Nhánh","đâm","trồng","tt","Thằng","NgĐThi","dội","chọc","rùng","rợn","cay","Xế","lặn","oan","ách","mắc","tháo","Gông","cùm","xiềng","kìm","kẹp","hoạ","rắc","rối","gánh","giặc","bóc","adjudant","halte","ạch","Oạch","đt","gươm","HCM","Nỗi","kín","ngôi","điếu","viếng","bày","xót","hằn","vch","thách","gẫy","bền","chắc","trọt","chật","lính","chước","vơi","tht","đằm","chồng","họp","bênh","bưu","chúa","sắt","chuộng","NĐM","đành","quà","rành","lí","ampère","gợi","tẻ","Nền","bẩn","hóng","thờ","Quấy","Món","cá","luộc","chấm","mắm","Lởn","vởn","NgTuân","lén","lút","hãm","dấu","đáo","hoá","tp","nuôi","NgKhải","loạn","ren","trật","táng","chôn","cất","ủi","xét","Chắn","lối","Dãy","ngả","Nộp","thếp","đựng","đong","hộp","hạt","trgt","chừng","ph","phẳng","khẩn","lẫy","rực","mươi","Láy","ruột","rể","thăm","ốm","Trỗi","vỏ","nhẵn","PhVĐồng","thiêng","đph","hưởng","tỏi","sọ","chiếu","đèn","chm","Mảng","niềm","suốt","bèo","muống","thúng","thóc","bấy","ChMTrinh","khoáng","ào","lụt","Lội","bấc","NgHTưởng","ồn","nách","ngựa","dồn","viển","vông","ngông","xen","NgCgHoan","khéo","léo","Gột","Trg","xứ","lộn","Buông","xốc","bọc","kẹo","choàng","gối","khuy","cài","liệu","dâu","thấm","hòm","kiểu","bẻ","xẻ","sườn","gt","Tết","chót","Đè","nén","tước","kĩ","nghiệm","bẹp","tù","suất","tải","chở","trốn","át","tulơkhơ","Mắng","aurum","óng","ắc","accumulateur","ăm","ắp","ẵm","cắp","tiệc","dịp","đòn","dán","Giành","Phanh","Mĩ","gọn","gàng","bốc","nĩa","phe","vụng","vắng","chay","rằm","mồng","mặn","dối","cưới","đếm","giỗ","kị","xóm","nạt","doạ","dẫm","mánh","khoé","khít","gà","lãi","tháng","cd","năn","day","màng","nhịp","mụn","thói","TrTXương","GHC","quịt","quỵt","vã","nhoáng","đĩ","lẫn","Lợn","sẻ","vơ","thề","xẩy","gắng","thtục","dè","sẻn","lẻn","vẽ","vạ","đòi","đền","lăn","giấu","chùi","mép","béo","đậy","giếm","xổi","dưa","muối","Chuyền","ắt","NgCgTrứ","ngửa","sấp","Cõi","mút","Nối","giãn","bọng","vú","đực","điệu","hột","rạp","Ngấm","mẹo","xâm","Bìu","dái","mối","BNT","gõ","mịt","rền","độn","khua","mõ","ẩm","BCKN","giễu","cậu","ghê","gớm","êm","VNgGiáp","thoả","mọc","khóm","dày","nảy","chồi","bụi","cúng","gắn","Băn","khoăn","chửa","Đẩy","ẩy","lùm","dật","LVT","náu","Rắp","treo","gí","nút","Nhét","li","giặt","loát","soát","ập","dông","chậu","kẻo","pht","nựng","sầu","yếm","cử","đả","khía","sợi","trám","cuống","phao","nón","nớt","nhấn","khẳng","papa","st","Rùa","vảy","giạ","thùng","cẳng","lận","đận","truân","vất","vả","gổ","bavard","khoe","láp","đắn","nhăng","Vớ","vẩn","ballet","sân","đệm","ballot","Túi","đeo","lặt","vặt","gói","ngọn","xỏ","rọi","xiên","lố","Ví","nợ","HXHương","chê","thà","dại","Thưa","trịch","hách","vãi","Bơ","bải","mồi","chuột","cám","dỗ","diều","vác","bã","mía","mịn","Giò","lụa","Vạch","gửi","chép","Đắp","thợ","nề","vở","ngành","Pavlov","DgQgHàm","gỉ","chẵn","chục","Gá","quạt","đục","Vầng","thếch","Chòm","đốm","phai","nâu","phếch","ỏi","húng","Lọ","nết","nạc","đuối","Lững","thững","kèn","nhiễm","khuẩn","mua","dõi","ven","liềm","soi","khuynh","Nến","Thắp","tuộc","nhuyễn","khơ","chuồn","Gạt","Rút","Thẻ","sụt","sùi","Ngó","trích","lỏng","sền","sệt","chầu","thuế","gầy","huỷ","cn","chổi","vái","trtr","nản","hoại","đẳng","trèo","luẩn","quẩn","Uỷ","balle","panne","balcon","nhô","gác","ấầy","lìm","kc","cãi","TrVGiàu","cắm","mổ","xì","xào","nhúng","gạch","then","xâu","toạ","đít","dó","lắp","nắp","chuốc","rẻ","trôn","lẻ","Dải","Ả́nh","nghèo","thuê","ghe","Kê","phúng","bạnh","trú","ngụ","giẹp","hè","rủ","choáng","váng","sững","sét","ngơ","líu","thính","nêu","pound","Ireland","Syria","Sudan","tì","gập","cm","bẹ","toả","đoác","sưng","mì","sắn","bương","trọc","nể","tành","vụn","Ghế","vịn","đai","bảnh","Trau","chuốt","tươm","nhụi","nướng","Luỹ","thgtục","ầấy","trừu","ngát","lơn","quây","thon","Mướp","nạo","khát","Giọt","thót","hẹn","nguyền","PhTr","hăm","gìn","tx","quĩ","vay","hecta","gieo","nạn","rủi","ro","nom","hụt","tàng","khơi","quặn","sẫm","tầu","thoái","én","hỉ","xứng","kẻng","bậu","rè","Khoẻ","tôm","cạy","mênh","xôn","xao","HCận","nháo","xộn","bâche","thô","baht","Dạt","gáy","Liều","trũng","dãi","trát","miết","cạo","vát","gọt","khoét","nặn","phơ","vèo","chối","Tụi","bướm","thắc","ngoảnh","baccalauréat","khng","tjhuộc","Nhấc","nồi","băm","bặm","Mím","tảng","toé","văng","Bùn","khoản","nẩy","vết","tẩm","quấn","brancard","oC","Sẩy","lồi","lõm","nhôm","CgO","thênh","bẵng","bặt","thuôn","lõi","Xôi","săn","Radar","Chĩa","bulông","vòi","vẹo","sót","bớ","LQĐôn","cóc","nhốt","rễ","tưới","thạo","Khêu","Tột","bầm","cấy","tím","tấy","Tật","ương","bấm","trượt","lợ","rác","rưởi","cáu","hoen","ngổn","bấn","vướng","bời","quýt","giòn","hỡi","víu","bâng","khuâng","lâng","quơ","bấp","nghiêng","bập","sõi","ròi","bềnh","ghép","thuẫn","nguyện","đe","nẹt","đảng","hủ","gỡ","cầy","gở","bừng","trội","xiết","nghiện","bâu","xúm","xít","ruồi","tua","giàn","nhuỵ","noãn","bứng","nâng","vịt","phèn","hom","phiếu","đặn","bấu","quặp","kẽ","Rứt","bầy","hầy","thỉu","Rầm","vươn","kèo","bẫy","gài","tròng","be","xuồng","ướt","chạch","beige","sữa","mồm","dê","ăng","nứa","dàn","bẽ","Ngượng","ngùng","thẹn","Mẩu","xoà","bẻm","bèn","bẽn","lẽn","rơm","Phàm","bẹn","nếp","xắn","beo","véo","tóp","nhăn","nhúm","ỏng","bọt","mọn","lênh","đênh","bở","bép","xép","Mạt","lè","sượng","Bệ","rạc","trễ","ngắt","bộn","TrBĐằng","Kitô","cua","chén","bơi","bễ","thụt","khoá","trệ","Bụt","lùi","nao","núng","đò","dỡ","bện","thừng","quít","chếch","chập","nhấp","núc","xảo","bết","bịu","bệt","bêu","bệu","Nhão","bều","trờn","bít","bismuth","rên","rỉ","Corneille","vãn","nem","xoan","bõm","mứt","cói","lác","xách","dột","thgt","đần","bière","trơ","bìa","rọc","bịa","bịch","biếc","thẫm","biếm","Trứ","bielle","pít","biền","Tẩy","phổi","cúm","ngẫu","khỏí","biếng","nải","chường","nhác","lọt","thự","sớ","cổng","diễu","biếu","bìm","phễu","bịn","rịn","tốc","chặp","chủng","Dẫu","dành","Rộn","rịp","hốt","hoảng","bịnh","bịp","bit","nylon","bịt","hở","hũ","rò","viền","gậy","Chít","PhBChâu","bướu","bĩu","Hễ","bíu","sừng","lổm","ngổm","giậu","chạp","cạp","nhọn","thằn","lằn","sấu","mũ","dép","lép","vứt","hoạn","bõ","tớ","rày","vành","đuốc","láo","bọ","Giòi","chét","rầy","chích","lột","bói","nhào","bombe","pomme","đrô","bỏm","cõng","bòn","góp","nhặt","mót","bón","Trộn","thìa","cháo","gân","chằng","rạn","bòng","cùi","lọc","rán","luồng","thướt","Núp","ngắm","lảng","vía","nhựa","vợt","chần","lặp","Ghen","loáng","Tủ","véc","boong","pont","poste","porte","monnaie","dúm","nắn","còi","inh","nghẹt","bót","pot","beau","găm","Cót","chạt","nhện","toác","Đay","nót","khuếch","ten","hớt","sắm","lì","bock","boxe","húi","Vụt","chốn","trơn","nhờn","mài","boy","tấp","tểnh","lở","bổi","hổi","Mớ","Lúng","tuồng","sọt","zô","rích","et","xte","bồn","chồn","lươn","Nôn","thỏm","Đợt","nhỡ","xơ","Ruốc","trĩu","đoá","vồng","Giấm","bốp","bộp","chộp","vớt","Nghiền","Calcium","sulfat","beurre","Phết","phờ","trọi","đơm","Gờ","loét","gay","bỡ","ngỡ","ngàng","bợ","trói","bới","Trấu","chửi","Xới","búi","bơm","bờm","rậm","trán","xờm","xù","bợm","xở","bỡn","ghẹo","Kiểm","nơm","xoắn","bụ","dồi","bùa","quỉ","búa","nện","sù","sụ","dẻ","ngùi","chực","nhùi","chịt","lửng","lất","bủn","rủn","bún","xị","tách","moi","guốc","nhụng","nhẽo","túm","chưng","uổng","trưa","sèo","Vỉ","tộc","thiểu","liếng","lậu","thiu","bứt","nghêu","ngao","nhúc","nhích","rầu","chùng","buồng","trổ","buốt","buột","búp","poupée","dặn","bự","bửa","Hòng","bựa","sịch","mành","rèm","nực","kén","gỏng","lầy","rảo","ngoặt","rệt","bươi","múi","tép","mọng","bươm","rải","xằng","bươu","đẽo","ốt","dàm","ngứa","ngáy","lỏi","ngõ","vại","xí","canxi","cacao","calot","canot","curry","xốt","khịa","què","café","sám","rá","rem","crème","cravat","líp","bống","lườn","nhám","xoè","hước","hẩm","vẩy","mòi","chài","mõm","trê","khép","nép","chác","khố","ngục","Giắt","Lênin","ôi","mẻ","Đùng","tủi","ghẻ","vin","trẻo","cạm","ất","canke","xô","Quẻ","nguỵ","ráp","chẹn","suôn","thỏi","cào","chấu","chìa","dẻo","ngừa","khuây","chiết","Chạnh","phim","Uốn","tiu","cheng","HgTùng","lượn","xoi","mói","héc","gạc","cowboy","giở","nghênh","lừng","lợm","caoutchouc","mủ","sồng","nhen","ủy","tị","toạc","cảo","giảo","gáp","cable","rổ","Nẹp","váy","Luồn","rê","millimet","Đãi","cưa","têm","nhó","càu","nhàu","Cặn","kỉnh","gừng","sè","vố","đắng","NgTrãi","mỏm","cặc","cặm","Goòng","lún","cụi","chiu","hôn","QÂTK","cằn","cỗi","cối","nhằn","siết","rôm","Sủa","thuở","chừa","dãn","khuỷu","gắp","Gán","xẩm","vè","hâu","tạc","điếc","họng","úp","xóc","giằng","cộ","thây","chướng","sặc","sỡ","QSDC","ngoắc","gram","Khảm","thiển","tiệm","tằm","xấp","xỉ","vó","khiết","dìm","cật","dậm","hóp","phên","gặng","khảo","đỗi","vẫy","đấng","quỵ","luỵ","vun","mốc","kilomet","rẽ","ức","rủa","dượng","tróc","nhót","km","granit","ướp","rúc","dẹt","Thờn","bơn","méo","quăng","đắm","thẫn","mượt","nhuộm","mẩn","chạn","dát","hảng","Giạng","nhái","chẫu","chạng","vạng","Nhá","nhem","phớt","đanh","ngoa","ngoắt","cụt","thoai","loe","chão","múc","chạo","ổi","chát","dùi","Tom","chày","vắt","ứa","ùn","chọt","mẩm","nịch","vóc","hiềm","mền","xíu","chặm","nấng","PhBChàu","chéo","rỗ","nần","mầm","chặng","nôm","dụm","chẻ","khăng","răn","rữa","hóm","hỉnh","lọn","sụa","nhẹn","chừ","chuệch","choạc","chận","chọi","choạng","chờn","đom","đóm","chững","gặn","nhũng","vali","thẳm","Chụm","phở","xinê","ráy","chấy","rận","hầm","vờ","thớ","ché","dọng","Chp","lèn","cọc","ngáng","bêtông","chêm","chẽn","khoèo","táp","trắm","giẫy","loăng","chẹt","Ôtô","ngỏng","sấm","xộc","xệch","thoảng","chễm","chệ","Chềm","goá","Quăn","queo","chểnh","chệnh","ngạt","Ngất","tuất","séc","vá","trỏ","khảng","sướng","Nòng","choè","muỗi","mt","ngưỡng","chốt","nấp","rôn","NgDu","núm","Róc","khoanh","đăm","niêu","ngụm","Vời","roi","thết","dặm","HgXHãn","nhòm","Lôcôt","[","rấm]","nhộng","dừ","chĩnh","chíp","lic","rịt","chõ","vện","choán","choảng","sốc","hẫng","chóe","choé","chói","chòi","giun","Loá","hông","chỏm","chong","TBH","chòng","chành","nhả","chõng","vánh","Vót","Nhường","cọng","xoa","NgBKhiêm","ngồng","chổng","gọng","chỏi","chốp","mẹt","chột","cuội","khoát","giời","lêu","chới","chơm","chởm","chớm","nhay","chớt","thình","mèn","ngoặc","acid","khử","thé","tể","gộp","Thò","bậm","chúi","gốm","tụm","chùn","chụt","miệt","chuộc","chuôi","chuỗi","cườm","chuôm","heo","rỗng","chuồng","cọp","sổng","gặm","nhấm","tạng","chùy","chuỳ","rà","gẫu","soái","Quặng","tiềm","Kiêm","cưỡng","hửng","cobalt","coban","rỗi","dặt","lợp","rêu","ếch","nầm","đớp","Còng","gục","còm","dâm","cỏn","nhớn","cóng","cóp","gom","copier","két","kẹt","bụa","quạnh","TQ","Hươu","cỏi","sơmi","BNĐC","Alexandre","Rhodes","dô","dà","Lả","lơi","coke","xơi","Ươm","vữa","nêm","giăm","cồm","cộm","gợn","cốm","sêu","ngào","bỏng","cône","phỉ","colt","mm","alcool","colle","xòe","Jun","Thửa","ne","cồng","kềnh","modem","nghè","xự","xang","xê","tuỷ","tuý","cote","code","trập","Nếm","yểm","rập","rước","mẩy","NgBính","cởi","cổi","dọn","gù","culi","cuời","ngoáy","nắc","nẻ","tiếu","nhọc","xua","coup","vt","vọ","rình","lt","bẳn","kệch","hủi","chỏ","cũi","lủi","cùn","sộ","sòng","nồm","Nhảm","nhí","trá","cuỗm","diếp","rốn","vé","rít","cúp","coupe","cub","couper","cụp","cữ","ngoái","khem","cứa","cựa","Mấu","magnesium","gượng","lốm","phổí","sậu","NgVBổng","cưu","nhũ","huyệt","deca","diết","thía","nguôi","ngoàị","nua","dượi","rượi","dượị","xáo","daị","dẳng","rườm","thiến","dáị","lịnh","dạm","Ướm","cầụ","máỵ","thỏa","dạn","nãy","câụ","%","chuôị","ngửi","trôị","centimet","xiếc","Clarinet","dằm","nhổ","giây","chiền","nhậu","nhẹt","giâm","Râm","gã","ngấu","húp","dấn","dềnh","nhộn","quyện","xảm","dàu","ín","xức","phẩy","=","lụy","câble","thiếc","lằng","nhằng","kẽm","dấy","Lóp","ngóp","đẽ","nẻo","dể","ngoãn","khỏe","câỵ","liệm","hóạ","dỉ","sôvanh","dĩa","nỉa","tễ","mittinh","vợi","dử","Canô","mớị","mẫm","dọa","dóc","phịa","hoàị","tẩu","trâụ","lòi","dòm","hổng","xỉnh","dỏng","dạc","nhồi","giồi","dộị","nức","vẳng","dộng","dơ","trẽn","ngớ","gàn","lẩn","khờ","dớ","nghệch","dợn","dớp","ngoạn","cui","caosu","Đạọ","gãỵ","duỗị","XX","rớt","hùm","dứ","hấu","Đùn","dứa","dửng","tráo","compa","AB","đạị","cáị","dượt","đoái","thõng","đồm","giáọ","caọ","loạng","điểu","tạnh","kìa","Riết","róng","háu","gôn","NgKhuyến","gàu","rởm","gạn","niệu","sẹo","prô","tit","lợt","nít","tỉa","tộ","nhún","mận","gioi","thuổng","ngói","nhuần","đũng","Paris","nhiếc","đọa","đoạ","khản","đẵn","tiều","sứa","đăngten","nôi","giần","úng","Lấm","lõng","bõng","đẫm","sũng","phành","phạch","tráì","giùi","khiu","thau","video","rường","Đọ","nghịt","phôi","bẹt","nành","đâỷ","dẫy","đẫy","nống","tốị","wolfram","pile","lon","nạ","suốị","gùi","đôị","Quắt","xổ","ngỏ","hẵng","đầụ","phò","nệm","tốp","tâu","tộị","đểu","xóa","ỉa","tòi","đì","Lẳng","đìa","cu~","sến","táu","quởn","tuyn","parabol","hyperbol","ellips","nhổm","dậỵ","địt","rắm","đìu","sỗ","đoản","sút","Sảnh","lờị","loè","tét","thưng","uý","XSanh","đọt","tĩu","fatxit","buýt","ngù","giương","nhạy","khị","lẻo","nhaụ","Calô","IỊ","đốn","rúp","màụ","lõa","loã","lúm","proton","neutron","trồi","đị","đẫn","đợ","đờị","ngớt","đờm","nhầy","khạc","pê","ngoạm","mồị","NgXSanh","thốn","đụ","Khoả","ngợm","ruỗng","đui","douille","đùm","đụn","nha`","ASEAN","đúp","đút","nhẽ","đười","ươi","vệt","Viêc","ém","liếm","nín","nhẹm","Xập","xè","liệng","éo","èo","uột","ẻo","khảnh","yểu","ẽo","ẹt","ẹo","ẹp","mé","chề","thãi","đềm","ếm","Ngr","ềnh","ễnh","ngoé","gara","gateau","kg","ghẹ","gạ","gẫm","tía","gardien","hãng","khều","riêu","lm","sởn","chiếng","góa","xoạc","ganh","chóp","thắn","găng","hav","Gằm","ghè","hét","gụi","váp","lia","lịa","ngáo","gụ","ngấy","guộc","nghén","Hững","ngh","tởm","đỉa","nguội","ghếch","ghì","ghim","ghìm","ọp","nhặn","néo","Dôi","dánh","mùì","phẫu","kiềm","giãi","giạm","chái","gióng","giăng","quyệt","quánh","Marx","Lenin","Giẫm","quậy","quắp","giẵm","giặm","giằn","Bủa","giũ","giầm","giậm","cv","giập","rờn","giẻ","Gié","gièm","Trút","giẹo","giền","giêng","lùa","gióc","nhặng","giọi","phấp","phới","ruổi","giỏng","Nhđm","ồm","fa","Trỗ","giội","giờn","giũa","giúi","dúi","joule","niu","tơn","xéo","quằn","thòi","giựt","gỏi","ghề","Mấp","Quì","gội","gôm","goal","gởi","gắm","gờm","th","gờn","gợt","guồng","gút","gừ","gườm","gượm","hớ","tầy","liếp","sò","thốc","NgĐChiểu","hốc","hống","quặm","nghển","tặc","khốc","Ả","hám","hạm","rát","nhoi","giềng","se","khất","hãnh","kháu","khỉnh","Rãnh","hão","háo","hức","hạo","háy","ngấn","sắng","hằm","Gange","Tạt","xẻng","mó","lóc","dạồ","đật","NgVLinh","ful","beautiful","hẩy","vỉa","hèm","hắng","hen","Trót","hèo","hể","hếch","hoác","hên","hến","hếu","hí","hoáy","hia","hích","quặt","hiếng","hiêng","đễ","vạm","híp","xẩu","hoét","mích","róm","khướu","thối","hoán","tược","hoạnh","DgQHàm","lắt","Đác","Uyn","hòe","hói","Hõm","doành","tâng","ních","loãng","xừ","vằn","vục","hác","phạc","XDiệu","chù","trẩy","xiêu","Ngỗng","đượm","khạo","nheo","hời","dỗi","nhủ","hớp","logic","hú","hoãng","hụ","xỉa","xói","phè","thủi","hun","hùn","hụp","BĐGiang","olympic","lổ","rợ","trườn","dg","lị","huýt","Ngb","họci","chỉmới","sệ","ắng","phắc","ỉm","Inch","ình","ỉu","kalium","Trơng","vẹt","tréo","gạọ","mòng","nàọ","lể","phảị","lạị","chịụ","kềm","kên","Kền","vchg","kêụ","Trũi","phũ","trọ","nhốn","be`","hỏạ","huênh","Thâu","NgBáHọc","lọi","HThKháng","lợị","õm","lạo","khạp","khoải","khẳm","tiêụ","khắm","hòi","khấc","khấn","kilô","vọi","ỡm","khét","khàn","khệnh","khạng","nữạ","Kều","nàỵ","hydrogen","helium","nảỵ","giớị","taỵ","khiếm","Quở","lọng","tôị","phềnh","khỏa","núị","tậu","khoảnh","cườị","lới","ngút","khom","nãọ","khéọ","nin","khơị","liệụ","quện","khuân","khui","phui","khúm","khùng","trĩnh","đâụ","khuyển","khước","giùm","ngườị","giư~","yếụ","sởi","chùạ","quệ","kiệụ","theọ","vaị","ran","hộị","kình","équipe","giông","nhông","quặc","Sà","om","sòm","Latin","nhũn","suồng","sã","sụn","lạồ","thớt","chệch","cạch","đạch","lải","nhải","rưới","rù","hoẹ","lạm","loang","vảng","XIX","thăn","lẹn","Gịọng","lẽo","ớn","Koch","vút","làu","cạu","láu","lỉnh","plaque","loàn","xược","quáy","lẵng","nhắt","quẫn","loay","hoay","nhón","rổi","lét","phùn","phosphor","Phốt","Nấn","nhầm","ló","nhớt","nháp","radio","�","rức","air","Huyến","lém","laine","nhâng","hợm","liến","thoắng","tèo","vắn","nhẵng","lẹo","xẹp","lẹt","đẹt","toài","quèn","quẹt","Ngái","mề","nhể","đòng","trụi","lềnh","oang","túp","AK","lỵ","liểng","xiểng","chỏng","Quẳng","dim","Phèo","vãnh","quýnh","Luýnh","decimet","lịu","Nhịu","thày","sưởi","Nhọ","nhuốc","loà","xõa","xoã","lóa","loạc","loán","loanh","Nhây","toe","toét","lòe","loẹt","xối","loằng","nhoằng","nghỉm","tói","xuông","rổn","rảng","Thuỵ","lòm","nhang","truỵ","NhóNG","tã","giầy","Kilogram","blockhaus","mãng","Luộm","thuộm","ghẽ","lồn","nhím","rìa","enveloppe","vống","lốt","nhử","lởm","lờn","rouleau","compresseur","lú","Nhú","lụn","bốt","lụp","xụp","Nhụt","hừng","hực","cathod","anod","lườm","lượm","nhạnh","Ngoằn","ngoèo","lựu","mộl","vagabond","hử","dút","mazut","maquette","hêrôin","rón","yard","marque","mark","marc","Xam","TrVTrà","Hoẵng","luỵ","nhĩ","Trăn","HgĐThúy","main","mống","nhép","Chứt","rười","nghía","bupbê","mạp","ngác","Trằn","xim","sồi","gồi","von","meo","thuồng","mết","umê","ngốn","sảy","mếu","nỏ","mine","LKPhiêu","nanh","rứa","môtô","moteur","Muôi","quẽ","mode","mơn","trớn","nhoà","mưng","rìu","soa","khứu","thọc","mửa","natrium","natri","napalm","sém","nả","nã","nỉ","nái","nám","Rám","nạm","apartheid","nạng","phiu","nạy","ngáp","nấc","xắt","phịu","soóc","net","vằng","NGớN","~","Tuột","ngách","Ngoáo","đừ","đơ","xửa","khò","vọc","ngừ","rén","HT","Ngấp","ngứng","ngưởng","nghểu","nghẹn","xấư","nác","hũu","giổi","ngốc","phệt","chủy","electron","ngưa","ct","gare","Jesus","oái","phiếm","thơi","nhở","tườu","nhắp","chợp","PhVKhải","nhóc","nhèo","nhảnh","nhương","nhõ","nhỉnh","nhinh","nhíp","nhẻ","nập","nhồng","Yểng","nhột","nhẩm","níu","Methan","carbur","rết","đêế","hợt","note","chúm","chím","nùi","tivi","nũng","nịu","chửng","ực","nư","oo","oong","ooc","oa","oe","photocopy","oxygen","oxi","òa","oà","oách","oằn","ọc","ói","oi","úa","ohm","òm","nuớc","ót","Giâý","uế","nhớp","ối","úi","xuể","ộp","ốp","ới","chội","phare","phase","phin","bĩnh","tuôn","lớ","XV","XVI","base","tõm","oản","phỡn","phèng","truất","xệ","phạn","phịch","niết","Xúi","film","phỉnh","tót","rộp","TVTS","ax","by","tráp","nhụy","phào","quành","quào","quảy","quắc","quắm","quại","quắn","rúm","dăn","quéo","quẹo","nhoài","quầng","NgHồng","quầy","hì","NgVVĩnh","Quèo","quệt","Tròi","quết","quị","dịnh","vanh","Khuỵu","radis","um","xòa","lụi","PhKBính","rái","ram","sạm","rạm","rảnh","rạo","rafle","rặng","rộ","rần","rật","dờn","rây","rail","sếu","Rề","Dềng","trốc","rẩm","khừ","rệp","rỏ","rỉa","mồn","rọ","ròng","riếc","rồ","tụt","nõ","rũa","rục","rịch","rim","nhủn","Xán","rưng","rướm","Rớm","rương","rượt","lữa","xịu","lúp","chaloupe","sạ","sải","trệch","sàm","khoán","XXI","choang","ngời","măngsông","Sênh","chò","sạo","sạt","săm","chambre","sặm","săng","sằng","sâmbanh","tùm","sậm","sựt","sẩn","phứa","diềm","tTên","sây","Xước","sầy","đda","sấy","mngang","sề","sên","sểnh","[xi]","silicium","silic","ậm","ọe","siểm","xiểm","Hz","Vitamin","soán","Thoán","Khmer","sọc","uẩn","sóm","móm","sọm","hem","xúy","sượt","soài","sôcôla","Chauvin","sồ","lụng","sủi","sồn","sột","sộp","sất","soạt","chemise","virus","chiện","sờn","mởn","sớt","xắc","sướt","mướt","sụm","sún","Mớm","Ứ","bêrê","shooter","shoot","Carnot","suyển","suyền","suyễn","vồ","thó","trớ","Điếng","cồ","kilôgam","tasse","khhc","xỉu","tãi","gích","qũy","rivê","cosin","tụy","vạy","nhạp","lígiờ","ưgiữa","Phỗng","Tháy","nghẽn","taxi","tịu","phướn","laterit","ttnn","tuỵ","ngọng","te","gấc","tẽ","tém","teng","beng","tẹo","tẹt","tếch","teck","tête","tếu","ximăng","bĩ","choãi","hoằn","nhõm","Giê","thạp","tháu","thòm","nghếch","thặng","Qủa","khú","tủy","trẩu","thè","thẹo","carbon","thẹp","pích","thùa","thều","thọt","trâng","trố","Totem","thím","thòng","thóa","thoá","trặn","gầu","tọt","Tiễu","thồn","thổn","thộp","Khơme","thủa","carbonic","nuột","đẵng","trối","thui","thụi","Huỵch","thủm","thun","mủng","thút","sịt","Aristophanês","rẻo","rệ","thược","ngoai","thỉ","Trỉa","tiếm","xài","Páp","gười","đóa","xoăn","tịt","kcách","toang","toé","tọng","tợp","trạc","chôm","khoáy","bường","huý","trề","Dúng","trặc","vặc","trầy","trẹo","ngoe","khoeo","trét","trệt","triền","dínhtrên","tròm","trèm","vạnh","trịa","giạt","oăm","chợn","trớt","trợt","nột","xit","Nhoai","tượt","tour","túa","cữu","tũm","tun","tủn","mủn","nhứ","tuốt","tuồn","giép","Lừ","vựng","Sanskrit","ươn","mội","hởi","tắn","xtanh","nguây","nguẩy","tửu","uc","iu","êu","uranium","urani","Ù","Dấm","xiêm","rĩ","ủa","ngoéo","ục","ịch","thoang","ùm","nẫu","ụt","ịt","rợp","uỵch","ừng","ưỡn","vanille","CBNhạ","valse","valve","vanne","valvule","[nhưng","cả]","khè","vằm","Morgan","HĐThuý","Phắt","Miến","vít","Ngắc","ngứ","quẫy","vẩu","vấy","váo","hĩnh","vểnh","violon","vitamine","vias","quạch","khấp","khểnh","kiềng","kẽo","vập","vốc","oxit","PVKhải","Vóng","chuỷ","chũm","choẹ","sãi","vựa","cellule","ngót","nhãng","xạc","xạo","xăn","xẵng","xấc","autobus","camion","Ôtôca","auto","scène","xẹo","xếch","cire","cylindre","xilip","ciment","sirop","cigare","cirque","xìu","soie","xoàn","xuýt","soviet","ngúng","tớp","ur","soeur","sou","Xun","xoe","saucisse","xuề","xuổng","xúyt","xoát","yêng"};


void putTextCairo(
        cv::Mat &targetImage,
        std::string const& text,
        cv::Point2d centerPoint,
        std::string const& fontFaceStr,
        double fontSize,
        cv::Scalar textColor,
        bool fontItalic,
        bool fontBold)
{
    // Create Cairo
    cairo_surface_t* surface =
            cairo_image_surface_create(
                CAIRO_FORMAT_ARGB32,
                targetImage.cols,
                targetImage.rows);

    cairo_t* cairo = cairo_create(surface);

    // Wrap Cairo with a Mat
    cv::Mat cairoTarget(
                cairo_image_surface_get_height(surface),
                cairo_image_surface_get_width(surface),
                CV_8UC4,
                cairo_image_surface_get_data(surface),
                cairo_image_surface_get_stride(surface));

    // Put image onto Cairo
    cv::cvtColor(targetImage, cairoTarget, cv::COLOR_BGR2BGRA);

    // Set font and write text
    cairo_select_font_face (
                cairo,
                fontFaceStr.c_str(),
                fontItalic ? CAIRO_FONT_SLANT_ITALIC : CAIRO_FONT_SLANT_NORMAL,
                fontBold ? CAIRO_FONT_WEIGHT_BOLD : CAIRO_FONT_WEIGHT_NORMAL);

    cairo_set_font_size(cairo, fontSize);
    cairo_set_source_rgb(cairo, textColor[2], textColor[1], textColor[0]);

    cairo_text_extents_t extents;
    cairo_text_extents(cairo, text.c_str(), &extents);

    cairo_move_to(
                cairo,
                centerPoint.x - extents.width/2 - extents.x_bearing,
                centerPoint.y - extents.height/2- extents.y_bearing);
    cairo_show_text(cairo, text.c_str());

    // Copy the data to the output image
    cvtColor(cairoTarget, targetImage, cv:: COLOR_BGRA2BGR);

    cairo_destroy(cairo);
    cairo_surface_destroy(surface);
}

vector<string> readFile(const string& pattern){
    string STRING;
    ifstream infile;
    vector<string> v;
    infile.open (pattern);
    cout << pattern << "\n";
    while(!infile.eof()) // To get you all the lines.
    {
        getline(infile,STRING); // Saves the line in STRING.
        v.push_back(STRING);
    }
    infile.close();

    return v;
}



void createMask( Mat & img, Mat & mask, Size textSize, string fontFaceStr, string text){

    // write text to white background
    putTextCairo(img,text, cv::Point2d(textSize.width/2 , textSize.height/2), fontFaceStr, 27, Scalar(0,0,0), false, false);
    

    cvtColor(img, mask, CV_BGR2GRAY);
    threshold(mask, mask, 240, 255, THRESH_BINARY);
    bitwise_not (mask, mask);

    const int range_from  = -5;
    const int range_to    = 5;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);

    std::uniform_int_distribution<int>  distr1(-10000, 10000);

    Mat fullImageHSV;
    cvtColor(img, fullImageHSV, CV_BGR2HSV);
    for(int y=0;y<fullImageHSV.rows;y++){
        for(int x=0;x< fullImageHSV.cols;x++){
            Vec3b & intensity = fullImageHSV.at<Vec3b>(y,x);
            // cout<< "image : "<< y << "-" << x << "\n";
                
            if((float)(intensity.val[2]) < 0.55 * 255  ){
                //cout<< (float)(intensity.val[0])<< ","<< (float)(intensity.val[1])<< ","<< (float)(intensity.val[2]) <<"\n";
            
                // randomly for black (0,0,0)

                
                if (distr1(generator) % 20 == 0){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 90 + distr(generator);
                    intensity2.val[1] = 13/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 88/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;

                } 
                else if (distr1(generator) % 20 < 5){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 176/2 + distr(generator);
                    intensity2.val[1] = 19/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 57/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;
                } 
                else if (distr1(generator) % 20  < 15){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 162/2 + distr(generator);
                    intensity2.val[1] = 10/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 78/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;
                } else {
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 160/2 + distr(generator);
                    intensity2.val[1] = 19/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 94/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;

                }

            } else {  // randomly for other

                if (distr1(generator) % 15  < 10){
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 162/2 + distr(generator);
                    intensity2.val[1] = 10/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 78/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;
                } else {
                    Vec3b & intensity2 = fullImageHSV.at<Vec3b>(y,x);
                    intensity2.val[0] = 162/2 + distr(generator);
                    intensity2.val[1] = 19/100.0 * 255+ distr(generator);
                    intensity2.val[2] = 94/100.0 * 255+ distr(generator);

                    //cout<< "--" << (float)(intensity2.val[0])<< ","<< (float)(intensity2.val[1])<< ","<< (float)(intensity2.val[2]) <<"\n";
            
                    fullImageHSV.at<Vec3b>(y,x) = intensity2;

                }

            }
            
        }
    }

    cvtColor(fullImageHSV,img, CV_HSV2BGR);
}

Mat getBackground(Size textSize){

    // readFile("/Volumes/Data/WORKSPACE/git/bagiks/CMT-Text-Detection/dataset/bg/");
    vector<string> backgrounds = readFile(BASE + "/utils/backgrounds.txt");

    string background;
    Mat bg_mat;

    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(0, backgrounds.size());

    do {
        background = backgrounds.at(distr(generator));
        bg_mat = imread(background);
    } while (bg_mat.cols <= textSize.width + 10 ||  bg_mat.rows <= textSize.height + 10);

    cout << background << "\n";
    cout << bg_mat.cols - textSize.width -10 << "\n";
    cout << bg_mat.rows - textSize.height -10 << "\n";
    
    
    Rect roi;
    
    roi.width = textSize.width ;
    roi.height = textSize.height ;


    std::uniform_int_distribution<int>  distrX(3, bg_mat.cols - textSize.width -10);
    std::uniform_int_distribution<int>  distrY(3, bg_mat.rows -  textSize.height - 10);
    roi.x = distrX(generator);
    roi.y = distrY(generator);


    cout << textSize.width <<"-+-"<<  textSize.height << "\n";
    cout << bg_mat(roi).cols <<"-+-"<<  bg_mat(roi).rows << "\n";


    return bg_mat(roi);

}

Size getTextSize(string text){
    int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
    double fontScale = 1.0;
    int thickness = 1;
    int baseline= 1 ;
    
    Size textSize = getTextSize(text, fontFace,
                            fontScale, thickness, &baseline);


    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(4,6);


    textSize.width -= distr(generator);


    textSize.height += distr(generator) ;
    baseline += thickness;
    return textSize;
}


// wstring readWFile(const char* filename)
// {
//     std::wifstream wif(filename);
//     wif.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t>));
//     std::wstringstream wss;
//     wss << wif.rdbuf();
//     return wss.str();
// }



int main( int argc, const char** argv )
{
    
    ofstream trainFile;
    trainFile.open("trainFile.txt", std::ios_base::app);


    
    // text = texts[1];
    string text = "";
    text = texts[3424];

    for (int i = 0 ; i < sizeof(texts)/sizeof(texts[0]) ; i++){
        cout << i << "\n";
        break;
    }

    



    Size textSize = getTextSize(text);


    string fontFaceStr = "Times";//"maszyna";//"Times"; //"Traveling _Typewriter";

    // creat text image  and its mask
    Mat img( textSize.height , textSize.width , CV_8UC3, Scalar(255,255,255));
    Mat mask;
    createMask(img, mask, textSize, fontFaceStr, text);

    
    // make background
    Mat background = getBackground(textSize);

    
    // write text to background
    Mat crop = background.clone();
    putTextCairo(crop,text, cv::Point2d(textSize.width/2 , textSize.height/2), fontFaceStr, 27, Scalar(124/255.0, 125/255.0, 85/255.0), false, false);

    resize(crop, crop, Size(), 10,10, INTER_CUBIC);
    resize(crop, crop, Size(), 0.1,0.1, INTER_AREA);
    double alpha = 0.95;
    Mat dst;
    addWeighted(crop, alpha, background, 1.0-alpha, 0.0, dst);

    // put things together
    img.copyTo(dst,mask);


    namedWindow("MyWindow", CV_WINDOW_AUTOSIZE); //create a window with the name "MyWindow"
    imwrite(BASE+ "/dataset/words/out2.jpg", dst);

    trainFile << BASE+ "/dataset/words/out2.jpg " << text << "\n";
    trainFile << BASE+ "/dataset/words/out2.jpg " << text << "\n";

    trainFile.close();
    imshow("MyWindow", dst); //display the image which is stored in the 'img' in the "MyWindow" window

    waitKey(0); //wait infinite time for a keypress

    destroyWindow("MyWindow"); //destroy the window with the name, "MyWindow"

    return 0;
}


