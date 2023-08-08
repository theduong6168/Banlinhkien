#include <LiquidCrystal.h>                  //Gọi thư viện của LCD
LiquidCrystal lcd(11,9,6,5,4,3);            //Khai báo địa chỉ nối Arduino và Màn hình 16x02
byte Tim[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};

byte Phantram[] = {
  B00000,
  B11000,
  B11001,
  B00010,
  B00100,
  B01000,
  B10011,
  B00011
};

byte dauthang[] = {
  B00000,
  B01010,
  B01010,
  B11111,
  B01010,
  B11111,
  B01010,
  B01010
};

byte va[] = {
  B00000,
  B01100,
  B10010,
  B10100,
  B01000,
  B10101,
  B10010,
  B01101
};

byte dola[] = {
  B00000,
  B00100,
  B01111,
  B10100,
  B01110,
  B00101,
  B11110,
  B00100
};

byte loa[] = {
  B00001,
  B00011,
  B00111,
  B11111,
  B11111,
  B00111,
  B00011,
  B00001
};

byte nhietdo[] = {
  B11000,
  B11000,
  B00111,
  B01000,
  B01000,
  B01000,
  B00111,
  B00000
};


void setup() 
{
  lcd.begin(16,2);                    //Khai báo LCD được sử dụng là 16x2
  // Tạo các ký tự đặc biệt.
  lcd.setCursor(0,1);                 //Đưa con trỏ về cột 0 hàng 1
  lcd.print("Banlinhkien.vn");        //In ra màn hình dòng chữ 'Banlinhkien.vn'
  lcd.createChar(0, Tim);             //Hiển thị kí tự tim
  lcd.createChar(1, Phantram);        //Hiển thị kí tự phần trăm
  lcd.createChar(2, dauthang);        //Hiển thị kí tự dấu thăng
  lcd.createChar(3, va);              //Hiển thị kí tự và
  lcd.createChar(4, dola);            //Hiển thị kí tự đô la
  lcd.createChar(5, loa);             //Hiển thị kí tự loa
  lcd.createChar(6, nhietdo);         //Hiển thị kí tự độ C

}

void loop() 
// In các ký tự ra màn hình LCD
{ 
  lcd.setCursor(0,0);                 //Đưa con trỏ về vị trí 0,0 (cột, hàng)
  lcd.write(byte(0));                 //In kí tự ra màn hình

  lcd.setCursor(2,0);
  lcd.write(byte(1));

  lcd.setCursor(4,0);
  lcd.write(byte(2)); 

  lcd.setCursor(6,0);
  lcd.write(byte(3)); 

  lcd.setCursor(8,0);
  lcd.write(byte(4)); 

  lcd.setCursor(10,0);
  lcd.write(byte(5)); 

  lcd.setCursor(12,0);
  lcd.write(byte(6)); 
}
