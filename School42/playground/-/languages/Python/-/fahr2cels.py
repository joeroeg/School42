def main():
    lower = 0
    upper = 300
    step = 20
    fahr = lower

    while fahr <= upper:
        celsius = (5.0/9.0) * (fahr-32.0)
        print(f"{fahr:4.0f} {celsius:6.1f}")
        fahr = fahr + step

if __name__ == "__main__":
    main()
