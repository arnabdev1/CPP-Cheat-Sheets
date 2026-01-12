# Machine Leaning

## Intro
```python

import pandas as pd
from sklearn.tree import DecisionTreeRegressor

# STEP 1: Load the data
melbourne_file_path = '../input/melbourne-housing-snapshot/melb_data.csv'
melbourne_data = pd.read_csv(melbourne_file_path)

# STEP 2: Explore the Columns
print("Full list of columns in the dataset:")
print(melbourne_data.columns)
# OUTPUT: Index(['Suburb', 'Address', 'Rooms', 'Type', 'Price', 'Method', 'SellerG',
#         'Date', 'Distance', 'Postcode', 'Bedroom2', 'Bathroom', 'Car',
#         'Landsize', 'BuildingArea', 'YearBuilt', 'CouncilArea', 'Lattitude',
#         'Longtitude', 'Regionname', 'Propertycount'], dtype='object')

# STEP 3: Handle Missing Values
# Dropping rows where data is missing (NaN)
melbourne_data = melbourne_data.dropna(axis=0)

# STEP 4: Select the Prediction Target (y)
y = melbourne_data.Price

# STEP 5: Select Features (X)
melbourne_features = ['Rooms', 'Bathroom', 'Landsize', 'Lattitude', 'Longtitude']
X = melbourne_data[melbourne_features]

# Reviewing the data structure of X
print(X.describe())
# OUTPUT: 
#              Rooms     Bathroom      Landsize     Lattitude    Longtitude
# count  6196.000000  6196.000000   6196.000000   6196.000000   6196.000000
# mean      2.931407     1.576340    471.006940    -37.807904    144.990201
# std       0.955317     0.711362    897.449881      0.075850      0.101731
# min       1.000000     1.000000      0.000000    -38.164920    144.542370
# 25%       2.000000     1.000000    152.000000    -37.855438    144.926198
# 50%       3.000000     1.000000    373.000000    -37.802250    144.995800
# 75%       4.000000     2.000000    628.000000    -37.758200    145.052700
# max       8.000000     8.000000  37000.000000    -37.457090    145.526350

print(X.head())
# OUTPUT:
#    Rooms  Bathroom  Landsize  Lattitude  Longtitude
# 1      2       1.0     156.0   -37.8079    144.9934
# 2      3       2.0     134.0   -37.8093    144.9944
# 4      4       1.0     120.0   -37.8072    144.9941
# 6      3       2.0     245.0   -37.8024    144.9993
# 7      2       1.0     256.0   -37.8060    144.9954

# STEP 6: Define and Fit the Model
# We use a Decision Tree algorithm. random_state ensures the tree splits 
# the same way every time you run the code.
melbourne_model = DecisionTreeRegressor(random_state=1)
melbourne_model.fit(X, y)

# STEP 7: Make Predictions
print("Making predictions for the first 5 houses:")
predictions = melbourne_model.predict(X.head())
print(predictions)
# OUTPUT: [1035000. 1465000. 1600000. 1876000. 1636000.]

# Comparing to the actual values (y)
print("Actual prices for those houses:")
print(y.head().tolist())
# OUTPUT: [1035000.0, 1465000.0, 1600000.0, 1876000.0, 1636000.0]

```

## Intro 2
```python
import pandas as pd
from sklearn.tree import DecisionTreeRegressor
# We import a new tool to split our data
from sklearn.model_selection import train_test_split
# We import a metric to see how "wrong" our model is
from sklearn.metrics import mean_absolute_error

# STEP 1: Load and Clean
melbourne_file_path = '../input/melbourne-housing-snapshot/melb_data.csv'
data = pd.read_csv(melbourne_file_path).dropna(axis=0)

# STEP 2: Select Target and Features
y = data.Price
melbourne_features = ['Rooms', 'Bathroom', 'Landsize', 'Lattitude', 'Longtitude']
X = data[melbourne_features]

# STEP 3: The Split
# We split the data into four pieces:
# - train_X, train_y: These are used to "teach" the model.
# - val_X, val_y: These are the "unseen" houses used to "test" the model.
# 'test_size=0.2' means we hide 20% of the data for testing.
train_X, val_X, train_y, val_y = train_test_split(X, y, random_state=0, test_size=0.2)

# STEP 4: Train (Fit) the model ONLY on the training data
melbourne_model = DecisionTreeRegressor(random_state=1)
melbourne_model.fit(train_X, train_y)

# STEP 5: Predict on the validation data (houses the model hasn't seen)
val_predictions = melbourne_model.predict(val_X)

# STEP 6: Calculate Error
# Mean Absolute Error (MAE) tells us, on average, how far off our predictions are.
# Error = |Actual Price - Predicted Price|
mae = mean_absolute_error(val_y, val_predictions)

print("Predictions for first 5 unseen houses:")
print(val_predictions[0:5])
# OUTPUT: [ 890000.  497000.  935000. 1185000.  812000.]

print("\nActual prices for those houses:")
print(val_y.head().tolist())
# OUTPUT: [805000.0, 505000.0, 810000.0, 1200000.0, 1020000.0] 
# NOTICE: They no longer match perfectly!

print(f"\nMean Absolute Error: ${mae:,.2f}")
# OUTPUT: Mean Absolute Error: $273,121.72
```
