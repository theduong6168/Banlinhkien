# Tổng quan về ESP32-CAM

Trong bối cảnh công nghệ IoT (Internet of Things) ngày càng phát triển, ESP32-CAM đã nổi lên như một giải pháp đột phá, kết hợp vi điều khiển mạnh mẽ và khả năng xử lý hình ảnh trong một thiết kế nhỏ gọn, giá thành phải chăng. Với vi điều khiển ESP32-S, camera OV2640 2MP, hỗ trợ Wi-Fi, Bluetooth và khe cắm thẻ microSD, ESP32-CAM đang được ứng dụng rộng rãi trong các dự án như giám sát an ninh, nhà thông minh và các sáng tạo DIY. Bài tổng quan này sẽ cung cấp cái nhìn toàn diện về ESP32-CAM, từ đặc điểm kỹ thuật, ứng dụng thực tiễn đến tiềm năng phát triển, nhằm giúp người đọc hiểu rõ hơn về sức mạnh và vai trò của module này trong lĩnh vực công nghệ hiện nay.

   <img src="https://docs.sunfounder.com/projects/galaxy-rvr/en/latest/_images/esp32_cam.png" alt="ESP32-CAM" width="400"/>'

## Mục lục

- [ESP32-CAM là gì?](#esp32-cam-là-gì)
- [Thành phần của ESP32-CAM](#thành-phần-của-esp32-cam)
- [Sơ đồ chân](#sơ-đồ-chân)
- [Cách sử dụng ESP32-CAM với phần cứng bổ sung](#cách-sử-dụng-esp32-cam-với-phần-cứng-bổ-sung)
- [Chuẩn bị trên Arduino IDE](#chuẩn-bị-trên-arduino-ide)
- [Dự án mẫu](#dự-án-mẫu)
  - [Nhấp nháy LED](#nhấp-nháy-led)
  - [Code mẫu có sẵn trong Arduino IDE](#code-mẫu-có-sẵn-trong-arduino-ide)
- [Lời kết](#lời-kết)

---
## ESP32-CAM là gì?

ESP32-CAM là một module phát triển nhỏ gọn dựa trên chip ESP32-S, tích hợp camera OV2640, khe cắm thẻ microSD và các cổng GPIO để kết nối với cảm biến hoặc thiết bị khác. ESP32-CAM hỗ trợ Wi-Fi và Bluetooth, phù hợp cho các ứng dụng IoT như camera giám sát, truyền video trực tiếp hoặc dự án nhận diện hình ảnh. Với kích thước nhỏ, giá thành thấp và khả năng lập trình dễ dàng qua Arduino hoặc ESP-IDF, ESP32-CAM là lựa chọn phổ biến cho các dự án điện tử sáng tạo.

   <img src="https://cms.mecsu.vn/uploads/media/2023/08/thanh-phan-ESP32-CAM-696x389.jpeg" alt="ESP32-CAM" width="400"/>'

## Thành phần của ESP32-CAM

- **Bộ xử lý ESP32-S**: Vi xử lý lõi kép 32-bit Tensilica Xtensa LX6, tốc độ 240MHz, hỗ trợ các tác vụ phức tạp như xử lý video và trí tuệ nhân tạo.

   <img src="https://www.iotzone.vn/wp-content/uploads/2024/03/cach-su-dung-esp32-cam-tim-hieu-esp32-s.jpg" alt="Bộ xử lý ESP32-S" width="400"/>'
- **Bộ nhớ**: 
  - 520KB RAM nội bộ.
  - 4MB PSRAM bên ngoài để mở rộng dung lượng.
  - 4MB Flash để lưu trữ chương trình và dữ liệu.
 
   <img src="https://www.iotzone.vn/wp-content/uploads/2024/03/cach-su-dung-esp32-cam-tim-hieu-memory.jpg" alt="Bộ nhớ" width="400"/>'
- **Camera**: OV2640, độ phân giải 2MP (1600x1200 pixel), tương thích với nhiều cảm biến khác.
- **Kho lưu trữ**: Hỗ trợ thẻ microSD để lưu ảnh và video.
- **Ăng ten**: Ăng ten PCB tích hợp và đầu nối u.FL cho ăng ten ngoài.
- **Đèn LED**: 
  - Đèn Flash (GPIO 4) để chiếu sáng.
  - Đèn LED trạng thái (GPIO 33) để báo hiệu.
- **Mức tiêu thụ điện năng**: Mức tiêu thụ điện năng của ESP32-CAM thay đổi tùy theo chế độ hoạt động:
   - 80mAh khi không phát video.
   - 100-160mAh khi phát video.
   - 270mAh khi sử dụng đèn Flash.

## Sơ đồ chân

ESP32-CAM có 16 chân với các chức năng chính:
- **Power**: 5V và 3V3 (khuyến nghị dùng 5V).
- **GND**: Chân nối đất.
- **GPIO**: 10 chân GPIO khả dụng (tổng cộng 32 nhưng một số dùng nội bộ).
- **UART**: UART0 (GPIO 1 và GPIO 3) để giao tiếp.
- **MicroSD**: Kết nối thẻ nhớ.
- **ADC, Touch, SPI, PWM**: Hỗ trợ các chức năng ngoại vi.

   <img src="https://www.iotzone.vn/wp-content/uploads/2024/03/cach-su-dung-esp32-tim-hieu-so-do-cahn.jpg" alt="Sơ đồ chân" width="800"/>'

**Mô tả chức năng chi tiết:**
- **Power (Chân nguồn)**: Có hai chân nguồn là 5V và 3V3. Chúng ta có thể cấp nguồn cho ESP32-CAM qua một trong hai chân này. 
- **GND**: Nối đất
- **GPIO**: Trên ESP32-S có tổng 32 chân GPIO, nhưng có một số chân được dùng nội bộ cho PSRAM và máy ảnh nên chúng ta chỉ còn lại 10 chân có thể sử dụng. Trong đó, mỗi chân lại có 1 nhiệm vụ ngoại vi khác nhau, chẳng hạn như SPI, UART, ADC hoặc Touch.
- **UART**: Trên thực tế, ESP32-S có hai giao diện UART là UART0 và UART2. Tuy nhiên, chân RX (GPIO 16) của UART2 bị hỏng, khiến chúng ta chỉ có thể dùng UART0 trên ESP32-CAM (GPIO 1 và GPIO 3). Ngoài ra, do ESP32-CAM thiếu cổng USB nên các chân này phải dùng để bật đèn flash cũng như kết nối với các thiết bị UART như GPS, cảm biến vân tay, cảm biến khoảng cách,… tùy theo nhu cầu người dùng.
- **MicroSD**: Dùng để kết nối thẻ nhớ microSD. Nếu không sử dụng thẻ nhớ microSD, bạn có thể sử dụng các chân này làm đầu vào và đầu ra thông thường.
- **ADC**: Các chân ADC2 được trình điều khiển WiFi sử dụng nội bộ nên chúng không thể được sử dụng khi đang bật Wi-Fi.
- **Touch**: ESP32-CAM có 7 GPIO cảm ứng điện dung. Khi tải điện dung (chẳng hạn như ngón tay người) ở gần GPIO, ESP32 sẽ phát hiện sự thay đổi điện dung.
- **SPI**: ESP32-CAM chỉ có một SPI (VSPI) ở chế độ phụ và chế độ chính.
- **PWM**: ESP32-CAM có 10 kênh (tất cả các chân GPIO) PWM được điều khiển bởi bộ điều khiển PLC. Đầu ra PWM có thể được sử dụng để điều khiển động cơ kỹ thuật số và đèn LED.

**ESP32-CAM schematic**
  
  <img src="https://blog.mecsu.vn/wp-content/uploads/2021/10/so-do-ben-trong-ESP32.png" alt="Sơ đồ chân" width="1000"/>'
  
## Cách sử dụng ESP32-CAM với phần cứng bổ sung

ESP32-CAM không có cổng USB tích hợp, do đó cần phần cứng bổ sung để nạp code.

### Sử dụng bộ FTDI

1. **Chuẩn bị phần cứng**: Sử dụng mô-đun FTDI (USB-to-Serial) và kết nối với ESP32-CAM theo sơ đồ sau:

  - TX (FTDI) ↔ RX (ESP32-CAM)
  - RX (FTDI) ↔ TX (ESP32-CAM)
  - GND (FTDI) ↔ GND (ESP32-CAM)
  - 5V (FTDI) ↔ 5V (ESP32-CAM)

 <img src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2024/06/ESP32-CAM-FTDI-programmer.png?w=877&quality=100&strip=all&ssl=1" alt="Kết nối ESP32-CAM với FTDI" width="400"/>'
 
2. **Cấu hình FTDI**: Đặt jumper trên FTDI sang chế độ **5V** để cung cấp nguồn phù hợp cho ESP32-CAM.
3. **Chuyển ESP32-CAM sang chế độ lập trình**: Kết nối **GPIO 0** với **GND** trên ESP32-CAM trước khi cấp nguồn để kích hoạt chế độ nạp code.
4. **Cấu hình Arduino IDE**:
   - Cài đặt board ESP32 trong **Arduino IDE**.
   - Chọn board “**AI-Thinker ESP32-CAM**”.
   - Chọn cổng **COM** tương ứng với FTDI.
   - Tải code lên ESP32-CAM thông qua **Arduino IDE** bằng cách nhấn nút “**Upload**”.
5. **Chạy chương trình**: Sau khi nạp code thành công, ngắt kết nối **GPIO 0** với **GND** để chuyển ESP32-CAM sang chế độ chạy chương trình.

### Sử dụng ESP32-CAM-MB (Khuyến nghị)

1. Gắn ESP32-CAM lên board ESP32-CAM-MB.  

 <img src="https://www.iotzone.vn/wp-content/uploads/2024/03/cach-su-dung-esp32-cam-voi-mb.jpg" alt="Kết nối ESP32-CAM với ESP32-CAM-MB" width="400"/>'
 
2. Kết nối với máy tính qua cáp micro USB.
3. Tải code lên ESP32-CAM bằng **Arduino IDE**, đảm bảo chọn board “**AI-Thinker ESP32-CAM**” và cổng **COM** phù hợp trước khi nạp.

## Chuẩn bị trên Arduino IDE

1. **Cài đặt tiện ích ESP32**:
   - Mở **Arduino IDE**.
   - Vào **File > Preferences**.

<img src="https://www.iotzone.vn/wp-content/uploads/2023/10/lap-trinh-esp32-bang-arduino-ide.jpg" alt="ESP32-CAM" width="200"/>'

   - Thêm URL vào **Additional Board Manager URLs**:  https://dl.espressif.com/dl/package_esp32_index.json

<img src="https://www.iotzone.vn/wp-content/uploads/2023/10/cai-dat-arduino-ide-tai-esp32-2.jpg" alt="ESP32-CAM" width="600"/>'

   - Vào **Tools > Board > Board Manager**, tìm "esp32" và cài đặt.

<img src="https://www.iotzone.vn/wp-content/uploads/2023/10/lap-trinh-esp32-bang-arduino-ide-2.jpg" alt="ESP32-CAM" width="600"/>'

2. **Chọn board**:
- Vào **Tools > Board**, chọn "AI Thinker ESP32-CAM".

<img src="https://file.thegioiic.com/upload/large/54272.jpg" alt="ESP32-CAM" width="600"/>'

3. **Kết nối và chọn cổng**:
- Kết nối ESP32-CAM qua FTDI hoặc ESP32-CAM-MB.
- Chọn cổng COM trong **Tools > Port**.

## Dự án mẫu

### Nhấp nháy LED

Dự án đơn giản để làm quen với ESP32-CAM, sử dụng đèn LED Flash (GPIO 4).

```cpp
int flashPin = 4;

void setup() {
   pinMode(flashPin, OUTPUT);
}

void loop() {
   digitalWrite(flashPin, HIGH);
   delay(1000);
   digitalWrite(flashPin, LOW);
   delay(1000);
}
```

### Code mẫu có sẵn trong Arduino IDE
Arduino IDE cung cấp sẵn nhiều dự án mẫu để bạn khám phá khả năng của ESP32-CAM, dự án này biến ESP32-CAM thành một webcam phát video thời gian thực, lý tưởng cho các ứng dụng như giám sát an ninh, nhận diện khuôn mặt hoặc gọi video. Code mẫu có sẵn trong Arduino IDE:  
1. Vào **File > Examples > ESP32 > Camera > CameraWebServer**.

<img src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2024/06/Arduino-ide-esp32-cam-camerawebserver-example.png?w=823&quality=100&strip=all&ssl=1" alt="ESP32-CAM" width="600"/>'

2. Cấu hình code (chọn loại camera và thông tin Wi-Fi).

```cpp
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";
```

<img src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2024/06/ESP32-camera-webserver-select-camera-model.png?quality=100&strip=all&ssl=1" alt="ESP32-CAM" width="600"/>'

3. Upload code và truy cập địa chỉ IP của ESP32-CAM trên trình duyệt để xem video.

<img src="https://i0.wp.com/randomnerdtutorials.com/wp-content/uploads/2024/06/camerawebserver-example-get-ip-address.png?w=666&quality=100&strip=all&ssl=1" alt="ESP32-CAM" width="600"/>'

---
## Lời kết
ESP32-CAM, với sự kết hợp giữa vi điều khiển mạnh mẽ, khả năng kết nối không dây và camera tích hợp, đã khẳng định vị thế là một công cụ lý tưởng cho các dự án IoT sáng tạo. Từ giám sát an ninh, nhà thông minh đến các ứng dụng xử lý hình ảnh, mô-đun này không chỉ mang lại hiệu suất cao mà còn dễ tiếp cận nhờ giá thành phải chăng và hỗ trợ từ cộng đồng. Dù tồn tại một số hạn chế như thiếu cổng USB tích hợp hay số lượng GPIO giới hạn, ESP32-CAM vẫn là lựa chọn hàng đầu cho các nhà phát triển đam mê công nghệ. Hy vọng bài tổng quan này đã cung cấp cái nhìn rõ nét về tiềm năng và cách sử dụng ESP32-CAM, mở ra cơ hội để bạn khám phá và phát triển những ý tưởng độc đáo trong thế giới IoT.
