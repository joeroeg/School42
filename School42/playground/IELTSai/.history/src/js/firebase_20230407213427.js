import firebase from 'firebase/app';
import 'firebase/firestore';

// Replace the following config object with your own Firebase project configuration
const firebaseConfig = {
  apiKey: '45c0c9d95739c761e790c73f34d2f9464f636df0',
  authDomain: 'YOUR_AUTH_DOMAIN',
  projectId: 'ielts-ai-1',
  storageBucket: 'YOUR_STORAGE_BUCKET',
  messagingSenderId: 'YOUR_MESSAGING_SENDER_ID',
  appId: 'YOUR_APP_ID',
};

firebase.initializeApp(firebaseConfig);

const db = firebase.firestore();

export { db };
