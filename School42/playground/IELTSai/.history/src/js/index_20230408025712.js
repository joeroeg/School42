import { db } from "./firebase.js";
import { addDoc, collection } from "firebase/firestore";

const essayForm = document.getElementById("essay-form");
const essayText = document.getElementById("essay-text");
const handleCheckButtonClick = document.getElementById("check-button");

console.log("Script loaded");
document.getElementById("check-button")
    .addEventListener("click", () => {
handleCheckButtonClick.addEventListener("click", async () => { 
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