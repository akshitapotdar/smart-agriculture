os.system('cls')
import json, requests, time import pyrebase
import numpy as np # linear algebra
import pandas as pd # data processing, CSV file I/O from sklearn. model selection import train_ test _split
from sklearn.tree import DecisionT reeClassifier from sklearn ensemble import RandomForest Regressor import pandas as pd from sklearn.sm import SVC
from sklearn. model selection import train test split
config = 1
"a/Key": "60qMUSo8leadDxb92BMFOlI4YiaR9LkFvENTX",
"auth Domain", "agriculture-800aF-default-rdb.firebaseio.com",
"databaseURL": "htts://agriculture-800af-default-db,firebastio.com",
"storageBucket": "agriculture-800af-default"
firebase - pyrebase. initialize_app/config)
db - firebase database()
print(db)
ad pd.read
_csv("dataset.csv")
ad.shape
ad.info
ad.describe ad.headO
print(ad)
y = ad['result').values
X = ad.drop(result', axis=1).values
sm - SVCQ
sm. fit (X, y)
y_pred - svm.predict(X)
while True:
Temperature = db.child("Temperature").get
a Temperature.valO
print(a)
Humidity - db. child("Humidity").get
b=Humidity. valO
print(b)
PH = db.child("PhVal").getO
c=PH.valO
print(c)
x new = [a,b,c]
new pred = svm. predict([x_new])
type(new_pred)
print("Prediction: {}".format(new_pred))
db.update( {"Result": format(new_pred)})
time.sleep (5)
