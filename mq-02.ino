// Open Source
//MQ-2 - Sensor de Gás e Fumaça
// ligação pino sensor = A0;
// ligação do display SDA = A4 , SLC= A5, GND, VCC;


#include <LiquidCrystal_I2C.h> //INCLUSÃO DE BIBLIOTECA
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

int Pinbuzzer = 8; //PINO UTILIZADO PELO BUZZER
int PinA0 = A0;//PINO UTILIZADO PELO SENSOR DE GÁS MQ-2

int leitura_sensor = 300;//DEFININDO UM VALOR LIMITE (NÍVEL DE GÁS NORMAL)

void setup(){
lcd.begin (16,2); //SETA A QUANTIDADE DE COLUNAS(16) E O NÚMERO DE LINHAS(2) DO DISPLAY
lcd.setBacklight(HIGH); //LIGA O BACKLIGHT (LUZ DE FUNDO)
pinMode(PinA0, INPUT); //DEFINE O PINO COMO ENTRADA
pinMode(Pinbuzzer, OUTPUT); //DEFINE O PINO COMO SAÍDA
Serial.begin(9600);//INICIALIZA A SERIAL
}
void loop(){
  lcd.setCursor(0,0); //SETA A POSIÇÃO DO CURSOR
  lcd.print("MQ-2 GAS/FUMACA"); //IMPRIME O TEXTO NO DISPLAY LCD
  int valor_analogico = analogRead(PinA0); //VARIÁVEL RECEBE O VALOR LIDO NO PINO ANALÓGICO
  Serial.print("Leitura: "); //EXIBE O TEXTO NO MONITOR SERIAL
  Serial.println(valor_analogico);// MOSTRA NO MONITOR SERIAL O VALOR LIDO DO PINO ANALÓGICO
  
  if (valor_analogico > leitura_sensor){//SE VALOR LIDO NO PINO ANALÓGICO FOR MAIOR QUE O VALOR LIMITE, FAZ 
  digitalWrite(Pinbuzzer, LOW); //BUZZER DESLIGADO
  lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print("COM ALARME"); //IMPRIME O TEXTO NO DISPLAY LCD
  
  }else{ //SENÃO, FAZ
  digitalWrite(Pinbuzzer, HIGH);//BUZZER LIGADO
  lcd.setCursor(0,1); //SETA A POSIÇÃO DO CURSOR
  lcd.print("SEM ALARME"); //IMPRIME O TEXTO NO DISPLAY LCD
  }
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS
}
