/*
 * Segundo Laboratorio:
 * Consiste en controlar el color y la intensidad de 3 leds 
 * comunes y un RGB mediante dos potenciometros, uno para el brillo 
 *  y otro que define el color
*/

const int pinVerde = 9; //Led Verde en el pinDigital 9
const int pinAzul = 10; //Led Azul en el pinDigital 10
const int pinRojo = 11; //Led Rojo en el pinDigital 11
const int pinSensor = A0; //Potenciometro 1 en el pinAnalogico A0
const int pinSensor2 = A1; //Potenciometro 2 en el pinAnalogico A1

//Variables donde guardamos el valor de cada potenciometro.
int valorPotenciometro;
int valorPotenciometro2;

//Variables donde guardamos la intensidad individual de cada led.
int valRojo;
int valVerde;
int valAzul;

void setup() {
  
    Serial.begin(9600);
    
    //Declaramos los potenciometros como entradas
    pinMode(pinSensor, INPUT);  
    pinMode(pinSensor2, INPUT); 
    
    //Declaramos los leds como salidas
    pinMode(pinVerde, OUTPUT);  
    pinMode(pinAzul, OUTPUT);   
    pinMode(pinRojo, OUTPUT);   
    
}
void loop(){
  //Leemos los valores de los potenciometros
  valorPotenciometro = analogRead(pinSensor);
  valorPotenciometro2 = analogRead(pinSensor2);

  //Asignamos un valor a cada led mediante funciones
  valRojo = verValorRojo();
  valVerde = verValorVerde();
  valAzul = verValorAzul();

  //Encendemos cada led segun su valor individual y la intensidad leida 
  //por el potenciometro 2.
  analogWrite(pinRojo, map(valorPotenciometro2, 0, 1023, 0, valRojo)); 
  analogWrite(pinVerde, map(valorPotenciometro2, 0, 1023, 0, valVerde));
  analogWrite(pinAzul, map(valorPotenciometro2, 0, 1023, 0, valAzul));
  
  delay(50); //Esperamos 50 miliSegundos
}

//Funcion que lee el potenciometro y asigna un valor para el led Rojo
int verValorRojo(){
  int val = map(valorPotenciometro, 614, 1023, 0, 255);
  if (val<0){
    return 0;
  }
  return val;
}

//Funcion que lee el potenciometro y asigna un valor para el led Verde
int verValorVerde(){
  int val;
  if (valorPotenciometro>199 && valorPotenciometro<501){
    val = map(valorPotenciometro, 200, 500, 0, 255);
  }
  else{
    val = map(valorPotenciometro, 500, 800, 255, 0);
  }
  if (val<0 || val>255){
    return 0;
  }
  return val;
}

//Funcion que lee el potenciometro y asigna un valor para el led Azul
int verValorAzul(){
  int val = map(valorPotenciometro, 0, 409, 255, 0);
  if (val<0 || val>255){
    return 0;
  }
  return val;
}
