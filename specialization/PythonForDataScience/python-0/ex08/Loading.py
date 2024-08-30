"""function that simulates a progress bar for an iterable object."""
import time
import shutil

"""
100%|███| 333/333 [00:01<00:00, 170.49it/s]

100%        - progress percentage
|███|       - progress bar
333/333     - current iteration
00:01       - elapsed time (ET)
00:00       - estimated time remaining (ETA)
170.49it/s  - iterations per second
"""


def ft_tqdm(lst: range):
    """This function simulates a progress bar for iterating through a range.

    tw = terminal width
    pw = progress width
    eta = estimated time remaining
    et = elapsed time
    ips = iterations per second
    """
    total_len = len(lst)
    start_time = time.time()
    tw = shutil.get_terminal_size().columns
    pw = tw - 40

    for i, item in enumerate(lst, start=1):
        et = time.time() - start_time
        try:
            ips = i / et
            eta = (total_len - i) / ips
        except ZeroDivisionError:
            ips = float('inf')
            eta = 0

        elapsed_formatted = time.strftime('%M:%S', time.gmtime(et))
        eta_formatted = time.strftime('%M:%S', time.gmtime(eta))

        progress = int((i / total_len) * pw)
        progress_bar = f"|{'█' * progress:<{pw}}|"
        progress_percentage = int((i / total_len) * 100) // 1

        progress_info = f"{progress_percentage}%{progress_bar} {i}/{total_len}"
        time_info = f"[{elapsed_formatted}<{eta_formatted}, {ips:.2f}it/s]"

        output = f"{progress_info} {time_info}"
        print(f"\r{output}", end="", flush=True)
        yield item

    print()

def main():
    """Main function."""
    for elem in ft_tqdm(range(333)):
        time.sleep(0.005)


if __name__ == '__main__':
    main()
