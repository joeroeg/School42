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
        "status": "online",
        "location": {"lat": uniform(-90, 90), "lon": uniform(-180, 180)}
    }

while True:
    data = generate_data()
    producer.send('iot', value=data)
    print(f"Produced: {data}")
    time.sleep(0.1)  # Adjust frequency as needed
