package main

import "fmt"

func main() {
	var x, y int

	fmt.Scan(&x, &y)

	if x > y {
		x, y = y, x
	}

	sum := 0
	for i := x; i <= y; i++ {
		if i%13 != 0 {
			sum += i
		}
	}

	fmt.Println(sum)
}
