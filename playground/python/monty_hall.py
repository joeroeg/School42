import random

def monty_hall_simulation(trials=10000000):
    stick_wins = 0
    switch_wins = 0
    doors = 1000

    for _ in range(trials):
        # Step 1: Randomly place the prize behind one of 3 doors
        prize_door = random.randint(1, doors)

        # Step 2: Contestant randomly picks a door
        contestant_choice = random.randint(1, doors)

        # Step 3: Host opens a door that isn't the prize or contestant's choice
        remaining_doors = [door for door in range(1, doors) if door != contestant_choice and door != prize_door]
        host_choice = random.choice(remaining_doors)

        # Step 4: Determine the door the contestant would switch to
        switch_choice = [door for door in range(1, doors) if door != contestant_choice and door != host_choice][0]

        # Step 5: Check outcomes
        if contestant_choice == prize_door:  # Sticking wins
            stick_wins += 1
        if switch_choice == prize_door:  # Switching wins
            switch_wins += 1

    # Results
    print(f"Stick wins: {stick_wins} ({stick_wins / trials * 100:.2f}%)")
    print(f"Switch wins: {switch_wins} ({switch_wins / trials * 100:.2f}%)")

# Run the simulation
monty_hall_simulation()
