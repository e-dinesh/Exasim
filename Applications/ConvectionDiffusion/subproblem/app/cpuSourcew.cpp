#include "cpuSourcew1.cpp"
#include "cpuSourcew2.cpp"

template <typename T> void cpuSourcew(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw, int nce, int npe, int ne)
{
	if (modelnumber == 1)
		cpuSourcew1(f, xdg, udg, odg, wdg, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw, nce, npe, ne);
	else if (modelnumber == 2)
		cpuSourcew2(f, xdg, udg, odg, wdg, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw, nce, npe, ne);
}

template void cpuSourcew(double *, double *, double *, double *, double *, double *, double *, double, int, int, int, int, int, int, int, int, int, int, int);
template void cpuSourcew(float *, float *, float *, float *, float *, float *, float *, float, int, int, int, int, int, int, int, int, int, int, int);
