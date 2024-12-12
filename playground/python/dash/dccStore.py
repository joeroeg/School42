import dash
from dash import dcc, html, Input, Output, State
import pandas as pd

# Sample CSV file paths
csv_file1 = "data1.csv"
csv_file2 = "data2.csv"

# Load the data from CSVs into pandas DataFrames
df1 = pd.read_csv(csv_file1)
df2 = pd.read_csv(csv_file2)

# Combine the data (you can adjust this depending on your needs)
combined_data = pd.merge(df1, df2, on="IP")

# Create the Dash app
app = dash.Dash(__name__)

app.layout = html.Div([
    dcc.Store(id="data-store", data=combined_data.to_dict("records")),  # Store the combined data
    html.Button("Load Data", id="load-button"),
    html.Div(id="output-div")
])

# Callback to display stored data
@app.callback(
    Output("output-div", "children"),
    Input("load-button", "n_clicks"),
    State("data-store", "data")
)
def display_data(n_clicks, data):
    if n_clicks:
        df = pd.DataFrame(data)
        return html.Pre(df.to_string(index=False))
    return "Click the button to load data."

if __name__ == "__main__":
    app.run_server(debug=True)
