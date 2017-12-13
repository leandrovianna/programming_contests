package main

import "fmt"

func main() {
	var a, n int

	fmt.Scan(&a)

	for fmt.Scan(&n); n <= 0; {
		fmt.Scan(&n)
	}

	sum := 0
	for i := 0; i < n; i++ {
		sum += i + a
	}

	fmt.Println(sum)
}
