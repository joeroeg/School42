const express = require('express');
const cors = require('cors');
const dotenv = require('dotenv');
const axios = require('axios');
const { db } = require('../public/js/firebase.js');
// Load environment variables from .env file
dotenv.config();

// Create Express app
const app = express();

// Middleware
app.use(cors());
app.use(express.json());

// API routes

// Add an API route for essay checking
app.post('/api/check-essay', async (req, res) => {
  const essay = req.body.essay;

  if (!essay) {
    return res.status(400).json({ error: 'Essay text is required' });
  }

  try {
    // Call the external API with the essay text
    const response = await axios.post('https://api.example.com/analyze', {
      text: essay,
      apiKey: process.env.API_KEY,
    });

    // Process the external API response and send it back to the frontend
    const results = processApiResponse(response.data);
    res.json(results);
  } catch (error) {
    res.status(500).json({ error: 'An error occurred while processing the essay' });
  }
});

// Add a route to save essays
app.post('/api/essays', async (req, res) => {
  try {
    const { title, content } = req.body;

    const essayRef = db.collection('essays').doc();
    await essayRef.set({
      title,
      content,
      createdAt: new Date(),
    });

    res.status(201).json({ id: essayRef.id, title, content });
  } catch (error) {
    console.error(error);
    res.status(500).json({ error: 'Failed to save essay' });
  }
});

// Add a route to fetch all essays
app.get('/api/essays', async (req, res) => {
  try {
    const essaysRef = db.collection('essays');
    const snapshot = await essaysRef.get();

    const essays = [];
    snapshot.forEach((doc) => {
      essays.push({ id: doc.id, ...doc.data() });
    });

    res.status(200).json(essays);
  } catch (error) {
    console.error(error);
    res.status(500).json({ error: 'Failed to fetch essays' });
  }
});

// Helper function to process API response
function processApiResponse(data) {
  // Process the external API response and extract relevant information
  // (e.g., errors and suggestions)

  // Example: Extract errors and suggestions from LanguageTool API response
  const results = data.matches.map((match) => {
    return {
      type: match.rule.issueType,
      description: match.message,
      line: match.context.offset,
      column: match.context.length,
    };
  });

  return results;
}

// Start the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, () => {
  console.log(`Server started on port ${PORT}`);
});
