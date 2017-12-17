package main

import "fmt"

func main() {
	const N = 1000
	var x [N]int
	var t int

	fmt.Scan(&t)

	k := 0
	for i := 0; i < N; i++ {
		x[i] = k
		k = (k + 1) % t
	}

	for i := 0; i < N; i++ {
		fmt.Printf("N[%d] = %d\n", i, x[i])
	}
}
