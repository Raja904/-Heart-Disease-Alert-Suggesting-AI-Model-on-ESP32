# Heart Disease Alert Suggesting System on ESP32

This project presents a real-time heart disease risk alert system using a Decision Tree model deployed on an ESP32 microcontroller. The system uses just four health metrics—commonly trackable by modern smartwatches—to predict the likelihood of heart disease and provide early warnings.

By combining simple AI logic with a ₹300 ESP32 board, the system proves that meaningful healthcare solutions can be built using minimal resources.

---

## Motivation

With smart wearables increasingly capable of tracking health parameters like heart rate and blood pressure, we wanted to explore whether this data could be used to provide real-time, local predictions of heart disease. 

This project shows how even a **small set of features (age, sex, blood pressure, heart rate)** can deliver a predictive model with significant accuracy. Deployed on an ESP32, the system works **without internet connectivity** and can serve as an **early warning system**, especially in rural or resource-limited settings.

---

## Dataset

- Source: [UCI Heart Disease Dataset](https://archive.ics.uci.edu/dataset/45/heart+disease)
- Original features: 14
- Selected features for embedded use:
  - `age`
  - `sex`
  - `trestbps` (resting systolic blood pressure)
  - `thalach` (maximum heart rate achieved)
- Target label: `target` (1 = presence of heart disease, 0 = absence)

---

## Model Overview

- **Model Type:** Decision Tree Classifier  
- **Library:** scikit-learn  
- **Training/Test Split:** 80/20  
- **Test Accuracy:** 79.5%  
- **Cross-Validation Accuracy:** 77%  
- **Max Depth:** 5 (to prevent overfitting and simplify rule translation)

The trained model uses only essential logic, making it ideal for deployment on edge devices with constrained resources.

---

## Deployment on ESP32

The trained decision tree was manually translated into C++ decision rules and implemented in an Arduino `.ino` file for use on an ESP32 microcontroller.

- **Hardware Used:** ESP32 board (cost: ₹300)
- **Firmware File:** `heart_esp_decision_tree.ino`
- **Deployment Platform:** Arduino IDE
- **Input:** Entered via Serial Monitor (age, sex, blood pressure, heart rate)
- **Output:** Real-time prediction displayed in Serial Monitor

This setup allows low-cost, offline inference without needing cloud APIs or heavy compute resources.

---

## Project Files

| File                          | Description                                                                 |
|------------------------------|-----------------------------------------------------------------------------|
| `test.ipynb`                 | Jupyter notebook for data preprocessing, EDA, model training, and evaluation |
| `heart_esp_decision_tree.ino`| C++ code for ESP32 containing manually written decision rules                |
| `README.md`                  | Project overview and usage documentation                                     |

---

## How to Run

1. Open `test.ipynb` to review the model training, feature selection, and evaluation process.
2. Open the `heart_esp_decision_tree.ino` file in Arduino IDE.
3. Flash the code to the ESP32 board.
4. Open the Serial Monitor.
5. Input values for:
   - Age
   - Sex (0 = Female, 1 = Male)
   - Resting Blood Pressure
   - Max Heart Rate Achieved
6. The system will output a prediction based on the trained model logic.

---

## Why This Project Matters

- Uses only 4 easily available features, making it suitable for integration with smartwatches and health bands.
- Works entirely offline on a microcontroller that costs less than ₹300.
- Simple logic, fast inference, and real-time feedback.
- Ideal for early screening and awareness, especially in areas with limited healthcare access.

This project demonstrates how **AI + IoT** can be combined to build practical, affordable, and life-saving solutions.


