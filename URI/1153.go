package main

import "fmt"

func factorial(n int) int {
	if n < 2 {
		return 1
	} else {
		return n * factorial(n-1)
	}
}

func main() {
	var n int

	fmt.Scan(&n)

	fmt.Println(factorial(n))
}
