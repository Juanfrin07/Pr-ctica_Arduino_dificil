char variable = 0 ;

//Motor A
int ENA = 10;
int IN1 = 9;
int IN2 = 8;

// Motor B
int ENB = 5;
int IN3 = 7;
int IN4 = 6;

//Intermitentes
int inter_d_i = 13;
int inter_d_d = 2;
int inter_t_i = 3;
int inter_t_d = 4;

//Luces
int luz_d = A3;
int luz_t = A5;

#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 11); // RX, TX


void setup ()
{
  // Declaramos todos los pines como salidas
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
  pinMode (inter_d_i, OUTPUT);
  pinMode (inter_d_d, OUTPUT);
  pinMode (inter_t_i, OUTPUT);
  pinMode (inter_t_d, OUTPUT);
  pinMode (luz_d, OUTPUT);
  pinMode (luz_t, OUTPUT);
  Serial.begin(57600);
  mySerial.begin(9600);
}


void loop ()
{
  if (mySerial.available()) {
    variable = mySerial.read();
    Serial.print(variable);
  }


  switch (variable) {

    case 'a':
      Adelante ();

      break;

    case 't':

      Atras ();
      digitalWrite(inter_t_i, HIGH);
      digitalWrite(inter_t_d, HIGH);
      delay (100);
      digitalWrite(inter_t_i, LOW);
      digitalWrite(inter_t_d, LOW);
      delay (100);
      digitalWrite(inter_t_i, HIGH);
      digitalWrite(inter_t_d, HIGH);
      delay (100);
      digitalWrite(inter_t_i, LOW);
      digitalWrite(inter_t_d, LOW);
      delay (100);
      digitalWrite(inter_t_i, HIGH);
      digitalWrite(inter_t_d, HIGH);
      delay (100);
      digitalWrite(inter_t_i, LOW);
      digitalWrite(inter_t_d, LOW);
      delay (100);

      break;

    case 'd':
      Derecha ();
      digitalWrite(inter_t_d, HIGH);
      digitalWrite(inter_d_d, HIGH);
      delay (100);
      digitalWrite(inter_t_d, LOW);
      digitalWrite(inter_d_d, LOW);
      delay (100);
      digitalWrite(inter_t_d, HIGH);
      digitalWrite(inter_d_d, HIGH);
      delay (100);
      digitalWrite(inter_t_d, LOW);
      digitalWrite(inter_d_d, LOW);
      delay (100);
      digitalWrite(inter_t_d, HIGH);
      digitalWrite(inter_d_d, HIGH);
      delay (100);
      digitalWrite(inter_t_d, LOW);
      digitalWrite(inter_d_d, LOW);
      delay (100);

      break;

    case 'i':
      Izquierda ();
      digitalWrite(inter_t_i, HIGH);
      digitalWrite(inter_d_i, HIGH);
      delay (100);
      digitalWrite(inter_t_i, LOW);
      digitalWrite(inter_d_i, LOW);
      delay (100);
      digitalWrite(inter_t_i, HIGH);
      digitalWrite(inter_d_i, HIGH);
      delay (100);
      digitalWrite(inter_t_i, LOW);
      digitalWrite(inter_d_i, LOW);
      delay (100);
      digitalWrite(inter_t_i, HIGH);
      digitalWrite(inter_d_i, HIGH);
      delay (100);
      digitalWrite(inter_t_i, LOW);
      digitalWrite(inter_d_i, LOW);
      delay (100);

      break;

    case 'p':
      Parar ();
      digitalWrite(inter_t_i, HIGH);
      digitalWrite(inter_t_d, HIGH);
      digitalWrite(inter_d_i, HIGH);
      digitalWrite(inter_d_d, HIGH);
      delay(1000);
      digitalWrite(inter_t_i, LOW);
      digitalWrite(inter_t_d, LOW);
      digitalWrite(inter_d_i, LOW);
      digitalWrite(inter_d_d, LOW);

      break;

    case 'l':
      digitalWrite(luz_d, HIGH);

      break;

    case 'w':
      digitalWrite(luz_t, HIGH);
      break;

    case 'e':
      digitalWrite(luz_d, LOW);

      break;

    case 'm':
      digitalWrite(luz_t, LOW);

      break;

    case 'x':
      digitalWrite(inter_t_i, HIGH);
      digitalWrite(inter_t_d, HIGH);
      digitalWrite(inter_d_i, HIGH);
      digitalWrite(inter_d_d, HIGH);
      delay (100);
      digitalWrite(inter_t_i, LOW);
      digitalWrite(inter_t_d, LOW);
      digitalWrite(inter_d_i, LOW);
      digitalWrite(inter_d_d, LOW);
      delay (100);
      digitalWrite(inter_t_i, HIGH);
      digitalWrite(inter_t_d, HIGH);
      digitalWrite(inter_d_i, HIGH);
      digitalWrite(inter_d_d, HIGH);
      delay (100);
      digitalWrite(inter_t_i, LOW);
      digitalWrite(inter_t_d, LOW);
      digitalWrite(inter_d_i, LOW);
      digitalWrite(inter_d_d, LOW);
      delay (100);



      break;

  }

}


void Adelante ()
{
  //Direccion motor A
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 170); //Velocidad motor A

}

void Atras ()
{
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, HIGH);
  analogWrite (ENA, 170); //Velocidad motor A

}

void Derecha ()
{

  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, HIGH);
  analogWrite (ENB, 100); //Velocidad motor A
}

void Izquierda ()
{

  //Direccion motor B
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 150); //Velocidad motor A
}


void Parar ()
{
  //Direccion motor A
  digitalWrite (IN1, LOW);
  digitalWrite (IN2, LOW);
  analogWrite (ENA, 0); //Velocidad motor A
  //Direccion motor B
  digitalWrite (IN3, LOW);
  digitalWrite (IN4, LOW);
  analogWrite (ENB, 0); //Velocidad motor A
}
