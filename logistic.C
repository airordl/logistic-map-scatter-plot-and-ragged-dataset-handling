#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

long double logistic (long double,long double);

int main () {
	double zero = .5;
	fstream logi ("logi.dat");
	
	const int N = 1000;
	const int asymptote = 100;
	
	double** dat = new double* [N];
	
	double rin = 0;
	double rfin = 4;//4 is the standard upper limit
	double rdelta = .001;
	double nofrs = (rfin - rin) / rdelta;
	
	for (int i = 0; i < N ; ++i) {
		dat[i] = new double [(const int) nofrs];
	}
	
	double aux;
	int I = 0;
	
	cout << "buffering " << endl;
	
	for (double r = rin; r < rfin; r+= rdelta) {
		aux = zero;
		for (int i = 0; i < N + asymptote; ++i) {
			
			//cout << "aux = " << aux << '\t';
			aux = logistic(aux,r);
			
			if ( i > asymptote - 1) {
				if (I < nofrs) dat[i-asymptote][I] = aux;
			}
		}
		
		for (int i = 0; i< N; ++i) {
		//	logi << dat[i] << ' ';
		}
		//logi << endl;
		I++;
	}
	
	bool write;
	
	cout << "writing " << endl;
	
	double upper = 10;
	double lower = -10;
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < (const int) nofrs; ++j) {
			write = true;
			
			
			if ( write && dat[i][j] < upper && dat[i][j] > lower) 
                logi << setprecision (10) << fixed << dat[i][j] << ' ';
		  //  else	
            //    logi << 0 << ' ';
		}
		logi << endl;
	}
	
	cout << '\a' ;
}

long double logistic (long double x, long double r) {
	return r*x*(1.-x);
}






///////////////////////
