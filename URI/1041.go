//URI Online Judge - Coordenadas de um Ponto - 1041
package main

import "fmt"

type Point struct {
	X float64
	Y float64
}

func main() {
	p := Point{}

	fmt.Scan(&p.X, &p.Y)

	var qd int

	if p.X == 0 && p.Y == 0 {
		fmt.Print("Origem\n")
	} else if p.X == 0 {
		fmt.Print("Eixo Y\n")
	} else if p.Y == 0 {
		fmt.Print("Eixo X\n")
	} else {
		if p.X > 0 {
			if p.Y > 0 {
				qd = 1
			} else {
				qd = 4
			}
		} else {
			if p.Y > 0 {
				qd = 2
			} else {
				qd = 3
			}
		}
		fmt.Printf("Q%d\n", qd)
	}
}
