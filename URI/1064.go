package main

import "fmt"

func main() {
	const N = 6

	var x, count, sum = 0.0, 0, 0.0
	for i := 0; i < N; i++ {
		fmt.Scan(&x)
		if x > 0 {
			sum += x
			count++
		}
	}

	fmt.Printf("%d valores positivos\n", count)
	fmt.Printf("%.1f\n", sum/float64(count))
}
