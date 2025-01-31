template <typename T> void cpuSource(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw)
{
	#pragma omp parallel for
	for (int i = 0; i <ng; i++) {
		T udg1 = udg[0*ng+i];
		f[0*ng+i] = 1.0;
		f[1*ng+i] = udg1;
	}
}

template void cpuSource(double *, double *, double *, double *, double *, double *, double *, double, int, int, int, int, int, int, int, int);
template void cpuSource(float *, float *, float *, float *, float *, float *, float *, float, int, int, int, int, int, int, int, int);
