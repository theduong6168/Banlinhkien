#include <LiquidCrystal.h> //Gọi thư viện của LCD
LiquidCrystal lcd(11,9,6,5,4,3); //Khai báo địa chỉ nối Arduino và Màn hình 16x02
int i=0;
byte ten[] = {0x00,0x00,0x04,0x02,0x1F,0x02,0x04,0x00};
byte nguoi[] = {0x0E,0x0E,0x0E,0x04,0x1F,0x04,0x0A,0x0A};
byte tim1[] = {0x00,0x00,0x0A,0x1F,0x1F,0x0E,0x04,0x00};
byte tim2[] = {0x00,0x00,0x0A,0x15,0x11,0x0A,0x04,0x00};
void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2); //Khai báo LCD được sử dụng là 16x2
  lcd.createChar(0, ten); //Hiển thị kí tự ten
  lcd.createChar(1, nguoi); //Hiển thị kí tự nguoi
  lcd.createChar(2, tim1); //Hiển thị kí tự tim1
  lcd.createChar(3, tim2); //Hiển thị kí tự tim2
  lcd.clear();
  lcd.setCursor(0,0);//Đưa con trỏ về cột 0 hàng 1
  lcd.print("Gui Huyen"); //In ra màn hình dòng chữ 'Banlinhkien.vn'
  lcd.setCursor(0,1);//Đưa con trỏ về cột 0 hàng 1
  lcd.print("Nguoi yeu anh..."); //In ra màn hình dòng chữ 'Banlinhkien.vn'
  delay(3000);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.write(byte(1));
  lcd.setCursor(15,0);
  lcd.write(byte(1));
  lcd.setCursor(14,0);
  lcd.write(byte(2));
  for (int i=1; i<14; i++)
  {
    lcd.setCursor(i,0);
    lcd.write(byte(0));
    //lcd.clear();
    delay(500);
    lcd.setCursor(i,0);
    lcd.print(' ');
  };
  
  for (int j=1; j<15; j++)
  {
      lcd.setCursor(j,0);
      lcd.write(byte(3));
      delay(200);
  };
  
  lcd.setCursor(3,1);//Đưa con trỏ về cột 3 hàng 1
  lcd.print("I Love You");
  
}

void loop() {
  
}
