//URI - Soma de Impares Consecutivos - 1071
package main

import "fmt"

func main() {
	var x, y, sum int
	fmt.Scan(&x, &y)

	if y < x {
		x, y = y, x
	}

	x++ // x nao esta incluso
	if x%2 == 0 {
		x++
	}

	y-- //y nao estao incluso
	if y%2 == 0 {
		y--
	}

	sum = 0
	for i := x; i <= y; i += 2 {
		sum += i
	}

	fmt.Println(sum)
}
