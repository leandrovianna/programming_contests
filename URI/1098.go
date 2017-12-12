package main

import "fmt"

func main() {
	for i := 0; i <= 20; i += 2 {
		for j := 10; j <= 30; j += 10 {
			x := float64(i) / 10.0
			y := float64(i+j) / 10.0
			fmt.Printf("I=%v J=%v\n", x, y)
		}
	}
}
