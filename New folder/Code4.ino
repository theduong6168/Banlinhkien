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

int nutnhando = 3;
int nutnhantrang = 4;

int servo = 6; // Tín hiệu điều khiển Servo chân 6.
int vitri = 0; 

Servo myservo; //Tạo biến myServo của loại Servo

void setup()
{
  myservo.attach(servo); // myServo được liên kết với pin tại vị trí servo = 6(Chân 6))
  myservo.write (0); // Điều khiển động cơ servo đến góc 0 độ
  
  Serial.begin(9600);
 
  pinMode(nutnhando, INPUT); 
  pinMode(nutnhantrang, INPUT);
}


void loop()
{
  int trangthaido = digitalRead(nutnhando); // Đọc trạng thái nút nhấn đỏ
  int trangthaitrang = digitalRead(nutnhantrang); // Đọc trạng thái nút nhấn trắng
  
  Serial.print("Trạng thái nút nhấn đỏ: ");
  Serial.print(trangthaido);
  Serial.print("    ");
  Serial.print("Trạng thái nút nhấn trắng: ");
  Serial.print(trangthaitrang);
  Serial.print("    ");
  Serial.print("Góc Servo: ");
  Serial.println(vitri);
  delay(200);

  
  if (trangthaido == 1 && trangthaitrang == 0)   //Nút nhấn đỏ bấm và nút nhấn trắng không bấm.
  {
    myservo.write (vitri ++);
  // myservo.write (vitri += 15);
    if (vitri > 180)
      {
        vitri = 180;
      }
  }

  else if (trangthaido == 0 && trangthaitrang == 1)  //nút nhấn trắng bấm và nút nhấn đỏ không bấm.
  {
   myservo.write (vitri --);
   // myservo.write (vitri -= 15);
    if (vitri < 0)
      {
        vitri = 0;
      }
  }
  
}
