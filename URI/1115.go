package main

import "fmt"

func input(x, y *int) bool {
	fmt.Scan(x, y)
	return *x != 0 && *y != 0
}

func main() {
	var x, y int

	for input(&x, &y) {
		if x > 0 && y > 0 {
			fmt.Println("primeiro")
		} else if x < 0 && y > 0 {
			fmt.Println("segundo")
		} else if x < 0 && y < 0 {
			fmt.Println("terceiro")
		} else {
			fmt.Println("quarto")
		}
	}
}
