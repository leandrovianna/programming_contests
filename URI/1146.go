package main

import "fmt"

func main() {
	var n int

	for fmt.Scan(&n); n > 0; {
		for i := 1; i <= n; i++ {
			fmt.Print(i)
			if i != n {
				fmt.Print(" ")
			}
		}
		fmt.Print("\n")
		fmt.Scan(&n)
	}
}
