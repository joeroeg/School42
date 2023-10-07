// Import the functions you need from the SDKs you need
import { initializeApp } from "./node_modules/firebase/app";
import { getFirestore } from "./node_modules/firebase/firestore";

const firebaseConfig = {
        "type": "service_account",
        "project_id": "ielts-ai-1",
        "private_key_id": "17403fb3be2477106c89a7e0d5e648816cb4474e",
        "private_key": "-----BEGIN PRIVATE KEY-----\nMIIEvQIBADANBgkqhkiG9w0BAQEFAASCBKcwggSjAgEAAoIBAQCgRQH4B+5bEIvl\nfa+mRC3v9ShrlYmqHEikVN/AvYeZ53LDED93bsWfEYi0Jl+2U3jaKlfnp/3HjKoQ\n5z5Ma1h1Mdfbo+/9GV+CkOxQZMzj3cS5YFxoODIn1vnAli+kKusQoqTcqqbVugFv\n+COEcEXaDIPDMsHG+Y72mACU57cU0OV3VonLocGTHUwfe2UQdLi9Wf1WZ2oGrk1q\nqtioncsfbuJxPt5cK8q3L1Zpfzc0ls2kFHl/VQMDKVsxWiRMVtotUz3KqfMXyCAv\nrXavydOiv9TwEYxbK2cwZBUjGRbyGnMHnpDFTaq86dgSqV7cqbSxlN6qqzmiC4y0\nFD/jCCJrAgMBAAECggEATP76JCvDQjKf0v/f6/PjUd2oro7n1TbDW1d/K3yicbj0\ntGvQ4dLw1Cu7TjkFUHWnoMAo/R0C2eRlK7u8fUAw/hSVDGsk96ZB8VsofLMAkBRR\n13FI07Tzu5oW4IQGnUsVJSfOJklB33n+CMngXlcF5+yNPLDc0XfBTAzYcrEjjrbN\nWs4uqL3xy4u/6DjXCSJtXWTQLjR1PiI29su2N3HlxPeOez2Ro2g/g7IZHxvWqX9J\nxHkIpLCpwBN3kDaEPBHfIR1gFU8FPBgCOKp6JphOcm8mJ4lJEJcl+ksLchPq3uLS\nSXzPYyRd+QoxX7jwM5eYidEbfdUmkueHNCwAUfnFcQKBgQDhXgzwKj7ekIbaChI1\nUgBbe0ovt9lGIwi7exDEE0c5qC0Ys3pDMV6bqy8opw09qK4y8NEi3IoqaXVSAu6l\nM5GdslVtQNhQ7iqfXFx+ddB4sT88GT2ZsnwiDsHdA3rg5Gw8RDTOYVrYCjawk9/4\ntrI+zMRCtgY21s6v4DmBprFsowKBgQC2DctS+2XoNbnw90ODn0CwSrQQ82lq6E9m\nAT2G2maVkrIrSe93AFfU7tzkbw4z8p40bqok3oLRw7SbowxaizYdhKvUXtzblOyf\nPMzip5tWe0yagjC1OzeahrM060CZ3H3I/ogjIbmGInUD0VhKkn+7jCiuHMHKdGpn\nFDVhw39HmQKBgQDHkPNAEQjPKYhguB5bnRu35rtQ+iqq0wc+jcHQ/4lI40Xb48LW\nkXdHvhTqmNM+0IpBjcKEbmrjF7PORc5x9/JwhKTlNFDZia2wpKc7TLSoy7xFScyk\nt8r4lbzSK+y6DUxTKcrhHpDFUnYPc0MYCSBaQBVjRbDHCvzH/XSu/J+MpQKBgCHJ\nj5m4BKLDDd5V1ZbhAH13b9HRixgHQ20X/9Y+RFmwHxb/oszAKIzhQ+e1YLptZcUv\nYK51CWxq2OMlsI5BVerGi6lfbbfm/L9U5mWOW7sCKSZn0ShhdCFerHW+z39+t22N\nJ7D1elwVmwf5W1yDsecZzRb7SVAMqQ62Zm3dfYrJAoGAEIUTBjIsSww2GBRYCib8\ntTTlskCpyCSPWjGmmCIAYd2XE/PZXVxBIQ9EkkS2JUyWTG4mbzrTdyl5XDrb0lOM\nZupT3QIR0LVeu79mSbf5HAouBsfwuhp52FlBaROfkyKTLyCyskJzEHj48il04Ptg\noJ7+l6pKJ0XlnN4SL12WFks=\n-----END PRIVATE KEY-----\n",
        "client_email": "firebase-adminsdk-qwj0m@ielts-ai-1.iam.gserviceaccount.com",
        "client_id": "100867186921822115701",
        "auth_uri": "https://accounts.google.com/o/oauth2/auth",
        "token_uri": "https://oauth2.googleapis.com/token",
        "auth_provider_x509_cert_url": "https://www.googleapis.com/oauth2/v1/certs",
        "client_x509_cert_url": "https://www.googleapis.com/robot/v1/metadata/x509/firebase-adminsdk-qwj0m%40ielts-ai-1.iam.gserviceaccount.com"
};

// Initialize Firebase
const app = initializeApp(firebaseConfig);

const db = getFirestore(app);

export { db };
