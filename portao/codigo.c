int aberto = 4;
int fechado = 2;
int comando = 8;
int ligado = 12;
int direcao = 13;
int dir = 1;
int led = 11;  // Pino do LED
bool piscar = false;

void setup()
{
  pinMode(aberto, INPUT);
  pinMode(fechado, INPUT);
  pinMode(comando, INPUT);
  pinMode(ligado, OUTPUT);
  pinMode(direcao, OUTPUT);
  pinMode(led, OUTPUT);  // Configura o pino do LED como saída
  Serial.begin(9600);
}

void loop()
{
  int inicioEstado = digitalRead(aberto);
  int fimEstado = digitalRead(fechado);
  int com = digitalRead(comando);
  delay(400);

  if (inicioEstado == HIGH)
  {
    Serial.println("Aberto");
    digitalWrite(ligado, LOW);
    dir = 1;
    piscar = false;  // Para de piscar o LED
    digitalWrite(led, LOW);  // Apaga o LED
  }
  else if (fimEstado == HIGH)
  {
    Serial.println("Fechado");
    digitalWrite(ligado, LOW);
    dir = 0;
    piscar = false;  // Para de piscar o LED
    digitalWrite(led, LOW);  // Apaga o LED
  }
  else
  {
    digitalWrite(direcao, dir);
    if (com == HIGH)
    {
      if (dir == 1)
      {
        dir = 0;
        Serial.println("Portão fechando");
      }
      else
      {
        dir = 1;
        Serial.println("Portão abrindo");
      }
      digitalWrite(ligado, HIGH);
      piscar = true;  // Inicia o piscar do LED
    }
  }

  if (piscar)
  {
    digitalWrite(led, HIGH);  // Liga o LED
    delay(500);               // Espera 0.5 segundos
    digitalWrite(led, LOW);   // Desliga o LED
    delay(500);               // Espera 0.5 segundos
  }
}

