#-*-coding:utf-8-*-
import time
import numba


@numba.jit
def is_prime(n):
    i = 2
    while i < n:
        if n % i == 0:
            return False
        i += 1
    return True


def test():
    prime_num = 0
    t1 = time.clock()
    for i in range(2, 100000):
        if is_prime(i):
            prime_num += 1
    t2 = time.clock()
    print ("time cost:{}s, prime_num:{}".format(t2-t1, prime_num))


if __name__ == '__main__':
    test()