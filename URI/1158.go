package main

import "fmt"

func main() {
	var n int
	var x, y int

	fmt.Scan(&n)

	for ; n > 0; n-- {
		fmt.Scan(&x, &y)

		if x%2 == 0 {
			x++
		}

		sum := 0
		for i := 0; i < y; i++ {
			sum += x
			x += 2
		}

		fmt.Println(sum)
	}
}
