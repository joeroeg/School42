import numpy as np
import dash
from dash import dcc, html
from dash.dependencies import Input, Output
import plotly.graph_objects as go
from noise import pnoise3

# Function to generate cloud
def generate_cloud(size, scale, octaves, threshold):
    cloud = np.zeros((size, size, size))
    for x in range(size):
        for y in range(size):
            for z in range(size):
                cloud[x, y, z] = pnoise3(x / scale, y / scale, z / scale, octaves, 0.5, 2.0)
    cloud_normalized = (cloud - cloud.min()) / (cloud.max() - cloud.min())
    x, y, z = np.indices(cloud_normalized.shape)
    x, y, z = x.flatten(), y.flatten(), z.flatten()
    values = cloud_normalized.flatten()
    mask = values > threshold
    return x[mask], y[mask], z[mask], values[mask]

# Initialize Dash app
app = dash.Dash(__name__)

# App layout
app.layout = html.Div(id="app-container", children=[
    html.Div([
        html.Button("Toggle Night Mode", id="night-mode-button", n_clicks=0),
    ], style={'textAlign': 'center', 'margin': '20px'}),

    dcc.Graph(id='cloud-visualization'),

    dcc.Slider(
        id='scale-slider',
        min=5,
        max=50,
        step=0.1,
        value=20,
        marks={5: '5', 50: '50'}
    ),

    dcc.Interval(id='slider-interval', interval=500, n_intervals=0),
])

# Callback to update the visualization and toggle night mode
@app.callback(
    Output('cloud-visualization', 'figure'),
    Output("app-container", "style"),
    [Input('scale-slider', 'value'),
     Input('night-mode-button', 'n_clicks')]
)
def update_cloud(scale, n_clicks):
    is_night_mode = n_clicks % 2 == 1

    # Generate cloud data
    x, y, z, values = generate_cloud(size=32, scale=scale, octaves=4, threshold=0.5)

    # Define Plotly theme template
    theme_template = "plotly_dark" if is_night_mode else "plotly"

    # Create figure
    fig = go.Figure(data=go.Scatter3d(
        x=x, y=y, z=z, mode='markers',
        marker=dict(size=2, color=values, colorscale='Plasma', opacity=0.8)
    ))
    fig.update_layout(
        template=theme_template,
        scene=dict(xaxis_title="X", yaxis_title="Y", zaxis_title="Z")
    )

    # Update app background color
    app_style = {
        "backgroundColor": "#111111" if is_night_mode else "#FFFFFF",
        "color": "#FFFFFF" if is_night_mode else "#000000",
        "padding": "20px",
        "minHeight": "100vh"
    }

    return fig, app_style

if __name__ == '__main__':
    app.run_server(debug=True)
