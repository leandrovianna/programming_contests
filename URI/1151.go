package main

import "fmt"

func main() {
	var n1, n2, n int

	n1 = 0
	n2 = 1

	fmt.Scan(&n)

	fmt.Print(n1)
	if n > 1 {
		fmt.Printf(" %d ", n2)
	}

	for i := 2; i < n; i++ {
		n1, n2 = n2, n1+n2
		fmt.Print(n2)

		if i != n-1 {
			fmt.Print(" ")
		}
	}

	fmt.Print("\n")
}
