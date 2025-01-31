template <typename T> void opuAvfield(T *f, T *xdg, T *udg, T *odg, T *wdg, T *uinf, T *param, T time, int modelnumber, int ng, int nc, int ncu, int nd, int ncx, int nco, int ncw, int nce, int npe, int ne, Mutation::Mixture *mix)
{

	double Ustate[6];
	int nspecies = 5;
	int ndim = 2;
	double rho_scale = uinf[0];
	double u_scale = uinf[1];
	double rhoe_scale = uinf[2];
	double omega_scale = rho_scale*u_scale;
    // std::cout << "IN AVFIELD" << std::endl;
	for (int i = 0; i <ng; i++) {
		int j = i%npe;
		int k = (i-j)/npe;
		T param1 = param[0];
		T param15 = param[14];
		T param16 = param[15];
		T param17 = param[16];
		T param18 = param[17];
		T uinf1 = uinf[0];
		T uinf2 = uinf[1];
		T xdg1 = xdg[j+npe*0+npe*ncx*k];
		T xdg2 = xdg[j+npe*1+npe*ncx*k];
		T udg1 = udg[j+npe*0+npe*nc*k];
		T udg2 = udg[j+npe*1+npe*nc*k];
		T udg3 = udg[j+npe*2+npe*nc*k];
		T udg4 = udg[j+npe*3+npe*nc*k];
		T udg5 = udg[j+npe*4+npe*nc*k];
		T udg6 = udg[j+npe*5+npe*nc*k];
		T udg7 = udg[j+npe*6+npe*nc*k];
		T udg8 = udg[j+npe*7+npe*nc*k];
		T udg9 = udg[j+npe*8+npe*nc*k];
		T udg10 = udg[j+npe*9+npe*nc*k];
		T udg11 = udg[j+npe*10+npe*nc*k];
		T udg12 = udg[j+npe*11+npe*nc*k];
		T udg13 = udg[j+npe*12+npe*nc*k];
		T udg14 = udg[j+npe*13+npe*nc*k];
		T udg15 = udg[j+npe*14+npe*nc*k];
		T udg16 = udg[j+npe*15+npe*nc*k];
		T udg17 = udg[j+npe*16+npe*nc*k];
		T udg18 = udg[j+npe*17+npe*nc*k];
		T udg19 = udg[j+npe*18+npe*nc*k];
		T udg20 = udg[j+npe*19+npe*nc*k];
		T udg21 = udg[j+npe*20+npe*nc*k];
		T udg22 = udg[j+npe*21+npe*nc*k];
		T udg23 = udg[j+npe*22+npe*nc*k];
		T udg24 = udg[j+npe*23+npe*nc*k];
		T odg1 = odg[j+npe*0+npe*nco*k];
		T odg2 = odg[j+npe*1+npe*nco*k];

		T t1pi = 1.0/3.141592653589793;

		udg1 = udg1*(t1pi*atan(udg1*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg2 = udg2*(t1pi*atan(udg2*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg3 = udg3*(t1pi*atan(udg3*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg4 = udg4*(t1pi*atan(udg4*1.0E+12)+1.0/2.0)+3.182454300088011E-13;
		udg5 = udg5*(t1pi*atan(udg5*1.0E+12)+1.0/2.0)+3.182454300088011E-13;

		double Ucons[8] = {udg1, udg2, udg3, udg4, udg5, udg6, udg7, udg8};
		dimensionalizeConsVars(Ucons, (double*)uinf, nspecies, ndim);
		conservativeToState(Ucons, Ustate, (double*)uinf, nspecies, ndim);
		double rhovec[5] = {Ustate[0],Ustate[1],Ustate[2],Ustate[3],Ustate[4]};
		double rhoe = Ustate[nspecies];

		mix->setState(rhovec, &rhoe, 0);
		uinf1 = mix->P() / rhoe_scale;
		uinf2 = mix->mixtureFrozenGamma();
// uinf2 = 1.4;
				T t2 = uinf2*2.0;
		T t3 = uinf2+1.0;
		T t4 = 1.0/3.141592653589793;
		T t5 = 1.0/param15;
		T t8 = udg9+udg10+udg11+udg12+udg13;
		T t9 = udg17+udg18+udg19+udg20+udg21;
		T t10 = param17*1.0E+12;
		T t11 = udg1*1.0E+12;
		T t12 = udg2*1.0E+12;
		T t13 = udg3*1.0E+12;
		T t14 = udg4*1.0E+12;
		T t15 = udg5*1.0E+12;
		T t6 = t2-2.0;
		T t7 = 1.0/t3;
		T t16 = atan(t11);
		T t17 = atan(t12);
		T t18 = atan(t13);
		T t19 = atan(t14);
		T t20 = atan(t15);
		T t21 = t4*t16;
		T t22 = t4*t17;
		T t23 = t4*t18;
		T t24 = t4*t19;
		T t25 = t4*t20;
		T t26 = t21+1.0/2.0;
		T t27 = t22+1.0/2.0;
		T t28 = t23+1.0/2.0;
		T t29 = t24+1.0/2.0;
		T t30 = t25+1.0/2.0;
		T t31 = t26*udg1;
		T t32 = t27*udg2;
		T t33 = t28*udg3;
		T t34 = t29*udg4;
		T t35 = t30*udg5;
		T t36 = t31+t32+t33+t34+t35+1.591227150044006E-12;
		T t37 = 1.0/t36;
		T t38 = t37*t37;
		T t39 = t37*udg8;
		T t40 = t37*uinf1;
		T t41 = t8*t37*udg6;
		T t42 = t9*t37*udg7;
		T t43 = -t41;
		T t44 = -t42;
		T t47 = t39*1.0E+12;
		T t48 = t40*1.0E+12;
		T t49 = -t37*(t41-udg14);
		T t50 = -t37*(t42-udg23);
		T t51 = t39+t40-1.0E-4;
		T t52 = t37*(t41-udg14)*-1.0E+12;
		T t53 = t37*(t42-udg23)*-1.0E+12;
		T t45 = t43+udg14;
		T t46 = t44+udg23;
		T t54 = t47+t48-1.0E+8;
		T t58 = t49+t50-1.0E+4;
		T t60 = t52+t53-1.0E+16;
		T t55 = atan(t54);
		T t61 = atan(t60);
		T t56 = t4*t55;
		T t62 = t4*t61;
		T t57 = t56+1.0/2.0;
		T t63 = t62-1.0/2.0;
		T t59 = t51*t57;
		T t67 = -t63*(t37*(t41-udg14)+t37*(t42-udg23)+1.0E+4);
		T t68 = t63*(t37*(t41-udg14)+t37*(t42-udg23)+1.0E+4);
		T t64 = t59+1.000000003182454E-4;
		T t69 = t68*-1.0E+12;
		T t70 = t67-2.0E+4;
		T t65 = t6*t7*t64;
		T t71 = t69-2.0E+16;
		T t66 = 1.0/sqrt(t65);
		T t72 = atan(t71);
		T t73 = t4*t72;
		T t74 = t73+1.0/2.0;
		T t75 = -t74*(t68+2.0E+4);
		T t76 = t68+t75+1.0E+4;
		T t77 = odg2*t5*t66*t76;
		T t78 = -t77;
		T t80 = t77*1.0E+12;
		T t79 = param17+t78;
		T t81 = -t80;
		T t82 = t10+t81;
		T t83 = atan(t82);
		T t84 = t4*t83;
		T t85 = t84-1.0/2.0;
		T t86 = t79*t85;
		f[j+npe*0+npe*nce*k] = odg2*param16*t5*(sqrt(t38*(udg6*udg6)+t38*(udg7*udg7))+1.0/t66)*(t86-(t4*atan(param18*-1.0E+12+t86*1.0E+12+3.182454300088011E-1)+1.0/2.0)*(-param18+t86+3.182454300088011E-13));

		// T t2 = udg1*udg1;
		// T t3 = udg2*udg2;
		// T t4 = udg3*udg3;
		// T t5 = udg4*udg4;
		// T t6 = udg5*udg5;
		// T t7 = uinf2*2.0;
		// T t8 = uinf2+1.0;
		// T t9 = 1.0/3.141592653589793;
		// T t10 = 1.0/param15;
		// T t13 = param17*1.0E+12;
		// T t14 = udg1*1.0E+12;
		// T t15 = udg2*1.0E+12;
		// T t16 = udg3*1.0E+12;
		// T t17 = udg4*1.0E+12;
		// T t18 = udg5*1.0E+12;
		// T t11 = t7-2.0;
		// T t12 = 1.0/t8;
		// T t19 = atan(t14);
		// T t20 = atan(t15);
		// T t21 = atan(t16);
		// T t22 = atan(t17);
		// T t23 = atan(t18);
		// T t39 = t2*1.0E+24;
		// T t40 = t3*1.0E+24;
		// T t41 = t4*1.0E+24;
		// T t42 = t5*1.0E+24;
		// T t43 = t6*1.0E+24;
		// T t24 = t9*t19;
		// T t25 = t9*t20;
		// T t26 = t9*t21;
		// T t27 = t9*t22;
		// T t28 = t9*t23;
		// T t44 = t39+1.0;
		// T t45 = t40+1.0;
		// T t46 = t41+1.0;
		// T t47 = t42+1.0;
		// T t48 = t43+1.0;
		// T t29 = t24+1.0/2.0;
		// T t30 = t25+1.0/2.0;
		// T t31 = t26+1.0/2.0;
		// T t32 = t27+1.0/2.0;
		// T t33 = t28+1.0/2.0;
		// T t49 = 1.0/t44;
		// T t50 = 1.0/t45;
		// T t51 = 1.0/t46;
		// T t52 = 1.0/t47;
		// T t53 = 1.0/t48;
		// T t34 = t29*udg1;
		// T t35 = t30*udg2;
		// T t36 = t31*udg3;
		// T t37 = t32*udg4;
		// T t38 = t33*udg5;
		// T t54 = t9*t14*t49;
		// T t55 = t9*t15*t50;
		// T t56 = t9*t16*t51;
		// T t57 = t9*t17*t52;
		// T t58 = t9*t18*t53;
		// T t59 = t29+t54;
		// T t60 = t30+t55;
		// T t61 = t31+t56;
		// T t62 = t32+t57;
		// T t63 = t33+t58;
		// T t74 = t34+t35+t36+t37+t38+1.591227150044006E-12;
		// T t64 = t59*udg9;
		// T t65 = t60*udg10;
		// T t66 = t61*udg11;
		// T t67 = t59*udg17;
		// T t68 = t62*udg12;
		// T t69 = t60*udg18;
		// T t70 = t63*udg13;
		// T t71 = t61*udg19;
		// T t72 = t62*udg20;
		// T t73 = t63*udg21;
		// T t75 = 1.0/t74;
		// T t76 = t75*t75;
		// T t77 = t75*udg8;
		// T t78 = t75*uinf1;
		// T t86 = t64+t65+t66+t68+t70;
		// T t87 = t67+t69+t71+t72+t73;
		// T t79 = t77*1.0E+12;
		// T t80 = t78*1.0E+12;
		// T t81 = t77+t78-1.0E-4;
		// T t88 = t75*t86*udg6;
		// T t89 = t75*t87*udg7;
		// T t82 = t79+t80-1.0E+8;
		// T t90 = -t88;
		// T t91 = -t89;
		// T t95 = -t75*(t88-udg14);
		// T t96 = -t75*(t89-udg23);
		// T t97 = t75*(t88-udg14)*-1.0E+12;
		// T t98 = t75*(t89-udg23)*-1.0E+12;
		// T t83 = atan(t82);
		// T t92 = t90+udg14;
		// T t93 = t91+udg23;
		// T t102 = t95+t96-1.0E+4;
		// T t103 = t97+t98-1.0E+16;
		// T t84 = t9*t83;
		// T t104 = atan(t103);
		// T t85 = t84+1.0/2.0;
		// T t105 = t9*t104;
		// T t94 = t81*t85;
		// T t106 = t105-1.0/2.0;
		// T t99 = t94+1.000000003182454E-4;
		// T t107 = -t106*(t75*(t88-udg14)+t75*(t89-udg23)+1.0E+4);
		// T t108 = t106*(t75*(t88-udg14)+t75*(t89-udg23)+1.0E+4);
		// T t100 = t11*t12*t99;
		// T t109 = t108*-1.0E+12;
		// T t110 = t107-2.0E+4;
		// T t101 = 1.0/sqrt(t100);
		// T t111 = t109-2.0E+16;
		// T t112 = atan(t111);
		// T t113 = t9*t112;
		// T t114 = t113+1.0/2.0;
		// T t115 = -t114*(t108+2.0E+4);
		// T t116 = t108+t115+1.0E+4;
		// T t117 = odg2*t10*t101*t116;
		// T t118 = -t117;
		// T t120 = t117*1.0E+12;
		// T t119 = param17+t118;
		// T t121 = -t120;
		// T t122 = t13+t121;
		// T t123 = atan(t122);
		// T t124 = t9*t123;
		// T t125 = t124-1.0/2.0;
		// T t126 = t119*t125;
		// f[j+npe*0+npe*nce*k] = odg2*param16*t10*(sqrt(t76*(udg6*udg6)+t76*(udg7*udg7))+1.0/t101)*(t126-(t9*atan(param18*-1.0E+12+t126*1.0E+12+3.182454300088011E-1)+1.0/2.0)*(-param18+t126+3.182454300088011E-13));
        // f[j+npe*0+npe*nce*k] = 0.0;
	}
}

template void opuAvfield(double *, double *, double *, double *, double *, double *, double *, double, int, int, int, int, int, int, int, int, int, int, int, Mutation::Mixture *);
template void opuAvfield(float *, float *, float *, float *, float *, float *, float *, float, int, int, int, int, int, int, int, int, int, int, int, Mutation::Mixture *);
