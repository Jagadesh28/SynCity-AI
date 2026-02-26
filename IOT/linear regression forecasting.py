aimport pandas as pd
import gspread
from oauth2client.service_account import ServiceAccountCredentials
from sklearn.linear_model import LinearRegression
import numpy as np


scope = ["https://spreadsheets.google.com/feeds",
         "https://www.googleapis.com/auth/drive"]

creds = ServiceAccountCredentials.from_json_keyfile_name("credentials.json", scope)
client = gspread.authorize(creds)

sheet = client.open("SmartCampusData").sheet1
data = sheet.get_all_records()

df = pd.DataFrame(data)


df['Date'] = pd.to_datetime(df['Date'], dayfirst=True)
df = df.sort_values('Date')
df['Day'] = np.arange(len(df))

print("\n📊 Monthly Smart Campus Data Loaded")


def train_predict_model(column):
    X = df[['Day']]
    y = df[column]

    model = LinearRegression()
    model.fit(X, y)

    next_day = len(df)
    next_day_pred = model.predict([[next_day]])[0]

    return next_day_pred


next_energy = train_predict_model("Energy")
next_water = train_predict_model("Water")
next_temp = train_predict_model("Temp")
next_waste = train_predict_model("Waste")

print("\n🔮 NEXT DAY USAGE PREDICTION\n")
print(f"⚡ Energy Usage Prediction : {next_energy:.2f}")
print(f"💧 Water Usage Prediction  : {next_water:.2f}")
print(f"🌡 Temperature Prediction  : {next_temp:.2f}")
print(f"🗑 Waste Level Prediction  : {next_waste:.2f}")


latest = df.iloc[-1]

energy = latest["Energy"]
water = latest["Water"]
temp = latest["Temp"]
waste = latest["Waste"]

print("\n📡 LIVE CAMPUS STATUS\n")
print(latest)


print("\n⚙ REAL-TIME AUTOMATION\n")

if energy > 80:
    print("⚡ High Energy → Turn OFF extra loads")

if water < 30:
    print("💧 Tank Low → Motor ON")
elif water > 80:
    print("💧 Tank Full → Motor OFF")

if temp > 35:
    print("🌡 High Temp → Cooling ON")
else:
    print("🌡 Temperature Normal")

if waste > 70:
    print("🗑 Bin Full → Cleaning Required")


print("\n🚀 AI PREVENTIVE ACTIONS\n")

if next_energy > 80:
    print("⚡ Tomorrow Overload Risk → Load Balancing")

if next_water < 30:
    print("💧 Tomorrow Water Shortage → Storage Planning")

if next_temp > 35:
    print("🌡 Tomorrow Heat Risk → Pre-Cooling")

if next_waste > 70:
    print("🗑 Tomorrow Waste Overflow → Cleaning Schedule")

print("\n✅ AI Digital Twin Decision Engine Active")

