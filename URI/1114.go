package main

import "fmt"

func input(pass *int) bool {
	fmt.Scan(pass)
	return *pass != 2002
}

func main() {
	var pass int
	for input(&pass) {
		fmt.Println("Senha Invalida")
	}

	fmt.Println("Acesso Permitido")
}
