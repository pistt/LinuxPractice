long long sum(long long n) {
	if (n == 1) return 1;
	return n + sum(n -1);
}
