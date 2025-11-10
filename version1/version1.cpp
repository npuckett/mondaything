// Non-blocking LED blink on pin 3 using millis()
#include <Arduino.h>

// Configuration
const uint8_t LED_PIN = 5;                 // Target pin to blink
const unsigned long INTERVAL_MS = 500UL;   // Blink interval (milliseconds)

// State
static unsigned long lastToggleMs = 0UL;
static bool ledState = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  lastToggleMs = millis();
}

void loop() {
  unsigned long now = millis();

  // Handle rollover safely: subtraction works with unsigned long overflow
  if (now - lastToggleMs >= INTERVAL_MS) {
    lastToggleMs = now;
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState ? HIGH : LOW);
  }

  // Do other non-blocking work here if needed
}