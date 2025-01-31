template <typename T>  __global__  void kernelgpuInitu2(T *f, T *xdg, T *uinf, T *param, int modelnumber, int ng, int ncx, int nce, int npe, int ne)
{
	int i = threadIdx.x + blockIdx.x * blockDim.x;
	while (i<ng) {
		int j = i%npe;
		int k = (i-j)/npe;
		T xdg1 = xdg[j+npe*0+npe*ncx*k];
		T xdg2 = xdg[j+npe*1+npe*ncx*k];
		f[j+npe*0+npe*nce*k] = 0.0;
		i += blockDim.x * gridDim.x;
	}
}

template <typename T> void gpuInitu2(T *f, T *xdg, T *uinf, T *param, int modelnumber, int ng, int ncx, int nce, int npe, int ne)
{
	int blockDim = 256;
	int gridDim = (ng + blockDim - 1) / blockDim;
	gridDim = (gridDim>1024)? 1024 : gridDim;
	kernelgpuInitu2<<<gridDim, blockDim>>>(f, xdg, uinf, param, modelnumber, ng, ncx, nce, npe, ne);
}

template void gpuInitu2(double *, double *, double *, double *, int, int, int, int, int, int);
template void gpuInitu2(float *, float *, float *, float *, int, int, int, int, int, int);
