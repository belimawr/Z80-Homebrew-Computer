int wait = 9;
int bus_ack = 10;
int t = 100;
int count;
bool changed;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(wait, OUTPUT);
  pinMode(bus_ack, OUTPUT);
  count = 0;
  changed = false;

  digitalWrite(wait, HIGH);
  Serial.begin(9600);
}

void loop() {
  if ((count > 32) && (count < 64)) {
    digitalWrite(wait, LOW);
    Serial.println("LOW");
  } else if ((count > 128) && (count < 192)){
    digitalWrite(bus_ack, LOW);
    Serial.println("BUS_ACK");
  } else {
    digitalWrite(bus_ack, HIGH);
    digitalWrite(wait, HIGH);
    Serial.println("HIGH");
  }

  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(8, HIGH);
  delay(t);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(8, LOW);
  delay(t);

  count++;
  Serial.println(count);
}
