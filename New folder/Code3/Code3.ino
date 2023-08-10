/*
 =======================================================================================================================================
Servo myServo: Tạo biến myServo của loại Servo
myServo.attach(PIN_NUMBER): myServo được liên kết với pin tại vị trí PIN_NUMBER
myServo.write(angle): Ghi một góc từ 0 đến 180 cho servo gắn với myServo
myServo.writeMicroseconds(uS): Ghi một giá trị tính bằng micro giây vào servo được gắn với myServo (thường từ 1000 đến 2000 với 1500 là điểm giữa)
myServo.read(): Trả về một số nguyên chứa góc hiện tại của servo trong khoảng từ 0 - 180
myServo.attached(): Trả về true nếu servo được gắn vào pin
myServo.detach(): Tách myServo bằng một pin đính kèm
=======================================================================================================================================
Channel M&E Automation:https://bit.ly/3uz3Bt8
Vui lòng đăng ký kênh https://bit.ly/34a2of1 cảm ơn các bạn rất nhiều!
Danh sách phát Arduino : https://bit.ly/34BUDlU
//https://github.com/Arduino-IRremote/Arduino-IRremote
=======================================================================================================================================
*/

#include <Servo.h> // Thêm thư viện Servo.h vào chương trình.

Servo myservo;    // Tạo biến myServo của Động cơ Servo  
 
int servo = 6; // Tín hiệu điều khiển Servo chân 6.
int bientro = A0; // Chân tín hiệu biến trở
int gtbientro; // Lưu giá trị đọc từ biến trở
int vtservo; // Lưu giá trị đọc từ biến trở chuyển đổi sang góc 0-180 độ

void setup() 
{
  myservo.attach(servo); //myServo được liên kết với pin tại vị trí servo = 6(Chân 6))

  Serial.begin(9600);
}

void loop() 
{
  gtbientro = analogRead (bientro);
  vtservo = map (gtbientro,0,1023,0,180);

  myservo.write(vtservo);
  
  Serial.print("Góc Servo: "); Serial.println(vtservo);
  delay(300);

}
