// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getFirestore } from "firebase/firestore";

// Your web app's Firebase configuration
const firebaseConfig = {
  apiKey: "AIzaSyAlGITBYPhDwIful0nmjcJYaQkhhYTjkgw",
  authDomain: "ielts-ai-1.firebaseapp.com",
  databaseURL: "https://ielts-ai-1-default-rtdb.firebaseio.com",
  projectId: "ielts-ai-1",
  storageBucket: "ielts-ai-1.appspot.com",
  messagingSenderId: "222054530806",
  appId: "1:222054530806:web:b26f305f171bd6c11d76d7"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);

const db = getFirestore(app);

export { db };
