# Binary Trees Cheat Sheet

## Binary Tree Node Declaration
```python


"""
Kaggle: Intro to Machine Learning
Tutorial: Your First Machine Learning Model
Author: Dan Becker
Description: This script demonstrates how to load house data, 
select features, and build a Decision Tree model to predict prices.
"""

import pandas as pd
from sklearn.tree import DecisionTreeRegressor

# STEP 1: Load the data
# We use pandas to read a CSV file containing housing data.
# For this tutorial, the Melbourne housing dataset is typically used.
melbourne_file_path = '../input/melbourne-housing-snapshot/melb_data.csv'
data = pd.read_csv(melbourne_file_path)

# STEP 2: Filter and Clean Data
# In this specific tutorial, we handle missing values by dropping any rows 
# that have 'NaN' (not available) values to keep the first model simple.
data = data.dropna(axis=0)

# STEP 3: Selecting the Prediction Target (y)
# The 'target' is the column we want the model to predict. 
# In this case, it is the 'Price' of the house.
y = data.Price

# STEP 4: Choosing "Features" (X)
# Features are the columns used to determine the house price. 
# We create a list of column names to be used as predictors.
melbourne_features = [
    'Rooms', 
    'Bathroom', 
    'Landsize', 
    'Lattitude', 
    'Longtitude'
]

# We select the data corresponding to these features and store it in X.
X = data[melbourne_features]

# --- Quick Data Review ---
# It's good practice to verify the data before modeling.
print("Reviewing the first few rows of X (features):")
print(X.head())
print("\nDescriptive statistics for X:")
print(X.describe())

# STEP 5: Define and Fit the Model
# 5.1 Define: We specify the type of model (DecisionTreeRegressor).
# We use 'random_state=1' to ensure that we get the same results 
# every time the code is run (important for reproducibility).
melbourne_model = DecisionTreeRegressor(random_state=1)

# 5.2 Fit: This is where the model "learns" patterns from the data.
# We provide the features (X) and the target prices (y).
melbourne_model.fit(X, y)

# STEP 6: Make Predictions
# Now that the model is trained, we can use it to predict prices.
# Usually, you'd predict on new data, but here we predict for 
# the first few rows of the training data to see how it works.
print("\nMaking predictions for the following 5 houses:")
print(X.head())

print("\nThe predictions are:")
predictions = melbourne_model.predict(X.head())
print(predictions)

# Comparing predictions to actual values
print("\nActual target values (Prices):")
print(y.head().tolist())

```

```
