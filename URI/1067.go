//URI - Numeros Impares - 1067
package main

import "fmt"

func main() {
	var x int

	fmt.Scan(&x)

	if x%2 == 0 {
		x = x - 1 //impar anterior
	}

	for i := 1; i <= x; i += 2 {
		fmt.Println(i)
	}
}
