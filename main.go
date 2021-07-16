package main

import (
	"fmt"
	"time"
)

func is_prime(n int) bool {
	/* 声明局部变量 */
	var i = 2

	for i < n {
		if n%i == 0 {
			return false
		}
		i++
	}
	return true
}

func main() {
	t1 := time.Now()
	prime_num := 0
	count := 100000
	fori := 0; i < count; i++ {
		if is_prime(i) {
			prime_num++
		}
	}
	t2 := time.Since(t1)
	fmt.Println("time cost:", t2, "prime_num:", prime_num)
}
