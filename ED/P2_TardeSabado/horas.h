#pragma once

#include <iostream>
#include <stdexcept>
#include <iomanip>

class Horas {
public:
	Horas() {}
	Horas(int h, int m, int s): hora(h), min(m), sec(s) {
		if (h < 0 || h > HORAS_DIA) throw std::invalid_argument("ERROR");
		else if (m < 0 || m > MINUTOS_HORA) throw std::invalid_argument("ERROR");
		else if (s < 0 || s > SEGUNDOS_MIN) throw std::invalid_argument("ERROR");
	}
	int get_hora() const { return hora; };
	int get_min() const { return min; };
	int get_sec() const { return sec; };

	Horas& operator= (Horas const& other) {
		if (this != &other) {
			hora = other.hora;
			min = other.min;
			sec = other.sec;
		}
		return *this;
	}
	bool operator> (Horas const& other) const {
		if (hora > other.hora) return true;
		else if (hora < other.hora) return false;
		else if (min > other.min) return true;
		else if (min < other.min) return false;
		else if (sec > other.sec) return true;
		else return false;
	}
	bool operator< (Horas const& other) const {
		if (hora > other.hora) return false;
		else if (hora < other.hora) return true;
		else if (min > other.min) return false;
		else if (min < other.min) return true;
		else if (sec > other.sec) return false;
		else if (sec < other.sec) return true;
		else return false;
	}
	bool operator== (Horas const& other) const {
		return hora == other.hora && min == other.min && sec == other.sec;
	}
	bool operator<= (Horas const& other) const {
		return *this < other || *this == other;
	}
	Horas operator+ (Horas const& other) const {
		int h, m, s;
		h = hora + other.hora;
		m = min + other.min;
		s = sec + other.sec;
		if (s > SEGUNDOS_MIN) {
			s -= SEGUNDOS_MIN + 1;
			m += 1;
		}
		if (m > MINUTOS_HORA) {
			m -= MINUTOS_HORA + 1;
			h += 1;
		}
		if (h > HORAS_DIA) throw std::invalid_argument("ERROR");
		return Horas(h, m, s);
	}

private:
	const int HORAS_DIA = 23;
	const int MINUTOS_HORA = 59;
	const int SEGUNDOS_MIN = MINUTOS_HORA;
	int hora, min, sec;
};

inline std::ostream& operator<< (std::ostream& out, Horas const& h) {
	out << std::setw(2) << std::setfill('0') << h.get_hora() << ":"
		<< std::setw(2) << std::setfill('0') << h.get_min() << ":"
		<< std::setw(2) << std::setfill('0') << h.get_sec();
	return out;
}
inline std::istream& operator>> (std::istream& in, Horas& ho) {
	int h, m, s;
	char aux;
	in >> h >> aux >> m >> aux >> s;
	ho = Horas(h, m, s);
	return in;
}