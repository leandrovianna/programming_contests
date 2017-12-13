package main

import "fmt"

func main() {
	var n, a, b int

	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		fmt.Scan(&a, &b)

		if b == 0 {
			fmt.Println("divisao impossivel")
		} else {
			fmt.Printf("%.1f\n", float64(a)/float64(b))
		}
	}
}
