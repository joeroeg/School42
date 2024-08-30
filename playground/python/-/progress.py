import random
import time

BAR = chr(9608)

def get_progress_bar(progress, total, bar_width=40):
    """Returns a string that represents a progress bar."""
    progressBar = '|'
    progressBar += BAR * int((progress / total) * bar_width)
    progressBar += ' ' * (bar_width - int((progress / total) * bar_width))
    progressBar += '|'
    progressBar += ' ' + str(round(progress / total * 100, 1)) + '%'
    progressBar += ' ' + str(progress) + '/' + str(total)
    return progressBar

def main():
    print('Progress Bar Simulation')
    bytes_downloaded = 0
    download_size = 4096
    while bytes_downloaded < download_size:
        bytes_downloaded += random.randint(0, 100)
        bar_str = get_progress_bar(bytes_downloaded, download_size)
        print(bar_str, end='', flush=True)
        time.sleep(0.2)
        print('\b' * len(bar_str), end='', flush=True)

if __name__ == '__main__':
    main()
