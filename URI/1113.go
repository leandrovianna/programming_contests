package main

import "fmt"

func input(x, y *int) bool {
	fmt.Scan(x, y)
	return *x != *y
}

func main() {
	var x, y int
	x, y = 10, 11

	for input(&x, &y) {
		if x > y {
			fmt.Println("Decrescente")
		} else {
			fmt.Println("Crescente")
		}
	}
}
