package main

import "fmt"

func isPrime(x int) bool {
	for i := 2; i*i <= x; i++ {
		if x%i == 0 {
			return false
		}
	}

	return true
}

func main() {
	var n, x int

	for fmt.Scan(&n); n > 0; n-- {
		fmt.Scan(&x)

		if isPrime(x) {
			fmt.Printf("%d eh primo\n", x)
		} else {
			fmt.Printf("%d nao eh primo\n", x)
		}
	}
}
