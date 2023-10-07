// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getFirestore } from "firebase/firestore";

// Your web app's Firebase configuration
const firebaseConfig = {
  // Your Firebase configuration
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);

// Get a Firestore instance
const db = getFirestore(app);

export { db };
