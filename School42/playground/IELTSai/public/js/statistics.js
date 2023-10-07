async function fetchErrorStatistics() {
    const response = await fetch('/api/error-statistics');
    const errorStats = await response.json();
  
    displayErrorStatistics(errorStats);
  }
  
  function displayErrorStatistics(errorStats) {
    const ctx = document.getElementById('errorChart').getContext('2d');
  
    const chart = new Chart(ctx, {
      type: 'bar',
      data: {
        labels: errorStats.categories,
        datasets: [
          {
            label: 'Error Count',
            data: errorStats.errorCounts,
            backgroundColor: 'rgba(75, 192, 192, 0.2)',
            borderColor: 'rgba(75, 192, 192, 1)',
            borderWidth: 1,
          },
        ],
      },
      options: {
        scales: {
          y: {
            beginAtZero: true,
          },
        },
      },
    });
  }
  
  // Call the fetchErrorStatistics function when the page loads
  fetchErrorStatistics();
  