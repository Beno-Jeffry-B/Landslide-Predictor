from flask import Flask, request, jsonify, render_template
from flask_ngrok import run_with_ngrok
import pandas as pd
import numpy as np
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.model_selection import train_test_split

app = Flask(__name__)
run_with_ngrok(app)

# Load the dataset and train the model
df = pd.read_excel('Book1.xlsx')
df['Landslide'] = (df['Landslide Probability'] > 0.5).astype(int)
X = df.drop(['Landslide', 'Landslide Probability'], axis=1)
y = df['Landslide']

# Train-test split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Standardize the data
scaler = StandardScaler()
X_train = scaler.fit_transform(X_train)
X_test = scaler.transform(X_test)

# Train logistic regression model
lr_model = LogisticRegression(max_iter=1000)
lr_model.fit(X_train, y_train)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/predict', methods=['POST'])
def predict():
    data = request.json
    input_data = np.array([data['precipitation'], data['energy'], data['soil_moisture'],
                           data['latitude'], data['longitude'], data['elevation'], 
                           data['run'], data['slope']]).reshape(1, -1)
    
    input_data = scaler.transform(input_data)
    prediction_proba = lr_model.predict_proba(input_data)
    

    landslide_probability = prediction_proba[0][1] * 100
    
    return jsonify({'prediction': landslide_probability})



if __name__ == '__main__':
    app.run()

