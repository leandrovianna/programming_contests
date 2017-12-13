package main

import "fmt"

func main() {
	var g1, g2, qtdInter, qtdGremio, qtdEmp = 0, 0, 0, 0, 0

	for {
		fmt.Scan(&g1, &g2)

		if g1 > g2 {
			qtdInter++
		} else if g1 < g2 {
			qtdGremio++
		} else {
			qtdEmp++
		}

		fmt.Println("Novo grenal (1-sim 2-nao)")
		fmt.Scan(&g1)
		if g1 != 1 {
			break
		}
	}

	fmt.Printf("%d grenais\n", qtdInter+qtdGremio+qtdEmp)
	fmt.Printf("Inter:%d\nGremio:%d\nEmpates:%d\n",
		qtdInter, qtdGremio, qtdEmp)

	if qtdInter > qtdGremio {
		fmt.Println("Inter venceu mais")
	} else if qtdInter < qtdGremio {
		fmt.Println("Gremio venceu mais")
	} else {
		fmt.Println("Nao houve vencedor")
	}
}
