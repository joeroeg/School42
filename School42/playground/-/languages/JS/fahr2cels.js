// print Fahrenheit-Celsius table
// for f = 0, 20, ..., 300

function main() {
    const lower = 0;
    const upper = 300;
    const step = 20;
    let fahr = lower;

    while (fahr <= upper) {
        const celsius = (5.0/9.0) * (fahr-32.0);
        console.log(`${fahr.toFixed(0).padStart(4)} ${celsius.toFixed(1).padStart(6)}`);
        fahr = fahr + step;
    }
}

main();
