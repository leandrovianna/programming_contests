package main

import "fmt"

func main() {
	var x, y int

	fmt.Scan(&x, &y)

	if x > y {
		x, y = y, x
	}

	for i := x + 1; i < y; i++ {
		r := i % 5
		if r == 2 || r == 3 {
			fmt.Println(i)
		}
	}
}
