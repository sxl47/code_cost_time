#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

int is_prime(long n) {
    long i = 2L;
    while (i < n) {
        if (n % i == 0) {
            return 0;
        }
        i += 1;
    }
    return 1;
}

uint64_t elapsed(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);
}

int main() {
    int prime_num = 0;

    struct timeval start, end;

    gettimeofday(&start, 0);

    for (long i = 0; i < 100000; i ++) {
        if (is_prime(i)) {
            prime_num += 1;
        }
    }
    gettimeofday(&end, 0);

    uint64_t elapsed_time = elapsed(start, end);

    printf("time cost:%fs, prime_num:%ld\n", elapsed_time/1000000.0, prime_num);

    return 0;
}