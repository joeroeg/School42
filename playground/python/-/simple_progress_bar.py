import time

def simple_progress_bar(total):
    for i in range(total):
        progress = (i + 1) / total
        bar = '█' * int(progress * 20)
        print(f'\r{bar:<20} {int(progress * 100)}%', end='', flush=True)
        time.sleep(0.1)
    print()

simple_progress_bar(50)
