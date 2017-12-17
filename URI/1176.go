package main

import "fmt"

func main() {
	const N = 61
	var fib [N]uint64

	fib[0] = 0
	fib[1] = 1
	for i := 2; i < N; i++ {
		fib[i] = fib[i-1] + fib[i-2]
	}

	var t, n int

	for fmt.Scan(&t); t > 0; t-- {
		fmt.Scan(&n)

		fmt.Printf("Fib(%d) = %v\n", n, fib[n])
	}
}
