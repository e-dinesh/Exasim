template <typename T> void opuFlux(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw)
{
	for (int i = 0; i <ng; i++) {
		T param1 = param[0];
		T udg2 = udg[1*ng+i];
		T udg3 = udg[2*ng+i];
		T wdg1 = wdg[0*ng+i];
		T t2 = wdg1+1.0;
		f[0*ng+i] = param1*t2*udg2;
		f[1*ng+i] = param1*t2*udg3;
	}
}

template void opuFlux(double *, double *, double *, double *, double *, double *, double *, double, int, int, int, int, int, int, int, int);
template void opuFlux(float *, float *, float *, float *, float *, float *, float *, float, int, int, int, int, int, int, int, int);
