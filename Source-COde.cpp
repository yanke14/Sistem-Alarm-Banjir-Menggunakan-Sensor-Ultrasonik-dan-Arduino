#define TRIG_PIN 9 // Pin Trig sensor ultrasonik
#define ECHO_PIN 10 // Pin Echo sensor ultrasonik
#define BUZZER_PIN 11 // Pin buzzer
#define LED_GREEN 12 // Pin LED Hijau
#define LED_RED 13 // Pin LED Merah

long duration;
float distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT); // Trig sebagai output
  pinMode(ECHO_PIN, INPUT);  // Echo sebagai input
  pinMode(BUZZER_PIN, OUTPUT); // Buzzer sebagai output
  pinMode(LED_GREEN, OUTPUT); // LED Hijau sebagai output
  pinMode(LED_RED, OUTPUT);   // LED Merah sebagai output
  Serial.begin(9600); // Memulai komunikasi serial
}

void loop() {
  // Mengirim sinyal ultrasonik
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Menerima pantulan gelombang ultrasonik
  duration = pulseIn(ECHO_PIN, HIGH);

  // Menghitung jarak
  distance = (duration * 0.034) / 2;

  // Menampilkan jarak ke Serial Monitor
  Serial.print("Jarak: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Logika peringatan
  if (distance < 10.0) { // Jika air tinggi (contoh: jarak < 10 cm)
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
  } else { // Jika air normal
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(500); // Tunggu 500 ms sebelum loop berikutnya
}