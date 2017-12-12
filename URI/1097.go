package main

import "fmt"

func main() {
	var start = 5
	for i := 1; i <= 9; i += 2 {
		for j := start + 2; j >= start; j-- {
			fmt.Printf("I=%v J=%v\n", i, j)
		}
		start += 2
	}
}
