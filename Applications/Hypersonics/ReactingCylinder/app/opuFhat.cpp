template <typename T> void opuFhat(T *f, T *xdg, T *udg1, T *udg2, T *odg1, T *odg2,  T *wdg1, T *wdg2, T *uhg, T *nlg, T *tau, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw, Mutation::Mixture *mix)
{
}

template void opuFhat(double *, double *, double *, double *, double *, double *, double *, double *, double *, double *, double *, double *, double *, double, int, int, int, int, int, int, int, int, Mutation::Mixture *);
template void opuFhat(float *, float *, float *, float *, float *, float *, float *, float *, float *, float *, float *, float *, float *, float, int, int, int, int, int, int, int, int, Mutation::Mixture *);
