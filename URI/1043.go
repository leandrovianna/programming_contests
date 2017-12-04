//URI Online Judge - Triangulo - 1043
package main

import "fmt"

func main() {
	var a, b, c float64
	fmt.Scan(&a, &b, &c)

	if a < b+c && b < a+c && c < a+b {
		perimetro := a + b + c
		fmt.Printf("Perimetro = %.1f\n", perimetro)
	} else {
		area := c * (a + b) / 2
		fmt.Printf("Area = %.1f\n", area)
	}
}
