from dash import Dash, html
import dash_mantine_components as dmc
from dash import Dash, _dash_renderer
_dash_renderer._set_react_version("18.2.0")

app = Dash(external_stylesheets=dmc.styles.ALL)

app.layout = dmc.MantineProvider(
    children=html.Div(
        [
            dmc.Text("Your content here"),
            # Add more components as needed
        ]
    )
)

if __name__ == "__main__":
    app.run_server(debug=True)
