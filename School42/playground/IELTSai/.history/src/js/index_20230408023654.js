import { db } from "./firebase.js";
import { addDoc, collection } from "firebase/firestore";

const essayForm = document.getElementById("essay-form");
const essayText = document.getElementById("essay-text");
const handleCheckButtonClick = document.getElementById("check-button");

console.log("Script loaded");

async function handleCheckButtonClick.addEventListener("click", async () => { 
    const essay = essayText.value;
    if (!essay) {
        console.log("Empty essay");
        return;
    }

    try {
        const docRef = await addDoc(collection(db, "essays"), {
            content: essay,
            timestamp: new Date(),
        });
        console.log("Essay saved with ID: ", docRef.id);
    } catch (e) {
        console.error("Error saving essay: ", e);
    }
});

async function handleCheckButtonClick() {
  console.log("Check Essay button clicked"); // Add this line

  const essay = essayText.value;
  if (!essay) return;

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
