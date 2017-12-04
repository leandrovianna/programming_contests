package main

import "fmt"

func main() {
	ddd_to_city := map[int]string{
		61: "Brasilia",
		71: "Salvador",
		11: "Sao Paulo",
		21: "Rio de Janeiro",
		32: "Juiz de Fora",
		19: "Campinas",
		27: "Vitoria",
		31: "Belo Horizonte",
	}

	var ddd int
	fmt.Scan(&ddd)

	if answer, ok := ddd_to_city[ddd]; ok {
		fmt.Println(answer)
	} else {
		fmt.Println("DDD nao cadastrado")
	}
}
