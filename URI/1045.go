//URI Online Judge - Tipos de Triangulos - 1045
package main

import "fmt"

func swap(x, y *float64) {
	*x, *y = *y, *x
}

func main() {
	var a, b, c float64
	fmt.Scan(&a, &b, &c)

	if b > a {
		swap(&b, &a)
	}

	if c > a {
		swap(&c, &a)
	}

	a2, b2, c2 := a*a, b*b, c*c

	if a >= b+c {
		fmt.Println("NAO FORMA TRIANGULO")
	} else {
		if a2 == b2+c2 {
			fmt.Println("TRIANGULO RETANGULO")
		} else if a2 > b2+c2 {
			fmt.Println("TRIANGULO OBTUSANGULO")
		} else if a2 < b2+c2 {
			fmt.Println("TRIANGULO ACUTANGULO")
		}

		if a == b && b == c {
			fmt.Println("TRIANGULO EQUILATERO")
		} else if a == b || a == c || b == c {
			fmt.Println("TRIANGULO ISOSCELES")
		}
	}
}
