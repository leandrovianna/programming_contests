package main

import "fmt"

func main() {
	const N = 10
	var x [N]int

	for i := 0; i < N; i++ {
		fmt.Scan(&x[i])

		if x[i] <= 0 {
			x[i] = 1
		}
	}

	for i := 0; i < N; i++ {
		fmt.Printf("X[%d] = %d\n", i, x[i])
	}
}
