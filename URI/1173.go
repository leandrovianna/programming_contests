package main

import "fmt"

func main() {
	const N = 10
	var x [N]int
	var n int

	fmt.Scan(&n)

	x[0] = n

	for i := 1; i < N; i++ {
		x[i] = 2 * x[i-1]
	}

	for i := 0; i < N; i++ {
		fmt.Printf("N[%d] = %d\n", i, x[i])
	}
}
