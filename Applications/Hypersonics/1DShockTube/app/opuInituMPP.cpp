template <typename T> void opuInitu(T *f, T *xdg, T *uinf, T *param, int modelnumber, int ng, int ncx, int nce, int npe, int ne, Mutation::Mixture *mix)
{
	for (int i = 0; i <ng; i++) {
		int j = i%npe;
		int k = (i-j)/npe;
		T param1 = param[0];
		T param2 = param[1];
		T param3 = param[2];
		T param4 = param[3];
		T param5 = param[4];
		T param6 = param[5];
		T param7 = param[6];
		T param8 = param[7];
		T param9 = param[8];
		T param10 = param[9];
		T param11 = param[10];
		T param12 = param[11];
		T param13 = param[12];
		T param14 = param[13];
		T xdg1 = xdg[j+npe*0+npe*ncx*k];
        // if (xdg1 < 0)
        // {
        f[j+npe*0+npe*nce*k] = param1;
        f[j+npe*1+npe*nce*k] = param2;
        f[j+npe*2+npe*nce*k] = param3;
        f[j+npe*3+npe*nce*k] = param4;
        f[j+npe*4+npe*nce*k] = param5;
        f[j+npe*5+npe*nce*k] = param6;
        f[j+npe*6+npe*nce*k] = param7;
        // }
        // else
        // {
        //     f[j+npe*0+npe*nce*k] = param8;
        //     f[j+npe*1+npe*nce*k] = param9;
        //     f[j+npe*2+npe*nce*k] = param10;
        //     f[j+npe*3+npe*nce*k] = param11;
        //     f[j+npe*4+npe*nce*k] = param12;
        //     f[j+npe*5+npe*nce*k] = param13;
        //     f[j+npe*6+npe*nce*k] = param14;
        // }
	}
}

template void opuInitu(double *, double *, double *, double *, int, int, int, int, int, int, Mutation::Mixture *);
template void opuInitu(float *, float *, float *, float *, int, int, int, int, int, int, Mutation::Mixture *);
