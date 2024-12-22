from load_csv import load_csv
import matplotlib.pyplot as plt
import pandas as pd


def main():
    """Plot life expectancy from 1800 to 2050."""
    df_life = load_csv('life_expectancy_years.csv')
    df_gdp = load_csv('gdp.csv')
    year = 1900

    df_life_f = df_life[['country', str(year)]]
    df_life_f = df_life_f.set_index('country')
    df_gdp_filtered = df_gdp[['country', str(year)]]
    df_gdp_filtered = df_gdp_filtered.set_index('country')
    df_gdp_filtered = df_gdp_filtered.rename(columns={str(year): 'gdp'})
    df_life_f = df_life_f.rename(columns={str(year): 'life_expectancy'})
    df = pd.concat([df_gdp_filtered, df_life_f], axis=1, join='inner')
    df = df.reset_index()
    df = df.dropna()

    plt.figure(figsize=(12, 6))
    plt.scatter(df['gdp'], df['life_expectancy'])
    plt.title(year)
    plt.xlabel('Gross domestic product')
    plt.ylabel('Life expectancy')
    plt.show()


if __name__ == '__main__':
    main()
