package main

import "fmt"

func main() {
	const N = 5
	var x, count int

	for i := 0; i < N; i++ {
		fmt.Scan(&x)
		if x&1 == 0 {
			count++
		}
	}

	fmt.Printf("%d valores pares\n", count)
}
