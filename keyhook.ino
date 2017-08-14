#define PIN D7
#define FSR_PIN A0

int fsrReading;
int fsrThreshold;

bool keyDetected;

int setThreshold(String threshold) {
    fsrThreshold = threshold.toInt();
    return 0;
}

void setup() {
    pinMode(PIN, OUTPUT);
    pinMode(FSR_PIN, INPUT);

    Particle.variable("detected", keyDetected);
    Particle.function("Threshold", setThreshold);
    fsrThreshold = 100;
}

void loop() {
    fsrReading = analogRead(FSR_PIN);
    keyDetected = fsrReading > fsrThreshold;
    digitalWrite(PIN, keyDetected ? HIGH : LOW);
}
