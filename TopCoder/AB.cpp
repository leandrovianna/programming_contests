#include <string>
#include <iostream>

class AB {
    public:
        std::string createString(int n, int k) {
            std::string s = "";
            int max_pairs = (n/2) * (n - n/2);

            if (k < n) {
            	s = "A" + std::string(k, 'B') 
            		+ std::string(n - 1 - k, 'A');
            	s += '\0';
            }                
            else if (k <= max_pairs) {
            	s = std::string(n/2, 'A')
            		+ std::string(n - n/2, 'B');
            	s += '\0';
            }
            
			return s;
        }
};				

int main() {
	AB ab;

	std::cout << ab.createString(5, 8) << std::endl;
	std::cout << ab.createString(10, 12) << std::endl;
	std::cout << ab.createString(2, 0) << std::endl;
	return 0;
}
