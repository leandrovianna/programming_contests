package main

import "fmt"

func main() {
	var x, y int
	x, y = 10, 10

	for x > 0 && y > 0 {
		fmt.Scan(&x, &y)

		if x > 0 && y > 0 {
			if x > y {
				x, y = y, x
			}

			sum := 0
			for i := x; i <= y; i++ {
				sum += i
				fmt.Printf("%d ", i)
			}

			fmt.Printf("Sum=%d\n", sum)
		}
	}
}
