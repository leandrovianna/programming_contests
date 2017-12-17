package main

import "fmt"

func s() float64 {

	var f float64 = 1.0

	for i := 2; i <= 39; i++ {
		f += float64(i+1) / float64(i)
	}

	return f
}

func main() {
	fmt.Printf("%.2f\n", s())
}
