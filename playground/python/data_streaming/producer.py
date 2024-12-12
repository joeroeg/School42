from kafka import KafkaProducer
import json
import time
from random import randint, uniform

producer = KafkaProducer(bootstrap_servers='localhost:9092',
                         value_serializer=lambda v: json.dumps(v).encode('utf-8'))

def generate_data():
    return {
        "device_id": f"device_{randint(1, 1000)}",
        "timestamp": time.time(),
        "temperature": round(uniform(-10, 40), 2),
        "status": "online" if randint(0, 1) else "offline",
        "location": {"lat": uniform(-90, 90), "lon": uniform(-180, 180)}
    }

while True:
    data = generate_data()
    producer.send('iot', value=data)
    # Save the data to a file for later use
    with open("data.json", "a") as f:
        f.write(json.dumps(data) + "\n")
