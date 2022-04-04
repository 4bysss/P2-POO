class Tarjeta{
	public:
		static enum Tipo{Otro,VISA,Mastercard,Maestro,JCB,AmericanExpress};
		Tarjeta(int num,Usuario&,Fecha&);
		Tipo& tipo()const;
		const Numero& numero()const { return num;};
		const Usuario& titular()const{ return titu;};
		const Fecha& caducidad()const{ return cadu;};
		const bool activa()const {return acti;};
		bool activa(bool t=true);
		void anular_titular();

		//Clase excepcion para tarjetas caducadas
		class Caducada{
			public:
				
				Caducada(Fecha&fech = cadu):cuand(fech);
				Fecha& cuando();
			private:
				Fecha& cuand;
		};
		//Clase excepcion para tarjetas duplicadas
		class Num_duplicado{
			public:
				Num_duplicado(Numero& n):dup(n);
				Numero&que();
			private:
				Numero&dup;
		};
		class Desactivada{};

	private:
		const Numero& num;
		Usuario* titu;
		const Fecha& cadu;
		bool acti;
};

//Subclase Numero 

class Numero{
	public:
		static enum Razon{LONGITUD,DIGITOS,NO_VALIDO};
		operator const char*() const;
		class Incorrecto{
			public:
				Incorrecto(Numero::Razon r);
				Numero::Razon& razon();
			private:
				Numero::Razon raz;
	private:
		Cadena& troq;
};


//Metodos externos de Numero 
bool operator<(const Numero&,const Numero&);


//Metodos externos de Tarjeta 
bool operator<(const Tarjeta&,const Tarjeta&);
std::ostream& operator<<(std::ostream&,Tarjeta&);