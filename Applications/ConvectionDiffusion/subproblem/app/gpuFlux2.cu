template <typename T>  __device__  void devicegpuFlux2(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw)
{
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	while (i<ng) {
		T udg2 = udg[1*ng+i];
		T udg3 = udg[2*ng+i];
		f[0*ng+i] = udg2;
		f[1*ng+i] = udg3;
		i += blockDim.x * gridDim.x;
	}
}

template <typename T> __global__ void kernelgpuFlux2(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw)
{
	devicegpuFlux2(f, xdg, udg, odg, wdg, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw);
}

template <typename T> void gpuFlux2(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw)
{
	int blockDim = 256;
	int gridDim = (ng + blockDim - 1) / blockDim;
	gridDim = (gridDim>1024)? 1024 : gridDim;
	kernelgpuFlux2<<<gridDim, blockDim>>>(f, xdg, udg, odg, wdg, uinf, param, time, modelnumber, ng, nc, ncu, nd, ncx, nco, ncw);
}

template void gpuFlux2(double *, double *, double *, double *, double *, double *, double *, double, int, int, int, int, int, int, int, int);
template void gpuFlux2(float *, float *, float *, float *, float *, float *, float *, float, int, int, int, int, int, int, int, int);
