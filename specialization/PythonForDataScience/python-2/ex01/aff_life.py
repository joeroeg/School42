from load_csv import load_csv
import matplotlib.pyplot as plt

df = load_csv('life_expectancy_years.csv')
print(df.dtypes)
# plt.plot(df['Year'], df['Life expectancy'])
# plt.xlabel('Year')
# plt.ylabel('Life expectancy')
# plt.title('Life expectancy')
# plt.show()
