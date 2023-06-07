#include <LiquidCrystal.h>      //añadimos las librerias
#include <Servo.h>
#include <Wire.h>               
#include <LiquidCrystal_I2C.h>


#define lcdAddress 0x27  //configuracion de la lcd
#define filas 2
#define columnas 16
LiquidCrystal_I2C lcd(lcdAddress, columnas, filas);
#define SDA A4
#define SCL A5


#define buzzer 4                          //configuracion del buzzer

int frecuencia = 850;   //creamos variables para todo lo que se va a usar
int duracion = 300;

#define bot_1 7
#define bot_2 8
#define bot_3 9
#define bot_4 10
#define pot1 A1
#define pot2 A2
#define pot3 A3
int valor;
int valor2;
int valor3;
int val;
int val2;
int val3;
bool valor_reset = 0;
int botonstdo = 0;
int botonstdo2 = 0;
int botonstdo3 = 0;
int botonstdo4 = 0;
int valbtn = 0;
int valbtn2 = 0;
int valbtn3 = 0;
int valbtn4 = 0;
Servo cito; //variable para poder usar el servomotor
Servo cito2;
Servo cito3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  cito.attach(11);//activamos el pin del servo
  cito2.attach(12);
  cito3.attach(14);

  pinMode(bot_1, INPUT);   //establecemos salidas y entradas
  pinMode(bot_2, INPUT);
  pinMode(bot_3, INPUT);
  pinMode(bot_4, INPUT);
  pinMode(buzzer, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), reset, HIGH); //Se configuraciones las interrupciones


lcd.begin(16, 2);  
lcd.init();       //inicializacion del LCD
lcd.backlight();  //luz del fondo de la LCD

}

void loop() {
servos(); // la funcion de los servos

if(valor_reset == 1){  //utilizamos un if para que funcione todo lo de la interrupcion
lcd.clear();
lcd.setCursor(0,0);
lcd.print("RESETEO...");
cito.write(0);
cito2.write(0);
cito3.write(0);
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("reseteo finalizado");
delay(1500);
tone(buzzer,frecuencia, duracion);
delay(1000);
valor_reset=0;
}

if (digitalRead(bot_1) == 0) { /*ifs para los botones*/
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Moviendo Brazo...");
  digitalWrite(pot1, LOW);
  digitalWrite(pot2, LOW);
  digitalWrite(pot3, LOW);
  cito.write (45);
 delay(500);
}
else{
  cito.write(0);
 delay(500);
}

if (digitalRead(bot_2) == 0) {/**/
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Moviendo Brazo...");
  digitalWrite(pot1, LOW);
  digitalWrite(pot2, LOW);
  digitalWrite(pot3, LOW);
  cito.write (90);
 delay(500);
}
else{
  cito.write(0);
 delay(500);
}

if (digitalRead(bot_3) == 0) {/**/
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Moviendo Brazo...");
  digitalWrite(pot1, LOW);
  digitalWrite(pot2, LOW);
  digitalWrite(pot3, LOW);
  cito.write (130);
 delay(500);
}
else{
  cito.write(0);
 delay(500);
}

if (digitalRead(bot_4) == 0) {/**/
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Moviendo Brazo...");
  digitalWrite(pot1, LOW);
  digitalWrite(pot2, LOW);
  digitalWrite(pot3, LOW);
  cito.write (180);
 delay(500);
}
else{
  cito.write(0);
 delay(500);
}

}

void reset(){ //void para la interrupcion que es el reseteo
  valor_reset= 1;
  return valor_reset;


}

void servos (){ //void con la programacion de los servos
valor = analogRead(pot1);
val = map(valor, 0, 1023, 0, 180);
cito.write(val);
delay(15);

valor2 = analogRead(pot2);
val2 = map(valor2, 0, 1023, 0, 180);
cito2.write(val2);
delay(15);

valor3 = analogRead(pot3);
val3 = map(valor3, 0, 1023, 0, 180);
cito3.write(val3);
delay(15);

lcd.clear();
lcd.print("Moviendose a:   ");
lcd.setCursor(0,1);
lcd.print("R");
lcd.print(valor);
lcd.setCursor(6,1);
lcd.print("B");
lcd.print(valor2);
lcd.setCursor(12,1);
lcd.print("A");
lcd.print(valor3);
}



