//URI - Quadrado de Pares - 1073
package main

import "fmt"

func main() {
	var n int64
	fmt.Scan(&n)

	if n%2 == 1 {
		n--
	}

	for i := int64(2); i <= n; i += 2 {
		fmt.Printf("%d^2 = %d\n", i, i*i)
	}
}
