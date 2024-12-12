from kafka import KafkaConsumer
import json

# Kafka consumer setup
consumer = KafkaConsumer(
    'iot-data',  # Replace with your topic name
    bootstrap_servers='localhost:9092',
    auto_offset_reset='earliest',
    group_id='iot',  # Group ID for this consumer
    value_deserializer=lambda v: json.loads(v.decode('utf-8'))
)

# Consuming messages
print("Listening for messages...")
try:
    for message in consumer:
        print(f"Consumed: {message.value}")
except KeyboardInterrupt:
    print("Stopped consuming messages.")
