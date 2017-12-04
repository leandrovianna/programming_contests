package main

import "fmt"

func main() {
	var s1, s2, s3 string
	fmt.Scan(&s1, &s2, &s3)

	var answer string

	switch true {
	case s3 == "carnivoro":
		answer = "aguia"
	case s2 == "ave" && s3 == "onivoro":
		answer = "pomba"
	case s2 == "mamifero" && s3 == "onivoro":
		answer = "homem"
	case s2 == "mamifero" && s3 == "herbivoro":
		answer = "vaca"
	case s2 == "inseto" && s3 == "hematofago":
		answer = "pulga"
	case s2 == "inseto" && s3 == "herbivoro":
		answer = "lagarta"
	case s2 == "anelideo" && s3 == "hematofago":
		answer = "sanguessuga"
	case s2 == "anelideo" && s3 == "onivoro":
		answer = "minhoca"
	default:
		answer = "URI is the best!"
	}

	fmt.Println(answer)
}
