//URI - Seis Numeros Impares - 1070
package main

import "fmt"

func main() {
	const N int = 6
	var x int

	fmt.Scan(&x)

	if x%2 == 0 {
		x = x + 1
	}

	for i := 0; i < N; i++ {
		fmt.Println(x)
		x += 2
	}
}
