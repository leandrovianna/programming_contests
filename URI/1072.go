//URI - Intervalo 2 - 1072
package main

import "fmt"

func main() {
	var n, x int

	fmt.Scan(&n)

	in, out := 0, 0
	for i := 0; i < n; i++ {
		fmt.Scan(&x)

		if 10 <= x && x <= 20 {
			in++
		} else {
			out++
		}
	}

	fmt.Printf("%d in\n%d out\n", in, out)
}
