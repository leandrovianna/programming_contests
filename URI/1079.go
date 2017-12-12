package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)

	for i := 0; i < n; i++ {
		var x, y, z float64

		fmt.Scan(&x, &y, &z)

		fmt.Printf("%.1f\n", x*0.2+y*0.3+z*0.5)
	}
}
