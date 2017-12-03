//URI Online Judge - Tempo de Jogo com Minutos - 1047
package main

import "fmt"

func main() {
	var h1, m1, h2, m2 int
	fmt.Scan(&h1, &m1, &h2, &m2)
	
	t1 := h1 * 60 * 60 + m1 * 60
	t2 := h2 * 60 * 60 + m2 * 60

	d := t1 - t2
	if d < 0 {
		d += 24 * 60 * 60
	}

	h := d / (60 * 60)
	d %= 60 * 60

	fmt.Printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", h, d)
}
