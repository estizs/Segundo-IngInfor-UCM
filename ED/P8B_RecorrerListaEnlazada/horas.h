// Estibaliz Zubimendi
// A79
#pragma once

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <vector>
#include <algorithm>

class Hora {
public:
	Hora() {};
	Hora(int h, int m, int s) : hora(h), min(m), sec(s) {
		if (h < 0 || h > HORAS_DIA) throw std::invalid_argument("ERROR");
		else if (m < 0 || m > MINUTOS_HORA) throw std::invalid_argument("ERROR");
		else if (s < 0 || s > SEGUNDOS_MINUTO) throw std::invalid_argument("ERROR");
	}

	int get_hora() const { return hora; };
	int get_min() const { return min; };
	int get_sec() const { return sec; };

	Hora& operator=(Hora const& other) {
		if (this != &other) {
			hora = other.hora;
			min = other.min;
			sec = other.sec;
		}
		return *this;
	}
	bool operator< (Hora const& h) const {
		if (hora > h.hora) return false;
		else if (hora < h.hora) return true;
		else if (min > h.min) return false;
		else if (min < h.min) return true;
		else if (sec > h.sec) return false;
		else if (sec < h.sec) return true;
		else return false;
	}
	bool operator == (Hora const& h) const {
		return hora == h.hora && min == h.min && sec == h.sec;
	}
	bool operator <= (Hora const& h) const {
		return *this < h || *this == h;
	}
private:
	const int HORAS_DIA = 23;
	const int MINUTOS_HORA = 59;
	const int SEGUNDOS_MINUTO = MINUTOS_HORA;
	int hora, min, sec;
};

inline std::ostream& operator<<(std::ostream& out, Hora const& h) {
	out << std::setw(2) << std::setfill('0') << h.get_hora() << ":"
		<< std::setw(2) << std::setfill('0') << h.get_min() << ":"
		<< std::setw(2) << std::setfill('0') << h.get_sec() << "\n";
	return out;
}
inline std::istream& operator>>(std::istream& in, Hora& ho) {
	int h, m, s;
	char aux;
	in >> h >> aux >> m >> aux >> s;
	ho = Hora(h, m, s);
	return in;
}