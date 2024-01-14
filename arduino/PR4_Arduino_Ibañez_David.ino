
#include <LiquidCrystal.h> // Importamos la librería Liquid Crystal para la pantalla LCD

int motorPin = 3;   // PIN para encender/apagar motor
int watertime = 5;  // Constante para multiplicar la duración del riego 
int waittime = 1;   // Constante para los tiempos de espera

//Crear el objeto LCD con los números correspondientes (rs, en, d4, d5, d6, d7)
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  pinMode(motorPin, OUTPUT);  // Configurar Pin 3 como salida. 
  Serial.begin(9600); // Abrir puerto serie con una velocidad de 9600 baud/seg.
  lcd.begin(16, 2); // Inicializar la pantalla LCD con el número de columnas y filas.
  lcd.print("Riego automatico"); // Mensaje en la pantalla.
}

void loop() {
  int moisturePin = analogRead(A0);  //Lectura del sensor de humedad conectado en el pin analógico A0.
  int moisture = map(moisturePin, 0, 325, 0, 100); // Mapeo de los valores del sensor de humedad en porcentaje después de la calibración del sensor. 
  
  // El mapeo es distinto en Tinkercad que en el Arduino físico. 
  // Serial.print("Valor humedad: "); // Muestra del texto "Valor humedad" en el Serial Monitor. 
  // Serial.println(moisturePin); // Muestra del valor recuperado en la variable "moisture Pin"

  if (moisturePin >= 0 && moisturePin < 250) {  // Condición para activar la bomba de agua después de la calibración.
    digitalWrite(motorPin, HIGH);               // Activa la bomba de agua. 
    lcd.setCursor(0, 1); // Elegir en qué columna y en qué fila se mostrará la siguiente información. 0 = Primera columna. 1 = Segunda fila. 
    lcd.print("Regando......"); // Muestra la información "Regando..." en la pantalla LCD
    Serial.println("Regando....."); // Muestra la información "Regando..." en el Monitor y en la web. 
    delay(watertime * 1000);      // Tiempo de retardo para calibrar la posible latencia. 
    digitalWrite(motorPin, LOW);  // Apagar el motor durante los próximos segundos para que pueda controlar si la tierra está suficientemente húmeda.
    delay(waittime * 2000);       // Tiempo del motor en reposo. Si la tierra no está lo suficientemente húmeda, se vuelve a activar.

  } else {
    digitalWrite(motorPin, LOW);  // Apagar el motor en el caso de que la tierra esté humeda
    delay(waittime * 1000);       // Tiempo de espera.
    lcd.setCursor(0, 1); // Si no está regando, muestra el valor de humedad en la siguiente posición(columna:0) de la segunda línea(fila:1) de la pantalla.
    lcd.print("Humedad: ");
    lcd.print(moisture);
    lcd.print(" %    ");
    Serial.print("Humedad: "); // Muestra la misma información de humedad en el Monitor serial y en la web.
    Serial.print(moisture);
    Serial.println("%");
  }

  delay(waittime * 1000); // Tiempo de espera para equilibrar posibles latencias. 
}