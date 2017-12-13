package main

import "fmt"

func main() {
	var x, y int

	fmt.Scan(&x, &y)

	k := 1
	for i := 0; i < y/x; i++ {
		for j := 0; j < x; j++ {
			fmt.Print(k)
			k++

			if j == x-1 {
				fmt.Print("\n")
			} else {
				fmt.Print(" ")
			}
		}
	}
}
