#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int t, p, x, y;		
	double ang, ang2;
	string res;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> p >> x >> y;

		// colocando os pontos em grafico padrao
		x -= 50;
		y -= 50;
		
		//descobrindo o valor de angulo
		ang = atan2(x, y);
		// convertendo para graus
		ang = (ang * 180.0) / M_PI;
		if (ang < 0) ang += 360;

		// angulo do progresso
		ang2 = p / 100.0 * 360;

		if (ang >= ang2) {
			res = "white";
		}
		else {
			res = "black";
		}

		cout << "Case #" << i+1 << ": " << res << endl;
	}
	return 0;
}
