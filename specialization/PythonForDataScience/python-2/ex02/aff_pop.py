from load_csv import load_csv
import matplotlib.pyplot as plt
import pandas as pd


def main():
    """Plot life expectancy from 1800 to 2050."""
    df = load_csv('life_expectancy_years.csv')

    countries = ["Canada", "United States"]
    filtered_data = df[df['country'].isin(countries)]
    filtered_data = filtered_data.set_index('country')
    data = filtered_data.transpose()
    data.reset_index(inplace=True)
    data = data.rename(columns={'index': 'year'})
    data['year'] = pd.to_numeric(data['year'])
    start_year = 1800
    end_year = 2050
    data = data[(data['year'] >= start_year) & (data['year'] <= end_year)]

    plt.figure(figsize=(12, 6))

    for country in countries:
        plt.plot('year', country, data=data, label=country)

    plt.title('Life expectancy in Canada and the United States')
    plt.xlabel('Year')
    plt.ylabel('Life expectancy (years)')
    plt.legend()
    plt.show()


if __name__ == '__main__':
    main()
