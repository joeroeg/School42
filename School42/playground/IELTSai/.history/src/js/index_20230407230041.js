import * as Grammarly from '@grammarly/editor-sdk';
import { db } from './firebase';

let grammarlyInstance;

async function initializeGrammarly(textarea) {
  grammarlyInstance = await Grammarly.init('client_K9LVnuRNq4DTZZnbrdQzdH');
}
const editor = document.querySelector("grammarly-editor-plugin");
editor.config = {underlines: "off"};

const essayForm = document.getElementById('essay-form');
const essayText = document.getElementById('essay-text');
const checkButton = document.getElementById("check-button");

async function handleCheckButtonClick() {
    const essay = essayText.value;
    if (!essay) return;
  
    // Save essay to the database
    await saveEssay(essay);

    // Call a function to handle the backend request
    const response = await checkEssay(essay);
  
    // Process and display the response (e.g., show errors and suggestions)
    displayResults(response);

    // Configure the Grammarly plugin to turn off underlines
    const editor = document.querySelector("grammarly-editor-plugin");
    editor.config = {
      underlines: "off"
    };
  
    // Copy the essay content to the Grammarly-enabled textarea and display it
    grammarlyText.value = essay;
    grammarlyWrapper.style.display = 'block';
    essayText.style.display = 'none';
  }
  

async function checkEssay(essay) {
    try {
        const response = await fetch('/api/check-essay', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ essay }),
        });

        if (!response.ok) {
            throw new Error('An error occurred while checking the essay');
        }

        const data = await response.json();
        return data;
    } catch (error) {
        console.error('Error: ', error);
    }
}

function displayResults(results) {
    // Clear previous results
    results.innerHTML = '';

    if (!results || results.length === 0) {
        results.innerHTML = '<p class="text-center">No errors found.</p>';
        return;
    }

    // Create a list to display errors and suggestions
    const ul = document.createElement('ul');
    ul.classList.add('list-group');

    results.forEach((result) => {
        const li = document.createElement('li');
        li.classList.add('list-group-item');
        li.textContent = `${result.type}: ${result.description} (Line: ${result.line}, Column: ${result.column})`;
        ul.appendChild(li);
    });

    results.appendChild(ul);
}