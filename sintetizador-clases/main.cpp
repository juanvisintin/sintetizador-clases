#include <iostream>
#include <cmath>

const double PI = 3.14159265358979323846;

class Oscilador {
public:
	double frecuencia;
	double sampleRate;
	double fase;

	// calcula la siguiente muestra y avanza la fase
	double siguienteMuestra() {
		double muestra = std::sin(2.0 * PI * fase);
		fase += frecuencia / sampleRate;
		if (fase >= 1.0) {
			fase -= 1.0;
		}
		return muestra;
	}
};

int main() {
	Oscilador grave;
	grave.frecuencia = 440.0;
	grave.sampleRate = 44100.0;
	grave.fase = 0.0;
	
	Oscilador agudo;
	agudo.frecuencia = 880.0;
	agudo.sampleRate = 44100.0;
	agudo.fase = 0.0;

	for (int i = 0; i < 6; ++i) {
		std::cout << "Muestra " << i << ": Grave = " << grave.siguienteMuestra()
			<< "   Agudo = " << agudo.siguienteMuestra() << "\n";
	}

	return 0;
}