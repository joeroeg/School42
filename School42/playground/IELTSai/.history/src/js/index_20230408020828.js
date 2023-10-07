import { db } from "./firebase";
import { addDoc, collection } from "firebase/firestore";

const essayForm = document.getElementById("essay-form");
const essayText = document.getElementById("essay-text");
const checkButton = document.getElementById("check-button");

checkButton.addEventListener("click", async () => {
    const essay = essayText.value;
    if (!essay) return;

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
