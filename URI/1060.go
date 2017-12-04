package main

import "fmt"

func main() {
	const N = 6

	var x, count = 0.0, 0
	for i := 0; i < N; i++ {
		fmt.Scan(&x)
		if x > 0 {
			count++
		}
	}

	fmt.Printf("%d valores positivos\n", count)
}
