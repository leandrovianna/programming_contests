package main

import "fmt"

func main() {
	var n, x, y int

	for fmt.Scan(&n); n > 0; n-- {
		fmt.Scan(&x, &y)

		sum := 0
		if x > y {
			x, y = y, x
		}

		for i := x + 1; i < y; i++ {
			if i%2 == 1 {
				sum += i
			}
		}
		fmt.Println(sum)
	}
}
