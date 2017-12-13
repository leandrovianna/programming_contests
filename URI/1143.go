package main

import "fmt"
import "math"

func main() {
	var n int

	fmt.Scan(&n)

	for i := 1; i <= n; i++ {
		for j := 1; j <= 3; j++ {
			fmt.Print(math.Pow(float64(i), float64(j)))
			if j == 3 {
				fmt.Print("\n")
			} else {
				fmt.Print(" ")
			}
		}
	}
}
