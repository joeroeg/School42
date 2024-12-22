from load_csv import load_csv
import matplotlib.pyplot as plt
import pandas as pd


def main():
    """Plot life expectancy in Canada."""
    df = load_csv('life_expectancy_years.csv')

    country = "Canada"
    country_data = df[df['country'] == country].set_index('country')

    transposed = country_data.transpose()
    transposed.reset_index(inplace=True)
    transposed.columns = ['year', 'life_expectancy_years']

    transposed['year'] = pd.to_numeric(transposed['year'])

    plt.plot(transposed['year'], transposed['life_expectancy_years'])
    plt.xlabel('Year')
    plt.ylabel('Life expectancy')
    plt.title(f'{country} life expectancy Projections')
    plt.show()


if __name__ == '__main__':
    main()
