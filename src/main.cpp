#include <Arduino.h>

#define ADC_PRECISSION 14
#define ADC_FREQUENCY 2400
#define R1_LED_CHAN 1
#define R2_LED_CHAN 2
#define L1_LED_CHAN 3
#define L2_LED_CHAN 4
#define R1_LED_PIN 27
#define R2_LED_PIN 26
#define L1_LED_PIN 12
#define L2_LED_PIN 14

void setup() {
    Serial.begin(115200);

    // turn internal blue LED on
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);

    ledcAttachPin(R1_LED_PIN, R1_LED_CHAN);
    ledcAttachPin(R2_LED_PIN, R2_LED_CHAN);
    ledcAttachPin(L1_LED_PIN, L1_LED_CHAN);
    ledcAttachPin(L2_LED_PIN, L2_LED_CHAN);
    ledcSetup(R1_LED_CHAN, ADC_FREQUENCY, ADC_PRECISSION);
    ledcSetup(R2_LED_CHAN, ADC_FREQUENCY, ADC_PRECISSION);
    ledcSetup(L1_LED_CHAN, ADC_FREQUENCY, ADC_PRECISSION);
    ledcSetup(L2_LED_CHAN, ADC_FREQUENCY, ADC_PRECISSION);
    ledcWrite(R1_LED_CHAN, 0);
    ledcWrite(R2_LED_CHAN, 0);
    ledcWrite(L1_LED_CHAN, 0);
    ledcWrite(L2_LED_CHAN, 0);

    Serial.println("dragon mask ready");
}

void loop() {
    static uint16_t brightness = 0;
    static short dir = 2;

    ledcWrite(R1_LED_CHAN, brightness);
    ledcWrite(L1_LED_CHAN, brightness);

    ledcWrite(R2_LED_CHAN, 1024 - brightness);
    ledcWrite(L2_LED_CHAN, 1024 - brightness);

    brightness += dir;
    if (brightness <= 0 || brightness >= 1024) dir = -dir;

    delay(2);
}
