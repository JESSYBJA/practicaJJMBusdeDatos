#define buscarled 1
#define buscarnumero 2

int led = 0;
int dato = 0;
int EstadodeBusqueda = 0;
int boton = 2;



void setup() {
  Serial.begin(9600);
  Serial.println("hola soy arduino");
  pinMode (13, OUTPUT);
  pinMode (boton,INPUT);
}

void loop() {

  //aqui nuevo codigo
  if (digitalRead(boton)==1){
    Serial.print ("H");
    delay(500);
  }
  if (Serial.available()) {
    char letra = Serial.read();
    if (letra == 'L') {
      EstadodeBusqueda = buscarled;
    }
    else if (letra == 'D') {
      EstadodeBusqueda = buscarnumero;
    }
    else if (letra == '.') {
      analogWrite(led, dato);
      Serial.print("El led es:");
      Serial.print(led);
      Serial.print("dato:");
      Serial.println(dato);

      led = 0;
      dato = 0;
      EstadodeBusqueda =0;
    }
    else if (letra >= '0' && letra <= '9') {
      int numeroactual = int (letra - '0');
      if (EstadodeBusqueda == buscarled) {
        led = led * 10 + numeroactual;
      }
      else if (EstadodeBusqueda == buscarnumero) {
        dato = dato * 10 + numeroactual;
      }
    }
  }

}
