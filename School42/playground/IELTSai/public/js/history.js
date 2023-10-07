async function fetchEssayHistory() {
  const response = await fetch('/api/essays');
  const essays = await response.json();

  // Update the UI with the essay history data
}

fetchEssayHistory();
  
  function displayEssays(essays) {
    const essayList = document.getElementById('essayList');
  
    essays.forEach((essay, index) => {
      const row = `
        <tr>
          <th scope="row">${index + 1}</th>
          <td>${essay.title}</td>
          <td>${new Date(essay.date).toLocaleDateString()}</td>
          <td><a href="essay/${essay.id}">View</a></td>
        </tr>
      `;
  
      essayList.insertAdjacentHTML('beforeend', row);
    });
  }
  
  // Call the fetchEssayHistory function when the page loads
  fetchEssayHistory();

  async function saveEssay(title, content) {
    const response = await fetch('/api/essays', {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
      },
      body: JSON.stringify({ title, content }),
    });
  
    const essay = await response.json();
  
    // Update the UI with the saved essay data
  }
  