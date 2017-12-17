package main

import "fmt"

func input(x *int) bool {
	fmt.Scan(x)
	return *x != 0
}

func main() {
	var x int

	for input(&x) {
		if x%2 != 0 {
			x++
		}

		sum := 0
		for i := 0; i < 5; i++ {
			sum += x
			x += 2
		}

		fmt.Println(sum)
	}
}
