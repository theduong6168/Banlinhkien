# Phát Video và Nhận Diện Khuôn Mặt với ESP32-CAM sử dụng Arduino IDE

Hướng dẫn này giúp bạn nhanh chóng thiết lập một máy chủ web phát video với tính năng nhận diện và phát hiện khuôn mặt bằng bo mạch ESP32-CAM và Arduino IDE. Bạn sẽ hoàn thành thiết lập trong vòng 5 phút!

> **Lưu ý**: Hướng dẫn này sử dụng ví dụ `CameraWebServer` từ thư viện `arduino-esp32`. Bài viết không đề cập đến việc chỉnh sửa mã ví dụ. Để xem dự án thay thế, tham khảo [Máy chủ Web Phát Video ESP32-CAM (tương thích với Home Assistant và Node-RED)](https://randomnerdtutorials.com/esp32-cam-video-streaming-web-server-camera-home-assistant/).

## Mục Lục
- [Giới Thiệu](#giới-thiệu)
- [Điều Kiện Tiên Quyết](#điều-kiện-tiên-quyết)
- [Yêu Cầu Phần Cứng](#yêu-cầu-phần-cứng)
- [Cài Đặt Tiện Ích ESP32 trong Arduino IDE](#cài-đặt-tiện-ích-esp32-trong-arduino-ide)
- [Tải Mã Lên Bo Mạch](#tải-mã-lên-bo-mạch)
- [Truy Cập Máy Chủ Phát Video](#truy-cập-máy-chủ-phát-video)
- [Khắc Phục Sự Cố](#khắc-phục-sự-cố)
- [Tài Nguyên Bổ Sung](#tài-nguyên-bổ-sung)

## Giới Thiệu

[ESP32-CAM](https://makeradvisor.com/tools/esp32-cam/) là một mô-đun camera nhỏ gọn, giá rẻ với chip ESP32-S, có giá khoảng 10 USD. Bo mạch tích hợp camera OV2640, các chân GPIO, và khe cắm thẻ microSD, phù hợp cho các dự án IoT như phát video, nhận diện khuôn mặt, và giám sát.

Hướng dẫn này sẽ hướng dẫn bạn thiết lập một máy chủ web phát video với tính năng phát hiện và nhận diện khuôn mặt bằng Arduino IDE. Bạn sẽ kết nối ESP32-CAM với mạng Wi-Fi cục bộ, phát video trực tiếp trên trình duyệt, và kích hoạt các tính năng nhận diện khuôn mặt.

## Điều Kiện Tiên Quyết

Trước khi bắt đầu, hãy đảm bảo bạn có:
- Arduino IDE đã được cài đặt [](https://www.arduino.cc/en/software).
- Kiến thức cơ bản về lập trình Arduino.
- Mạng Wi-Fi ổn định để ESP32-CAM kết nối.

## Yêu Cầu Phần Cứng

Để thực hiện hướng dẫn này, bạn cần:
- **ESP32-CAM với camera OV2640** [](https://makeradvisor.com/tools/esp32-cam/).
- **Bộ lập trình FTDI** (ví dụ: bộ chuyển đổi USB-to-TTL CP2102).
- **Dây nối** để kết nối.
- **Máy tính** đã cài đặt Arduino IDE.
- **Nguồn 5V** (tùy chọn, để tránh lỗi brownout).

> **Mẹo**: Đảm bảo bộ lập trình FTDI có jumper chọn 5V, vì một số bo mạch ESP32-CAM yêu cầu nguồn 5V để tránh lỗi brownout.

## Cài Đặt Tiện Ích ESP32 trong Arduino IDE

1. **Cài Đặt Arduino IDE**: Nếu chưa cài, tải và cài đặt phiên bản mới nhất từ [arduino.cc](https://www.arduino.cc/en/software).
2. **Thêm Hỗ Trợ Bo Mạch ESP32**:
   - Vào **File > Preferences**.
   - Trong trường **Additional Board Manager URLs**, thêm:
