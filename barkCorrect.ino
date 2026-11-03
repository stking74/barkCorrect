//barkCorrect.ino

  /*
  An attempt to get the damn dog to shut up when she's left alone.

  Uses a piezo element to detect sound over a set volume threshold.
  When a positive detection is made, responds by playing an ultrasonic noise to discourage the source.
  */

const int sense_pin = A0;
const int response_frequency = 15000;
int sound_intensity = 0;
const int sound_threshold = 20;

void setup() {
  
  pinMode(sense_pin, INPUT);
  analogReference(INTERNAL);

}

void loop() {
  
  sound_intensity = analogRead(sense_pin);
  if (sound_intensity >= sound_threshold) {

    pinMode(sense_pin, OUTPUT);
    tone(sense_pin, response_frequency);
    delay(1000);
    noTone(sense_pin);
    pinMode(sense_pin, INPUT);
    sound_intensity = 0;
    delay(1000);

  }

}
