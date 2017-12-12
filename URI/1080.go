package main

import "fmt"

func main() {
	const N int = 100

	var max, maxi, x int = 0, 0, 0

	for i := 1; i <= N; i++ {
		fmt.Scan(&x)
		if x > max {
			max = x
			maxi = i
		}
	}

	fmt.Println(max)
	fmt.Println(maxi)
}
