#include "cpuSource1.cpp"
#include "cpuSource2.cpp"

template <typename T> void cpuSource(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw)
{
	if (modelnumber == 1)
		cpuSource1(f, xdg, udg, odg, wdg, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw);
	else if (modelnumber == 2)
		cpuSource2(f, xdg, udg, odg, wdg, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw);
}

template void cpuSource(double *, double *, double *, double *, double *, double *, double *, double, int, int, int, int, int, int, int, int);
template void cpuSource(float *, float *, float *, float *, float *, float *, float *, float, int, int, int, int, int, int, int, int);
