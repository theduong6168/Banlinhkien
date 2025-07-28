# Phát Video và Nhận Diện Khuôn Mặt với ESP32-CAM sử dụng Arduino IDE

Hướng dẫn này giúp bạn nhanh chóng thiết lập một máy chủ web phát video với tính năng nhận diện và phát hiện khuôn mặt bằng bo mạch ESP32-CAM và Arduino IDE. Bạn sẽ hoàn thành thiết lập trong vòng 5 phút! Ngoài ra, tài liệu này cung cấp thông tin chi tiết về sơ đồ chân (pinout) của mô-đun ESP32-CAM AI-Thinker để hỗ trợ các dự án của bạn.

> **Lưu ý**: Hướng dẫn này sử dụng ví dụ `CameraWebServer` từ thư viện `arduino-esp32`. Bài viết không đề cập đến việc chỉnh sửa mã ví dụ. Để xem dự án thay thế, tham khảo [Máy chủ Web Phát Video ESP32-CAM (tương thích với Home Assistant và Node-RED)](https://randomnerdtutorials.com/esp32-cam-video-streaming-web-server-camera-home-assistant/).

## Mục Lục
- [Giới Thiệu](#giới-thiệu)
- [Điều Kiện Tiên Quyết](#điều-kiện-tiên-quyết)
- [Yêu Cầu Phần Cứng](#yêu-cầu-phần-cứng)
- [Sơ Đồ Chân ESP32-CAM AI-Thinker](#sơ-đồ-chân-esp32-cam-ai-thinker)
- [Cài Đặt Tiện Ích ESP32 trong Arduino IDE](#cài-đặt-tiện-ích-esp32-trong-arduino-ide)
- [Tải Mã Lên Bo Mạch](#tải-mã-lên-bo-mạch)
- [Truy Cập Máy Chủ Phát Video](#truy-cập-máy-chủ-phát-video)
- [Khắc Phục Sự Cố](#khắc-phục-sự-cố)
- [Tài Nguyên Bổ Sung](#tài-nguyên-bổ-sung)

## Giới Thiệu

[ESP32-CAM](https://makeradvisor.com/tools/esp32-cam/) là một mô-đun camera nhỏ gọn, giá rẻ với chip ESP32-S, có giá khoảng 10 USD. Bo mạch tích hợp camera OV2640, các chân GPIO, và khe cắm thẻ microSD, phù hợp cho các dự án IoT như phát video, nhận diện khuôn mặt, và giám sát.

Hướng dẫn này sẽ hướng dẫn bạn thiết lập một máy chủ web phát video với tính năng phát hiện và nhận diện khuôn mặt bằng Arduino IDE. Bạn sẽ kết nối ESP32-CAM với mạng Wi-Fi cục bộ, phát video trực tiếp trên trình duyệt, và kích hoạt các tính năng nhận diện khuôn mặt. Phần bổ sung cung cấp thông tin chi tiết về sơ đồ chân của mô-đun ESP32-CAM AI-Thinker, giúp bạn hiểu cách sử dụng các chân GPIO và kết nối phần cứng.

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

## Sơ Đồ Chân ESP32-CAM AI-Thinker

Mô-đun ESP32-CAM AI-Thinker là phiên bản phổ biến nhất của ESP32-CAM, được sử dụng rộng rãi trong các dự án IoT. Dưới đây là sơ đồ chân và các thông tin quan trọng:

### Hình Ảnh Sơ Đồ Chân
![Sơ Đồ Chân ESP32-CAM AI-Thinker](https://randomnerdtutorials.com/wp-content/uploads/2020/07/ESP32-CAM-AI-Thinker-Pinout.png)

### Chi Tiết Chân
ESP32-CAM AI-Thinker có **16 chân GPIO**, nhưng một số chân có chức năng cố định hoặc bị hạn chế do kết nối với camera và thẻ microSD. Dưới đây là bảng mô tả các chân:

| **Chân**      | **Chức Năng**                                                                 |
|---------------|------------------------------------------------------------------------------|
| GPIO 0        | Kết nối với camera, dùng để nạp mã (nối với GND khi nạp).                   |
| GPIO 1        | TX (dùng cho giao tiếp UART, nạp mã).                                       |
| GPIO 2        | Kết nối với thẻ microSD.                                                    |
| GPIO 3        | RX (dùng cho giao tiếp UART, nạp mã).                                       |
| GPIO 4        | Kết nối với thẻ microSD và đèn flash tích hợp.                              |
| GPIO 5        | Điều khiển nguồn camera (Camera Power Down).                                |
| GPIO 12       | Kết nối với thẻ microSD.                                                    |
| GPIO 13       | Kết nối với thẻ microSD.                                                    |
| GPIO 14       | Kết nối với thẻ microSD.                                                    |
| GPIO 15       | Kết nối với thẻ microSD.                                                    |
| GPIO 16       | PSRAM (bộ nhớ ngoài).                                                       |
| GPIO 32       | XCLK (đồng hồ camera).                                                     |
| GPIO 33       | Đèn flash tích hợp (có thể dùng làm GPIO nếu không sử dụng đèn).            |
| VCC           | Nguồn 5V hoặc 3.3V (khuyến nghị dùng 5V để tránh lỗi brownout).             |
| GND           | Đất (Ground).                                                              |
| U0TXD, U0RXD  | Chân UART cho nạp mã và giao tiếp Serial.                                   |

### Lưu Ý Quan Trọng
- **Nguồn Điện**: ESP32-CAM hỗ trợ nguồn 5V hoặc 3.3V, nhưng nguồn 5V được khuyến nghị để tránh lỗi brownout, đặc biệt khi sử dụng camera hoặc Wi-Fi.
- **GPIO 0**: Phải nối với GND để nạp mã. Sau khi nạp, ngắt kết nối để chạy chương trình.
- **Đèn Flash Tích Hợp**: Được kết nối với GPIO 4. Có thể sử dụng như GPIO nếu không cần đèn.
- **Thẻ MicroSD**: Các chân GPIO 2, 4, 12, 13, 14, 15 được sử dụng cho thẻ microSD. Nếu không dùng thẻ, các chân này có thể được dùng làm GPIO.
- **Hạn Chế GPIO**: Một số chân bị giới hạn do kết nối với camera hoặc PSRAM, vì vậy hãy kiểm tra kỹ trước khi sử dụng.

### Kết Nối với FTDI Programmer
Để nạp mã, kết nối ESP32-CAM với bộ lập trình FTDI như sau:
- **VCC (FTDI)** → **5V (ESP32-CAM)**.
- **GND (FTDI)** → **GND (ESP32-CAM)**.
- **TX (FTDI)** → **RX (GPIO 3, ESP32-CAM)**.
- **RX (FTDI)** → **TX (GPIO 1, ESP32-CAM)**.
- **GPIO 0 (ESP32-CAM)** → **GND** (khi nạp mã).

Xem sơ đồ đấu nối:
![Sơ Đồ Đấu Nối ESP32-CAM FTDI](https://randomnerdtutorials.com/wp-content/uploads/2019/01/esp32-cam-ftdi-programmer-schematic.png)

> **Cảnh Báo**: Đảm bảo bộ lập trình FTDI cung cấp đủ dòng (ít nhất 500mA) để tránh lỗi khi nạp hoặc chạy.

## Cài Đặt Tiện Ích ESP32 trong Arduino IDE

1. **Cài Đặt Arduino IDE**: Nếu chưa cài, tải và cài đặt phiên bản mới nhất từ [arduino.cc](https://www.arduino.cc/en/software).
2. **Thêm Hỗ Trợ Bo Mạch ESP32**:
   - Vào **File > Preferences**.
   - Trong trường **Additional Board Manager URLs**, thêm:
