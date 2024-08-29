import time
import shutil

def format_time(seconds):
    """Format a time in seconds to a string in the format MM:SS."""
    return time.strftime("%M:%S", time.gmtime(seconds))


def ft_tqdm(lst: range) -> None:
    """Simulate a progress bar for an iterable."""
    start = time.time()
    total = len(lst)
    bar_length = 30
    for i, _ in enumerate(lst):
        progress = i / total
        elapsed = time.time() - start
        remaining = elapsed / progress - elapsed if progress > 0 else 0
        print(
            f"[{'=' * int(progress * bar_length):{bar_length}s}] "
            f"{progress * 100:.2f}% "
            f"({format_time(elapsed)}/{format_time(remaining)})", end="\r"
        )
        time.sleep(0.005)
    print()


def main():
    for _ in ft_tqdm(range(0, 333)):
        pass


if __name__ == "__main__":
    main()
