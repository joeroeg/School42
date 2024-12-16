(function testLocalStorageLimit() {
    let size = 0;
    const testKey = 'test';
    try {
        while (true) {
            localStorage.setItem(testKey + size, 'a'.repeat(1024)); // 1 KB per item
            size++;
        }
    } catch (e) {
        console.log(`Local storage limit reached: ${size} KB (${(size / 1024).toFixed(2)} MB)`);
        localStorage.clear(); // Cleanup after test
    }
})();

(function testLocalStorageLimit() {
    let size = 0;
    const testKey = 'test';
    try {
        while (true) {
            localStorage.setItem(testKey + size, 'a'.repeat(1024)); // 1 KB per item
            size++;
        }
    } catch (e) {
        console.log(`Local storage limit reached: ${size} KB (${(size / 1024).toFixed(2)} MB)`);
        localStorage.clear(); // Cleanup after test
    }
})();
