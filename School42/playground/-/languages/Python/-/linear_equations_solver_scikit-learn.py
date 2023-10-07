from sklearn.linear_model import LinearRegression

# Input data X and target values y
X = [[1], [2], [3]]
y = [2, 3, 4]

# Create a linear regression model
model = LinearRegression()

# Fit the model to the data
model.fit(X, y)

# Get coefficients (slope and intercept)
slope = model.coef_[0]
intercept = model.intercept_

print("Slope:", slope)
print("Intercept:", intercept)
