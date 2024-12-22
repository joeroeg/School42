from load_csv import load_csv

try:
    print(load_csv('life_expectancy_years.csv'))
except Exception as e:
    print(e)
