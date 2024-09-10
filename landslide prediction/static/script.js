document.getElementById('predictForm').addEventListener('submit', async function (e) {
    e.preventDefault();

    const data = {
        precipitation: document.getElementById('precipitation').value,
        energy: document.getElementById('energy').value,
        soil_moisture: document.getElementById('soil_moisture').value,
        latitude: document.getElementById('latitude').value,
        longitude: document.getElementById('longitude').value,
        elevation: document.getElementById('elevation').value,
        run: document.getElementById('run').value,
        slope: document.getElementById('slope').value
    };

    // Validate decimal places for all fields
    for (const key in data) {
        if (!validateDecimalLength(data[key])) {
            alert(`The value for ${key} must be a decimal with at least 10 digits after the decimal point.`);
            return;
        }
    }

    const response = await fetch("/predict", {
        method: "POST",
        headers: {
            "Content-Type": "application/json"
        },
        body: JSON.stringify(data)
    });

    const result = await response.json();
    document.getElementById('result').innerText = "Prediction: " + result.prediction.toFixed(2) + "%";
});

function validateDecimalLength(value) {
    const regex = /^-?\d*\.\d{10,}$/;  // Allows negative and positive values with at least 10 decimal places
    return regex.test(value);
}
