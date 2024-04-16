int ln1 = 13; // motor1 için giriş pini
int ln2 = 12; // motor2 için giriş pini
int ena = 9; // motor1 için hız pini

int ln3 = 5; // motor2 için giriş pini
int ln4 = 4; // motor2 için giriş pini
int enb = 6; // motor1 için hız pini

int value;  // terminalden gelen veriyi tutması için bir değişken atıyoruz


void setup() {  // pinlerin çıkış olduğunu tanımlandı
  Serial.begin(9600);  
  pinMode(ln1,OUTPUT);
  pinMode(ln2,OUTPUT); 
  pinMode(ln3,OUTPUT);  
  pinMode(ln4,OUTPUT); 
  pinMode(ena,OUTPUT); 
  pinMode(enb,OUTPUT);
  
}

void loop() {
  value = Serial.read(); // terminalden gelen değer value değişkenine atandı
  if (value == 'f'){ // eğer girilen karakter 'f' ise ileri yönde hareket etmesini sağlayan forward() fonksiyonu çağrılır
    Serial.println("ileri yonde hareket ediliyor..."); 
    forward();
  }
  if (value == 'b'){ // eğer girilen karakter 'b' ise geri yönde hareket etmesini sağlayan back() fonksiyonu çağrılır
    Serial.println("geri gidiliyor...");
    back();
  }
  if (value == 'r'){ // eğer girilen karakter 'r' ise sağ'a hareket etmesini sağlayan right() fonksiyonu çağrılır
    Serial.println("sag'a gidiliyor...");
    right();
  }
  if (value == 'l'){ // eğer girilen karakter 'l' ise sol'a hareket etmesini sağlayan left() fonksiyonu çağrılır
    Serial.println("sol'a gidiliyor...");
    left();
  }
  if (value == 's'){ // eğer girilen karakter 's' ise olduğu yerde spin atmasını sağlayan spin() fonksiyonu çağrılır
    Serial.println("spin atiliyor...");
    spin();
  }  
}
void forward(){  // ileri yönde hareket için ln1 HIGH, ln2 LOW yapılır.
  digitalWrite(ln1,HIGH); 
  digitalWrite(ln2,LOW);
  analogWrite(ena,200); // dönme hızı ayarlanır
  
  digitalWrite(ln3,HIGH); // ileri yönde hareket için ln3 HIGH, ln4 LOW yapılır
  digitalWrite(ln4,LOW);
  analogWrite(enb,200); // dönme hızı ayarlanır
}
void back(){
  digitalWrite(ln1,LOW); // geri yönde hareket için ln1 LOW, ln2 HIGH yapılır
  digitalWrite(ln2,HIGH);
  analogWrite(ena,200); // dönme hızı ayarlanır
  
  digitalWrite(ln3,LOW); // geri yönde hareket için ln3 LOW, ln4 HIGH yapılır
  digitalWrite(ln4,HIGH);
  analogWrite(enb,200); // dönme hızı ayarlanır
}
void right(){
  digitalWrite(ln1,HIGH); // sağ'a hareket için ln1 HIGH, ln2 LOW yapılır
  digitalWrite(ln2,LOW);
  analogWrite(ena,200); // dönme hızı ayarlanır
  
  digitalWrite(ln3,HIGH); // sağ'a hareket için ln3 HIGH, ln4 LOW yapılır
  digitalWrite(ln4,LOW);
  analogWrite(enb,50); // 2. motorun hızı daha düşük ayarlanır
}
void left(){
  digitalWrite(ln1,LOW); // sol'a hareket için ln1 LOW, ln2 HIGH yapılır
  digitalWrite(ln2,HIGH);
  analogWrite(ena,50); // 1. motorun hızı daha düşük ayarlanır
  
  digitalWrite(ln3,LOW); // sol'a hareket için ln3 LOW, ln4 HIGH yapılır
  digitalWrite(ln4,HIGH);
  analogWrite(enb,200); // dönme hızı ayarlanır
}
void spin(){
  digitalWrite(ln1,HIGH); // spin atması için tek taraflı motor çalıştırılır
  digitalWrite(ln2,LOW);
  analogWrite(ena,255); // dönme hızı ayarlanır
  
  digitalWrite(ln3,LOW);
  digitalWrite(ln4,LOW);
  analogWrite(enb,0); // tek taraflı dönme sağlanması için hız sıfır yapılır.
}