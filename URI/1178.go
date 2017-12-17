package main

import "fmt"

func main() {
	const N = 100
	var x [N]float64

	fmt.Scan(&x[0])

	for i := 1; i < N; i++ {
		x[i] = x[i-1] / 2
	}

	for i := 0; i < N; i++ {
		fmt.Printf("N[%d] = %.4f\n", i, x[i])
	}
}
