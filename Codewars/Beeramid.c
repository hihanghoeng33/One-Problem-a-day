int beeramid(double bonus, double price) {
    int res = bonus / price;
    int n = 1;
    int level = 0;
    while (level <= res) {
        level = (n * (n + 1) * (2 * n + 1)) / 6; 
        n++;
    }
    return n - 2; 
}
