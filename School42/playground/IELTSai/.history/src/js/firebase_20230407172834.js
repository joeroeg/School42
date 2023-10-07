var admin = require("firebase-admin");

var serviceAccount = require("/home/device/Documents/IELTSai/src/ielts-ai-1-firebase-adminsdk-qwj0m-45c0c9d957.json");

admin.initializeApp({
  credential: admin.credential.cert(serviceAccount)
});

const db = admin.firestore(); // or admin.database() for Realtime Database

module.exports = { admin, db };
