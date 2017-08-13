#define PIN D7
#define FSR_PIN A0

int state = 0;
int fsrReading;
int fsrThreshold;

int setThreshold(String threshold) {
    fsrThreshold = threshold.toInt();
    return 0;
}

void setup() {
    pinMode(PIN, OUTPUT);
    pinMode(FSR_PIN, INPUT);
    Particle.variable("fsrReading", fsrReading);
    Particle.variable("fsrThreshold", fsrThreshold);
    Particle.function("Threshold", setThreshold);
    fsrThreshold = 100;
}

void loop() {
    fsrReading = analogRead(FSR_PIN);
    digitalWrite(PIN, fsrReading > fsrThreshold ? HIGH : LOW);
    state = !state;
}
