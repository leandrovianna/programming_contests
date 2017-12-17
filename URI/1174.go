package main

import "fmt"

func main() {
	const N = 100
	var x [N]float64

	for i := 0; i < N; i++ {
		fmt.Scan(&x[i])
	}

	for i := 0; i < N; i++ {
		if x[i] <= 10 {
			fmt.Printf("A[%d] = %.1f\n", i, x[i])
		}
	}
}
