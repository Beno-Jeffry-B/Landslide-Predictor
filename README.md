# Landslide-Predictor

Landslides are highly destructive natural disasters, causing significant loss of life and property worldwide. This project proposes a solution through a landslide prediction and warning model using sensor networks to monitor rainfall and soil moisture content. Data from IoT-connected sensors is transmitted for real-time analysis, and logistic regression calculates the likelihood of an imminent landslide. A warning system is activated to alert authorities and the public, helping mitigate damage and save lives.

Our goal is to develop a comprehensive two-part solution to address the challenges of landslide prediction, combining both software and hardware components. The software side features a web application that allows users to input location-specific data, which is then analyzed using machine learning algorithms to calculate and display the likelihood of a landslide in real-time. The model, trained on synthetic data with logistic regression, ensures accurate risk assessments. On the hardware side, a network of advanced sensors continuously monitors key environmental factors, including soil moisture, temperature, and humidity. This data, updated every 10 seconds, is displayed in real-time and plays a critical role in early landslide detection.

Hardware setup: 
Build a sensor network using ESP-8266, soil moisture sensor and DHT-11 sensor. Upload the code through a type b cable in Arduino IDE. The output of the sensor system is shown in the serial monitor.

Software setup:





1. **Set Up Virtual Environment**:
   - Create a virtual environment:  
     ```bash
     python -m venv myenv
     ```
   - Activate the virtual environment:  
     ```bash
     myenv\Scripts\activate
     ```

2. **Install Required Libraries**:
   - List installed libraries:  
     ```bash
     pip list
     ```
   - If not installed, run:  
     ```bash
     pip install Flask flask-ngrok scikit-learn numpy tensorflow pandas openpyxl
     ```

3. **Navigate to Project Directory**:
   - Change to the project directory:
     ```bash
     cd "C:\Users\jeffr\OneDrive\Desktop\landslide prediction"
     ```
   - Confirm directory contents:  
     ```bash
     dir
     ```

4. **Set Up Ngrok**:
   - Install ngrok (using Chocolatey):  
     ```bash
     choco install ngrok
     ```
   - Authenticate ngrok:  
     ```bash
     ngrok authtoken <your-ngrok-auth-token>
     ```

5. **Run the Flask Application**:
   - Run the Python application:  
     ```bash
     python app.py
     ```
   - Open a new terminal and run ngrok:  
     ```bash
     ngrok http 5000
     ```
   - Access your app via the public URL provided by ngrok (e.g., `http://abcd1234.ngrok.io`).




