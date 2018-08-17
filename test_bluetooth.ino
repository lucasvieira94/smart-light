
#define RELE 7
SoftwareSerial bluetooth(RX, TX); // RX, TX
 
void setup() {
  Serial.begin(9600); // Inicializa a serial nativa do Arduino
  pinMode(RELE,OUTPUT); // Inicializamos o pino 7 do relé como output
  digitalWrite(RELE,LOW); // Inicializa a chave como desligada
  bluetooth.begin(9600); // Inicializa a serial via software (Onde está conectado o nosso módulo bluetooth)
}
 
void verificaBluetooth(){ // Verifica se existe algum dado a ser lido da serial
  if (bluetooth.available()){ // verifica se existem bytes a serem lidos da porta serial virtual
     char dados = bluetooth.read(); // Lê 1 byte da porta serial
     Serial.println(dados); // Mostra esse dado lido na porta serial
     if (dados=='0'){ // Se o byte lido for igual a 0
       digitalWrite(RELE,LOW); // Desliga a chave
     }
     else{
        if (dados=='1'){ // Se o byte lido for igual a 1
          digitalWrite(RELE,HIGH); // Liga a chave e aciona a bomba
        }
     }
  }
}
 
void loop (){
  verificaBluetooth();
}
