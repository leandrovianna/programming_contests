//URI Online Judge - Tempo de Jogo com Minutos - 1047
package main

import "fmt"

func main() {
	var h1, m1, h2, m2 int
	fmt.Scan(&h1, &m1, &h2, &m2)

	dh := h2 - h1
	if dh <= 0 {
		dh += 24
	}

	dm := m2 - m1
	if dm < 0 {
		dm += 60
		dh -= 1
	}

	fmt.Printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", dh, dm)
}
