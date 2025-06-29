#include <WiFi.h> // Include for WiFi, even if not used, to avoid potential missing header issues.

// Decision Tree Function (Keep this the same)
int predict(float age, float sex, float trestbps, float maxheartrate) {
  if (maxheartrate <= 147.5) {
    if (sex <= 0.5) {
      if (trestbps <= 122.0) {
        return 1;
      } else {
        if (age <= 63.5) {
          if (trestbps <= 131.0) return 0;
          else return 0;
        } else {
          if (trestbps <= 145.0) return 1;
          else return 0;
        }
      }
    } else {
      if (maxheartrate <= 142.5) {
        if (maxheartrate <= 122.5) {
          if (trestbps <= 126.0) return 0;
          else return 0;
        } else {
          if (maxheartrate <= 123.5) return 1;
          else return 0;
        }
      } else {
        if (trestbps <= 116.0) {
          if (age <= 54.5) return 1;
          else return 0;
        } else {
          if (age <= 69.5) return 0;
          else return 1;
        }
      }
    }
  } else {
    if (age <= 57.5) {
      if (sex <= 0.5) {
        if (age <= 55.5) return 1;
        else {
          if (maxheartrate <= 151.5) return 0;
          else return 1;
        }
      } else {
        if (maxheartrate <= 168.5) {
          if (trestbps <= 128.5) return 0;
          else return 1;
        } else {
          if (trestbps <= 151.0) return 1;
          else return 0;
        }
      }
    } else {
      if (sex <= 0.5) {
        if (age <= 63.5) {
          if (maxheartrate <= 170.0) return 0;
          else return 1;
        } else {
          if (maxheartrate <= 163.5) return 1;
          else return 0;
        }
      } else {
        if (maxheartrate <= 157.5) {
          if (age <= 66.5) return 1;
          else return 0;
        } else {
          if (trestbps <= 134.5) return 0;
          else return 0;
        }
      }
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Serial Input Prediction...");
}

void loop() {
  for (int i = 0; i < 3; ++i) {
    Serial.print("\n[Iteration ");
    Serial.print(i + 1);
    Serial.println("]");

    Serial.println("Enter age (e.g., 60.5):");
    while (!Serial.available()) {
      delay(100); // Wait for input
    }
    float age = Serial.parseFloat();
    Serial.println(age);
    while (Serial.available()) Serial.read(); // Clear buffer

    Serial.println("Enter sex (0 for Female, 1 for Male):");
    while (!Serial.available()) {
      delay(100);
    }
    float sex = Serial.parseFloat();
    Serial.println(sex);
    while (Serial.available()) Serial.read();

    Serial.println("Enter resting blood pressure (trestbps, e.g., 130.0):");
    while (!Serial.available()) {
      delay(100);
    }
    float trestbps = Serial.parseFloat();
    Serial.println(trestbps);
    while (Serial.available()) Serial.read();

    Serial.println("Enter maximum heart rate (e.g., 155.0):");
    while (!Serial.available()) {
      delay(100);
    }
    float maxheartrate = Serial.parseFloat();
    Serial.println(maxheartrate);
    while (Serial.available()) Serial.read();

    int prediction = predict(age, sex, trestbps, maxheartrate);
    Serial.print("Prediction: ");
    if (prediction == 1) {
      Serial.println("⚠️ Alert: There may be heart disease.");
    } else {
      Serial.println("✅ No heart disease detected.");
    }

    delay(1000); // Small delay before next iteration
  }
  Serial.println("\n[Finished] All 3 iterations completed.");
  while(true); // Stop the loop.
}
