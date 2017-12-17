package main

import "fmt"

func main() {
	const N = 20
	var x [N]int

	for i := 0; i < N; i++ {
		fmt.Scan(&x[i])
	}

	for i := 0; i < N/2; i++ {
		x[i], x[N-i-1] = x[N-i-1], x[i]
	}

	for i := 0; i < N; i++ {
		fmt.Printf("N[%d] = %d\n", i, x[i])
	}
}
