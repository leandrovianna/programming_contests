package main

import "fmt"
import "math"

func exp(x, y int) int {
	r := int(math.Pow(float64(x), float64(y)))
	return r
}

func main() {
	var n int

	fmt.Scan(&n)

	for i := 1; i <= n; i++ {
		a := make([]int, 3)
		for j := 1; j <= 3; j++ {
			a[j-1] = exp(i, j)
			fmt.Print(a[j-1])
			if j == 3 {
				fmt.Print("\n")
			} else {
				fmt.Print(" ")
			}
		}

		fmt.Printf("%d %d %d\n", a[0], a[1]+1, a[2]+1)
	}
}
